/*
    Allocate Minimum Number of Pages
    Technique: Binary Search on Answer

    Time Complexity: O(N log S)
    Space Complexity: O(1)
    where S = sum of all pages
*/

class Solution {
private:
    // Check if we can allocate books so that max pages per student <= limit
    bool isPossible(vector<int> &pages, int students, int limit) {
        int count = 1;          // students used
        long long currSum = 0;

        for (int i = 0; i < pages.size(); i++) {
            if (pages[i] > limit) return false;

            if (currSum + pages[i] <= limit) {
                currSum += pages[i];
            } else {
                count++;
                currSum = pages[i];
            }
        }
        return count <= students;
    }

public:
    int findPages(vector<int> &pages, int students) {
        if (students > pages.size()) return -1;

        int low = *max_element(pages.begin(), pages.end());
        int high = accumulate(pages.begin(), pages.end(), 0);
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(pages, students, mid)) {
                ans = mid;       // valid answer
                high = mid - 1;  // try smaller max
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
