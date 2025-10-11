#include <bits/stdc++.h>
using namespace std;
#include<vector>
int main() {
    
    vector<int> arr={5, 3, 4, 5};
    int n=arr.size();
    int sumPlayer1=0,
    sumPlayer2=0;
    vector<bool> res(n,false);
    
    
    for(int i=0;i<n;i+=2){
        sumPlayer1+=arr[i];
        
        for(int j=i+1;j<n;j+=2){
            if(!res[j])
            sumPlayer2+=arr[j];
            res[j]=true;
            
        }
    }
    if(sumPlayer1 ==sumPlayer2 || sumPlayer1>sumPlayer2)
    cout<<"true"<<" "<<sumPlayer1;
    else
    cout<<"false"<<" "<<sumPlayer2;
    
	// your code goes here

}


recursion

class Solution {
    int rec(vector<int>& nums, int l, int r) {
        if (l == r) return nums[l];  // base case

        int leftPick = nums[l] - rec(nums, l + 1, r);
        int rightPick = nums[r] - rec(nums, l, r - 1);

        return max(leftPick, rightPick);
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        return rec(nums, 0, nums.size() - 1) >= 0;
    }
};


class Solution {
public:
    int solve(vector<int>& nums, int sum1 , int sum2, bool turn ,int i, int j ){
        if(i>j){
            if(sum1>=sum2)
                return 1;
            
            return 0;
        }
        
        if(turn){
             return solve(nums,sum1+nums[i],sum2,false,i+1,j) || solve(nums,sum1+nums[j],sum2,false,i,j-1);
        }
        
        else
           return solve(nums,sum1,sum2+nums[i],true,i+1,j) &&  solve(nums,sum1,sum2+nums[j],true,i,j-1);
        
        
    }
    

    bool PredictTheWinner(vector<int>& nums) {
        return solve(nums,0,0,true,0,nums.size()-1);
    }
};