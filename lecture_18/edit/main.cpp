#include <bits/stdc++.h>
using namespace std;

#define INF 1e9


#define INF 1e9
#define NMAX 105

int memo[NMAX][NMAX];

//the state (spos, tpos) tell us the minimum number of moves we need to do in order to change the substring [0, spos] of s in the substring [0, tpos] of t.
int dp(string s, int spos, string t, int tpos){
    if(spos == -1 && tpos == -1) return 0;
    if(spos == -2 || tpos == -2) return INF;
    if(memo[spos+1][tpos+1] != -1) return memo[spos+1][tpos+1];
    //we have three possible moves:
    //1) delete the last letter from string s
    //2) add a letter to the end of string s to match the last letter of string t
    //3) change the last letter of string s in the last letter of string t
    int m = min(min(1+dp(s, spos-1, t, tpos), 1+dp(s, spos, t, tpos-1)), 1+dp(s, spos-1, t, tpos-1));
    //if the last letters of the two substrings are equal we can transition to state (spos-1, tpos-1) without performing any move
    if(spos >= 0 && tpos >= 0 && s[spos] == t[tpos])
        m = min(m, dp(s, spos-1, t, tpos-1));
    memo[spos+1][tpos+1] = m;
    return m;

}

int editDistance(string s, string t){
    for(int i = 0; i < NMAX; i++)
        for(int j = 0; j < NMAX; j++)
            memo[i][j] = -1;

    return dp(s, s.length()-1, t, t.length()-1);
}

int main(){

    string s, t;
    cin >> s >> t;

    cout << editDistance(s, t);
    
    return 0;
}
