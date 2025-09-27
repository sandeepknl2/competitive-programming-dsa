// C++ program to find valid paranthesisations
// of length n

#include <bits/stdc++.h>
using namespace std;

// Helper function to recursively count
// valid parentheses arrangements
int helper(int left, int right, int &ans) {

    // If no more left and right parentheses
    // are remaining, a valid combination is found
    if (left == 0 && right == 0) {
        ans++;
        return ans;
    }

    // If more right parentheses than left,
    // return (invalid state)
    if (left > right) {
        return 0;
    }

    // Try adding a left parenthesis if available
    if (left > 0) {
        helper(left - 1, right, ans);
    }

    // Try adding a right parenthesis 
  	// if available
    if (right > 0) {
        helper(left, right - 1, ans);
    }

    return ans;
}

// Function to count valid parentheses
// arrangements of length n
int findWays(int n) {

    // If n is odd, no valid arrangements possible
    if (n % 2 == 1)
        return 0;
    int ans = 0;
    return helper(n / 2, n / 2, ans);
}

int main() {
    int n = 6;
    int res = findWays(n);
    cout << res << endl;
    return 0;
}

secode bryute
#include <iostream>
#include <vector>
using namespace std;

// Function to check if a sequence of '(' and ')' is valid
bool isValid(const string &s) {
    int balance = 0;
    for (char c : s) {
        if (c == '(') balance++;
        else balance--;
        if (balance < 0) return false; // more ')' than '(' at some point
    }
    return balance == 0; // all '(' matched
}

int main() {
    int n = 3; // number of pairs
    int totalValid = 0;
    int length = 2 * n;

    // Iterate through all possible sequences (2^(2n))
    int totalSequences = 1 << length; // 2^(2n)
    for (int mask = 0; mask < totalSequences; mask++) {
        string seq = "";
        for (int i = length - 1; i >= 0; i--) {
            if (mask & (1 << i)) seq += ')';
            else seq += '(';
        }

        if (isValid(seq)) totalValid++;
    }

    cout << "Number of valid parentheses expressions of length " << length << " is: " << totalValid << endl;
}



optimkzed

Cn​=n+12∗(2n−1)​∗Cn−1​with C0​=1
#include <iostream>
using namespace std;

long long catalan(int n) {
    long long C = 1;
    for (int i = 0; i < n; i++) {
        C = C * 2 * (2*i + 1) / (i + 2); // iterative formula
    }
    return C;
}

int main() {
    int n = 6; // number of pairs
    cout << "Number of valid parentheses expressions for n = " << n << " is: " << catalan(n) << endl;
}
