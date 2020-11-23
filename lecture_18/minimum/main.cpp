int minJumps(int arr[], int n){
    //I'm already at the end of the array
    if(n <= 1)
        return 0;
    //I'm stuck at the beginning
    if(arr[0] == 0) return -1;

    //rightmost is the rightmost index we can reach with the constraint that the last jump start from an index r such that 0 <= i <= r
    int rightmost = arr[0];
    //remaining is the maximum natural number such that we can reach index [i, i + remaining] with a minimum number of jumps given by jumps
    int remaining = arr[0];
    //jumps is the minimum number of jumps we need to do to reach index i
    int jumps = 1;
    
    for(int i = 1; i < n; i++){
        if (i == n - 1) 
            return jumps; 
        //we can reach index i so the new definition of rightmost is the following:
        rightmost = max(rightmost, i+arr[i]);
        //if we don't update jumps, remaining--
        remaining--;
        //if remaining is 0, it's clear that to reach indexes (i+1, n-1] we need at least jumps + 1 jumps.
        if(remaining == 0){
            jumps++;
            //from the definiton of rightmost is clear that if i>=rightmost we are stuck 
            if(i>=rightmost)
                return -1;
            //we need at least jumps to reach i, so from the definition of rightmost we know that we need less than jumps + 1 jumps to reach the following rightmost - i indexes. But it is also clear that we cannot do it in less than jumps + 1 jumps, because otherwise we would have remaining != 0
            remaining = rightmost - i;
        }
        
    }
    
    return jumps;
}
