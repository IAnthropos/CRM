#ifndef ORDER_H
#define ORDER_H
#include "product.h"
#include "sources.h"
#include "client_info.h"
#include <vector>

class OrderPos
{
public:
    ~OrderPos() = default;
    OrderPos(const Product & product, int contity)
        : _product(product), _contity(contity){}
    const Product & _product;
    int _contity;
};

class Order
{
public:
    ~Order() = default;
    Order(Status order_status, std::vector<OrderPos> order_positions, const Client & client, int choosen_adress)
        : _order_status(order_status),
          _order_positions(order_positions),
          _client(client),
          _choosen_adress(choosen_adress){}
    Status _order_status;
    std::vector<OrderPos> _order_positions;
    const Client & _client;
    int _choosen_adress;

    std::string getAdress() const
    {
        const auto adr = _client._adresses.find(_choosen_adress)->second;
        return "Клиент: " + _client._fio + ". Адрес: " + adr._city + ", " + adr._street + ", " + adr._house_num;
    }

};


#endif // ORDER_H
