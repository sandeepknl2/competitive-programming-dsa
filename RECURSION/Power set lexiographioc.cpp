#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "abc";
    int n = s.size();

    vector<string> subs;

    // generate all subsets using loops (brute-force)
    for (int i = 0; i < n; i++) {
        string temp = "";
        for (int j = i; j < n; j++) {
            temp += s[j];          // add next char
            subs.push_back(temp);  // store current substring
        }
    }

    // sort lexicographically
    sort(subs.begin(), subs.end());

    // print result
    for (auto str : subs)
        cout << str << " ";
}


recuripn

#include <bits/stdc++.h>
using namespace std;

void generate(string s, string curr, int index, vector<string> &ans) {
    // Base case
    if (index == s.size()) {
        if (!curr.empty()) ans.push_back(curr);
        return;
    }

    // Recursive case:
    // Option 1: Include current character
    generate(s, curr + s[index], index + 1, ans);

    // Option 2: Exclude current character
    generate(s, curr, index + 1, ans);
}

int main() {
    string s = "abc";
    vector<string> ans;

    generate(s, "", 0, ans);

    sort(ans.begin(), ans.end());

    for (auto str : ans)
        cout << str << " ";
}
