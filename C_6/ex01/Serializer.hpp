#include <stdint.h>
#ifndef SERIALIZER_HPP

#include <iostream>
struct Data {
    int value;
};

class Serializer {
private:
    Serializer();
    ~Serializer();
    Serializer(const Serializer& other);
    Serializer& operator=(const Serializer& other);
public :
    static uintptr_t serialize(Data* ptr);
    static Data *deserialize(uintptr_t ptr);
};

#endif