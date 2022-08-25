#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <iostream>

typedef struct Data
{
	int coucou;
}	lol;

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif