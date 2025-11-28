#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "cbacdcbc";
    vector<char> res;

    vector<int> freq(128, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }

    int n = s.size();
    vector<bool> used(128, false);  // ✅ added to avoid duplicates

    for (int i = 0; i < n; i++) {
        char c = s[i];
        freq[c - 'a']--;  // ✅ decrease frequency for current char

        if (used[c - 'a']) continue;  // ✅ skip if already in result

        // ✅ simplified — no nested j loop
        while (!res.empty() && res.back() > c && freq[res.back() - 'a'] > 0) {
            used[res.back() - 'a'] = false;
            res.pop_back();
        }

        res.push_back(c);
        used[c - 'a'] = true;
    }

    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
    }
}


optimiwd
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "cbacdcbc";
    vector<int> freq(26, 0);       // count remaining frequency of each character
    vector<bool> used(26, false);  // check if char is already in result
    string res = "";               // result string (acts as a stack)

    // Step 1: count frequency
    for (char c : s) freq[c - 'a']++;

    // Step 2: process each character
    for (char c : s) {
        freq[c - 'a']--; // one occurrence used

        // skip if already added to result
        if (used[c - 'a']) continue;

        // maintain increasing lexicographical order
        while (!res.empty() && res.back() > c && freq[res.back() - 'a'] > 0) {
            used[res.back() - 'a'] = false;
            res.pop_back();
        }

        res.push_back(c);
        used[c - 'a'] = true;
    }

    cout << res;
}
