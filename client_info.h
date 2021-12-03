#ifndef CLIENT_INFO_H
#define CLIENT_INFO_H
#include <iostream>
#include <map>

class Adress
{
public:
    ~Adress() = default;
    Adress(std::string UID, std::string city, std::string street, std::string house_num)
        : _UID(UID), _city(city), _street(street), _house_num(house_num){}
    std::string _UID;
    std::string _city;
    std::string _street;
    std::string _house_num;
};

class Client
{
public:
    ~Client() = default;
    Client(std::string ID, std::string fio, std::map<int, const Adress &> adresses)
        : _ID(ID), _fio(fio), _adresses(adresses){}
    std::string _ID;
    std::string _fio;
    std::map<int, const Adress &> _adresses;
};
#endif // CLIENT_INFO_H
