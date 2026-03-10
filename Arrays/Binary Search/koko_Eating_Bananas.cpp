class Solution {
public:

    int calculateHours(vector<int>& piles, int k){
        int hours = 0;

        for(int pile : piles){
            hours += (pile + k - 1) / k;
        }

        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        int ans = high;

        while(low <= high){

            int mid = (low + high) / 2;

            int hours = calculateHours(piles, mid);

            if(hours <= h){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};
