#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
class Product
{
public:
    ~Product() = default;
    Product(std::string UID, std::string name)
        : _UID(UID), _name(name){}
    std::string _UID;
    std::string _name;
};
#endif // PRODUCT_H
