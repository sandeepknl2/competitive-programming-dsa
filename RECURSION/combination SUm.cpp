#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 4; // numbers 1 to 4
    int k = 2; // choose 2 numbers
    vector<vector<int>> res;

    // Normal nested loops (for k = 2)
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            vector<int> temp;
            temp.push_back(i);
            temp.push_back(j);
            res.push_back(temp);
        }
    }

    // Print results
    for (auto v : res) {
        for (auto x : v)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}



OPTIMIZE


#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 4; // total numbers
    int k = 3; // choose k numbers
    vector<vector<int>> res;

    // Start with the first combination [1, 2, ..., k]
    vector<int> comb(k);
    for (int i = 0; i < k; i++)
        comb[i] = i + 1;

    while (true) {
        res.push_back(comb); // store current combination

        // Find the last position that can be increased
        int i;
        for (i = k - 1; i >= 0; i--) {
            if (comb[i] < n - (k - 1 - i)) {
                comb[i]++;  // increase this number
                // Update all numbers after it
                for (int j = i + 1; j < k; j++)
                    comb[j] = comb[j - 1] + 1;
                break;
            }
        }

        // if nothing can be increased, we’re done
        if (i < 0)
            break;
    }

    // Print all combinations
    for (auto v : res) {
        for (auto x : v)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}
