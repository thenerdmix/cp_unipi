#include <bits/stdc++.h>
using namespace std;

#define MAX_C 1000005 //we have a maximum of 1000000 colors
#define MAX_N 200005

//the answer could be big
typedef long long ll;

ll C[MAX_C];
ll A[MAX_N];
ll ans = 0;
int cursor_l = 0, cursor_r = 0;

void add(int p){
    ans -= C[A[p]]*C[A[p]]*A[p];
    C[A[p]]++;
    ans += C[A[p]]*C[A[p]]*A[p];
}

void remove(int p){
    ans -= C[A[p]]*C[A[p]]*A[p];
    C[A[p]]--;
    ans += C[A[p]]*C[A[p]]*A[p];
}

ll solve(int l, int r){
    while(cursor_l < l) remove(cursor_l++);
    while(cursor_l > l) add(--cursor_l);
    while(cursor_r < r) add(++cursor_r);
    while(cursor_r > r) remove(cursor_r--);
    return ans;
}

int main(){

    fill(C, C+MAX_N, 0);

    int N, T;
    cin >> N >> T;
    int L[T], R[T];

    for(int i = 1; i <= N; i++) cin >> A[i];

    for(int i = 0; i < T; i++) cin >> L[i] >> R[i];

    int bucket_size = floor(sqrt(MAX_N));
    int no_buckets = MAX_N/bucket_size + 1;

    vector<pair<int, int>> buckets[no_buckets];

    for(int i = 0; i < T; i++) buckets[L[i]/bucket_size].push_back({R[i], i}); 

    //we use an epic trick to sort the buckets. Consider the scenario where L and R are uniformely distribuited in the range [0, N]. Then if we sort the buckets one in ascending in order, the following one in descending order, and so on we achieve something like this:
    //     ~       ~       ~     
    //    ~ ~     ~ ~     ~ ~
    //   ~   ~   ~   ~   ~   ~
    //  ~     ~ ~     ~ ~     ~
    // ~       ~       ~       ~
    // instead of this
    //     ~   ~   ~   ~   ~   ~
    //    ~~  ~~  ~~  ~~  ~~  ~~
    //   ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
    //  ~  ~~  ~~  ~~  ~~  ~~  ~
    // ~   ~   ~   ~   ~   ~   ~
    //
    // counting the number of tildes we notice we have reduced by a factor of two the number of movements of the cursor_r with one simple trick!

    //array to print the answer in the correct order
    ll solution[T];
    
    //sorting the buckets according to the trick
    for(int i = 0; i < no_buckets; i++){
        sort(buckets[i].begin(), buckets[i].end());
        if(i%2 == 1)
            reverse(buckets[i].begin(), buckets[i].end());
        for(auto j: buckets[i])
            solution[j.second] = solve(L[j.second], R[j.second]);
    }

    //printf is SO much faster than cout when you have to print a lot of stuff
    for(int i = 0; i < T; i++)
        printf("%I64d\n", solution[i]);

    return 0;
}
