#include <bits/stdc++.h>
using namespace std;

#define NMAX 100005
vector<int> adjList[NMAX];
vector<int> lr[NMAX];
bool visited[NMAX] = {false};
int C[NMAX];
//colors is the array we are applying mo's algorithm on. colors[i] tells us the color of the i-th occurrence in the euler path.
int colors[2*NMAX];

//we use an euler path to transform the tree in an array. It's easy to define the boundaries of the segments we have to query: all the element between the two occurrences of a vertex are elements of the subtree rooted at that vertex. So l[v][0] e l[v][1] are the indexes of the ends of the segment that represents the subtree rooted at vertex v.
//euler path
int c = 1;
void euler(int start){
    lr[start].push_back(c);
    colors[c] = C[start];
    c++;

    visited[start] = true;
    for(auto v: adjList[start])
        if(!visited[v]) euler(v);

    lr[start].push_back(c);
    colors[c] = C[start];
    c++;
}

//we use a bit to manage frequencies. The elements i of the array we are building the bit tree on counts the number of different colors that appears with frequency i in the current segment.
//bit
int LSOne(int x){ return x&(-x);} 
int ft[NMAX] = {0};

void update(int x, int v){
    for(; x < NMAX && x > 0; x+=LSOne(x)) ft[x] += v;
}

int query(int x){
    if(x >= NMAX) return query(NMAX-1);
    int sol = 0;
    for(; x > 0; x-=LSOne(x)) sol += ft[x];
    return sol;
}

//mo's algorithms
int counter[2*NMAX] = {0};
int counter_l = 0, counter_r = 0;

void add(int p, int v){
    update(counter[colors[p]], -1);
    counter[colors[p]]++;
    update(counter[colors[p]], 1);
}

void remove(int p, int v){
    update(counter[colors[p]], -1);
    counter[colors[p]]--;
    update(counter[colors[p]], 1);
}

int solve(int l, int r, int v){
    while(counter_l < l) remove(counter_l++, v);
    while(counter_l > l) add(--counter_l, v);
    while(counter_r < r) add(++counter_r, v);
    while(counter_r > r) remove(counter_r--, v);
    return query(NMAX-1)-query(v-1);
}

int main(){

    int N, M;
    scanf("%d %d", &N, &M);
    for(int i = 1; i <=N; i++) scanf("%d", &C[i]);

    for(int i = 0; i < N-1; i++){
        int a, b; scanf("%d %d", &a, &b);
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    euler(1);

    colors[0] = 0;

    int L[M], R[M], K[M];

    for(int i = 0; i < M; i++){
        int v; int a, b; scanf("%d %d", &v, &K[i]);
        L[i] = lr[v][0]; R[i] = lr[v][1];
    }

    int bucket_size = floor(sqrt(2*NMAX));
    int no_buckets = 2*NMAX/bucket_size + 1;
    
    vector<pair<int, int>> buckets[no_buckets];

    for(int i = 0; i < M; i++) buckets[L[i]/bucket_size].push_back({R[i], i}); 

    //array to print the answer in the correct order
    int solution[M];
    
    //sorting the buckets according to the trick used in the problem powerful trees
    for(int i = 0; i < no_buckets; i++){
        sort(buckets[i].begin(), buckets[i].end());
        if(i%2 == 1)
            reverse(buckets[i].begin(), buckets[i].end());
        for(auto j: buckets[i])
            solution[j.second] = solve(L[j.second], R[j.second], 2*K[j.second]); //note that we multiply by 2 the value of k because in the euler path each vertex occurs twice
    }

    //printf is SO much faster than cout when you have to print a lot of stuff
    for(int i = 0; i < M; i++)
        printf("%d\n", solution[i]);

    return 0;
}
