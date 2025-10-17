#include <bits/stdc++.h>
using namespace std;

int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    int maxSum = 0;

    for (int i = 0; i <= k; i++) {
        int leftSum = 0, rightSum = 0;

        // Take i cards from the front
        for (int j = 0; j < i; j++) 
            leftSum += cardPoints[j];

        // Take (k - i) cards from the back
        for (int j = 0; j < k - i; j++) 
            rightSum += cardPoints[n - 1 - j];

        maxSum = max(maxSum, leftSum + rightSum);
    }

    return maxSum;
}

int main() {
    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;
    cout << maxScore(cardPoints, k);
    return 0;
}


recueion
#include <bits/stdc++.h>
using namespace std;

// Recursive function
int Combi(vector<int>& arr, int left, int right, int k) {
    // Base case
    if (k == 0) return 0;

    // If only one pick left, pick the max of two ends
    if (left > right) return 0;

    // Option 1: Pick from left
    int takeLeft = arr[left] + Combi(arr, left + 1, right, k - 1);

    // Option 2: Pick from right
    int takeRight = arr[right] + Combi(arr, left, right - 1, k - 1);

    // Return the best possible sum
    return max(takeLeft, takeRight);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;

    int maxSum = Combi(arr, 0, arr.size() - 1, k);

    cout << "Maximum score = " << maxSum << endl;
    return 0;
}


optimi slising winfow

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        
        // Step 1: Find total sum of all cards
        int total = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        
        // Step 2: If we must take all cards
        if (k == n) return total;

        int windowSize = n - k;

        // Step 3: Find initial window sum of size (n - k)
        int windowSum = 0;
        for (int i = 0; i < windowSize; i++) {
            windowSum += cardPoints[i];
        }

        int minWindowSum = windowSum;

        // Step 4: Slide the window across the array
        for (int i = windowSize; i < n; i++) {
            windowSum += cardPoints[i] - cardPoints[i - windowSize];
            minWindowSum = min(minWindowSum, windowSum);
        }

        // Step 5: Subtract smallest window sum from total
        return total - minWindowSum;
    }
};


prefux sun

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        
        int leftSum = 0, rightSum = 0;
        int maxScore = 0;

        // Step 1: Take all k cards from left initially
        for (int i = 0; i < k; i++) {
            leftSum += cardPoints[i];
        }
        maxScore = leftSum; // initial best

        // Step 2: Now, shift one card at a time from left to right
        // (remove one from leftSum, add one from right)
        for (int i = 1; i <= k; i++) {
            leftSum -= cardPoints[k - i];             // remove one from the end of left part
            rightSum += cardPoints[n - i];            // add one from the back
            maxScore = max(maxScore, leftSum + rightSum);
        }

        return maxScore;
    }
};
