#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    int N; cin >> N;
    int A[N];
    ll sum = 0;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        sum += A[i];
    }

    if(sum%3!=0){
        cout << 0;
        return 0;
    }

    sum /= 3;

    int left[N+1]; //left[i] contains the number of indexes j < i such that the prefix sum of A [0, ..., j] is equal to N/3;
    ll current = 0;
    left[0] = 0;
    for(int i = 1; i <= N; i++){
        left[i] = left[i-1];
        current += A[i-1];
        if(current == sum) left[i]++;
    }

    //now we traverse the array in the reverse order
    current = 0;
    ll ans = 0;
    for(int i = N-1; i >= 2; i--){
        current += A[i];
        if(current == sum) ans += left[i-1];
    }

    cout << ans;
    
    return 0;
}
