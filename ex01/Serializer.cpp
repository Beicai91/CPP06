#include "Serializer.hpp"
//constructors, destructor and operator
Serializer::Serializer(){}
Serializer::Serializer(const Serializer &other){(void)other;}
Serializer  &Serializer::operator=(const Serializer &other)
{
    (void)other;
    return (*this);
}
Serializer::~Serializer(){}

//other funcs
uintptr_t   Serializer::serialize(Data *ptr)
{
    uintptr_t   addr = reinterpret_cast<uintptr_t>(ptr);
    return (addr);
}

Data    *Serializer::deserialize(uintptr_t raw)
{
    Data    *ptr = reinterpret_cast<Data *>(raw);
    return (ptr);
}