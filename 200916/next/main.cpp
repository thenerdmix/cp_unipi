#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

int main(){
   int T; cin >> T;
   while(T--){
       int N; cin >> N;
       ll ans[N];
       ll A[N];
       //slight variation of the sliding window algorithm. We consider "suffix" window. There's only one way of popping and inserting so we can use a stack
       stack<int> d;
       for(int i = 0; i < N; i++) cin >> A[i];
       for(int j = N-1; j>=0; j--){
            while(!d.empty() && A[d.top()] < A[j]) d.pop();
            if(d.empty())
                ans[j] = -1;
            else
                ans[j] =  A[d.top()];
            d.push(j);
       }
       for(int i = 0; i < N; i++) cout << ans[i] << " ";
       cout << endl;
   }
   return 0;
}
