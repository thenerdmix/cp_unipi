#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<pair<int, int>> vii;

int LSOne(int x){ return x&(-x); }

void up(int x, int v, int* ft, int N){
    for(; x < N; x+=LSOne(x)) ft[x] += v; 
}

int qu(int x, int* ft){
    int ans = 0;
    for(; x > 0; x-=LSOne(x)) ans += ft[x];
    return ans;
}

int main(){

    int N, M;
    cin >> N >> M;
    vii A; A.resize(N);

    for(int i = 0; i < N; i++){
        int x = 0; cin >> x;
        A[i] = make_pair(x, i+1);
    }

    //first of all sort the A array
    sort(A.begin(), A.end());

    //group the queries by their X argument
    int L[M], R[M];
    vi X[N+1];
    for(int i = 0; i < M; i++){
        cin >> L[i] >> R[i];
        L[i]++; R[i]++;
        int x = 0; cin >> x;
        if(x >= N) X[N].push_back(i);
        else X[x].push_back(i);
    }

    int Nft = N+1;
    int ft[Nft]; fill(ft, ft+Nft, 0);

    int ans[M];

    //the idea is to fill the Fenwick tree starting with the smallest elements of the A array, so we can process the queries grouped by X argument.
    int p = 0; 
    for(int i = 0; i <= N; i++){
        while(p < N && A[p].first <= i){
            up(A[p].second, 1, ft, Nft);
            p++;
        } 
        for(auto j: X[i]) ans[j] = qu(R[j], ft)-qu(L[j]-1, ft);
    }

    for(int i = 0; i < M; i++)
        cout << ans[i] << endl;
    
    return 0;
}
