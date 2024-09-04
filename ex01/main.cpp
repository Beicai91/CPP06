#include "Serializer.hpp"
#include <iostream>

int main(void)
{
    Data    *data = new Data;
    data->d = 42;
    std::cout << "Data *: " << data << std::endl;
    uintptr_t   res = Serializer::serialize(data);
    std::cout << "uintptr_t: " << res << std::endl;
    Data    *origin = Serializer::deserialize(res);
    std::cout << "deserialized to Data *: " << origin << std::endl;
    delete data;
    return (0);
}