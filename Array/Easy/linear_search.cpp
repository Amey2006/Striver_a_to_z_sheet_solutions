#include <iostream>
#include <vector>

using namespace std;


int linearSearch(const vector<int>& arr, int target) {

    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return i; 
        }
    }
    return -1; 

int main() {
    vector<int> data = {12, 45, 67, 8, 93, 21, 5};
    int target = 93;

    int result = linearSearch(data, target);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}