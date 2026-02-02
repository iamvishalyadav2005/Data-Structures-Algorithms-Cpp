/*
    Aggressive Cows Problem
    Technique: Binary Search on Answer

    Time Complexity: O(N log N)
    Space Complexity: O(1)
*/

class Solution {
private:
    // Check if we can place k cows with at least 'dist' distance
    bool canPlaceCows(vector<int> &stalls, int k, int dist) {
        int count = 1;                 // first cow placed
        int lastPos = stalls[0];

        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - lastPos >= dist) {
                count++;
                lastPos = stalls[i];
            }
            if (count >= k) return true;
        }
        return false;
    }

public:
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());

        int low = 1;
        int high = stalls.back() - stalls.front();
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canPlaceCows(stalls, k, mid)) {
                ans = mid;          // valid answer
                low = mid + 1;      // try larger distance
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
