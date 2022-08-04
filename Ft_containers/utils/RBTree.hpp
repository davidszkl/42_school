#pragma once
#include <algorithm>
#include <memory>
#include <iostream>

namespace ft
{

enum COLOR {BLACK, RED};

template<typename value_type>
struct s_Node {
	value_type	data;
	s_Node*		parent;
	s_Node*		Lchild;
	s_Node*		Rchild;
	COLOR		color;

	s_Node() : parent(nullptr), Lchild(nullptr), Rchild(nullptr), color(BLACK) {}
	s_Node (value_type v) : data(v), parent(nullptr), Lchild(nullptr), Rchild(nullptr), color(BLACK){}
	~s_Node() {}
};

template<class Container, class Allocator = std::allocator<s_Node<typename Container::value_type> > >
class RBT
{
public:

	typedef typename Container::value_type									value_type;
	typedef typename Container::key_type									key_type;
	typedef typename Container::mapped_type									mapped_type;
	typedef typename Allocator::template rebind<s_Node<value_type> >::other	allocator_type;
	typedef struct s_Node<value_type>										Node;
	typedef Node*															Node_ptr;
	typedef typename Container::key_compare									key_compare;
	typedef typename Container::size_type									size_type;

	Node_ptr				_leaf;// GO TO PRIVATE
private:

	size_type 				_size;
	key_compare				_comp;
	allocator_type			_alloc;
	Node_ptr				_root;
	

	Node_ptr	new_node(value_type val, Node_ptr parent) {
		Node_ptr newNode = _alloc.allocate(1);
		_alloc.construct(newNode, val);
		newNode->parent	 = parent;
		newNode->Lchild  = _leaf;
		newNode->Rchild  = _leaf;
		newNode->color	 = RED;
		return newNode;
	}

	void transplant(Node_ptr A, Node_ptr B) {
		if (!A->parent)
			_root = B;
		else if (A == A->parent->Lchild)
			A->parent->Lchild = B;
		else
			A->parent->Rchild = B;
		B->parent = A->parent;
	}

	void fix_insert(Node_ptr currentNode) {
		while (currentNode->parent->color == RED)
		{
			if (currentNode->parent == currentNode->parent->parent->Rchild)
			{
				Node_ptr uncle = currentNode->parent->parent->Lchild;
				if (uncle->color == RED)
				{
					uncle->color = BLACK;
					currentNode->parent->color = BLACK;
					currentNode->parent->parent->color = RED;
					currentNode = currentNode->parent->parent;
				}
				else
				{
					if (currentNode == currentNode->parent->Lchild)
					{
						currentNode = currentNode->parent;
						rotate_right(currentNode);
					}
					else
					{
						currentNode->parent->color = BLACK;
						currentNode->parent->parent->color = RED;
						rotate_left(currentNode->parent->parent);
					}
				}
			}
			else
			{
				Node_ptr uncle = currentNode->parent->parent->Rchild;
				if (uncle->color == RED)
				{
					uncle->color = BLACK;
					currentNode->parent->color = BLACK;
					currentNode->parent->parent->color = RED;
					currentNode = currentNode->parent->parent;
				}
				else
				{
					if (currentNode == currentNode->parent->Rchild)
					{
						currentNode = currentNode->parent;
						rotate_left(currentNode);
					}
					else
					{
						currentNode->parent->color = BLACK;
						currentNode->parent->parent->color = RED;
						rotate_right(currentNode->parent->parent);
					}
				}
			}
			if (currentNode == _root)
				break ;
		}
		_root->color = BLACK;
	}

	void	rotate_right(Node_ptr x) {
		Node_ptr y = x->Lchild;
		x->Lchild = y->Rchild;
		if (y->Rchild != _leaf) 
			y->Rchild->parent = x;
		y->parent = x->parent;
		if (!x->parent)
			_root = y;
		else if (x == x->parent->Rchild)
			x->parent->Rchild = y;
		else
			x->parent->Lchild = y;
		y->Rchild = x;
		x->parent = y;
	}

	void	rotate_left(Node_ptr x) {
		Node_ptr y = x->Rchild;
		x->Rchild = y->Lchild;
		if (y->Lchild != _leaf)
			y->Lchild->parent = x;
		y->parent = x->parent;
		if (!x->parent)
			_root = y;
		else if (x == x->parent->Lchild)
			x->parent->Lchild = y;
		else
			x->parent->Rchild = y;
		y->Lchild = x;
		x->parent = y;
	}

