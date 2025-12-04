#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end   = {2, 4, 6, 7, 9, 9};
    int n = start.size();

    // Step 1: Build meeting pairs
    vector<pair<int,int>> meetings;
    for (int i = 0; i < n; i++) {
        meetings.push_back({start[i], end[i]});
    }

    // Step 2: Sort by end time (basic rule for easier checking)
    // sort(meetings.begin(), meetings.end(), 
    //     [](auto &a, auto &b){ return a.second < b.second; });
    for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
        if (meetings[j].second < meetings[i].second) {
            swap(meetings[i], meetings[j]);
        }
    }
}

    // Step 3: Start counting
    int count = 1;                   // Take the first meeting
    int lastEnd = meetings[0].second;

    // Step 4: Check each remaining meeting
    for (int i = 1; i < n; i++) {
        int s = meetings[i].first;
        int e = meetings[i].second;

        // If this meeting starts AFTER previous one ends (strict >)
        if (s > lastEnd) {
            count++;                // We can take it
            lastEnd = e;            // Update last taken meeting end
        }
    }

    cout << count << endl;
    return 0;
}

bette
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
       int n = start.size();
        if (n == 0) return 0;

        // store as (end, start)
        vector<pair<int,int>> meet;
        for (int i = 0; i < n; i++) {
            meet.push_back({end[i], start[i]});
        }

        // sort by end time (because end is .first)
        sort(meet.begin(), meet.end());

        int count = 1;                 // always take the first (earliest ending)
        int lastEnd = meet[0].first;   // its end time

        for (int i = 1; i < n; i++) {
            int s = meet[i].second;    // start time
            int e = meet[i].first;     // end time

            // strict > because touching is NOT allowed
            if (s > lastEnd) {
                count++;
                lastEnd = e;
            }
        }

        return count;
        
    }
};


excpected

class Meeting {
  public:
    int start, finish;

    Meeting(int start, int finish) {
        this->start = start;
        this->finish = finish;
    }
};

// Custom comparator function
bool compareMeetings(const Meeting& m1, const Meeting& m2) {
    return m1.finish < m2.finish;
}

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<Meeting> meetings;

        // Pushing the pair of starting and finish time in a list.
        for (int i = 0; i < n; i++) {
            meetings.push_back(Meeting(start[i], end[i]));
        }

        // Sorting the list of meetings by finish time using a custom comparator
        sort(meetings.begin(), meetings.end(), compareMeetings);

        int lastFinishTime = -1;
        int res = 0;

        for (int i = 0; i < n; i++) {
            // If the start time of this meeting is greater than or equal
            // to the finish time of the previously selected meeting,
            // increment the counter and update last.
            if (meetings[i].start > lastFinishTime) {
                res++;
                lastFinishTime = meetings[i].finish;
            }
        }

        // Returning the counter.
        return res;
    }
};