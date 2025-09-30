#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Manual function to count number of 1s in binary
int countBits(int x) {
    int cnt = 0;
    while (x > 0) {
        if (x % 2 == 1)  // last digit is 1
            cnt++;
        x = x / 2;       // move to next bit
    }
    return cnt;
}

// Manual function to convert integer to string
string intToString(int x) {
    if (x == 0) return "0";
    string s = "";
    while (x > 0) {
        char c = '0' + (x % 10); // get last digit as char
        s = c + s;               // prepend
        x = x / 10;              // remove last digit
    }
    return s;
}

vector<string> readBinaryWatch(int turnedOn) {
    vector<string> result;

    // Loop through all possible hours (0-11)
    for (int h = 0; h <= 11; h++) {
        // Loop through all possible minutes (0-59)
        for (int m = 0; m <= 59; m++) {
            // Count number of LEDs ON
            int totalBits = countBits(h) + countBits(m);

            // If total LEDs ON matches the requirement
            if (totalBits == turnedOn) {
                // Format hour (no leading zero)
                string hourStr = intToString(h);

                // Format minute (always 2 digits)
                string minuteStr;
                if (m < 10)
                    minuteStr = "0" + intToString(m);
                else
                    minuteStr = intToString(m);

                string time = hourStr + ":" + minuteStr;
                result.push_back(time);
            }
        }
    }

    return result;
}

int main() {
    int turnedOn;
    cout << "Enter number of LEDs turned on (0-10): ";
    cin >> turnedOn;

    vector<string> times = readBinaryWatch(turnedOn);

    cout << "Possible times (" << times.size() << "):\n";
    for (auto &t : times) {
        cout << t << " ";
    }
    cout << endl;

    return 0;
}



with in built to_string and __builtin_popcount


with shift
int countBits(int x) {
    int cnt = 0;
    while (x > 0) {
        cnt += (x & 1); // add 1 if last bit is 1
        x >>= 1;        // shift right by 1
    }
    return cnt;
}
eith builinpopcount


 int totalBits = __builtin_popcount(h) + __builtin_popcount(m);


recurion

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Convert integer to string manually
string intToString(int x) {
    if (x == 0) return "0";
    string s = "";
    while (x > 0) {
        char c = '0' + (x % 10);
        s = c + s;
        x = x / 10;
    }
    return s;
}

// Backtracking helper function
void backtrack(int pos, int turnedOn, int currOn, int hour, int minute, vector<string> &result) {
    // Base case: exact number of LEDs turned on
    if (currOn == turnedOn) {
        if (hour <= 11 && minute <= 59) {
            string time = intToString(hour) + ":";
            if (minute < 10)
                time += "0" + intToString(minute);
            else
                time += intToString(minute);
            result.push_back(time);
        }
        return;
    }

    // If we have used all LEDs
    if (pos == 10) return;

    // 1. Turn current LED ON
    if (pos < 4) // hour LEDs (positions 0-3)
        backtrack(pos + 1, turnedOn, currOn + 1, hour + (1 << pos), minute, result);
    else // minute LEDs (positions 4-9)
        backtrack(pos + 1, turnedOn, currOn + 1, hour, minute + (1 << (pos - 4)), result);

    // 2. Turn current LED OFF
    backtrack(pos + 1, turnedOn, currOn, hour, minute, result);
}

vector<string> readBinaryWatch(int turnedOn) {
    vector<string> result;
    backtrack(0, turnedOn, 0, 0, 0, result);
    return result;
}

int main() {
    int turnedOn;
    cout << "Enter number of LEDs turned on (0-10): ";
    cin >> turnedOn;

    vector<string> times = readBinaryWatch(turnedOn);

    cout << "Possible times (" << times.size() << "):\n";
    for (auto &t : times) {
        cout << t << " ";
    }
    cout << endl;

    return 0;
}
