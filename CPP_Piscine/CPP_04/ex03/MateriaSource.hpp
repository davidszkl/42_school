#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
public:

	MateriaSource();
	MateriaSource(MateriaSource const & cpy);
	~MateriaSource();

	MateriaSource& operator=(MateriaSource const & rhs);
	
	void 		learnMateria(AMateria *source);
	AMateria*	createMateria(std::string const & type);
	AMateria*	getInventory(int idx) const;

protected:

	AMateria*	_inventory[4];
	int			_learned;
};

#endif