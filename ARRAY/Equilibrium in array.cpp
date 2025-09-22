Equilibrium in array.cpp

class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        int n = arr.size();
    long long totalSum = 0, leftSum = 0;

  
    for (int x : arr) totalSum += x;

    
    for (int i = 0; i < n; i++) {
        totalSum -= arr[i];
        if (leftSum == totalSum) return i; 
        leftSum += arr[i];
    }
    return -1;

        
    }
};
