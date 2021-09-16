#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Order_Header.h"

using namespace std;

struct Order;

void orderPrintAll(const vector<Order>& vect) {
    system("cls");
    cout << vect.size() << "\n";
    ifstream in;
    string data;
    in.open("data.dat", ios::app);
    if (in.is_open())
    {
        for (int i = 0; i < vect.size(); i++) {
            getline(in, data, '*');
            if (data.find("True") != string::npos)cout << "";
            else {
                cout << data << endl;
            }
        }
        in.close(); //закрыли  файл

    }
    else {
        cout << "The order was not found. Please try again.\n";
    }


    system("pause");
}

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