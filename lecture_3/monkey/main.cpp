#include <bits/stdc++.h>
#define NMAX 100005

using namespace std;
int R[NMAX];
int N;

int look(int k){
    int c = -1; //c is my current position. Ground = -1 
    while(k >= 0){
       if(c == N-1) return true; //victory! 
       if(R[c+1]-((c==-1)?0:R[c]) < k) c++;
       else if(R[c+1]-((c==-1)?0:R[c]) == k){
           c++;
           k--;
       }
       else return false;
    }
    return false;
}

int bin(int start, int end){
    if(start == end) return start;
    int middle = (start+end)/2;
    if(look(middle)) return bin(start, middle);
    else return bin(middle+1, end);
}


int main(){
    
    int T; cin >> T;

    for(int t = 1; t <= T; t++){
        cin >> N;
        //find the maximum element for optimal binary search
        int m = -1; 
        for(int i = 0; i < N; i++){
            cin >> R[i];
            m = max(m, R[i]);
        }
        cout << "Case " << t << ": " <<  bin(0, m) << endl;
    }

    
    return 0;
}
