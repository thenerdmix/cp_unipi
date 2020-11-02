#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define INF LONG_MAX
typedef long long ll;

int LEFT(int i){ return 2*i + 1; }
int RIGHT(int i){ return 2*i; }

ll t[4*MAXN] = {INF}, lazy[4*MAXN] = {0};
void update(int v, int tl, int tr, int l, int r, int diff){
    //prima cosa: eseguo pending updates
    if(lazy[v] != 0){
        t[v] += lazy[v];
        if(tl != tr){
            lazy[LEFT(v)] += lazy[v];
            lazy[RIGHT(v)] += lazy[v];
        }
        lazy[v] = 0;
    }

    if(tl > tr || tl > r || tr < l) return;

    //segmento corrente tutto nel range
    if(tl >= l && tr <= r){
        t[v] += diff;
        
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
    t[v] = min(t[LEFT(v)], t[RIGHT(v)]);
}

ll query(int v, int tl, int tr, int l, int r){
    if(lazy[v] != 0){
        t[v] += lazy[v];
        if(tl != tr){
            lazy[LEFT(v)] += lazy[v];
            lazy[RIGHT(v)] += lazy[v];
        }
        lazy[v] = 0;
    }

    if(tl > r || tr < l || tl > tr) return INF; 
    
    if(tl >= l && tr <= r) return t[v];

    int tm = (tl+tr)/2;
    ll q1 = query(LEFT(v), tl, tm, l, r), q2 = query(RIGHT(v), tm+1, tr, l, r);
    return min(q1, q2);
    
}

void build(int* a, int v, int tl, int tr){
    if(tl == tr){
        t[v] = a[tl];
        return;
    }
    int tm = (tl + tr)/2;
    build(a, LEFT(v), tl, tm);
    build(a, RIGHT(v), tm+1, tr);
    t[v] = min(t[LEFT(v)], t[RIGHT(v)]);
    return;
}

ll query(int l, int r, int N){
    return query(1, 0, N-1, l, r);
}

void update(int l, int r, int diff, int N){
    update(1, 0, N-1, l, r, diff);
}

int main(){

    //I lost a lot of time because I was using cin instead of scanf :(
    int N; scanf("%d", &N);
    int a[N];
    for(int i = 0; i < N; i++) scanf("%d", &a[i]);
    build(a, 1, 0, N-1);

    int var;
    int Q; scanf("%d", &Q);
    string str;
    while((Q--) >= 0){
        getline(cin, str);
        stringstream ss(str);
        vector<int> v;
        while(ss >> var)
            v.push_back(var);

        if(v.size() == 0) continue;

        int l = v[0], r = v[1];

        if(v.size() == 2){
            if(l <= r) cout << query(l, r, N) <<endl;
            else{
               ll q1 = query(l, N-1, N),  q2 = query(0, r, N);
               cout << min(q1, q2) << endl;
            }
        }
        
        if(v.size() == 3){
            if(l <= r) update(l, r, v[2], N);
            else{
                update(l, N-1, v[2], N);
                update(0, r, v[2], N);
            }
        }
    }

    return 0;
}
