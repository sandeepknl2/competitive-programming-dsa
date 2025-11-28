ude <vector>

using namespace std;

int celebrity(vector<vector<int>> & mat) {
    int n = mat.size();

    // indegree and outdegree array
    vector<int> indegree(n, 0), outdegree(n, 0);

    // query for all edges
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x = mat[i][j];

            // set the degrees
            outdegree[i] += x;
            indegree[j] += x;
        }
    }

    // find a person with indegree n-1
    // and out degree 0
    for (int i = 0; i < n; i++)
        if (indegree[i] == n && outdegree[i] == 1)
            return i;

    return -1;
}

int main() {
    vector<vector<int> > mat = {{ 1, 1, 0 },
                                { 0, 1, 0 },
                                { 0, 1, 1 }};
    cout << celebrity(mat);
    return 0;
}

oyimized

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        stack<int> st;

        // Step 1: Push all people into the stack
        for (int i = 0; i < n; i++)
            st.push(i);

        // Step 2: Eliminate non-celebrities
        while (st.size() > 1) {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();

            // If a knows b → a cannot be a celebrity
            if (mat[a][b] == 1)
                st.push(b);
            else
                st.push(a);
        }

        // Step 3: Check the potential celebrity
        int c = st.top();
        st.pop();

        // Step 4: Verify candidate c
        for (int i = 0; i < n; i++) {
            if (i == c) continue;

            // If c knows someone OR someone doesn't know c → not a celebrity
            if (mat[c][i] == 1 || mat[i][c] == 0)
                return -1;
        }

        return c;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> mat = {
        {1, 1, 0},
        {0, 1, 0},
        {0, 1, 1}
    };

    cout << obj.celebrity(mat);
    return 0;
}
