#include <iostream>
using namespace std;
class Solution {
private:
    // Helper function to check mid^n relative to m
    // Returns 1 if mid^n == m
    // Returns 2 if mid^n > m
    // Returns 0 if mid^n < m
    int checkPower(int mid, int n, int m) {
        long long ans = 1;
        for (int i = 1; i <= n; i++) {
            ans *= mid;
            if (ans > m) return 2; // Early exit to prevent integer overflow
        }
        if (ans == m) return 1;
        return 0;
    }

public:
    int NthRoot(int n, int m) {
        int low = 1, high = m;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int status = checkPower(mid, n, m);

            if (status == 1) {
                return mid; // Exact root found
            } else if (status == 0) {
                low = mid + 1; // Move to the right half
            } else {
                high = mid - 1; // Move to the left half
            }
        }

        return -1; // If no integer Nth root exists
    }
};

int main() {
    Solution sol;
    cout << sol.NthRoot(3, 27) << endl; // Output: 3
    cout << sol.NthRoot(4, 69) << endl; // Output: -1
    return 0;
}