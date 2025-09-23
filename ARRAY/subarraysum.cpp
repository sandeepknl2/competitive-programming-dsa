#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1,2,3};
    int n = arr.size();
    int sum = 0;

    // Loop over all possible subarrays
    for (int i = 0; i < n; i++) {       // start index
        for (int j = i; j < n; j++) {   // end index
            // sum elements from i to j
            for (int k = i; k <= j; k++) {
                sum += arr[k];
            }
        }
    }

    cout << sum << endl;  // Output: 20
    return 0;
}


opyimized

int n = arr.size();
    int sum = 0;
    
    for(int i = 0; i < n; i++) {
        sum += arr[i] * (i + 1) * (n - i);
    }
    
    return sum;
}