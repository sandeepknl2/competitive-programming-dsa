#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {2,2,2,1,2,2,1,2,2,2};
    int n = arr.size();
    int k = 2;
    int cnt1 = 0;

    for (int i = 0; i < n; i++) {
        int oddCount = 0;
        for (int j = i; j < n; j++) {
            if (arr[j] % 2 != 0) oddCount++;
            if (oddCount == k) cnt1++;
            else if (oddCount > k) break; // stop early
        }
    }

    cout << cnt1;
}


if we using even then

#include <bits/stdc++.h>
using namespace std;
#include<vector>

int main() {
	vector<int> arr={2,2,2,1,2,2,1,2,2,2};
	int n=arr.size();
	int k=2,cnt=0,cnt1=0;
	
	for(int i=0;i<n;i++){
	    cnt=0;
	    for(int j=i;j<n;j++){
	        if(arr[j]%2==0)
	        continue;
	        cnt++;
	        if(cnt==k){
	        cnt1+=n-j;--------------------------> must an shuld
	        }
	    }
	   
	}
	cout<<cnt1;

}

sliding window

#include <bits/stdc++.h>
using namespace std;

int countAtMostK(vector<int>& arr, int k) {
    int n = arr.size();
    int left = 0, right = 0;
    int oddCount = 0, result = 0;

    while (right < n) {
        // Add new element to window
        if (arr[right] % 2 != 0)
            oddCount++;

        // Shrink window if too many odds
        while (oddCount > k) {
            if (arr[left] % 2 != 0)
                oddCount--;
            left++;
        }

        // All subarrays ending at right with <= k odds
        result += (right - left + 1);
        right++;
    }
    return result;
}

int main() {
    vector<int> arr = {1,1,2,1,1};
    int k = 3;

    // Count subarrays with exactly k odds
    int ans = countAtMostK(arr, k) - countAtMostK(arr, k - 1);

    cout << ans;
}



map


unordered_map<int,int>mp;
        // Replace odd with 1 and even with 0
        for(auto &num:nums)
            if(num%2)
                num=1;
            else 
                num=0;
        mp[0]=1;
        int sum=0;
        int count=0;
        for(auto num:nums)
        {
            sum+=num;
            count+=mp[sum-k];
            mp[sum]++;
        }
        return count;
    