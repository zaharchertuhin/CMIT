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

void redact_Order(vector<Order>& vect) {
    system("cls");
    int orderid;
    cout << "Введите Номер Заказа: " << endl;
    cin >> orderid;
    ofstream out;
    string data, description, status;
    out.open("data.dat");
    out << "";
    out.close();
    cout << "Введите описание заказа: ";
    cin >> description;
    getline(cin, description, '.');
    cout << "Введите статус заказа: ";
    getline(cin, status, '.');
    for (int i = 1; i <= vect.size(); i++) {
        for (auto x : vect) {
            if (i == orderid) {
                vect[orderid - 1].description = description;
                vect[orderid - 1].status = status;
                cout << "ok" << endl;
                break;
            }
        }
        out.open("data.dat", ios::app);
        if (out.is_open())
        {
            out << "id: " << vect[i - 1].id << "\n" << "discription: " << vect[i - 1].description << "\n" << "status: " << vect[i - 1].status << "\n";
            if (vect[i - 1].delete_status == false) out << "delete_status: False" << "\n";
            out << "*" << endl;
            out.close();
            cout << "Save...";

        } else {
        cout << "The order was not found. Please try again.\n";
        }
    }
   
    
    /*system("pause");*/
}