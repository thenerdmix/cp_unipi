#include <bits/stdc++.h>
using namespace std;

void maxMeetings(int start[], int end[], int n) {
    vector<pair<int, int>> v(n, {0, 0});
    //after we sort the meetings by increasing end time it becomes a greedy problem
    for(int i = 0; i < n; i++) v[i] = {end[i], i};
    sort(v.begin(), v.end());

    cout << v[0].second+1 << " ";
    int last = v[0].first;

    for(int i = 1; i < n; i++){
        if(start[v[i].second]> last){
            cout << v[i].second+1 << " ";
            last = v[i].first;
        }
    } 
}

int main(){

    int n; cin >> n;
    int start[n], end[n];
    for(int i = 0; i < n; i++) cin >> start[i];
    for(int i = 0; i < n; i++) cin >> end[i];
    
    maxMeetings(start, end, n);
    
    return 0;
}
