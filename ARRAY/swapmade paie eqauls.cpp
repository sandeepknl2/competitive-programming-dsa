#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a = {3,3};
    vector<int> b = {3, 6, 3, 3};

    int n = a.size();
    int m = b.size();

    int sumA = 0, sumB = 0;
    for(int i = 0; i < n; i++) sumA += a[i];
    for(int i = 0; i < m; i++) sumB += b[i];

    bool found = false;

    // Try swapping each element of a with each element of b
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int newSumA = sumA - a[i] + b[j];
            int newSumB = sumB - b[j] + a[i];

            if(newSumA == newSumB) {
                cout << "Swap a[" << i << "] = " << a[i] 
                     << " with b[" << j << "] = " << b[j] << endl;
                found = true;
                break;  // stop after first valid swap
            }
        }
        if(found) break;
    }

    if(!found) cout << "No possible swap" << endl;

    return 0;
}


oprtimized

 long long sumA = 0, sumB = 0;
        for (int x : a) sumA += x;
        for (int x : b) sumB += x;

        long long diff = sumA - sumB;

        // If difference is odd, no integer swap possible
        if (diff % 2 != 0) return false;

        long long target = diff / 2;

        // Store all elements of b in a set for fast lookup
        unordered_set<int> setB(b.begin(), b.end());

        for (int x : a) {
            if (setB.count(x - target)) {
                return true;  // Found a valid swap
            }
        }

        return false; // No valid 

sumA - sumB = 2 * (a[i] - b[j]) 

sumA - sumB = 2 * (a[i] - b[j])
Divide both sides by 2:

Copy code
a[i] - b[j] = (sumA - sumB) / 2
✅ This value (sumA - sumB)/2 is exactly what target stores.