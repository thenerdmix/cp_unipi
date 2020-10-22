#include <bits/stdc++.h>
using namespace std;

int main(){

    string s; cin >> s;
    int Q; cin >> Q;
    int c[s.length()]; //prefix sum array
    c[0] = 0;
    for(int i = 1; i < s.length(); i++){
        c[i] = c[i-1];
        if(s[i-1] == s[i]) c[i]++; 
    }

    for(int i = 0; i < Q; i++){
        int l, r; cin >> l >> r;
        cout << c[r-1]-c[l-1] << endl;
    }
    
    return 0;
}
