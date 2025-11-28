#include <bits/stdc++.h>
using namespace std;

bool isSubstring(string s, string t, int start, int end) {
    vector<int> freqS(128, 0), freqT(128, 0);

    // Count frequencies of t
    for (char c : t)
        freqT[c]++;

    // Count frequencies of substring s[start..end]
    for (int i = start; i <= end; i++)
        freqS[s[i]]++;

    // Check if substring covers all chars in t
    for (char c : t) {
        if (freqS[c] < freqT[c])
            return false;
    }
    return true;
}

int main() {
    string s = "ADOBECODEBANC", t = "ABC";
    int n = s.size(), m = t.size();
    string res = "";
    int minLen = INT_MAX;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (isSubstring(s, t, i, j)) {
                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    res = s.substr(i, j - i + 1);/// res = "";
// for (int k = i; k <= j; k++) {
  //
  res += s[k];
//}
                }
            }
        }
    }

    cout << "Minimum window substring: " << res << endl;
    return 0;
}
optimized

#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
    vector<int> freqT(128, 0);  // frequency map for t
    for (char c : t) freqT[c]++;

    int left = 0, right = 0;
    int minLen = INT_MAX;
    int start = 0;
    int required = t.size();   // total chars we need to match

    while (right < s.size()) {
        if (freqT[s[right]] > 0) 
            required--;  // found one needed char
        freqT[s[right]]--;  // mark it used
        right++;

        // When all characters are matched
        while (required == 0) {
            // Update result if smaller window found
            if (right - left < minLen) {
                minLen = right - left;
                start = left;
            }

            // Try shrinking from left
            freqT[s[left]]++;
            if (freqT[s[left]] > 0)
                required++;  // lost one needed char
            left++;
        }
    }

    return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
}

int main() {
    string s = "ADOBECODEBANC", t = "ABC";
    string res = minWindow(s, t);
    cout << "Minimum window substring: " << res << endl;
    return 0;
}
