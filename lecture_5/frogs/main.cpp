/*atcoder library segment tree
 * https://atcoder.github.io/ac-library/production/document_en/segtree.html
 */

#include <bits/stdc++.h>
#include <cassert>

using namespace std;

const int INF = 1e9;

int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
    public:
        segtree() : segtree(0) {}
        segtree(int n) : segtree(std::vector<S>(n, e())) {}
        segtree(const std::vector<S>& v) : _n(int(v.size())) {
            log = ceil_pow2(_n);
            size = 1 << log;
            d = std::vector<S>(2 * size, e());
            for (int i = 0; i < _n; i++) d[size + i] = v[i];
            for (int i = size - 1; i >= 1; i--) {
                update(i);
            }
        }

        void set(int p, S x) {
            assert(0 <= p && p < _n);
            p += size;
            d[p] = x;
            for (int i = 1; i <= log; i++) update(p >> i);
        }

        S get(int p) {
            assert(0 <= p && p < _n);
            return d[p + size];
        }

        S prod(int l, int r) {
            assert(0 <= l && l <= r && r <= _n);
            S sml = e(), smr = e();
            l += size;
            r += size;

            while (l < r) {
                if (l & 1) sml = op(sml, d[l++]);
                if (r & 1) smr = op(d[--r], smr);
                l >>= 1;
                r >>= 1;
            }
            return op(sml, smr);
        }

        S all_prod() { return d[1]; }

        template <bool (*f)(S)> int max_right(int l) {
            return max_right(l, [](S x) { return f(x); });
        }
        template <class F> int max_right(int l, F f) {
            assert(0 <= l && l <= _n);
            assert(f(e()));
            if (l == _n) return _n;
            l += size;
            S sm = e();
            do {
                while (l % 2 == 0) l >>= 1;
                if (!f(op(sm, d[l]))) {
                    while (l < size) {
                        l = (2 * l);
                        if (f(op(sm, d[l]))) {
                            sm = op(sm, d[l]);
                            l++;
                        }
                    }
                    return l - size;
                }
                sm = op(sm, d[l]);
                l++;
            } while ((l & -l) != l);
            return _n;
        }

        template <bool (*f)(S)> int min_left(int r) {
            return min_left(r, [](S x) { return f(x); });
        }
        template <class F> int min_left(int r, F f) {
            assert(0 <= r && r <= _n);
            assert(f(e()));
            if (r == 0) return 0;
            r += size;
            S sm = e();
            do {
                r--;
                while (r > 1 && (r % 2)) r >>= 1;
                if (!f(op(d[r], sm))) {
                    while (r < size) {
                        r = (2 * r + 1);
                        if (f(op(d[r], sm))) {
                            sm = op(d[r], sm);
                            r--;
                        }
                    }
                    return r + 1 - size;
                }
                sm = op(d[r], sm);
            } while ((r & -r) != r);
            return 0;
        }

    private:
        int _n, size, log;
        std::vector<S> d;

        void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};


//custom defined function for a maximum query segment tree

int op(int a, int b){
    return max(a, b); 
}

int e(){
    return -INF;
}


//for the problem
int p;

//this function f is the monotone function I use to binary search in the segment tree. Segment trees support the operation max_right() in logN time. This operaton (if the function f is well defined and monotone) return the maximum index r such that f(op(a[0], a[1], ... a[r-1])) == true, where op is the binary operation defined on the monoid, in this specific casethe max operation
bool f(int x){
    if(x<p) return true;
    else return false;
}

int main(){
    int N, M; cin >> N >> M;
    int L[N];
    vector<pair<int, int>> v;
    for(int i = 0; i < N; i++){
        int a; cin >> a >> L[i];
        v.push_back({a, i});
    }
    sort(v.begin(), v.end());

    int map[N];
    int count[N];
    fill(count, count + N, 0);
    
    //sort the frogs by position, simple map to remember the original order in need to print the answer.
    for(int i = 0; i < N; i++) map[v[i].second] = i;

    segtree<int, op, e> seg(N);

    for(int i = 0; i < N; i++)
        seg.set(i, v[i].first+L[v[i].second]);
    
    //multiset to save the mosquitoes who remains alive
    multiset<pair<int, int>> m;

    for(int i = 0; i < M; i++){
        int b; cin >> p >> b;
        //l represents the index of the leftmost frog that has a kill range right extremum bigger than the position of the current mosquito
        int l = seg.max_right(0, f);
        //this if checks if the l frog can actually kill the mosquito, equivalently if the kill range left extremum is smaller than the position of the frog
        if(l < N && v[l].first <= p){
            int newb = seg.get(l)+b;
            seg.set(l, newb);
            count[l]++;
            auto it = m.lower_bound({v[l].first, 0});
            //checking if the recently updated frog can kill other mosquitoes
            while(it != m.end()){
                if((*it).first <= newb){
                    newb += (*it).second;
                    seg.set(l, newb);
                    count[l]++;
                    auto tempit = it;
                    ++it;
                    m.erase(tempit);
                }
                else{
                    break;
                }
            }
        }
        else{
            m.insert({p, b});
        }
    }

    for(int i = 0; i < N; i++){
        cout << count[map[i]] << " " << seg.get(map[i])-v[map[i]].first << endl;
     
