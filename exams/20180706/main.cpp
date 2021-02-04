#include <bits/stdc++.h>
using namespace std;
#define NMAX 505
#define D 4

int N, M;
int cum_mat[NMAX][NMAX][D];

bool inrange(int r, int c){
    if(r>=0 && r < N && c >= 0 && c < M) return true;
    return false;
}

int query(int r1, int c1, int r2, int c2, int dir){
    if(r1>r2||c1>c2) return 0;
    if(r1==0 && c1==0) return cum_mat[r2][c2][dir];
    if(r1==0) return cum_mat[r2][c2][dir]-cum_mat[r2][c1-1][dir];
    if(c1==0) return cum_mat[r2][c2][dir]-cum_mat[r1-1][c2][dir];
    else return cum_mat[r2][c2][dir]-cum_mat[r2][c1-1][dir]-cum_mat[r1-1][c2][dir]+cum_mat[r1-1][c1-1][dir];
}

int main(){

    cin >> N >> M;
    string table[N];

    for(int i = 0; i < N; i++)
        cin >> table[i];

    int count[N][M][D];

    //0 right, 1 left, 2 down, 3 up
    int col[D] = {1, -1, 0, 0};
    int row[D] = {0, 0, 1, -1};

    for(int dir = 0; dir < D; dir++)
        for(int r = 0; r < N; r++)
            for(int c = 0; c < M; c++){
                if(table[r][c] == '.' && inrange(r+row[dir], c+col[dir]) && table[r+row[dir]][c+col[dir]] =='.') count[r][c][dir] = 1;
                else count[r][c][dir] = 0;
            }

    for(int dir = 0; dir < D; dir++)
        for(int r = 0; r < N; r++)
            for(int c = 0; c < M; c++){
                if(r==0 && c==0) cum_mat[r][c][dir] = count[r][c][dir];
                else if(r==0) cum_mat[r][c][dir] = cum_mat[r][c-1][dir]+count[r][c][dir];
                else if(c==0) cum_mat[r][c][dir] = cum_mat[r-1][c][dir]+count[r][c][dir];
                else cum_mat[r][c][dir] = cum_mat[r-1][c][dir]+cum_mat[r][c-1][dir]-cum_mat[r-1][c-1][dir]+count[r][c][dir];
            }

    
    int T;
    cin >> T;
    for(int t = 0; t < T; t++){
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--; c1--; r2--; c2--;
        cout << (query(r1, c1, r2, c2-1, 0)+query(r1, c1+1, r2, c2, 1)+query(r1, c1, r2-1, c2, 2)+query(r1+1, c1, r2, c2, 3))/2 << endl;
    }

    
    return 0;
}
