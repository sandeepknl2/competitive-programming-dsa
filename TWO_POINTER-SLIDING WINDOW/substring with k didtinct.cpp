
#include <bits/stdc++.h>
using namespace std;

// bool issubstring(int st, int en, string s, int k) {
//     int usedk = 0;
//     set<char> c;
//     for (int i = st; i <= en; i++) {
//         if (c.insert(s[i]).second)  // newly inserted character
//             usedk++;
//         if (usedk > k)
//             return false;
//     }
//     return true;
// }

bool issubstring(int st, int en, string s, int k) {
    vector<int> freq(128, 0); // ASCII 128
    int distinct = 0;

    for (int i = st; i <= en; i++) {
        if (freq[s[i]] == 0)  // first time seeing this character
            distinct++;
        freq[s[i]]++;
    }

    return distinct <= k;
}

int main() {
    string s = "eceba";
    int k = 2;
    int n = s.size();
    int maxl = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {   // include substring of length 1
            if (issubstring(i, j, s, k)) {
                maxl = max(maxl, j - i + 1);
            }
        }
    }

    cout << maxl << endl;   // Output the maximum length
    return 0;
}
  

optimized

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "eceba";
    int k = 2;
    int n = s.size();
    int maxl = 0;

    int left = 0, right = 0;
    int distinct = 0;
    vector<int> freq(128, 0);  // ASCII frequency map

    while (right < n) {
        char c = s[right];
        if (freq[c] == 0)  // first time seeing this character
            distinct++;
        freq[c]++;
        right++;

        // Shrink window if distinct > k
        while (distinct > k) {
            char leftChar = s[left];
            freq[leftChar]--;
            if (freq[leftChar] == 0)
                distinct--;
            left++;
        }

        // Update maximum length of valid window
        maxl = max(maxl, right - left);
    }

    cout << maxl << endl;   // Output the maximum length
    return 0;
}


