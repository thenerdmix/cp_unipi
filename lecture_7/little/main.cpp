#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;

int main(){

    //the problem is equivalent to find how many overlapping segment we have in a specific position. Then we proceed greedily: the most queried index is the one we assign the biggest value to, and so on

    int N, Q; cin >> N >> Q;
    vll v; v.resize(N, 0);
    for(int i = 0; i < N; i++) cin >> v[i];

    vii set;
    for(int i = 0; i < Q; i++){
        int l, r; cin >> l >> r; l--; r--;
        set.push_back({l, 0});
        set.push_back({r+1, 1});
    }

    sort(set.begin(), set.end());
    sort(v.begin(), v.end());

    vi count; count.resize(N, 0);

    int current = 0;
    int position = 0;
    for(int i = 0; i < N; i++){
        while(position < set.size() && set[position].first <= i){
            if(set[position].second == 0) current++;
            else current--;
            position++;
        }
        count[i] += current;
    }

    sort(count.begin(), count.end());
    ll ans = 0;
    for(int i = 0; i < N; i++) ans += count[i]*v[i];
    cout << ans;
    
    return 0;
}
