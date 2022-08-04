#include "config.hpp"
#include "string_utils.hpp"
#include "debug.hpp"
#include <vector>
#include <cctype>
#include <string>
#include <algorithm>

//return statement (does not clean any whitespaces) without trailing ';'
//str[i] wil be == to return_value[0]
static std::string get_statement(const std::string& str, std::size_t i)
{
	std::size_t j = std::string(&str[i]).find(";");	
	if (j == std::string::npos)
		j = std::string(&str[i]).length();
	return str.substr(i, j);
}

//return location {...} (does not clean any whitespaces)
//str[i] wil be == to return_value[0]
static std::string get_location(const std::string& str, std::size_t i)
{
	std::size_t j = std::string(&str[i]).find("}");	
	if (j == std::string::npos)
		j = std::string(&str[i]).length();
	else
		j++;
	return str.substr(i, j);
	
}

//cpp version of ft_split with any whitespace as delimiter
static std::vector<std::string> split(const std::string& statement)
{
	using std::string;
	using std::isspace;

	std::vector<std::string> ret_val;
	std::size_t i = 0;
	while (i < statement.length())
	{
		while (i < statement.length() && isspace(statement[i]))
			i++;
		if (i == statement.length())
			return ret_val;
		std::size_t j = i;
		while (j < statement.length() && !isspace(statement[j]))
			j++;
		ret_val.push_back(statement.substr(i, j - i));
		i = j;
	}
	return ret_val;
}

// is_valid_statement but server only
static bool is_valid_server_statement(const std::vector<std::string>& statement)
{
	if (statement[0] == "error_page" && statement.size() == 3)
	{
		try {
			int i = my_stoi(statement[1]);
			if (i < 0)
				throw std::runtime_error("invlid error page number");
		} catch (...) {
			return false;
		}
		return true;
	}
	if (statement.size() != 2) return false;
	if (statement[0] == "server_name") return true;
	if (statement[0] == "listen")
	{
		try {
			int i = my_stoi(statement[1]);
			if (i <= 0 || i > 65535)
				throw std::runtime_error("invalid port number");
		} catch (...) {
			return false;
		}
		return true;
	}
	if (statement[0] == "client_max_body_size")
	{
		try {
			int i = my_stoi(statement[1]);
			if (i < 0)
				throw std::runtime_error("invlid error page number");

		} catch (...) {
			return false;
		}
		return true;
	}
	return false;
}

// is_valid_statement but location only
static bool is_valid_location_statement(const std::vector<std::string>& statement)
{
	if (statement.size() != 2) return false;

	const std::string& s = statement[0];
	if (s == "autoindex" && statement[1] != "on" && statement[1] != "off")
		return false;
	if (s == "use" || s == "redirect"
		|| s == "root" || s == "autoindex"
		|| s == "index" || s == "upload_pass")
		return true;
	return false;
}


// checks if statement is correct
// level == 0 -> checks for statements in server block
// level == 1 -> checks for statements in location block
static bool is_valid_statement(const std::vector<std::string>& split_statement, int level)
{
	if (level == 0)
		return is_valid_server_statement(split_statement);
	if (level == 1)
		return is_valid_location_statement(split_statement);
	return false;
}

//set statement for server scope
static void set_statement(config& c, const std::vector<std::string>& statement)
{
	const std::string& s = statement[0];
	if (s == "server_name")
		c.server_name = statement[1];
	if (s == "listen")
		c.port = my_stoi(statement[1]);
	if (s == "error_page")
		c.error_pages[my_stoi(statement[1])] = statement[2];
	if (s == "client_max_body_size")
		c.max_body = my_stoi(statement[1]);
}

//set statement for location scope
static void set_statement(config::location& l, const std::vector<std::string>& statement)
{
	const std::string& s0 = statement[0];
	const std::string& s1 = statement[1];

	if (s0 == "use")
		l.allowed_methods.push_back(s1);
	if (s0 == "redirect")
		l.redirect = s1;
	if (s0 == "root")
		l.root = s1;
	if (s0 == "autoindex")
		l.autoindex = (s1 == "on");
	if (s0 == "index")
		l.index = s1;
	if (s0 == "upload_pass")
		l.upload_dir = s1;
}

