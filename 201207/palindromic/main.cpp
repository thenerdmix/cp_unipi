#include <bits/stdc++.h>
using namespace std;

#define NMAX 1005

int main(){
    int T; cin >> T;
    while(T--){
        string s; cin >> s;
        int l = s.length();
        int a[l][l];
        int ans = 1;
        for(int i = 0; i < l; i++)
            for(int j = 0; j < l; j++)
                a[i][j] = 0;
        for(int i = 0; i < l; i++) a[i][i] = 1;
        for(int i = l-1; i >= 0; i--)
            for(int j = i+1; j < l; j++){
                if(s[i] == s[j] && j-i==1) a[i][j] = 2;
                else if(s[i] == s[j]) a[i][j] = a[i+1][j-1]+2;
                else a[i][j] = max(a[i+1][j], a[i][j-1]);
                ans = max(ans, a[i][j]);
            }
        cout << ans << endl;
    }
    
    return 0;
}
