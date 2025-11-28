#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> tasks = {5, 9, 8, 5, 9};
    vector<int> workers = {1, 6, 4, 2, 6};
    int pills = 1, strength = 5;

    // Step 1: Sort both lists
    sort(tasks.begin(), tasks.end());     // easiest → hardest
    sort(workers.begin(), workers.end()); // weakest → strongest

    int n = tasks.size();
    int m = workers.size();
    int i = n - 1; // start from hardest task
    int j = m - 1; // start from strongest worker
    int cnt = 0;

    // Step 2: Match hardest tasks to strongest workers
    while (i >= 0 && j >= 0) {
        if (workers[j] >= tasks[i]) {
            // worker strong enough directly
            cnt++;
            i--;
            j--;
        }
        else if (pills > 0 && workers[j] + strength >= tasks[i]) {
            // use a pill if it makes worker strong enough
            pills--;
            cnt++;
            i--;
            j--;
        }
        else {
            // task too hard even with pill → skip this task
            i--;
        }
    }

    cout << "Maximum tasks that can be done: " << cnt << endl;
    return 0;
}
opytimized

class Solution {
public:
    bool canAssign(int k, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        deque<int> dq;
        for (int i = workers.size() - k; i < workers.size(); i++)
            dq.push_back(workers[i]); // pick strongest k workers

        for (int i = k - 1; i >= 0; i--) { // hardest to easiest
            int task = tasks[i];

            // if even the strongest worker + pill < task → impossible
            if (dq.back() + strength < task) return false;

            // if strongest worker can do task without pill
            if (dq.back() >= task) {
                dq.pop_back();
            } 
            // else use pill on weakest worker
            else {
                dq.pop_front();
                pills--;
                if (pills < 0) return false;
            }
        }
        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int lo = 0, hi = min((int)tasks.size(), (int)workers.size()), ans = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (canAssign(mid, tasks, workers, pills, strength)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};
