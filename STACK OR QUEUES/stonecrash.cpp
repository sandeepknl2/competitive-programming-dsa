#include <bits/stdc++.h>
using namespace std;

void push1(stack<int>& st, int x) {
    st.push(x);
}

int crashed(stack<int>& st) {
    while (st.size() > 1) {
        int a = st.top(); st.pop();
        int b = st.top(); st.pop();
        if (a != b) st.push(abs(a - b));
    }
    return st.empty() ? 0 : st.top();
}

int main() {
    vector<int> arr = {2, 7, 4, 1, 8, 1};
    sort(arr.begin(), arr.end()); // Optional

    stack<int> st;
    for (int x : arr) {
        push1(st, x);
    }

    int result = crashed(st);
    cout << result;
}


most optimized

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {2, 7, 4, 1, 8, 1};
    sort(a.begin(), a.end());  // sort the stones

    while (a.size() > 1) {
        int x = a.back(); a.pop_back();   // biggest
        int y = a.back(); a.pop_back();   // second biggest
        if (x != y) a.push_back(x - y);   // push the difference
        sort(a.begin(), a.end());         // keep sorted
    }

    cout << (a.empty() ? 0 : a[0]);
}


priority queue

       priority_queue<int>pq(a.begin(),a.end());

        while(pq.size() > 1)
        {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();

            if(a != b)
                pq.push(abs(a-b));
        }
        return pq.empty() ? 0 : pq.top();