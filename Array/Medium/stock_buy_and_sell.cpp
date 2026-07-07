#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX; // Track the lowest buying price seen so far
        int maxProfit = 0;      // Track the maximum profit possible

        for (int price : prices) {
            // Update minPrice if we find a cheaper day to buy
            if (price < minPrice) {
                minPrice = price;
            } 
            // Otherwise, check if selling today yields a better profit
            else if (price - minPrice > maxProfit) {
                maxProfit = price - minPrice;
            }
        }

        return maxProfit;
    }
};