#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {3,2,3};
    vector<int> ne;
    vector<int> freq(256,0);

    int n = arr.size();
    int s = n/3;   
    for(int i=0; i<n; i++){
        freq[arr[i]]++;  
    }
    for(int i=0; i<n; i++){
        if(freq[arr[i]] > s){
            ne.push_back(arr[i]);  
            freq[arr[i]] = 0;       
        }
    }
    for(int x : ne){
        cout << x << " ";
    }

    return 0;
}


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
           int n = nums.size();
        int cand1 = 0, cand2 = 0;
        int count1 = 0, count2 = 0;
        for (int num : nums) {
            if (num == cand1) count1++;
            else if (num == cand2) count2++;
            else if (count1 == 0) {
                cand1 = num;
                count1 = 1;
            }
            else if (count2 == 0) {
                cand2 = num;
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }
        count1 = count2 = 0;
        for (int num : nums) {
            if (num == cand1) count1++;
            else if (num == cand2) count2++;
        }
        vector<int> ans;
        if (count1 > n/3) ans.push_back(cand1);
        if (count2 > n/3) ans.push_back(cand2);
        
        return ans;
    
    }
};