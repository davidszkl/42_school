#ifndef ICE_HPP
# define ICE_HPP
# include "AMateria.hpp"

class Ice : public AMateria
{
public:

	Ice();
	Ice(Ice const& cpy);
	~Ice();

	Ice& operator=(Ice const & rhs);

	virtual	AMateria*	clone() const;
	virtual	void		use(ICharacter & target);
	std::string			getType() const;
};

#endif