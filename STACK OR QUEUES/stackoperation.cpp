#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    stack<int> st;        // main stack
    stack<int> maxStack;  // keeps track of maximum elements

    for (int i = 0; i < n; i++) {
        int type;
        cin >> type;

        if (type == 1) {  // Push operation
            int x;
            cin >> x;
            st.push(x);

            // if maxStack empty or x is new max
            if (maxStack.empty() || x >= maxStack.top()) {
                maxStack.push(x);
            }
        }
        else if (type == 2) { // Pop operation
            if (!st.empty()) {
                int topVal = st.top();
                st.pop();

                // if popped element was the max, pop from maxStack too
                if (topVal == maxStack.top()) {
                    maxStack.pop();
                }
            }
        }
        else if (type == 3) { // Print current max
            cout << maxStack.top() << endl;
        }
    }
    return 0;
}
