int countSubarrays(vector<int>& arr, int k) {
    int n = arr.size();
    unordered_map<int,int> mp;

    int xr = 0;
    int count = 0;

    mp[0] = 1;   // VERY IMPORTANT

    for(int i = 0; i < n; i++) {
        xr ^= arr[i];

        int x = xr ^ k;

        if(mp.find(x) != mp.end()) {
            count += mp[x];
        }

        mp[xr]++;
    }

    return count;
}
