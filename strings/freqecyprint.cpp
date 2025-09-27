class Solution {
public:
    string frequencySort(string s) {
        string result = "";
        vector<pair<char, int>> freq;

        // Step 1: Count frequency (brute force way)
        for (int i = 0; i < s.size(); i++) {
            int count = 0;
            for (int j = 0; j < s.size(); j++) {
                if (s[i] == s[j]) count++;
            }
            freq.push_back({s[i], count});
        }

        // Step 2: Sort by frequency (descending)
        sort(freq.begin(), freq.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        // Step 3: Build result
        for (auto &p : freq) {
            result.append(p.second, p.first);
        }

        return result;
    }
};


opyimoized
class Solution {
public:
    string frequencySort(string s) {
        // Step 1: Count frequency of each character
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        // Step 2: Create buckets (index = frequency, value = chars with that freq)
        int n = s.size();
        vector<vector<char>> buckets(n + 1);
        for (auto &p : freq) {
            buckets[p.second].push_back(p.first);
        }

        // Step 3: Build result string from high freq to low
        string result = "";
        for (int f = n; f > 0; f--) {
            for (char c : buckets[f]) {
                result.append(f, c); // add char 'f' times
            }
        }

        return result;
    }
};
