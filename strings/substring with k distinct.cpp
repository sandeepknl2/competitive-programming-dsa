// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;

int main() {
 string s = "aba";
int k = 2;
int n = s.size();
int ans = 0;

for (int i = 0; i < n; i++) {
    vector<int> freq(256, 0);
    int distinct = 0;
    for (int j = i; j < n; j++) {
        if (freq[s[j]] == 0) {
            distinct++;
        }
        freq[s[j]]++;

        if (distinct == k) ans++;
    }
}

cout << ans;  // 3 for "aba", k=2


    return 0;
}

optimized chatgpt
int atMostK(string &s, int k) {
    int n = s.size();
    int left = 0, ans = 0;
    unordered_map<char, int> freq;

    for (int right = 0; right < n; right++) {
        freq[s[right]]++;

        // Shrink window if more than k distinct
        while ((int)freq.size() > k) {
            freq[s[left]]--;
            if (freq[s[left]] == 0) freq.erase(s[left]);
            left++;
        }

        // All substrings ending at right with at most k distinct
        ans += (right - left + 1);
    }
    return ans;
}

// Count substrings with exactly K distinct chars
int substringsWithKDistinct(string s, int k) {
    return atMostK(s, k) - atMostK(s, k - 1);
}




optomiwzed gfg

#include <iostream>
#include <vector>
using namespace std;

// function which finds the number of 
// substrings with atmost k Distinct
// characters.
int count(string &s, int k) {
    int n = s.length();
    int ans = 0;
    
    // use sliding window technique
    vector<int> freq(26, 0);
    int distinctCnt = 0;
    int i = 0;
    
    for (int j = 0; j < n; j++) {
        
        // expand window and add character
        freq[s[j] - 'a']++;
        if (freq[s[j] - 'a'] == 1) distinctCnt++;
        
        // shrink window if distinct characters exceed k
        while (distinctCnt > k) {
            freq[s[i] - 'a']--;
            if (freq[s[i] - 'a'] == 0) distinctCnt--;
            i++;
        }
        
        // add number of valid substrings ending at j
        ans += j - i + 1;
    }
    
    return ans;
}

// function to find the number of substrings
// with exactly k Distinct characters.
int countSubstr(string &s, int k) {
    int n = s.length();
    int ans = 0;
    
    // subtract substrings with at most 
    // k-1 distinct characters from substrings
    // with at most k distinct characters
    ans = count(s, k) - count(s, k-1);
    
    return ans;
}

int main() {
    string s = "abc";
    int k = 2;
    cout << countSubstr(s, k);
    return 0;
}