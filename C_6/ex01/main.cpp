#include "Serializer.hpp"
#include <ios>



int main()
{
    Data *data = new Data;
    data->value = 12;
    
    std::cout << std::boolalpha << (data == Serializer::deserialize(Serializer::serialize(data)));
    
}