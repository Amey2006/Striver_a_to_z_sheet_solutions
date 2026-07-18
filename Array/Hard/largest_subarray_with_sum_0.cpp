#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxLen(vector<int>& arr) {
        unordered_map<int, int> sumMap;
        int max_len = 0;
        int current_sum = 0;

        for (int i = 0; i < arr.size(); i++) {
            current_sum += arr[i];

            if (current_sum == 0) {
                max_len = i + 1;
            }
            if (sumMap.find(current_sum) != sumMap.end()) {
                max_len = max(max_len, i - sumMap[current_sum]);
            } else {
                sumMap[current_sum] = i;
            }
        }

        return max_len;
    }
};