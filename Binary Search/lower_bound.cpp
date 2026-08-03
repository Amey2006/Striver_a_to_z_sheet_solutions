#include <vector>

int lowerBound(const std::vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    int ans = arr.size(); // Default answer if no element is >= target

    while (low <= high) {
        // Prevents integer overflow compared to (low + high) / 2
        int mid = low + (high - low) / 2; 

        if (arr[mid] >= target) {
            ans = mid;        // Found a potential index
            high = mid - 1;   // Look for a smaller index on the left
        } else {
            low = mid + 1;    // Target is larger, look on the right
        }
    }
    return ans;
}
