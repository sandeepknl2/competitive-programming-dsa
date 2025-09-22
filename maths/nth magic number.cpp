#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 4, a = 2, b = 3;
    vector<int> arr;

    // Generate enough numbers
    for(int i = 1; arr.size() < n; i++) { // stop when we have n numbers
        if(i % a == 0 || i % b == 0)
            arr.push_back(i);
    }

    cout << arr[n-1] << endl; // n-th magical number

    return 0;
}


opyimzws