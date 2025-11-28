class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> arr;
        int num = 1;

        while (arr.size() < n) {
            int x = num;
            while (x % 2 == 0) x /= 2;
            while (x % 3 == 0) x /= 3;
            while (x % 5 == 0) x /= 5;

            if (x == 1) arr.push_back(num);
            num++;
        }

        return arr[n - 1];
    }
};


optimized
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n);
        ugly[0] = 1;

        int p2 = 0, p3 = 0, p5 = 0;

        for (int i = 1; i < n; i++) {
            int next2 = ugly[p2] * 2;
            int next3 = ugly[p3] * 3;
            int next5 = ugly[p5] * 5;

            int nextUgly = min(next2, min(next3, next5));
            ugly[i] = nextUgly;

            if (nextUgly == next2) p2++;
            if (nextUgly == next3) p3++;
            if (nextUgly == next5) p5++;
        }

        return ugly[n - 1];
    }
};
