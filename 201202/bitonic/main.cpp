//same implementation of lis algorithm you can find in the other folder in this lecture directory. The only difference is that know we are interested to LIS(k) for each k so we save the index of the iterator we get from the binary search.
void LIS(vector<int>& nums, vector<int>& lis){
        lis[0] = 1;
        vector<int> s;
        s.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++){
            auto it = lower_bound(s.begin(), s.end(), nums[i]);
            int index = it-s.begin() + 1;
            if(it == s.end()) s.push_back(nums[i]);
            else *it = nums[i];
            lis[i] = index;
        }
}

//just run two LIS, one for the ordered nums vector and another for the reverse nums vector and sum the results.
int LongestBitonicSequence(vector<int>nums){
	    vector<int> leftLIS, rightLIS;
	    leftLIS.resize(nums.size(), 0); rightLIS.resize(nums.size(), 0);
	    LIS(nums, leftLIS);
	    reverse(nums.begin(), nums.end());
	    LIS(nums, rightLIS);
	    reverse(rightLIS.begin(), rightLIS.end());
	    int ans = -1;
	    for(int i = 0; i < nums.size(); i++) ans = max(ans, rightLIS[i]+leftLIS[i]-1);
        return ans;
}
