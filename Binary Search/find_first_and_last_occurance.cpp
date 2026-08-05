#include <iostream>
#include <vector>

using namespace std;

// Function to find the first occurrence
int findFirst(const vector<int>& arr, int n, int x) {
    int low = 0, high = n - 1;
    int first = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            first = mid;
            high = mid - 1; // Keep searching in the left half
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return first;
}

// Function to find the last occurrence
int findLast(const vector<int>& arr, int n, int x) {
    int low = 0, high = n - 1;
    int last = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            last = mid;
            low = mid + 1; // Keep searching in the right half
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return last;
}

int main() {
    int n, x;
    if (!(cin >> n >> x)) return 0;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int first = findFirst(arr, n, x);
    int last = findLast(arr, n, x);

    if (first == -1) {
        cout << -1 << "\n"; // Element not found
    } else {
        cout << first << " " << last << "\n";
    }

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main() {
//     int n, x;
//     cin >> n >> x;

//     vector<int> arr(n);
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     auto lb = lower_bound(arr.begin(), arr.end(), x);
    
//     // Check if element exists
//     if (lb == arr.end() || *lb != x) {
//         cout << -1 << "\n";
//     } else {
//         auto ub = upper_bound(arr.begin(), arr.end(), x);
//         int first = lb - arr.begin();
//         int last = (ub - arr.begin()) - 1;
//         cout << first << " " << last << "\n";
//     }

//     return 0;
// }