#include <bits/stdc++.h>
using namespace std;

int main(){
    int T; cin >> T;

    while(T--){
        int N; cin >> N;
        int A[N];
        for(int i = 0; i < N; i++) cin >> A[i];
        
        //l[i] denotes the maximum element in the subarray [i, N-1] of A
        int l[N];
        l[N-1] = A[N-1];

        bool leader[N];
        fill(leader, leader+N, false);
        //last element is a leader
        leader[N-1] = true;
        
        for(int j = N-2; j>=0; j--){
            if(A[j] >= l[j+1]) leader[j] = true;
            l[j] = max(A[j], l[j+1]);
        }

        for(int i = 0; i < N; i++)
            if(leader[i])
                cout << A[i] << " ";
        cout << endl;
    }    
    return 0;
}
