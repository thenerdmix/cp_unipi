#include <bits/stdc++.h>
using namespace std;

int LSOne(int x){ return x&(-x); }

void up(int x, int v, int* ft, int N){
    for(; x < N; x+=LSOne(x)) ft[x] += v; 
}

int qu(int x, int* ft){
    int ans = 0;
    for(; x > 0; x-=LSOne(x)) ans += ft[x];
    return ans;
}

void update(int l, int r, int v, int* ft1, int* ft2, int N){
   up(l, v, ft1, N);
   up(r+1, -v, ft1, N);
   up(l, v*(l-1), ft2, N);
   up(r+1, -v*r, ft2, N);
}

int prefix(int x, int* ft1, int* ft2){
    return x*qu(x, ft1)-qu(x, ft2);
}

int query(int l, int r, int* ft1, int* ft2){
    return prefix(r, ft1, ft2)-prefix(l-1, ft1, ft2);
}

int main(){
    ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while(T--){
        int N, U; cin >> N >> U; N++;
        int ft1[N]; fill(ft1, ft1+N, 0);
        int ft2[N]; fill(ft2, ft2+N, 0);

        for(int i = 0; i < U; i++){
            int l, r; cin >> l >> r; l++; r++;
            int v; cin >> v;
            update(l, r, v, ft1, ft2, N);
        }

        int Q; cin >> Q;
        for(int i = 0; i < Q; i++){
            int x; cin >> x; x++;
            cout << query(x, x, ft1, ft2) << endl;
        }

    }


    return 0;
}
