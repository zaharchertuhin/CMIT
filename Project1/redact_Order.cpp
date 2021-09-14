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
    Order st;
    int orderid;
    cout << "Введите Номер Заказа: " << endl;
    cin >> orderid;
    ofstream out;
    string data; 
    cout << "Введите описание заказа: ";
    getline(cin, st.description);
    cin >> st.description;
    cout << "Введите статус заказа: ";
    cin >> st.status;
    out.open("data.dat", ios::app);
    if (out.is_open())
    {
        for (int i = 0; i < vect.size(); i++) {
            if (data.find("id: " + to_string(orderid)) != string::npos) {
                if (data.find("True") != string::npos)cout << "Order was deleted" << endl;
                else {
                    out << 
                        "discription: " << st.description << "\n" <<
                        "status: " << st.status << "\n" << "delete_status: False" << "\n";
                    out << "*" << endl;
                    out.close();
                }
                out.close(); //закрыли  файл
            }
        }
    }
    else {
        cout << "The order was not found. Please try again.\n";
    }

    /*for (auto x : vect) {
        if (x.id == orderid) {
            cout << "Введите описание заказа: ";
            getline(cin, vect[orderid - 1].description);
            cin >> vect[orderid - 1].description;
            cout << "Введите статус заказа: ";
            cin >> vect[orderid - 1].status;
            cout << "Заказ изменен." << endl;
            system("pause");
            return;
        }
    }*/

    system("pause");
}