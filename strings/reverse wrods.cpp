class Solution {
public:
    string reverseWords(string s) {
        string res = "", word = "";
        int n = s.size();

        for (int i = 0; i <= n; i++) {
            if (i < n && s[i] != ' ') {
                word += s[i];  // build the current word
            } else {
                // reverse the current word
                reverse(word.begin(), word.end());

                if (!res.empty()) res += ' '; // add space between words
                res += word;  // append reversed word to result
                word = "";    // reset word
            }
        }

        return res;
    }
};


optomesd  

vector<string> words;
        int n = s.size();
        int i = 0;

        while (i < n) {
            // Skip spaces
            while (i < n && s[i] == ' ') i++;

            if (i >= n) break;

            // Collect the word
            string word = "";
            while (i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }

            words.push_back(word);
        }

        // Reverse the vector of words
        reverse(words.begin(), words.end());

        // Join words with single space
        string result = "";
        for (int j = 0; j < words.size(); j++) {
            result += words[j];
            if (j != words.size() - 1) result += ' ';
        }

        return result;
    }