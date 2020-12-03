#include <bits/stdc++.h>
using namespace std;

//to have a (at least a little bit) convincing explanation of why this 10 magic lines work, see what I've written in
//https://uz.sns.it/~fradeb/dokuwiki/wiki/algoritmi/lis

int longestSubsequence(int n, int a[]){
    vector<int> s;
    s.push_back(a[0]);
    for(int i = 1; i < n; i++){
        auto it = lower_bound(s.begin(), s.end(), a[i]);
        if(it == s.end()) s.push_back(a[i]);
        else *it = a[i];
    }
    return s.size();
}

int main(){
    int N; cin >> N; int A[N];
    for(int i = 0; i < N; i++){ cin >> A[i]; }

    cout << longestSubsequence(N, A);
    
    return 0;
}
