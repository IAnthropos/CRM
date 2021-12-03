#include "crm.h"
#include "order.h"
#include <iostream>

using namespace std;
void CRM::makeReport()
{
    Adress adress1("A1","Москва","ул.Пушкина","д.2");
    Adress adress2("A2","Москва","ул.Шверника","д.33");
    Adress adress3("A3","Москва","Ломоносовский проспект","д.1");
    Adress adress4("A3","Москва","ул. Первого мая","д.14");

    Client client1("C1", "Иванов Иван Иванович", map<int, const Adress &>{{1, adress1}});
    Client client2("C2", "Сергиенко Сергей Сергеевич", map<int, const Adress &>{{1, adress2}});
    Client client3("C4", "Сергиенко Лидия Викторовна", map<int, const Adress &>{{1, adress2}});
    Client client4("C4", "Карпов Карп Карпович", map<int, const Adress &>{{1, adress3}, {2, adress4}});

    Product boot_blue("P1","Ботинки синие, р. 42");
    Product boot_gray("P2","Ботинки серые, р. 42");
    Product gloves("P3","Перчатки, б/р");
    Product mask("P4","Маска \"Подчеркивает глаза\"");

    vector<Order> orders
    {
        Order(create, vector<OrderPos>{OrderPos(boot_blue, 10)}, client1, 1),
        Order(delivered, vector<OrderPos>{OrderPos(boot_gray, 1)}, client2, 1),
        Order(payed, vector<OrderPos>{OrderPos(mask, 10)}, client2, 1),
        Order(payed, vector<OrderPos>{OrderPos(gloves, 2)}, client3, 1),
        Order(payed, vector<OrderPos>{OrderPos(mask, 100), OrderPos(gloves, 3)}, client4, 2)
    };

    for(const auto & order: orders)
    {
        if(order._order_status == payed)
        {
            cout << order.getAdress() << endl;
        }
    }
};
