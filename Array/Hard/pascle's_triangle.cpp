#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1);
            
            for (int j = 1; j < i; j++) {
                row[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
            
            ans.push_back(row);
        }
        
        return ans;
    }
};

void printTriangle(const vector<vector<int>>& triangle) {
    for (const auto& row : triangle) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << "\n";
    }
}

int main() {
    Solution solver;
    int rows = 5;
    vector<vector<int>> result = solver.generate(rows);
    
    cout << "Pascal's Triangle for " << rows << " rows:\n";
    printTriangle(result);
    
    return 0;
}