	void fix_delete(Node_ptr A) {
		Node_ptr tmp = nullptr;
		while (A != _root && A->color == BLACK)
		{
			if (A == A->parent->Lchild) {
				tmp = A->parent->Rchild;
				if (tmp->color == RED) {
					tmp->color = BLACK;
					A->parent->color = RED;
					rotate_left(A->parent);
					tmp = A->parent->Rchild;
				}
				if (tmp->Lchild->color == BLACK && tmp->Rchild->color == BLACK) {
					tmp->color = RED;
					A = A->parent;
				}
				else 
				{
					if (tmp->Rchild->color == BLACK) {
						tmp->Lchild->color = BLACK;
						tmp->color = RED;
						rotate_right(tmp);
						tmp = A->parent->Rchild;
					}
					tmp->color = A->parent->color;
					A->parent->color = BLACK;
					tmp->Rchild->color = BLACK;
					rotate_left(A->parent);
					A = _root;
				}
			}
			else
			{
				tmp = A->parent->Lchild;
				if (tmp->color == RED) {
					tmp->color = BLACK;
					A->parent->color = RED;
					rotate_right(A->parent);
					tmp = A->parent->Lchild;
				}
				if (tmp->Rchild->color == BLACK && tmp->Rchild->color == BLACK) {
					tmp->color = RED;
					A = A->parent;
				}
				else {
					if (tmp->Lchild->color == BLACK)  {
						tmp->Rchild->color = BLACK;
						tmp->color = RED;
						rotate_left(tmp);
						tmp = A->parent->Lchild;
					}
					tmp->color = A->parent->color;
					A->parent->color = BLACK;
					tmp->Lchild->color = BLACK;
					rotate_right(A->parent);
					A = _root;
				}
			}
		}
		A->color = BLACK;
	}

public:

	RBT(allocator_type alloc = allocator_type()) : _size(0), _alloc(alloc) {
		_leaf			= new_node(value_type(), nullptr);
		_leaf->color 	= BLACK;
		_root			= _leaf;
	}
 
	RBT(const RBT& cpy) : _size(0) {
		_leaf			= new_node(value_type(), nullptr);
		_leaf->color 	= BLACK;
		_root			= _leaf;
		*this = cpy;
	}

	RBT& operator= (const RBT& rhs) {
		clear(_root);
		copy(rhs._root, rhs);
		_alloc	= rhs._alloc;
		return *this;
	}

	~RBT(){
		show_tree(_root);
		clear(_root);
		_alloc.destroy(_leaf);
		_alloc.deallocate(_leaf, 1);	
	}

	void clear(Node_ptr node) {

		if (node != _leaf) {
			clear(node->Lchild);
			clear(node->Rchild);
			simple_delete(node);
		}
	}

	void simple_delete(Node_ptr node) {
		if (node->parent)
		{
			if (node == node->parent->Lchild)
				node->parent->Lchild = _leaf;
			else if (node == node->parent->Rchild)
				node->parent->Rchild = _leaf;
		}
		else
			_root = _leaf;
		_alloc.destroy(node);
		_alloc.deallocate(node, 1);
		_size--;
	}

	void copy(Node_ptr node, const RBT & tree) {
		if (node != tree._leaf)
		{
			copy(node->Lchild, tree);
			copy(node->Rchild, tree);
			insert(ft::make_pair<key_type, mapped_type>(node->data.first, node->data.second));
		}
	}

	void swap(RBT & tree) {
		Node_ptr				tmp_root  = tree._root;
		size_type 				tmp_size  = tree._size;
		Node_ptr				tmp_leaf  = tree._leaf;
		key_compare				tmp_comp  = tree._comp;
		allocator_type			tmp_alloc = tree._alloc;

		tree._root  = _root;
		tree._size  = _size;
		tree._leaf  = _leaf;
		tree._comp  = _comp;
		tree._alloc = _alloc;

		_root = tmp_root;
		_size = tmp_size;
		_leaf = tmp_leaf;
		_comp = tmp_comp;
		_alloc = tmp_alloc;
	}

	Node_ptr insert(value_type val) {
	if (!_size) {
		_root = new_node(val, nullptr);
		_root->color = BLACK;
		_size++;
		return _root;
	}
	else
	{
		Node_ptr currentNode	= _root;
		Node_ptr previousNode	= _root;
		while (currentNode != _leaf)
		{
			previousNode = currentNode;
			if (val.first == currentNode->data.first)
					return currentNode;
			if  (_comp(val.first, currentNode->data.first))
				currentNode = currentNode->Lchild;
			else
				currentNode = currentNode->Rchild;
		}
		if (_comp(val.first, previousNode->data.first))
		{
			previousNode->Lchild = new_node(val, previousNode);
			currentNode = previousNode->Lchild;
		}
		else
		{
			previousNode->Rchild = new_node(val, previousNode);
			currentNode = previousNode->Rchild;
		}
		_size++;
		if (!previousNode->parent)
			return currentNode;
		fix_insert(currentNode);
		return currentNode;
	}
}

