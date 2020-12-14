#include <bits/stdc++.h>
using namespace std;

int main(){

    int N; cin >> N;

    vector<int> d;

    while(N > 0){
        d.push_back(N%10);
        N/=10;
    }

    //we have created a vector with the digits in order
    reverse(d.begin(), d.end());

    bool magic = true;
    int pos = d.size()-1;

    //the "trick" is to realize that no string in the set S = {1, 14, 144} is the suffix of any other string in S. So if we start to check from the last element of the vector we can uniquely tell if the substring [0, pos] ends with a string in S.
    while(pos >= 0){
        if(pos >=1 && d[pos] == 4 && d[pos-1] == 1) pos-=2;
        else if(pos >=2 && d[pos] == 4 && d[pos-1] == 4 && d[pos-2] == 1) pos-=3;
        else if(d[pos] == 1) pos-=1;
        else{
            magic = false;
            break;
        }
    }

    if(magic) cout << "YES";
    else cout << "NO";
    
    return 0;
}
