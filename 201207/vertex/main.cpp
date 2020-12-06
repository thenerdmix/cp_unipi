#include <bits/stdc++.h>
using namespace std;

#define NMAX 100005
vector<int> adjList[NMAX];
vector<int> children[NMAX];
int memo[NMAX];
bool visited[NMAX] = {false};

//building the tree structure rooted at 0 (children[v] contains all the children of vertex v)
void tree(int v){
    visited[v] = true;
    for(auto u: adjList[v])
        if(!visited[u]){
            children[v].push_back(u);
            tree(u);
        }
}

//the idea is that we can take or leave out from the set the vertex v. If we take it, then we have to solve the subproblem for all the trees with root corresponding to one of the children of v. If we don't include v in our set, we have to take all its children vertexes in the set and solve the same problem for the sub-subtrees.
int dp(int v){
    if(memo[v] != -1) return memo[v];
    int take = 1;
    for(auto u: children[v]) take += dp(u);
    int leave = children[v].size();
    for(auto u: children[v])
        for(auto w: children[u])
            leave += dp(w);

    return (memo[v] = min(take, leave));
     
}

int main(){

    int N; cin >> N;

    for(int i = 0; i < N-1; i++){
        int x, y; cin >> x >> y; x--; y--;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }

    fill(memo, memo + NMAX, -1);
    tree(0);

    cout << dp(0) << endl;

    
    return 0;
}
