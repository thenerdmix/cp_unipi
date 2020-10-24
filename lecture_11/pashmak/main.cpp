#include <bits/stdc++.h>
using namespace std;

int LSOne(int x){ return x&(-x); }

void update(int x, int v, int N, int* ft){
    for(; x < N; x += LSOne(x)) ft[x] += v;
}

int query(int x, int* ft){
    int sum = 0;
    for(; x > 0; x -= LSOne(x)) sum += ft[x];
    return sum;
}

int main(){
    int N; cin >> N;
    int A[N];
    int bitN = N + 1;
    int ft[bitN]; fill(ft, ft+bitN, 0);

    unordered_map<int, int> freq;
    unordered_map<int, int> rev_freq;

    for(int i = 0; i < N; i++) cin >> A[i];
    
    //the idea is: first of all we traverse the array from right to left and we update the bit tree, query(x)-query(x-1) tells us how many j there are such that f(j, n, a_j) = x
    for(int i = N-1; i >= 0; i--){
        if(freq.find(A[i]) == freq.end()) freq[A[i]] = 1;
        else freq[A[i]] = freq[A[i]] + 1;
        update(freq[A[i]], +1, bitN, ft);
    }

    //the answer can be really big! (quadratic in N)
    long long ans = 0;

    //now we just have to traverse the array from right to left. Knowing f(1, i, a_i) for each i we just have to sum the varius query(f(1, i, a_i) -1)
    for(int i = 0; i < N; i++){
        if(rev_freq.find(A[i]) == freq.end()) rev_freq[A[i]] = 1;
        else rev_freq[A[i]] = rev_freq[A[i]] + 1;
        update(freq[A[i]], -1, bitN, ft);
        freq[A[i]] = freq[A[i]] - 1;
        ans += query(rev_freq[A[i]]-1, ft);
    }
    
    cout << ans;
    
    return 0;
}
