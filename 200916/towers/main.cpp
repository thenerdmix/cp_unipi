#include <bits/stdc++.h>
#define MAXL 1005

using namespace std;

int main(){
    int count[MAXL];
    fill(count, count+MAXL, 0);
    int N; cin >> N;
    int l;
    for(int i = 0; i < N; i++){
        cin >> l;
        count[l]++;
    }
    int tot = 0; int largest = 0;
    for(int i = 0; i < MAXL; i++){
        if(count[i] != 0){
            tot++;
            largest = max(largest, count[i]); 
        }
    }
    cout << largest << " " << tot;
    return 0;
}
