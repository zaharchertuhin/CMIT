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

void orderFind(const vector<Order>& vect) {
    system("cls");
    int orderid;
    cout << "Введите Номер Заказа" << endl;
    cin >> orderid;
    ifstream in;
    string data;
    in.open("data.dat", ios::app);
    if (in.is_open())
    {
        for (int i = 0; i < vect.size();i++) {
            getline(in, data, '*');
            if (data.find("id: " + to_string(orderid)) != string::npos) {
                if (data.find("True") != string::npos)cout<< "Order was deleted"<< endl;
                else {
                    cout << data << endl;
                }
                in.close(); //закрыли  файл
            }
        }                
    }
    else{ 
        cout << "The order was not found. Please try again.\n"; 
    }
    system("pause");
}