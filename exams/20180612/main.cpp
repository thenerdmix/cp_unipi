#include <bits/stdc++.h>
using namespace std;

int main(){

    int N; cin >> N;
    
    int A[N];
    for(int i = 0; i < N; i++)
        cin >> A[i];

    int starting[N], ending[N];

    //starting[i] is the longest strictly increasing subarray starting at i
    ending[0] = 1;
    for(int i = 1; i < N; i++){
        if(A[i] > A[i-1]) ending[i] = ending[i-1]+1;
        else ending[i] = 1; 
    }
    
    //ending[i] is the longest strictly increasing subarray ending at i
    starting[N-1] = 1;
    for(int i = N-2; i >= 0; i--){
        if(A[i] < A[i+1]) starting[i] = starting[i+1]+1;
        else starting[i] = 1;
    }

    int ans = 1;

    //left and right subarray
    for(int i = 1; i < N-1; i++)
        if(i > 0 && i < N-1 && (A[i+1]-A[i-1]>=2)) ans = max(ans, ending[i-1]+starting[i+1]+1);

    //only right subarray
    for(int i = 0; i < N-1; i++)
        if(A[i+1] > 1) ans = max(ans, 1+starting[i+1]);

    //only left subarray
    for(int i = 1; i < N; i++)
        ans = max(ans, 1+ending[i-1]);

    cout << ans;

    
    return 0;
}
