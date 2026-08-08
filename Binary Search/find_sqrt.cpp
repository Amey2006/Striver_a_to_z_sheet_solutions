#include <iostream>

class Solution {
public:
    int floorSqrt(int n) {
        if (n == 0 || n == 1) return n;

        int low = 1, high = n;
        int ans = 1;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long val = mid * mid;

            if (val <= n) {
                ans = mid;      // mid could be our floor answer
                low = mid + 1;  // try to find a larger value in the right half
            } else {
                high = mid - 1; // mid*mid > n, search in the left half
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    int n1 = 36;
    std::cout << "Input: n = " << n1 << "\nOutput: " << sol.floorSqrt(n1) << std::endl; // Output: 6

    // Example 2
    int n2 = 28;
    std::cout << "Input: n = " << n2 << "\nOutput: " << sol.floorSqrt(n2) << std::endl; // Output: 5

    return 0;
}