#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <stdint.h>

typedef struct s_data
{
	std::string data;
} Data;

uintptr_t	serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data		*deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}
#endif