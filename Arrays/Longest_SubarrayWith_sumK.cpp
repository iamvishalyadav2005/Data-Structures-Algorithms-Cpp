int LongestSubarray(vector<int> &nums,int k){
    int n = nums.size();
  unordered_map<int> mp;
  int sum = 0;
  int maxLen = 0;
  for(int i = 0;i<n;i++){
    sum += nums[i];

    if(sum == k){
      maxLen = i+1;
    }
    if(mp.find(sum-k)!= mp.end()){
      maxLen = max(maxLen,i - mp[sum-k]);
    }

    if(mp.find(sum)== mp.end()){
      mp[sum] = i;
    }
  }
return maxLen;

}
  
