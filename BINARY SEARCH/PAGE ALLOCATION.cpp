#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Recursive brute-force function to allocate books
// arr -> book pages
// n -> total books
// k -> remaining students
// idx -> current starting index
int allocateBooks(const vector<int>& arr, int n, int k, int idx) {
    // Condition 1: If remaining books are fewer than students → impossible
    if (n - idx < k) return INT_MAX;

    // Base case: Only one student left → they take all remaining books
    if (k == 1) {
        int sum = 0;
        for (int i = idx; i < n; i++) sum += arr[i];
        return sum;
    }

    int sum = 0;
    int best = INT_MAX;

    // Try giving current student books from idx..i
    // Ensure at least (k-1) books remain for the remaining students
    for (int i = idx; i <= n - k; i++) {
        sum += arr[i];  // add current book to this student
        int next = allocateBooks(arr, n, k - 1, i + 1); // allocate remaining books
        if (next != INT_MAX) {
            int worst = max(sum, next);   // max pages any student gets in this allocation
            best = min(best, worst);      // choose allocation with minimal max
        }
    }

    return best;
}

int main() {
    vector<int> arr = {12, 34, 67, 90};
    int k = 2;  // number of students
    int n = arr.size();

    // Condition 2: Not enough books for all students
    if (k > n) {
        cout << -1 << endl;
        return 0;
    }

    int result = allocateBooks(arr, n, k, 0);

    // If result is INT_MAX → allocation impossible
    if (result == INT_MAX) cout << -1 << endl;
    else cout << "Minimum Maximum Pages = " << result << endl;

    return 0;
}
