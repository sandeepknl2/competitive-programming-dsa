#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n = 50; // or take user input
    const long long MOD = 1e9 + 7;

    long long even = 1, odd = 1;
    long long count = 0;

    while (count < n) {
        even = (even * 5) % MOD;
        count++;

        if (count == n)
            break;

        odd = (odd * 4) % MOD;
        count++;
    }

    // Final result = even^count_even * odd^count_odd
    long long ans = (even * odd) % MOD;
    cout << ans << endl;

    return 0;
}


optoimized

#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

// Fast modular exponentiation: computes (base^exp) % MOD
long long modPow(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

class Solution {
public:
    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2;  // digits at even indices
        long long oddCount  = n / 2;        // digits at odd indices

        long long ans = (modPow(5, evenCount) * modPow(4, oddCount)) % MOD;
        return (int)ans;
    }
};
