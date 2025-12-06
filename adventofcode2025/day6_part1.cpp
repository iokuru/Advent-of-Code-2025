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

void readIntVector(string &s, vector<int> &v) {
    stringstream ss(s);
    int x;
    while (ss >> x) v.push_back(x);
}

void readCharVector(string &s, vector<char> &v) {
    stringstream ss(s);
    char ch;
    while (ss >> ch) v.push_back(ch);
}

void Solve() {
    string s1, s2, s3, s4, s5;

    getline(cin, s1);
    getline(cin, s2);
    getline(cin, s3);
    getline(cin, s4);
    getline(cin, s5);

    vector<int> a, b, c, d;
    vector<char> e;

    readIntVector(s1, a);
    readIntVector(s2, b);
    readIntVector(s3, c);
    readIntVector(s4, d);
    readCharVector(s5, e);

    int res = 0;

    for(int i=0; i<1000; i++){
        if(e[i] == '+'){
            res += (a[i] + b[i] + c[i] + d[i]);
        }else{
            res += (a[i] * b[i] * c[i] * d[i]);   
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
