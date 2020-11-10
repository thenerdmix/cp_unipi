#include <bits/stdc++.h>
using namespace std;

int LSOne(int i){ return i&(-i); }

void update(int i, int diff, int* ft, int N){
    for(; i < N; i += LSOne(i)) ft[i] += diff;
}

int query(int i, int* ft){
    int sum = 0;
    for(; i > 0; i -= LSOne(i)) sum += ft[i];
    return sum;
}

int main(){
    
    int N; cin >> N;
    int ft[N], A[N], left[N], right[N];
    //the idea is that in left[i] we store how many elements are on the left of the element A[i] and are strictly less than A[i] in value. Analogously for the array right. So the answer is just the sum of the products left[i]*right[i]
    fill(ft, ft+N, 0);
    for(int i = 0; i < N; i++) cin >> A[i];

    for(int i = 0; i < N; i++){
        left[i] = query(A[i]-1, ft);
        update(A[i], 1, ft, N);    
    }

    fill(ft, ft+N, 0);
    for(int i = N-1; i >= 0; i--){
        right[i] = (N-i-1) - query(A[i], ft);
        update(A[i], 1, ft, N);
    }

    long long sum = 0;
    for(int i = 0; i < N; i++)
        sum += left[i]*right[i];

    cout << sum << endl;

    
    return 0;
}
