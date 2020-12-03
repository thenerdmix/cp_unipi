int dp(int pos, int value, int arr[], vector<vector<int>> &memo){
        if(value <= -1) return 0;
        if(pos == -1){
            if(value == 0) return 1;
            else return 0;
        }
        if(memo[pos][value] != -1) return memo[pos][value];
        return (memo[pos][value] = dp(pos-1, value, arr, memo) || dp(pos-1, value-arr[pos], arr, memo));

    }
int equalPartition(int N, int arr[])
    {
        int S = 0;
        for(int i = 0; i < N; i++) S+=arr[i];
        
        if(S%2!=0) return 0;
        
        vector<vector<int>> memo(N, vector<int>(S/2+1, -1));
        
        return dp(N-1, S/2, arr, memo);
    }
