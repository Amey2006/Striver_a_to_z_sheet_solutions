#include <iostream>
#include <vector>
using namespace std;
vector<int> findUnion(const vector<int>& arr1, const vector<int>& arr2) {
    int n = arr1.size();
    int m = arr2.size();
    int i = 0, j = 0;
    vector<int> unionArr;

    while (i < n && j < m) {
        // Skip duplicates in arr1
        if (i > 0 && arr1[i] == arr1[i - 1]) {
            i++;
            continue;
        }
        // Skip duplicates in arr2
        if (j > 0 && arr2[j] == arr2[j - 1]) {
            j++;
            continue;
        }

        if (arr1[i] < arr2[j]) {
            unionArr.push_back(arr1[i]);
            i++;
        } else if (arr2[j] < arr1[i]) {
            unionArr.push_back(arr2[j]);
            j++;
        } else { // If both are equal
            unionArr.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    // Process remaining elements of arr1
    while (i < n) {
        if (i == 0 || arr1[i] != arr1[i - 1]) {
            unionArr.push_back(arr1[i]);
        }
        i++;
    }

    // Process remaining elements of arr2
    while (j < m) {
        if (j == 0 || arr2[j] != arr2[j - 1]) {
            unionArr.push_back(arr2[j]);
        }
        j++;
    }

    return unionArr;
}

int main() {
    vector<int> arr1 = {1, 2, 2, 3, 4};
    vector<int> arr2 = {2, 3, 3, 5, 6};

    vector<int> result = findUnion(arr1, arr2);

    cout << "Union: ";
    for (int val : result) {
        cout << val << " ";
    }
    return 0;
}