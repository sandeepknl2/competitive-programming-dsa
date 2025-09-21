class Solution {
  public:
    void segregateEvenOdd(vector<int>& arr) {
   vector<int> even, odd;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] % 2 == 0) even.push_back(arr[i]);
            else odd.push_back(arr[i]);
        }
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());
        int index = 0;
        for(int x : even) arr[index++] = x;
        for(int x : odd) arr[index++] = x;
    }
};

