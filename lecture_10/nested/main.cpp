#include <bits/stdc++.h>
using namespace std;

int LSOne(int x){
    return (x&-x);
}

void update(int x, int N, int v, int* ft){
    for(; x < N; x += LSOne(x)) ft[x] += v;
}

int query(int x, int* ft){
    int sum = 0;
    for(; x > 0; x -= LSOne(x)) sum += ft[x];
    return sum;
}

int main(){
    vector<pair<int, int>> l, r;
    int N; cin >> N;
    //left and right ends
    int L[N], R[N];
    for(int i = 0; i < N; i++){
        cin >> L[i] >> R[i];
        l.push_back({L[i], i});
        r.push_back({R[i], i});
    }

    //bit tree size is N+1
    int bitN = N+1;
    int ft[bitN]; fill(ft, ft+bitN, 0);

    sort(l.begin(), l.end());
    sort(r.begin(), r.end());

    //map[i] tells me where the originally i-th element now is 
    int map[N];
    for(int i = 0; i < N; i++) map[r[i].second] = i;

    //fill bit tree
    for(int i = 1; i <= N; i++) update(i, bitN, 1, ft);

    //store answer
    int ans[N];
    
    for(auto left: l){
        ans[left.second] = query(map[left.second]+1-1, ft);
        update(map[left.second]+1, bitN, -1, ft); 
    }

    for(int i = 0; i < N; i++)
        cout << ans[i] << endl;

    return 0;
}
