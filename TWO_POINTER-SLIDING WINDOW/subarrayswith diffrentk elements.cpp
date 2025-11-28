#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 1, 2, 3};
    int n = arr.size(), k = 2;
    int count = 0;

    for (int i = 0; i < n; i++) {
        unordered_set<int> sset;
        for (int j = i; j < n; j++) {
            sset.insert(arr[j]);
            if (sset.size() == k)
                count++;
            else if (sset.size() > k)
                break; // no need to check further in this subarray
        }
    }

    cout << count << endl; // Output: 7
}


using function

#include <bits/stdc++.h>
using namespace std;

bool hasExactlyKDistinct(vector<int>& arr, int s, int e, int k) {
    unordered_set<int> sset; // store distinct elements
    for (int i = s; i <= e; i++) {
        sset.insert(arr[i]);
    }
    return sset.size() == k; // exactly k distinct elements
}

int main() {
    vector<int> arr = {1, 2, 1, 2, 3};
    int n = arr.size(), k = 2;
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) { // subarray from i to j
            if (hasExactlyKDistinct(arr, i, j, k))
                count++;
        }
    }

    cout << count << endl; // should output 7
    return 0;
}

optimized using slidimg omdkow

#include <bits/stdc++.h>
using namespace std;

int atMostKDistinct(vector<int>& nums, int k) {
    unordered_map<int,int> freq;  // counts for numbers in current window
    int left = 0;
    int count = 0;

    for (int right = 0; right < nums.size(); right++) {
        // Add current number to window
        freq[nums[right]]++;

        // If new number made distincts > k, shrink window from left
        while (freq.size() > k) {       // here size() counts distinct numbers
            freq[nums[left]]--;         // remove nums[left] from window
            if (freq[nums[left]] == 0) // fully removed a distinct number
                freq.erase(nums[left]); 
            left++;                     // move window
        }

        // Count all subarrays ending at 'right'
        count += right - left + 1;
    }

    return count;
}

int main() {
    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;
    cout << "Subarrays with at most k distinct: " << atMostKDistinct(nums, k) << endl;
}
