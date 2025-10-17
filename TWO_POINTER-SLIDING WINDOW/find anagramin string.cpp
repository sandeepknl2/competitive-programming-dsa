#include <bits/stdc++.h>
using namespace std;

bool isAgabram(string s, string p, int st, int en) {
    vector<int> fre(256, 0);
    vector<int> fre1(256, 0);
    int q = p.size();

    for (int i = st; i < en; i++) {
        fre[s[i]]++;
    }
    for (int i = 0; i < q; i++) {
        fre1[p[i]]++;
    }

    for (int i = 0; i < 256; i++) {
        if (fre[i] != fre1[i]) return false;
    }
    return true;
}

int main() {
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> arr;
    int n = s.size();

    for (int i = 0; i <= n - p.size(); i++) {
        if (isAgabram(s, p, i, i + p.size())) {
            arr.push_back(i);
        }
    }

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
}


optimized sliding

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
          int n = s.size(), m = p.size();
    vector<int> res;
    if (n < m) return res;

    vector<int> freqP(26, 0), freqS(26, 0);
    for (char c : p) freqP[c - 'a']++;
    for (int i = 0; i < m; i++) freqS[s[i] - 'a']++;
    bool isEqual = true;
    for (int i = 0; i < 26; ++i) {
        if (freqP[i] != freqS[i]) {
            isEqual = false;
            break;
        }
    }
    if (isEqual) res.push_back(0);
    for (int i = m; i < n; i++) {
        freqS[s[i] - 'a']++;      
        freqS[s[i - m] - 'a']--;   
        isEqual = true;
        for (int j = 0; j < 26; ++j) {
            if (freqP[j] != freqS[j]) {
                isEqual = false;
                break;
            }
        }
        if (isEqual) res.push_back(i - m + 1);
    }

    return res;
}
  
    
};