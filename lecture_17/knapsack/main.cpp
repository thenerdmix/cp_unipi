#include <bits/stdc++.h>
using namespace std;

#define NMAX 2005

int N;
//size and value
int s[NMAX], v[NMAX];
int memo[NMAX][NMAX];

int dp(int S, int P){
    if(memo[S][P] != -1) return memo[S][P];
    int m = 0;
    for(int i = 0; i < P; i++){
        if(s[i] <= S)
            m = max(m, dp(S-s[i], i) + v[i]);
    }

    return (memo[S][P] = m);
}

int main(){

    for(int i = 0; i < NMAX; i++)
        for(int j = 0; j < NMAX; j++)
            memo[i][j] = -1;

    int S;

    cin >> S >> N;

    for(int i = 0; i < N; i++)
        cin >> s[i] >> v[i];

    cout << dp(S, N);

    return 0;
}
