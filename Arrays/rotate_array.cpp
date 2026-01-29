// Problem: Rotate Array by K
// Approach: Reversal Algorithm
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int>& arr, int start, int end) {
    while(start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;//Number of Rotation
    int n = arr.size();

    k = k % n; // when ( k > n)

    reverseArray(arr, 0, n - 1);
    reverseArray(arr, 0, k - 1);
    reverseArray(arr, k, n - 1);

    for(int x : arr) cout << x << " ";
    return 0;
}
