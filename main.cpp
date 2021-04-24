#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums(10);
    for (int i = 0; i < 10; i++) {
        nums[i] = 10 - i;
    }
    for (int i = 0; i < 10; i++) {
        if (nums[i] > 2) {
            cout << nums[i] << " ";
        }
    }
}
