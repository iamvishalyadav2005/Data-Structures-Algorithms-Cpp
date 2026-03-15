class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> ans;

        for(auto interval : intervals){

            // case 1: interval comes before newInterval
            if(interval[1] < newInterval[0]){
                ans.push_back(interval);
            }

            // case 2: interval comes after newInterval
            else if(interval[0] > newInterval[1]){
                ans.push_back(newInterval);
                newInterval = interval;
            }

            // case 3: overlapping intervals
            else{
                newInterval[0] = min(newInterval[0], interval[0]);
                newInterval[1] = max(newInterval[1], interval[1]);
            }
        }

        ans.push_back(newInterval); // IMPORTANT

        return ans;
    }
};
