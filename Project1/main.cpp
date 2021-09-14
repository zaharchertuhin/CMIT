#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct Order {
    int id;
    string description;
    string status;
    bool delete_status;
};


//void ShowOrderList(vector<Order>& x) {
//    cout << "ID: " << x.id << endl;
//    cout << "Описание: " << x.description << endl;
//    cout << "Cтатус: " << x.status << endl;
//    cout << endl;
//    system("pause");
//}

void orderAdd(vector<Order>& vect);

void orderPrintAll(const vector<Order>& vect);

void orderFind(const vector<Order>& vect);

void redact_Order(vector<Order>& vect);

void deletorder(vector<Order>& vect);


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

        case 7: {
            key = false;
            break;
        }

        default: {
            cout << "Месье, вы дэбил, давайте по-новой." << endl;
            system("pause");
        }
        };
    }
}