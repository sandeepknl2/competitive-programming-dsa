#include <bits/stdc++.h>
using namespace std;
#include<vector>

int main() {
            vector<int> arr={1,1,1,0,0,0,1,1,1,1,0};
            int n=arr.size();
            int k=2;
            int maxL=0;
            
            for(int i=0;i<n;i++){
                int len=0;
                int usedK=0;
                for(int j=i;j<n;j++){
                     if(arr[j] == 0) {
                     if(usedK < k)
                    usedK++; 
                else
                    break; 
                     }
                len++;
                }
            
            maxL=max(maxL,len);
            }
            cout<<maxL;
}

optimized


int left = 0, usedK = 0, maxLen = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) usedK++;

            while (usedK > k) {
                if (nums[left] == 0) usedK--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;