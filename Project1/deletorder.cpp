#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Order {
    int id;
    string description;
    string status;
    bool delete_status;
};

void deletorder(vector<Order>& vect) {
    system("cls");
    Order st;
    int orderid;
    cout << "Введите Номер Заказа: " << endl;
    cin >> orderid;
    for (auto x : vect) {
        if (x.id == orderid) {
            vect[orderid - 1].delete_status = true;
            cout << "Заказ удален." << endl;
            system("pause");
            return;
        }
    }
    cout << "The order was not found. Please try again.\n";
    system("pause");
}