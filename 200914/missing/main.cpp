#include <bits/stdc++.h>
#define NMAX 1e7+5
using namespace std;

int main(){
    
    int T; cin >> T;

    while(T--){
        int N; cin >> N;
        int sum = 0, c;
        for(int i = 0; i < N-1; i++){
           cin >> c;
           sum += c; 
        }

        cout << N*(N+1)/2 - sum << endl;
    }    

    return 0;
}
