    int maxSoFar = 0;   // 1. Stores the largest number we have seen so far
    int chunks = 0;     // 2. Counts the number of chunks we can make

    for (int i = 0; i < arr.size(); i++) {         // 3. Loop through each index
        maxSoFar = max(maxSoFar, arr[i]);         // 4. Update the largest number seen so far

        if (maxSoFar == i) {                       // 5. If largest number equals current index
            chunks++;                              // 6. We can make a chunk here
        }
    }

    return chunks;                                 // 7. Return total number of chunks
}


optimizd easy

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();   // 1. Size of the array
        int a = 0;            // 2. Sum of numbers in original array so far
        int s = 0;            // 3. Sum of indices (0..i) so far
        int c = 0;            // 4. Count of chunks

        for(int i = 0; i < n; i++) {    // 5. Loop through the array
            a += arr[i];                 // 6. Add current number to sum of array
            s += i;                      // 7. Add current index to sum of indices
            if(a == s) c++;              // 8. If sums match, we can make a chunk
        }

        return c;   // 9. Return total number of chunks
    }
};

How It Works

a += arr[i] → running sum of elements in original array.

s += i → running sum of numbers if the array was sorted (because sorted array is [0,1,2,...]).

if(a == s) → when the sums are equal:

It means all numbers from 0 to i are present somewhere in the first i+1 elements.

So we can safely make a chunk ending here.