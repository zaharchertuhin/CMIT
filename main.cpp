#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector <int> nums;
   for (int i = 0; i<100; i++){
        nums[i]=10-i;
   }
   for (int i = 0; i< 100; i++){
       if (nums[i]>1){
           cout << nums[i] << " ";
       }
   }
}
