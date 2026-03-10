class Solution {
public:

    double calculate(vector<int>& dist, int speed){

        double total = 0;

        for(int i = 0; i < dist.size() - 1; i++){
            total += (dist[i] + speed - 1) / speed;
        }

        total += (double)dist.back() / speed;

        return total;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {

        if(dist.size() - 1 >= hour) return -1;

        int low = 1;
        int high = 1e7;
        int ans = -1;

        while(low <= high){

            int mid = low + (high - low) / 2;

            double time = calculate(dist, mid);

            if(time <= hour){
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
