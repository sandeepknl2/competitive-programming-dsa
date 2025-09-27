#include <iostream>
#include <vector>
#include <string>
using namespace std;

int gemstones(vector<string> arr) {
    int n = arr.size();
    int count = 0;

    // Check each mineral 'a' to 'z'
    for(char c = 'a'; c <= 'z'; c++) {
        bool isGem = true;

        // Check this mineral in all rocks
        for(int i = 0; i < n; i++) {
            bool found = false;
            for(int j = 0; j < arr[i].length(); j++) {
                if(arr[i][j] == c) {
                    found = true;
                    break; // found in this rock
                }
            }
            if(!found) {
                isGem = false; // missing in this rock
                break;
            }
        }

        if(isGem) count++;
    }

    return count;
}

int main() {
    int n;
    cin >> n;
    vector<string> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << gemstones(arr) << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int gemstones(vector<string> arr) {
    int n = arr.size();

    // Convert first rock to set
    set<char> common(arr[0].begin(), arr[0].end());

    // Intersect with remaining rocks
    for (int i = 1; i < n; i++) {
        set<char> s(arr[i].begin(), arr[i].end());
        set<char> temp;
        
        // Compute intersection
        set_intersection(
            common.begin(), common.end(),
            s.begin(), s.end(),
            inserter(temp, temp.begin())
        );
        common = temp; // update common minerals
    }

    return common.size();
}

int main() {
    int n;
    cin >> n;
    vector<string> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << gemstones(arr) << endl;
    return 0;
}



