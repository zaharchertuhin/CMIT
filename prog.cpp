//
// Created by Admin on 16.05.2021.
//

#include <iostream>
#include <map>
#include <fstream>
#include <random>
using namespace std;

int Select_map(map<int, int>& m){
    int sr = 0;
    for(int i = 1; i < 32; i++ ){
        int temperature = rand() % 18;
        cout << temperature << endl;
        m[i]= temperature;
        sr+=temperature;
    }
    sr /= 31;
//    cout << sr;
    ofstream file ("C:\\Users\\Admin\\Desktop\\date.txt", ios::trunc);
    for(int i = 1; i < 32; i++ ) {
        if (m[i] > sr) {
            file << "day " << i <<": "<< m[i]-sr<< endl;
        }
    }
}

int main() {
    map<int, int> temp_day;
    Select_map(temp_day);
}