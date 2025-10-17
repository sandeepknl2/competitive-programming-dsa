#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function: returns true if all characters in s[i..j] are unique
    bool isUnique(const string &s, int start, int end) {
        for(int i = start; i <= end; i++) {
            for(int j = i + 1; j <= end; j++) {
                if(s[i] == s[j]) return false;
            }
        }
        return true;
    }

    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLen = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(isUnique(s, i, j)) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }
};

int main() {
    Solution sol;
    string s = "abcabcbb";
    cout << "Longest substring length: " << sol.lengthOfLongestSubstring(s) << endl;
    return 0;
}


optimized 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int n = s.size();
        int start = 0, end = 0, maxLen = 0;

        while(end < n) {
            if(seen.find(s[end]) == seen.end()) {
                // character not in current window, expand
                seen.insert(s[end]);
                maxLen = max(maxLen, end - start + 1);
                end++;
            } else {
                // character repeated, shrink from start
                seen.erase(s[start]);
                start++;
            }
        }

        return maxLen;
    }
};