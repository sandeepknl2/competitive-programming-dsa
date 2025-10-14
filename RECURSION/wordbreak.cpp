#include <bits/stdc++.h>
using namespace std;

bool isSegment(string s, vector<string> wordDict) {
    int n = s.size();
    string temp = "";
    int i = 0;

    while (i < n) {
        temp += s[i]; // build current word
        bool found = false;

        // check if temp matches any word
        for (string w : wordDict) {
            if (temp == w) {
                found = true;
                temp = ""; // reset for next word
                break;
            }
        }

        i++;
        if (i == n && temp != "")  // reached end but last part unmatched
            return false;
    }

    return temp == ""; // all words matched exactly
}

int main() {
    string s = "leetcode";
    vector<string> word = {"leet", "code"};

    if (isSegment(s, word))
        cout << "true";
    else
        cout << "false";

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

bool canForm(string &s, vector<string> &dict, int i) {
    if (i == s.size()) return true; // base: reached end

    for (auto &word : dict) {
        int len = word.size();

        // Check if current part of s starts with 'word'
        bool match = true;
        for (int j = 0; j < len; j++) {
            if (i + j >= s.size() || s[i + j] != word[j]) {
                match = false;
                break;
            }
        }

        if (match) {
            // if this word fits, go ahead
            if (canForm(s, dict, i + len))
                return true;
        }
    }

    return false; // no word matched
}

int main() {
    string s = "LeetCode";
    vector<string> dict = {"Leet", "Code"};

    cout << (canForm(s, dict, 0) ? "true" : "false");
}


need TLE so we have to use DP and memoization