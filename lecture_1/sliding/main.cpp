#include <bits/stdc++.h>
using namespace std;

int main(){
    int T; cin >> T;

    while(T--){
        int N; int K; cin >> N >> K;
        int A[N];
        for(int i = 0; i < N; i++) cin >> A[i];
        //well-known algorithm
        deque<int> d;
        for(int i = 0; i < N; i++){
            while(!d.empty() && d.front() <= i - K) d.pop_front();
            while(!d.empty() && A[d.back()] <= A[i]) d.pop_back();
            d.push_back(i);
            if(i >= K-1) cout << A[d.front()] << " ";
        }
        cout << endl;
    }    
    return 0;
}
