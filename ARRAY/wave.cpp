Wave Arry
// Online C++ compiler to run C++ program online
#include<vector>
#include <iostream>
using namespace std;

int main() {
    
    vector<int> arr={1,2,3,4,5};
 
    int n=5;
       vector<int> s;
    for(int i=0;i<n;i+=2){
       if(i+1<n){
        s.push_back(arr[i+1]);
        s.push_back(arr[i]);
    }
        else{
             s.push_back(arr[i]);
        }
       
        
    }
    int w=s.size();
    for(int i=0;i<w;i++){

    cout <<s[i]<< " ";
    }

    return 0;
}

class Solution {
  public:
    void sortInWave(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i + 1 < n; i += 2) {
            swap(arr[i], arr[i + 1]);
        }
    }
};
