#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
const int INF = 2e9;

/* the main idea is that if we have at least one fire spell the set of spells we double is formed by the maximum fire spell + the maximum remaining (number of lightning spell - 1) spells we can double. The set L contains the lightning spells we are not doubling, the set dL contains the lightning spells we are doubling (analog. for the fire spells) */
int main(){
    int N; cin >> N;
    ll sum = 0;

    set<int> L, F, dL, dF;
     
    for(int i = 0; i < N; i++){
        int tp; cin >> tp; int d; cin >> d;
        if(tp == 0){
            if(d > 0){
                F.insert(d);
                sum += d;
            }
            else{
                if(F.erase(-d) > 0) sum += d;
                if(dF.erase(-d) > 0) sum += 2*d;
            }
        }
        else{
            if(d > 0){
                L.insert(d);
                sum += d;
            }
            else{
                if(L.erase(-d) > 0) sum += d;
                if(dL.erase(-d) > 0) sum += 2*d;
            }
        }



        if(!dL.empty()){
            sum -= *dL.begin();
            L.insert(*dL.begin());
            dL.erase(dL.begin());
        }

        if(!dF.empty()){
            sum -= *dF.begin();
            F.insert(*dF.begin());
            dF.erase(dF.begin());
        }

        if(dF.empty() && F.empty()){
            //peculiar case: when we don't have fire spell so the doubled spells are all of type lightning
            while((int)dL.size() < (int)(dL.size() + (int)L.size() - 1)){
                sum += *L.rbegin();
                dL.insert(*L.rbegin());
                L.erase(*L.rbegin());
            }
        }
        else{
            //in this other case we want to have at least a doubled fire spell and the remaining ones choosen from the maximum of the merged set F + L
            if(dF.empty() && dL.size() + L.size() >= 1){
                sum += *F.rbegin();
                dF.insert(*F.rbegin());
                F.erase(*F.rbegin());
            }
            
            while(dF.size() + dL.size() < dL.size() + L.size()){
                int tempF = ((!F.empty()) ? *F.rbegin() : -INF);
                int tempL = ((!L.empty()) ? *L.rbegin() : -INF);
                if(tempF > tempL){
                    sum += *F.rbegin();
                    dF.insert(*F.rbegin());
                    F.erase(*F.rbegin());
                }
                else{
                    sum += *L.rbegin();
                    dL.insert(*L.rbegin());
                    L.erase(*L.rbegin());
                }
            }

        }
        cout << sum << endl;
    }
    return 0;
}
