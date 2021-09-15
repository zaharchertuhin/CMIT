#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

struct Order {
    int id;
    string description;
    string status;
    bool delete_status;
};

void deletorder(vector<Order>& vect) {
    system("cls");
    int orderid;
    cout << "Введите Номер Заказа: " << endl;
    cin >> orderid;
    ofstream out;
    out.open("data.dat");
    out << "";
    out.close();
    for (int i = 1; i <= vect.size(); i++) {
        for (auto x : vect) {
            if (i == orderid) {
                vect[orderid - 1].delete_status = true;
                cout << "ok" << endl;
                break;
            }
        }
        out.open("data.dat", ios::app);
        if (out.is_open())
        {
            out << "id: " << vect[i - 1].id << "\n" << "discription: " << vect[i - 1].description << "\n" << "status: " << vect[i - 1].status << "\n";
            if (vect[i - 1].delete_status == false) out << "delete_status: False" << "\n";
            else out << "delete_status: True" << "\n";
            out << "*" << endl;
            out.close();
            

        }
        else {
            cout << "The order was not found. Please try again.\n";
        }
    }
    system("pause");
}