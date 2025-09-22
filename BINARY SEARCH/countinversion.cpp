#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n = 5;
    vector<int> ans = {0,1,2,3,4};
    int count = 0;

    for(int i = 0; i < n; i++) {
    for(int j=i+1;j<n;j++){
        if(i<j && ans[i]>ans[j])
        count++;
    }
        
        
    }
    cout<<count;

   
}
