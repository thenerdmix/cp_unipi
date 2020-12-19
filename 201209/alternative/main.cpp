#include <bits/stdc++.h>
using namespace std;

int main(){

    //breve discussione dell'esercizio https://uz.sns.it/~fradeb/dokuwiki/wiki/algoritmi/alternative

    int N; cin >> N;
    string s; cin >> s;

    int tre = 0, due = 0;

    int prev = 0, succ = 0;
    char curr = s[0];
    succ++;

    int alt = 0;
    for(int i = 1; i <= N; i++){
        if(i == N || s[i] != curr){
            if(succ >= 3) tre++;
            if(succ >= 2) due++;

            alt++;
            curr = s[i];
            prev = succ;
            succ = 1;
        }
        else succ++;
    }

    if(tre >= 1 || due >= 2) cout << alt+2;
    else if(due >= 1) cout << alt+1;
    else cout << alt;
    
    return 0;
}
