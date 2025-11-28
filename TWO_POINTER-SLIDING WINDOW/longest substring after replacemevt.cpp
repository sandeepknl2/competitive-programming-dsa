using frequency vector<int> count(26, 0);  // frequency of each letter
        int left = 0;
        int maxCount = 0;  // track the count of the most frequent character in current window
        int res = 0;

        for (int right = 0; right < s.size(); right++) {
            count[s[right] - 'A']++;
            maxCount = max(maxCount, count[s[right] - 'A']);

            // if we need to replace more than k characters, shrink window
            while ((right - left + 1) - maxCount > k) {
                count[s[left] - 'A']--;
                left++;
            }

            res = max(res, right - left + 1);
        }

        return res;
    }

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "AABABBA";
    int k = 1;
    int n = s.size();
    int maxLen = 0;

    // Try every starting index i
    for (int i = 0; i < n; i++) {
        vector<int> freq(26, 0); // Count of each letter in current substring
        int maxFreq = 0;          // Most frequent letter count in current substring

        // Expand substring from i to j
        for (int j = i; j < n; j++) {
            freq[s[j] - 'A']++;           // Count current character
            maxFreq = max(maxFreq, freq[s[j] - 'A']); // Track most frequent char

            int len = j - i + 1;          // Current substring length
            int changesNeeded = len - maxFreq; // How many letters to replace

            // If we can make substring uniform within k changes
            if (changesNeeded <= k)
                maxLen = max(maxLen, len);
            else
                break; // Adding more letters exceeds k
        }
    }

    cout << "Longest substring length after replacements: " << maxLen << endl;
    return 0;
}

// using map 

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "AABABBA";
    int k = 1;
    int n = s.size();
    int maxLen = 0;

    // Try every starting index i
    for (int i = 0; i < n; i++) {
        map<char, int> freq; // Frequency of each character in current substring
        int maxFreq = 0;     // Most frequent character count

        // Expand substring from i to j
        for (int j = i; j < n; j++) {
            freq[s[j]]++; // Count current character
            maxFreq = max(maxFreq, freq[s[j]]); // Track most frequent char

            int len = j - i + 1; // Current substring length
            int changesNeeded = len - maxFreq; // Number of replacements needed

            // If we can make substring uniform within k changes
            if (changesNeeded <= k)
                maxLen = max(maxLen, len);
            else
                break; // Adding more letters exceeds k
        }
    }

    cout << "Longest substring length after replacements: " << maxLen << endl;
    return 0;
}
