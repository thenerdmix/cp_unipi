#include <bits/stdc++.h>
using namespace std;


int main(){

    int T; cin >> T;

    while(T--){
        int N; cin >> N;
        int A[N];
        for(int i = 0; i < N; i++) cin >> A[i];
       
        //m denotes the solution of the subproblem for the subarray [0, i], mC denotes the maximum suffix subarray you can obtain in [0, i] 
        int m, mC;
        m = A[0];
        mC = A[0];

        for(int i = 1; i < N; i++){
            mC = max(A[i], A[i] + mC);
            m = max(m, mC);
        }

        cout << m << endl;
    }    

    return 0;
}
