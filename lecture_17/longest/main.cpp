// function to find longest common subsequence

#define MAXN 105
int memo[MAXN][MAXN];

//recursive dp with memoization, for each step we have three possible choices:
//  1) if the last letters are the same, we could use this last letter to form the common substring
//  2) we discard the last letter from s1
//  3) we discard the last letter from s2

int rec(int xpos, int ypos, string s1, string s2){
    if(xpos == -1) return 0;
    if(ypos == -1) return 0;
    
    if(memo[xpos][ypos] != -1) return memo[xpos][ypos];
    
    int m = -1;
    if(s1[xpos] == s2[ypos]) m = rec(xpos-1, ypos-1, s1, s2) + 1;
    return (memo[xpos][ypos] = max(m, max(rec(xpos-1, ypos, s1, s2), rec(xpos, ypos-1, s1, s2))));
}

int lcs(int x, int y, string s1, string s2){
    
    for(int i = 0; i < MAXN; i++)
        for(int j = 0; j < MAXN; j++)
            memo[i][j] = -1;

    return rec(x-1, y-1, s1, s2);
}
