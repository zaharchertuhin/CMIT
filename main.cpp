#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Order {
    int id;
    string description;
    string status;
    bool delete_status;
    void print() {
        cout << "\n" << "ID: " << id <<
             "\nОписание заказа:  " << description <<
             "\nСтатус: " << status << "\n" <<
             delete_status << endl;
    }
};

void orderAdd(vector<Order>& vect) {
    system("cls");
    Order neworder;
    neworder.id = vect.size() + 1;
    neworder.delete_status = false;
    cout << "Введите описание заказа: ";
    std::getline(std::cin, neworder.description);
    cin >> neworder.description;
    cout << "Введите статус заказа: ";
    cin >> neworder.status;
    vect.push_back(neworder);
}

void orderPrintAll(const vector<Order>& vect) {
    system("cls");
    for (auto x : vect) {
        if (x.delete_status == false) {
            x.print();
            cout << "\n";
        }
    }
    system("pause");
}

void orderFind(const vector<Order>& vect) {
    system("cls");
    int orderid;
    cout << "Введите Номер Заказа"<< endl;
    cin >> orderid;
    for (auto x : vect) {
        if (x.id == orderid) {
            if (x.delete_status == false) {
                x.print();
                system("pause");
                return;
            }
        }
    }
    cout << "The order was not found. Please try again.\n";
    system("pause");
}

void deletorder(vector<Order>& vect) {
    system("cls");
    Order st;
    int orderid;
    cout << "Введите Номер Заказа: "<< endl;
    cin >> orderid;
    for (auto x : vect) {
        if (x.id == orderid) {
            vect[orderid -1].delete_status = true;
            cout << "Заказ удален."<< endl;
            system("pause");
            return ;
        }
    }
    cout << "The order was not found. Please try again.\n";
    system("pause");
}

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
             "\t4) Удалить заказ.\n" <<
             "\t5) Выход\n";
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
                deletorder(orders);
                break;
            }

            case 5: {
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
