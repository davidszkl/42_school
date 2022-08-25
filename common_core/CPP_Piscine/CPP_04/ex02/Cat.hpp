#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
public:

	Cat();
	Cat(Cat const & cpy);
	~Cat();

	Cat &operator=(Cat const & rhs);

	virtual void makeSound() const;
	Brain	*getBrain() const;

private:

	Brain *_Brain;
};

#endif