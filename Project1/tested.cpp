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


void printTxt(vector<Order>& vect) {
    ifstream file("data.dat");
    char c = '%';

    for (int i = 0; i <= 493; ++i)
    { 
        char data[1000];
        file >> data[i];
        if (data[i] == c)break;

        cout << data[i];
    }
}