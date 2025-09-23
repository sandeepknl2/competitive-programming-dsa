void rotate(vector<int>& arr, int n) {
    int s = arr.size();
    int last = arr[s-1];

    for(int j = s-1; j > 0; j--) {
        arr[j] = arr[j-1];
    }
    arr[0] = last;
}
int main() {
    vector<int> arr = {1,2,3,4,5,6,7};
    int n = arr.size();
    int k = 3;

    for (int i = 0; i < k; i++) {
         rotate(arr,n);
    }

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}


optimized

 void reverseArr(vector<int>& nums, int l, int r) {
        while (l < r) {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;   // handle if k > n

        // Step 1: reverse all
        reverseArr(nums, 0, n - 1);

        // Step 2: reverse first k
        reverseArr(nums, 0, k - 1);

        // Step 3: reverse rest
        reverseArr(nums, k, n - 1);
    }