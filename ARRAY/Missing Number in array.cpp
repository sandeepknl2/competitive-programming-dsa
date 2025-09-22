miising

class Solution {
  public:
    int missingNum(vector<int>& arr) {
  int n = arr.size();
        long long totalSum = 0;

        for (int x : arr) totalSum += x;

        long long expectedSum = (1LL * (n+1) * (n+2)) / 2;  // formula sum(1..n+1)

        return expectedSum - totalSum;
    }
};