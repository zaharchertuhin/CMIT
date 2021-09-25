#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Order_Header.h"

using namespace std;

struct Order;

void orderAdd(vector<Order>& vect);

void orderPrintAll(vector<Order>& vect);

void orderFind(vector<Order>& vect);

void redact_Order(vector<Order>& vect);

void deletorder(vector<Order>& vect);

void load_order(vector<Order>& vect);

int main() {
    system("chcp 1251"); // for Clion use "chcp 65001"
    int a;
    vector<Order> orders;
    bool key = true;
    while (key) {
        system("cls");

        cout << "Заказы:\n" <<
            "\t1) Добавить заказ.\n" <<
            "\t2) Показать заказы.\n" <<
            "\t3) Найти заказ.\n" <<
            "\t4) Редактировать заказ\n" <<
            "\t5) Удалить заказ.\n" <<
            "\t6) Выгрузить заказы\n" <<
            "\t7) Выход\n";
        cin >> a;

        switch (a) {
        case 1: {
            orderAdd(orders);
            break;
        }
        case 2: {
            orderPrintAll(orders);
            break;
        }
        case 3: {
            orderFind(orders);
            break;
        }

        case 4: {
            redact_Order(orders);
            break;
        }

        case 5: {
            deletorder(orders);
            break;
        }
        case 6: {
            load_order(orders);
            break;
        }

        case 7: {
            key = false;
            break;
        }

        default: {
            cout << "Месье, вы дэбил, давайте по-новой." << endl;
            return 0;
        }
        };
    }
}