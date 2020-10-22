#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    
    //this solution is too slow, because stl distance() function run in Theta(n) time    
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        int A[N];
        for(int i = 0; i < N; i++) cin >> A[i];
        multiset<int> s;
        ll inv = 0;
        for(int i = N-1; i >= 0; i--){
            s.insert(A[i]);
            inv += distance(s.begin(), s.lower_bound(A[i]));
        }
        cout << inv << endl;
    }    
    return 0;
}
