#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 3, 0, 2};
    int n = arr.size();
    vector<int> temp(n);  // temporary array to store result

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[j] == i) {
                temp[i] = j;  // index of value i
                break;        // once found, no need to continue inner loop
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << temp[i] << " ";
    }

    return 0;
}


optimized

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 3, 0, 2};  // Original permutation
    int n = arr.size();

    // Step 1: Encode new values into the array
    for(int i = 0; i < n; i++){
        // arr[i] % n -> ensures we get the original value even after previous modifications
        // i * n -> encode the new value (index of the current element) into arr[arr[i]]
        arr[arr[i] % n] += i * n; 
        // After this step, each element stores:
        // arr[index] = original_value + new_value * n
    }

    // Step 2: Decode the new values to get the inverse permutation
    for(int i = 0; i < n; i++){
        arr[i] = arr[i] / n;  // integer division extracts the new value (inverse index)
    }

    // Step 3: Print the final inverse permutation
    for(int i = 0; i < n; i++){
        cout << arr[i] << " "; // Output: 2 0 3 1
    }

    return 0;
}
