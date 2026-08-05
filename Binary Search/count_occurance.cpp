#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
private:
    int findFirst(const vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1, first = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                first = mid;
                high = mid - 1; // Keep searching left
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return first;
    }

    int findLast(const vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1, last = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                last = mid;
                low = mid + 1; // Keep searching right
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return last;
    }

public:
    int countOccurrences(vector<int>& arr, int target) {
        int first = findFirst(arr, target);
        if (first == -1) return 0; // Target not present
        
        int last = findLast(arr, target);
        return last - first + 1;
    }
};