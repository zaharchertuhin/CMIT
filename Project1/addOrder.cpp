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

void orderAdd(vector<Order>& vect) {
    system("cls");
    Order neworder;
    neworder.id = vect.size() + 1;
    neworder.delete_status = false;
    cout << "¬ведите описание заказа: ";
    getline(cin, neworder.description);
    cin >> neworder.description;
    cout << "¬ведите статус заказа: ";
    cin >> neworder.status;
    vect.push_back(neworder);
    ofstream out;
    out.open("data.dat", ios::app);
    if (out.is_open())
    {
        out << "id: " << neworder.id << "\n" <<
            "discription: " << neworder.description << "\n" <<
            "status: " << neworder.status << "\n";
            if (neworder.delete_status == false) out << "delete_status: False" << "\n";
            out << "*" << endl;
            out.close();
    }

}