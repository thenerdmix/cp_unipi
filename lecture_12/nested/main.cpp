#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

//segment tree with lazy propagation (not useful for this problem where we only need pointwise updates)
int LEFT(int i){ return 2*i + 1; }
int RIGHT(int i){ return 2*i; }

int n = 0, t[4*MAXN] = {0}, lazy[4*MAXN] = {0};

void update(int v, int tl, int tr, int l, int r, int diff){
    //prima cosa: eseguo pending updates
    if(lazy[v] != 0){
        t[v] += (tr-tl+1)*lazy[v];
        if(tl != tr){
            lazy[LEFT(v)] += lazy[v];
            lazy[RIGHT(v)] += lazy[v];
        }
        lazy[v] = 0;
    }

    if(tl > tr || tl > r || tr < l) return;

    //segmento corrente tutto nel range
    if(tl >= l && tr <= r){
        t[v] += (tr-tl+1)*diff;
        
        //se non sono su una foglia
        if(tl != tr){
            lazy[LEFT(v)] += diff;
            lazy[RIGHT(v)] += diff;
        }
        return;
    }

    int tm = (tl+tr)/2;
    update(LEFT(v), tl, tm, l, r, diff);
    update(RIGHT(v), tm+1, tr, l, r, diff);
    t[v] = t[LEFT(v)] + t[RIGHT(v)];
}

int query(int v, int tl, int tr, int l, int r){

    if(lazy[v] != 0){
        t[v] += (tr-tl+1)*lazy[v];
        if(tl != tr){
            lazy[LEFT(v)] += lazy[v];
            lazy[RIGHT(v)] += lazy[v];
        }
        lazy[v] = 0;
    }

    if(tl > r || tr < l || tl > tr) return 0;

    if(tl >= l && tr <= r) return t[v];

    int tm = (tl+tr)/2;
    return query(LEFT(v), tl, tm, l, r) + query(RIGHT(v), tm+1, tr, l, r);
    
}

void build(int* a, int v, int tl, int tr){
    if(tl == tr){
        t[v] = a[tl];
        return;
    }
    int tm = (tl + tr)/2;
    build(a, LEFT(v), tl, tm);
    build(a, RIGHT(v), tm, tr);
    t[v] = t[LEFT(v)] + t[RIGHT(v)];
    return;
}

int main(){
    //the solution is the same as "nested" from lecture_10 but now we are using a segment tree with lazy propagation instead of a fenwick tree.
    vector<pair<int, int>> l, r;
    int N; cin >> N;
    //left and right ends
    int L[N], R[N];
    for(int i = 0; i < N; i++){
        cin >> L[i] >> R[i];
        l.push_back({L[i], i});
        r.push_back({R[i], i});
    }

    sort(l.begin(), l.end());
    sort(r.begin(), r.end());

    //map[i] tells me where the originally i-th element now is 
    int map[N];
    for(int i = 0; i < N; i++) map[r[i].second] = i;

    //fill bit tree
    for(int i = 1; i <= N; i++) update(1, 0, N, i, i, 1);

    //store answer
    int ans[N];
    
    for(auto left: l){
        ans[left.second] = query(1, 0, N, 0, map[left.second]+1-1);
        update(1, 0, N, map[left.second]+1, map[left.second]+1, -1); 
    }

    for(int i = 0; i < N; i++)
        cout << ans[i] << endl;

    return 0;
}
