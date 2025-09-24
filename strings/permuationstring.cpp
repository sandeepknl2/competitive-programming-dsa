#include <iostream>
#include <vector>
using namespace std;

bool checkInclusion(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    if (n > m) return false;

    vector<int> freq(256, 0);   // s1 frequencies
    vector<int> freq1(256, 0);  // sliding window frequencies

    // Frequency of s1 and first window of s2
    for (int i = 0; i < n; i++) {
        freq[s1[i]]++;
        freq1[s2[i]]++;
    }

    // Slide the window
    for (int i = n; i < m; i++) {
        if (freq == freq1) return true;  // match found

        // slide: add new char, remove old char
        freq1[s2[i]]++;
        freq1[s2[i - n]]--;
    }

    // check last window
    return freq == freq1;
}

int main() {
    string s1 = "ab", s2 = "eidbaooo";
    if (checkInclusion(s1, s2))
        cout << "Yes, permutation exists";
    else
        cout << "No, not possible";
    return 0;
}
