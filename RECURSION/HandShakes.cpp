my solutoion
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int n = arr.size();
    int cnt = 0;

    // Try all first-handshake options for person 1
    for (int i = 1; i < n; i++) { // person 1 pairs with arr[i]
        // For N=4, two possibilities
        if (i == 1) { 
            // 1-2, then 3-4
            cnt++;
        } else if (i == 2) { 
            // 1-3, then 2-4
            cnt++;
        }
    }

    cout << cnt << endl; // Output: 2
}


only for n=4

#include <bits/stdc++.h>
using namespace std;

// Check if two handshakes (a,b) and (c,d) cross
bool isCross(pair<int,int> x, pair<int,int> y) {
    int a = min(x.first, x.second), b = max(x.first, x.second);
    int c = min(y.first, y.second), d = max(y.first, y.second);
    return (a < c && c < b && b < d) || (c < a && a < d && d < b);
}

// Brute-force generation of all valid handshake sets
int countHandshakes(vector<int>& arr, vector<pair<int,int>>& chosen) {
    if (arr.empty()) return 1; // All paired

    int total = 0;
    int first = arr[0]; // Fix the first person

    for (int i = 1; i < arr.size(); i++) {
        int second = arr[i];
        pair<int,int> newPair = {first, second};

        // Check if new pair crosses any existing pair
        bool cross = false;
        for (auto p : chosen) {
            if (isCross(p, newPair)) {
                cross = true;
                break;
            }
        }

        if (!cross) {
            // Choose this pair
            vector<int> nextArr = arr;
            nextArr.erase(nextArr.begin() + i); // Remove second
            nextArr.erase(nextArr.begin());     // Remove first
            vector<pair<int,int>> nextChosen = chosen;
            nextChosen.push_back(newPair);

            total += countHandshakes(nextArr, nextChosen);
        }
    }

    return total;
}

int main() {
    int N;
    cout << "Enter even number of people: ";
    cin >> N;
    if (N % 2 != 0) {
        cout << "Number of people must be even!" << endl;
        return 0;
    }

    vector<int> arr(N);
    for (int i = 0; i < N; i++) arr[i] = i + 1;

    vector<pair<int,int>> chosen;
    int cnt = countHandshakes(arr, chosen);
    cout << "Total non-crossing handshake arrangements: " << cnt << endl;
}


uding Catalan
#include <iostream>
using namespace std;

// Function to compute factorial
unsigned long long factorial(int n) {
    unsigned long long res = 1;
    for (int i = 2; i <= n; i++)
        res *= i;
    return res;
}

// Function to compute nth Catalan number
unsigned long long catalan(int n) {
    unsigned long long num = factorial(2 * n);
    unsigned long long denom = factorial(n + 1) * factorial(n);
    return num / denom;
}

int main() {
    int n = 6; // Change this for other Catalan numbers
    cout << "Catalan number C_" << n << " = " << catalan(n) << endl;
    return 0;
}


to print the pairs
#include <bits/stdc++.h>
using namespace std;

// Recursive function to generate non-crossing handshakes
// start: first person in the current segment
// end: last person in the current segment
// current: current list of pairs
// all: store all arrangements
void generateHandshakes(int start, int end, vector<pair<int,int>> current, vector<vector<pair<int,int>>>& all) {
    if (start > end) {
        all.push_back(current);
        return;
    }

    // Pair start with any other person (must be even number of people between them)
    for (int i = start + 1; i <= end; i += 2) {
        vector<pair<int,int>> newCurrent = current;
        newCurrent.push_back({start, i});

        // Recursively solve left and right segments
        generateHandshakes(start + 1, i - 1, newCurrent, all);  // left group
        generateHandshakes(i + 1, end, newCurrent, all);        // right group
    }
}

int main() {
    int N;
    cout << "Enter even number of people: ";
    cin >> N;

    if (N % 2 != 0) {
        cout << "Odd N, no arrangements possible!" << endl;
        return 0;
    }

    vector<vector<pair<int,int>>> all;
    vector<pair<int,int>> current;

    generateHandshakes(1, N, current, all);

    cout << "Total non-crossing arrangements: " << all.size() << endl;

    // Print all arrangements
    for (auto& arr : all) {
        cout << "{ ";
        for (auto& p : arr) {
            cout << "(" << p.first << "," << p.second << ") ";
        }
        cout << "}" << endl;
    }

    return 0;
}


