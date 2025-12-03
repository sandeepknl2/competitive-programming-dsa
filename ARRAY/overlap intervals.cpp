class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        int n = intervals.size();
        int removals = 0;

        // Sort by start (optional but helps)
        sort(intervals.begin(), intervals.end());

        vector<bool> removed(n, false);

        // Compare EVERY interval with EVERY other interval
        for (int i = 0; i < n; i++) {
            if (removed[i]) continue;

            for (int j = i + 1; j < n; j++) {
                if (removed[j]) continue;

                int s1 = intervals[i][0], e1 = intervals[i][1];
                int s2 = intervals[j][0], e2 = intervals[j][1];

                // If overlap happens
                if (s2 < e1) {
                    // remove the one that ends later
                    if (e1 <= e2) {
                        removed[j] = true;
                        removals++;
                    } else {
                        removed[i] = true;
                        removals++;
                        break;  // stop checking interval i (it's removed)
                    }
                }
            }
        }

        return removals;
    }
};

optimized

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        // 1. Sort by end time
        sort(intervals.begin(), intervals.end(), 
             [](auto &a, auto &b) { return a[1] < b[1]; });

        int removals = 0;
        int lastEnd = intervals[0][1];

        // 2. Iterate from the second interval
        for (int i = 1; i < intervals.size(); i++) {
            // If overlap happens
            if (intervals[i][0] < lastEnd) {
                removals++;      // remove this interval
            } else {
                lastEnd = intervals[i][1];   // update last end
            }
        }

        return removals;
    }
};
