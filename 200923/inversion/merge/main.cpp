#include <bits/stdc++.h>
#define NMAX 200005
using namespace std;
typedef long long ll;

int A[NMAX];

ll merge(int x1, int y1, int x2, int y2){
    ll inv = 0;
    int p1 = 0, p2 = 0;
    int size1 = y1 - x1 + 1;
    int size2 = y2 - x2 + 1;
    int L[size1], R[size2];
    for(int i = 0; i < size1; i++) L[i] = A[x1+i];
    for(int i = 0; i < size2; i++) R[i] = A[x2+i];
    while(p1 < size1 && p2 < size2){
        if(L[p1] <= R[p2]){
            A[x1+p1+p2] = L[p1];
            p1++;
        }else{
            inv += size1 - p1;
            A[x1+p1+p2] = R[p2];
            p2++;
        }
    }
    while(p1 < size1){
        A[x1+p1+p2] = L[p1];
        p1++;
    }
    while(p2 < size2){
        A[x1+p1+p2] = R[p2];
        p2++;
    }
    return inv;
}

ll sort(int x, int y){
    if(x == y) return 0;
    int middle = (x+y)/2;
    return sort(x, middle) + sort(middle+1, y) + merge(x, middle, middle+1, y); 
}

int main(){
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        for(int i = 0; i < N; i++) cin >> A[i];
        cout << sort(0, N-1) << endl;
    }    
    return 0;
}