	void	delete_node(key_type key)
	{
		Node_ptr root = _root;
		Node_ptr tmp = search(root, key);
		if (tmp == _leaf)
			return ;
		Node_ptr A = tmp;
		COLOR original_color = A->color;
		Node_ptr B = nullptr;
		if (tmp->Lchild == _leaf) {
			B = tmp->Rchild;
			transplant(tmp, tmp->Rchild);
		}
		else if (tmp->Rchild == _leaf) {
			B = tmp->Lchild;
			transplant(tmp, tmp->Lchild);
		}
		else
		{
			A = min(tmp->Rchild);
			original_color = A->color;
			B = A->Rchild;
			if (A->parent == tmp)
				B->parent = A;
			else
			{
				transplant(A, A->Rchild);
				A->Rchild = tmp->Rchild;
				A->Rchild->parent = A;
			}
			transplant(tmp, A);
			A->Lchild = tmp->Lchild;
			A->Lchild->parent = A;
			A->color = tmp->color;
		}
		_alloc.destroy(tmp);
		_alloc.deallocate(tmp, 1);
		_size--;
		if (original_color == BLACK)
			fix_delete(B);
	}

	Node_ptr search(Node_ptr start, key_type key) const {
		if (key == start->data.first || start == _leaf)
			return start;
		if (key < start->data.first)
			return search(start->Lchild, key);
		else return search(start->Rchild, key);
	}

	Node_ptr min(Node_ptr start) {
		while (start->Lchild != _leaf)
			start = start->Lchild;
		return start;
	}

	Node_ptr max(Node_ptr start) {
		while (start->Rchild != _leaf)
			start = start->Rchild;
		return start;
	}

	Node_ptr successor(Node_ptr start) {
		if (start == _leaf)
			return start;
		else if (start == max(_root))
			return _leaf;
		else if (!start)
			return min(_root);
		else if (start->Rchild != _leaf)
			return min(start->Rchild);
		else
		{
			Node_ptr rval = start->parent;
			while (rval && start == rval->Rchild)
			{
				start = rval;
				rval = rval->parent;
			}
			return rval;
		}
	}

	Node_ptr successor(Node_ptr start) const {
		if (start == _leaf)
			return start;
		else if (start == max(_root))
			return _leaf;
		else if (!start)
			return min(_root);
		else if (start->Rchild != _leaf)
			return min(start->Rchild);
		else
		{
			Node_ptr rval = start->parent;
			while (rval && start == rval->Rchild)
			{
				start = rval;
				rval = rval->parent;
			}
			return rval;
		}
	}

	Node_ptr predecessor(Node_ptr start) {
		if (!start)
			return start;
		else if (start == _leaf)
			return max(_root);
		else if (start == min(_root))
			return nullptr;
		else if (start->Lchild != _leaf)
			return max(start->Lchild);
		else
		{
			Node_ptr rval = start->parent;
			while (rval && start == rval->Lchild)
			{
				start = rval;
				rval = rval->parent;
			}
			return rval;
		}
	}

	Node_ptr predecessor(Node_ptr start) const {
		if (!start)
			return start;
		if (start == _leaf)
			return max(_root);
		else if (start == min(_root))
			return nullptr;
		else if (start->Lchild != _leaf)
			return max(start->Lchild);
		else
		{
			Node_ptr rval = start->parent;
			while (rval && start == rval->Lchild)
			{
				start = rval;
				rval = rval->parent;
			}
			return rval;
		}
	}
	

	void in_order(Node_ptr start) {
			if (start != _leaf) {
			in_order(start->Lchild);
			show_Node(start);
			in_order(start->Rchild);
		}
	}

	void pre_order(Node_ptr start) {
		if (start != _leaf) {
			show_Node(start);
			pre_order(start->Lchild);
			pre_order(start->Rchild);
		}
	}

	void post_order(Node_ptr start) {
		if (start != _leaf) {		
			post_order(start->Lchild);
			post_order(start->Rchild);
			show_Node(start);
		}
	}

	bool level_order(Node_ptr start, int level) {
		if (start == _leaf)	return false;
		if (level == 1)		return true;
		bool left  = level_order(start->Lchild, level - 1);
		bool right = level_order(start->Rchild, level - 1);

		return (left || right);
	}

	void level_order_traversal(Node_ptr start) {
		int level = 1;
		while (level_order(start, level))
			level++;
	}

	Node_ptr	root() const {return _root;}
	size_t		size() const {return _size;}

	bool is_end(Node_ptr A) {
		if (A->Lchild && A->Lchild == _leaf && A->Rchild && A->Rchild == _leaf)
			return true;
		return false;
	}

	bool one_child(Node_ptr A) {
		return ((A->Lchild && A->Lchild != _leaf) + (A->Rchild && A->Rchild != _leaf)) == 1;
	}

	void show_tree(Node_ptr node) {
		if (node != _leaf)
		{
			show_Node(node);
			show_tree(node->Lchild);
			show_tree(node->Rchild);
		}
	}

	void show_Node(Node_ptr node) {
		if (node->parent && node == node->parent->Lchild)
			std::cout << "LCHILD [" << node->parent->data.first << "] ";
		else if (node->parent && node == node->parent->Rchild)
			std::cout << "RCHILD [" << node->parent->data.first << "] ";
		else
			std::cout << "ROOT   [R] ";
		std::cout << "[" << node->data.first << "][" << node->data.second << "][";
		if (node->color == BLACK)
			std::cout << "BLACK]" << std::endl;
		else
			std::cout << "RED]" << std::endl;
	}
};

}//ft