#include <iostream>
using namespace std;

bool isAnagram(string s, string t) {
    if(s.length() != t.length()) return false;

    int n = t.length();

    for(int i = 0; i < s.length(); i++){
        bool found = false;
        for(int j = 0; j < n; j++){
            if(s[i] == t[j]){
                // Swap matched char to end
                swap(t[j], t[n-1]);
                n--;  // reduce effective length
                found = true;
                break;
            }
        }
        if(!found) return false;
    }

    return true;
}

int main() {
    string s1 = "listen", t1 = "silent";
    string s2 = "hello", t2 = "bello";

    cout << s1 << ", " << t1 << " → " << (isAnagram(s1, t1) ? "True" : "False") << endl;
    cout << s2 << ", " << t2 << " → " << (isAnagram(s2, t2) ? "True" : "False") << endl;

    return 0;
}


opyimized
#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
    if(s.length() != t.length()) return false;

    int freq[256] = {0};  // ASCII frequency array

    // Count frequency for s
    for(char c : s) freq[c]++;

    // Subtract frequency using t
    for(char c : t) freq[c]--;

    // Check if all frequencies are zero
    for(int i = 0; i < 256; i++){
        if(freq[i] != 0) return false;
    }

    return true;
}

int main() {
    string s1 = "listen", t1 = "silent";
    string s2 = "hello", t2 = "bello";

    cout << s1 << ", " << t1 << " → " << (isAnagram(s1,t1) ? "True" : "False") << endl;
    cout << s2 << ", " << t2 << " → " << (isAnagram(s2,t2) ? "True" : "False") << endl;

    return 0;
}
