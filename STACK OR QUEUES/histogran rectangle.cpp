#include <bits/stdc++.h>
using namespace std;

int main() {

        vector<int> arr={2,1,5,6,2,3};
        int n=arr.size();
        
       
        
        int area=0;
        int maxarea=0;
        
        for(int i=0;i<n;i++){
            int h=arr[i];
              int rectanagle = 1; //missed this
            for(int j=i+1;j<n;j++){
                if(arr[j]>=h){
                rectanagle++;
                }
                else break;
            }
            
            for(int k=i-1;k>=0;k--){  // missed i-1
                if(arr[k]>=h)
                rectanagle++;
                else break;
            }
            area=rectanagle*h;
            maxarea=max(maxarea,area);
            
        }
        
        cout<<maxarea;

}

optimized

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int n = heights.size();
    stack<int> st;
    int maxArea = 0;

    for (int i = 0; i <= n; i++) {
        int currHeight = (i == n) ? 0 : heights[i];

        // Pop until current bar is higher
        while (!st.empty() && currHeight < heights[st.top()]) {
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            int area = height * width;
            maxArea = max(maxArea, area);
        }

        st.push(i);
    }

    cout << maxArea;
    return 0;
}

