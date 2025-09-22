#include <iostream>
#include <vector>
using namespace std;

vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, 0);

    // For each element, count smaller numbers to its right
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = i + 1; j < n; j++) {
            if (nums[j] < nums[i]) {
                count++;
            }
        }
        result[i] = count;
    }

    return result;
}

int main() {
    vector<int> nums = {5, 2, 6, 1};
    vector<int> ans = countSmaller(nums);

    cout << "[ ";
    for (int x : ans) cout << x << " ";
    cout << "]";
    return 0;
}


class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(n, 0); // store final answer

        // pair each number with its index
        vector<pair<int,int>> arr;
        for (int i = 0; i < n; i++)
            arr.push_back({nums[i], i});

        mergeSort(arr, 0, n - 1, counts);
        return counts;
    }

private:
    void mergeSort(vector<pair<int,int>>& arr, int left, int right, vector<int>& counts) {
        if (left >= right) return;
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, counts);
        mergeSort(arr, mid + 1, right, counts);

        merge(arr, left, mid, right, counts);
    }

    void merge(vector<pair<int,int>>& arr, int left, int mid, int right, vector<int>& counts) {
        vector<pair<int,int>> temp;
        int i = left, j = mid + 1;
        int rightCount = 0; // number of smaller elements from right side

        while (i <= mid && j <= right) {
            if (arr[j].first < arr[i].first) {
                rightCount++;       // arr[j] is smaller than arr[i]
                temp.push_back(arr[j]);
                j++;
            } else {
                counts[arr[i].second] += rightCount; // add all smaller elements from right
                temp.push_back(arr[i]);
                i++;
            }
        }

        // add remaining left elements
        while (i <= mid) {
            counts[arr[i].second] += rightCount;
            temp.push_back(arr[i]);
            i++;
        }

        // add remaining right elements
        while (j <= right) {
            temp.push_back(arr[j]);
            j++;
        }

        // copy back to original array
        for (int k = left; k <= right; k++)
            arr[k] = temp[k - left];
    }
};