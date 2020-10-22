#include <bits/stdc++.h>
using namespace std;

int main(){
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        int A[N];
        for(int i = 0; i < N; i++) cin >> A[i];
        //max_left(right)[i] denotes the maximum element in the prefix(suffix) subarray
        int max_left[N], max_right[N];
        max_left[0] = A[0];
        max_right[N-1] = A[N-1];
        for(int i = 1; i < N; i++) max_left[i] = max(max_left[i-1], A[i]);
        for(int i = N-2; i>=0; i--) max_right[i] = max(max_right[i+1], A[i]); 
        int sum = 0;
        for(int i = 0; i < N; i++)
            sum += min(max_right[i], max_left[i]) - A[i];
        cout << sum << endl;
    }    
    return 0;
}
