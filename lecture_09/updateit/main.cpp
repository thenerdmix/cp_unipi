#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main(){

    //the problem is equivalent to find how many overlapping segment we have in a specific position.
    ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while(T--){
        int N, U; cin >> N >> U;
        vii set;
        for(int i = 0; i < U; i++){
            int l, r; cin >> l >> r;
            int v; cin >> v;
            set.push_back({l, v});
            set.push_back({r+1, -v});
        }

        sort(set.begin(), set.end());

        vi count; count.resize(N, 0);

        int current = 0;
        int position = 0;
        for(int i = 0; i < N; i++){
            while(position < set.size() && set[position].first <= i){
                current+=set[position].second;
                position++;
            }
            count[i] += current;
        }
        
        int Q; cin >> Q;
        for(int i = 0; i < Q; i++){
            int x; cin >> x;
            cout << count[x] << endl;
        }
    }
        
    return 0;
}
