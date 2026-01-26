// Problem: Reverse an Array
// Approach: Two Pointer
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int i = 0, j = arr.size() - 1;

    while(i < j) {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }

    for(int x : arr) cout << x << " ";
    return 0;
}
