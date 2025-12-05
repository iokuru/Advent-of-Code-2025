#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define F first
#define S second
#define INF (int)4e18

constexpr int MOD = 1'000'000'007;

#ifndef ONLINE_JUDGE
  #define debug(x...) cerr << "[" << #x << "] = ", _debug(x)
  void _debug() { cerr << '\n'; }
  template<typename T, typename... V>
  void _debug(T t, V... v){ cerr << t; if(sizeof...(v)) cerr << ", "; _debug(v...); }
#else
  #define debug(...)
#endif

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int mpow(int a, int b, int mod = MOD){
    int r = 1;
    while(b){
        if(b & 1) r = (r * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return r;
}

int modinv(int a, int mod = MOD){
    return mpow(a, mod - 2, mod);
}

template<typename T>
istream& operator>>(istream &in, vector<T> &v){
    for(auto &x: v) in >> x;
    return in;
}

template<typename T>
ostream& operator<<(ostream &out, vector<T> &v){
    for(int i = 0; i < v.size(); i++){
        if(i) out << ' ';
        out << v[i];
    }
    return out;
}

struct DSU {
    vector<int> p, r;
    DSU(int n = 0){ init(n); }
    void init(int n){
        p.resize(n); r.assign(n,0);
        iota(all(p), 0);
    }
    int find(int x){ return p[x] == x ? x : p[x] = find(p[x]); }
    bool unite(int a, int b){
        a = find(a); b = find(b);
        if(a == b) return false;
        if(r[a] < r[b]) swap(a,b);
        p[b] = a;
        if(r[a] == r[b]) r[a]++;
        return true;
    }
};

struct Fenwick {
    int n; vector<int> bit;
    Fenwick(int n = 0){ init(n); }
    void init(int n_){ n = n_; bit.assign(n+1, 0); }
    void add(int i, int v){ for(++i;i<=n;i+=i&-i) bit[i]+=v; }
    int sum(int i){ int r=0; for(++i;i>0;i-=i&-i) r+=bit[i]; return r; }
    int range(int l,int r){ return sum(r)-(l?sum(l-1):0); }
};

void Solve(){
    int n = 4;
    int m = 6;
    vector<pair<int,int>> v(n, pair<int,int>());
    for(int i=0; i<n; i++){
        int a, b;
        char d;
        cin >> a >> d >> b;
        v[i] = {a,b};
    }
    vector<int> a(m);
    for(int i=0; i<m; i++){
        cin >> a[i];
    }
    int res = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(v[j].F <= a[i] && a[i] <= v[j].S){
                res++; 
                break;
            }
        }
    }
    cout << res;
}

int32_t main(){
    fast_io();
    int T = 1;
    //cin >> T;
    while(T--) Solve();
    return 0;
}
