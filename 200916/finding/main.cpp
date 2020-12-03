#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int main(){

    vector<iii> v;

    int n; cin >> n;
    int f;
    for(int i = 2; i <= 2*n; i++){
        for(int k = 1; k < i; k++){
            cin >> f;    
            v.push_back({f, {i, k}}); 
        }
    }

    sort(v.begin(), v.end());

    int matched[2*n+5];
    fill(matched, matched + 2*n+5, -1);

    while(!v.empty()){
        ii couple = v.back().second;
        v.pop_back();
        if(matched[couple.first] == -1 && matched[couple.second] == -1){
            matched[couple.first] = couple.second;
            matched[couple.second] = couple.first;
        }
    }

    for(int i = 1; i <= 2*n; i++)
        cout << matched[i] << " ";
    
    
    return 0;
}
