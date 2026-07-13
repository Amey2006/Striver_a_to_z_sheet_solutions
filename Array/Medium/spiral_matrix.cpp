#include <iostream>
#include <vector>
using namespace std;

void printSpiral(const vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return;

    int top = 0;
    int bottom = matrix.size() - 1;
    int left = 0;
    int right = matrix[0].size() - 1;

    while (top <= bottom && left <= right) {
        // 1. Move from Left to Right along the top row
        for (int i = left; i <= right; ++i) {
            cout << matrix[top][i] << " ";
        }
        top++; // Move the top boundary down

        // 2. Move from Top to Bottom along the right column
        for (int i = top; i <= bottom; ++i) {
            cout << matrix[i][right] << " ";
        }
        right--; // Move the right boundary left

        // 3. Move from Right to Left along the bottom row (if still valid)
        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                cout << matrix[bottom][i] << " ";
            }
            bottom--; // Move the bottom boundary up
        }

        // 4. Move from Bottom to Top along the left column (if still valid)
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                cout << matrix[i][left] << " ";
            }
            left++; // Move the left boundary right
        }
    }
    cout << endl;
}

int main() {
    vector<vector<int>> matrix = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    cout << "Spiral Order: ";
    printSpiral(matrix);

    return 0;
}