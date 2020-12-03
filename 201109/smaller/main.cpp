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

    //the idea is to group the query by their X value. In the vector v[i] we find the index of all the queries that have X = i. We notice that having X > N-1 is the same as having X = N-1. At this point we can start from X = 0 and process the queries in order. So the total time is: NlogN to order the initial array + M queries * logN.

    int N, M; cin >> N >> M; N++;
    int A[N];

    vector<pair<int, int>> a;

    for(int i = 1; i < N; i++){
        cin >> A[i];
        a.push_back({A[i], i});
    }

    int L[M], R[M], V[M];
    vector<int> v[N];

    for(int i = 0; i < M; i++){
        cin >> L[i] >> R[i] >> V[i];
        L[i]++; R[i]++;
        if(V[i] > N-1) v[N-1].push_back(i);
        else v[V[i]].push_back(i);
    }

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    int sol[M];

    int ft[N]; fill(ft, ft+N, 0);

    for(int i = 0; i <= N-1; i++){
        while(!a.empty() && a.back().first <= i){
            pair<int, int> p = a.back();
            a.pop_back();
            update(p.second, +1, ft, N);
        }
        for(auto j: v[i]){
            sol[j] = query(R[j], ft) - query(L[j]-1, ft);
        }
        
    }

    for(int i = 0; i < M; i++)
        cout << sol[i] << endl;
    
    return 0;
}
