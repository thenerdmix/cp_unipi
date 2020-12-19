#include <bits/stdc++.h>
using namespace std;

int main(){

    //breve discussione del problema: https://uz.sns.it/~fradeb/dokuwiki/wiki/algoritmi/wilbur

    int N; cin >> N;
    long long int ans = 0, prev = 0, succ = 0;
    for(int i = 0; i < N; i++){
        cin >> succ;
        ans += abs(succ-prev);
        prev = succ;
    } 
    cout << ans;
    
    return 0;
}
