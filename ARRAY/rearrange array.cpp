// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;
int main() {
    vector<int> arr={10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110,2};
//Output: [110, 10, 100, 20, 90, 30, 80, 40, 70, 50, 60};
    int n=arr.size();
    vector<int> ar;
    // int s=n;
    // for(int i=0;i<n;i++){
    //     ar.push_back(arr[s-1]);
    //       ar.push_back(arr[i]);
    //       s--;
          
        
    // }
    int i=0,j=n-1;
    while (i <= j) {
        if (i != j) {
            ar.push_back(arr[j--]); // max
            ar.push_back(arr[i++]); // min
        } else {
            ar.push_back(arr[i]);   // middle element if odd
            break;
        }
    }
     for(int i=0;i<n;i++){
         cout<<ar[i]<<" ";
     }

    
    

    return 0;
}

class Solution {
  public:
    void rearrange(vector<int>& arr) {
       int n = arr.size();
        if (n <= 1) return;

        // Sort first because input may be unsorted
        sort(arr.begin(), arr.end());             // O(n log n)

        long long maxElem = (long long)arr.back() + 1;  // > every element
        int minIdx = 0, maxIdx = n - 1;

        // Encode both values into arr[i]
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                arr[i] += (arr[maxIdx] % maxElem) * maxElem;
                --maxIdx;
            } else {
                arr[i] += (arr[minIdx] % maxElem) * maxElem;
                ++minIdx;
            }
        }

        
                for (int i = 0; i < n; i++) {
            arr[i] = arr[i] / maxElem;
        }
    }
    
    
};