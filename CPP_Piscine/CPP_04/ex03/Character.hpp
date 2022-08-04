#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"

class Character : public ICharacter
{
public:

	Character();
	Character(std::string name);
	Character(Character const & cpy);
	~Character();

	Character& operator=(Character const & rhs);

	virtual std::string const & getName() const;
	virtual void				equip(AMateria *materia);
	virtual void				unequip(int idx);
	virtual void				use(int idx, ICharacter& target);
	virtual int					getEquip();

protected:

	std::string	_name;
	AMateria*	_inventory[4];
	int			_equipped;
};

#endif