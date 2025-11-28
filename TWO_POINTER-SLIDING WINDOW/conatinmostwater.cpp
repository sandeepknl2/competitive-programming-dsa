#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1,8,6,2,5,4,8,3,7};
    int n = arr.size();
    int maxA = 0;  // to store maximum area

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int minh = min(arr[i], arr[j]);
            int area = minh * (j - i);
            maxA = max(maxA, area);
        }
    }

    cout << maxA;
}

optimized
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1,8,6,2,5,4,8,3,7};
    int n = arr.size();
    int maxA = 0;
    
    int left = 0, right = n - 1;

    while (left < right) {
        int height = min(arr[left], arr[right]);  // choose smaller height
        int width = right - left;                 // distance between them
        int area = height * width;                // calculate area

        maxA = max(maxA, area);                   // update max

        // Move pointer of smaller height
        if (arr[left] < arr[right]) {
            left++;
        } else {
            right--;
        }
    }

    cout << maxA;
}
