#include <bits/stdc++.h>
using namespace std;

#define NMAX 1000005

int N, K;
int sx, dx;
int A[NMAX];

//check if there is at least on good segment of length l
bool tenta(int l){
    int k = 0;

    //status[i] counts how many number i we have in the current window
    int status[NMAX];
    fill(status, status+NMAX, 0);
    for(int i = 0; i < l; i++){
        if(status[A[i]] == 0){
            k++;
        }
        status[A[i]]++;
    }

    if(k <= K){
        sx = 1, dx = l; 
        return true; 
    }

    for(int i = 1; i <= N - l; i++){
        if(status[A[i-1]] == 1) k--;
        status[A[i-1]]--;
        if(status[A[i+l-1]] == 0) k++;
        status[A[i+l-1]]++;
        if(k <= K){
            sx = i+1, dx = i+l;
            return true;
        }
    }

    return false;
}

//binary search the answer
int binary(int start, int end){
    if(start == end) return start;
    int middle = (start+end+1)/2;
    if(tenta(middle)){
        return binary(middle, end);
    }
    else{
        return binary(start, middle-1);
    }
}


int main(){
    
    cin >> N >> K;

    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    tenta(binary(1, N));
    cout << sx << " " << dx;

    return 0;
}
