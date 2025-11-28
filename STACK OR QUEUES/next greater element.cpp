#include <bits/stdc++.h>
using namespace std;

int main() {
vector<int> arr={6, 8, 0, 1, 3};
vector<int> res;
int n= arr.size();

for(int i=0;i<n;i++){
    int maxi=arr[i];
    for(int j=i;j<n;j++){
        if(arr[j]>maxi){
    
        maxi=max(maxi,arr[j]);
            break;
        }
        if(j==n-1)
        maxi=-1;
    }
    res.push_back(maxi);
}

for(int i=0;i<res.size();i++){
    cout<<res[i]<<" ";
}

}


optimized

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {6, 8, 0, 1, 3};
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        // Pop all smaller or equal elements
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        // If stack not empty, top is next greater
        if (!st.empty()) {
            res[i] = st.top();
        }

        // Push current element
        st.push(arr[i]);
    }

    // Print result
    for (int x : res) cout << x << " ";
}