// checks if ret val of get_statement is a location block
static bool is_location(const std::string& statement)
{
	std::size_t i = 0;
	while (i < statement.length() && std::isspace(statement[i]))
		i++;
	if (i == statement.length()) return false;
	std::string tmp(&statement[i]);
	if (!(tmp.length() >= 9
				&& tmp.substr(0, 8) == "location"
				&& (std::isspace(tmp[8]) || tmp[8] == '{')))
		return false;
	i += 8;
	while (i < statement.length() && std::isspace(statement[i]))
		i++;
	while (i < statement.length() && !std::isspace(statement[i]))
		i++;
	while (i < statement.length() && std::isspace(statement[i]))
		i++;
	if (i == statement.length() || statement[i] != '{') return false;
	return true;
}

//gets location {...} returns ...
static std::string unwrap_location(const std::string str, std::string& location_path)
{
	std::size_t i = str.find('{');
	i++;
	std::size_t j = std::string(&str[i]).rfind('}');
	
	std::size_t v1 = i-2;
	while (std::isspace(str[v1]))
		v1--;
	std::size_t v2 = v1;
	v1++;
	while (!std::isspace(str[v2]))
		v2--;
	v2++;
	location_path = str.substr(v2, v1 - v2);
	return str.substr(i, j);
}

//str is substring containing location body without the '{' and '}'
static config::location init_location_conf(const std::string& str, std::size_t line_num)
{
	config::location l;
	std::size_t i = 0;
	while (i < str.length() && !is_only_whitespaces(std::string(&str[i])))
	{
		std::string statement = get_statement(str, i);
		std::vector<std::string> split_statement = split(statement);
		if (!is_valid_statement(split_statement, 1)) //1 for location block
		{
			if (split_statement.size() == 0) split_statement.push_back("empty statement");
			throw std::runtime_error(to_string(line_num + std::count(str.begin(), str.end(), '\n')) + ": invalid statement in location block (" + split_statement[0] + ")");
		}
		set_statement(l, split_statement);
		i += statement.length() + 1;
	}
	return l;

}

//str is substring containing server body without the '{' and '}'
static config init_server_conf(const std::string& str, std::size_t line_num)
{
	config c;
	std::size_t i = 0;
	while (i < str.length() && !is_only_whitespaces(std::string(&str[i])))
	{
		std::string statement = get_statement(str, i);
		if (is_location(statement))
		{
			std::string locstr = get_location(str, i);
			std::string location_path;
			config::location l = init_location_conf(unwrap_location(locstr, location_path), line_num);
			l.path = location_path;
			c.location_blocks.push_back(l);
			i += locstr.length();
			continue;
		}
		std::vector<std::string> split_statement = split(statement);
		if (!is_valid_statement(split_statement, 0)) //0 for server block
		{
			if (split_statement.size() == 0) split_statement.push_back("empty statement");
			throw std::runtime_error(to_string(line_num + std::count(str.begin(), str.end(), '\n')) + ": invalid statement in server block" + "(" + split_statement[0] + ")");
		}
		set_statement(c, split_statement);
		i += statement.length() + 1;
	}
	return c;
}

//i is index of beginning '{'
//returns index of ending '}'
static std::size_t get_end_block(const std::string& str, std::size_t i)
{
	i++;
	int depth = 0;
	while (depth >= 0)
	{
		if (str[i] == '{') depth++;
		if (str[i] == '}') depth--;
		i++;
	}
	return i - 1;
}

std::vector<config> get_config_vector(const std::string& str, std::size_t line_num)
{
	std::vector<config> r;
	std::size_t i = 0;
	i = std::string(&str[i]).find("server");
	while (i < str.length())
	{
		while (str[i] != '{') i++;
		const std::size_t e = get_end_block(str, i);
		r.push_back(init_server_conf(str.substr(i + 1, e - i - 1), line_num + std::count(str.begin(), str.begin() + i, '\n')));
		i = e + 1;
		if (i == str.length()) break;
		std::size_t i2 = std::string(&str[i]).find("server");
		if (i2 == std::string::npos) break;
		i += i2;
	}
	return r;
}
