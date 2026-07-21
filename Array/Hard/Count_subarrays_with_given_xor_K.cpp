#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int solve(vector<int> &A, int B) {
        // Map to store the frequency of prefix XORs
        unordered_map<int, int> xor_freq;
        
        int current_xor = 0;
        int subarrays_count = 0;
        
        // Base case: A prefix XOR of 0 has occurred once (before entering the array)
        xor_freq[0] = 1;
        
        for (int num : A) {
            // Update the prefix XOR up to the current element
            current_xor ^= num;
            
            // We need: Y = current_xor ^ B
            int target_xor = current_xor ^ B;
            
            // If target_xor exists in the map, add its frequency to our count
            if (xor_freq.find(target_xor) != xor_freq.end()) {
                subarrays_count += xor_freq[target_xor];
            }
            
            // Store/update the frequency of the current prefix XOR
            xor_freq[current_xor]++;
        }
        
        return subarrays_count;
    }
};

int main() {
    Solution solver;
    vector<int> A = {4, 2, 2, 6, 4};
    int B = 6;
    
    cout << "Total subarrays with XOR " << B << " is: " 
              << solver.solve(A, B) << endl;
              
    return 0;
}