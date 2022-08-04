#ifndef CURE_HPP
# define CURE_HPP
# include "AMateria.hpp"

class Cure : public AMateria
{
public:

	Cure();
	Cure(Cure const& cpy);
	~Cure();

	Cure& operator=(Cure const & rhs);

	virtual	AMateria*	clone() const;
	virtual void		use(ICharacter & target);
	std::string			getType() const;
};

#endif