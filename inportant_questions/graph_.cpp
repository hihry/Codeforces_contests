//https://codeforces.com/contest/2131/problem/D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define endl '\n'
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pii>
#define YES cout << "YES\n"
#define NO cout << "NO\n"


#ifdef LOCAL
#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

template<typename T> void _print(T x) { cerr << x; }
template<typename T, typename V> void _print(pair<T, V> p) { cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}"; }
template<typename T> void _print(vector<T> v) { cerr << "["; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template<typename T> void _print(set<T> s) { cerr << "{"; for (T i : s) { _print(i); cerr << " "; } cerr << "}"; }

// ========== CONSTANTS ==========
const int INF = 1e18;
const int MOD = 1e9 + 7;  // or 998244353
const int N = 2e5 + 5;

vector<vector<int>> adj;
void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int n;
vector<vector<int>> adj;
void solve() {
    cin >> n;
    adj.resize(n);
    adj.clear();

    vector<int> deg(n , 0);
    for(int i = 1 ; i < n; i ++){
        int u , v; cin>> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v] ++;
    }

    int cnt = 0 ;
    for(int i = 1 ; i <= n ; i++){
        if(deg[i] == 1) cnt ++;
    }

    int mx = INT_MIN;
    for(int i = 1 ; i <= n ; i++){
        int leafCount = 0;
        for(auto &nb : adj[i]){
            if(deg[nb] == 1) leafCount ++;
        }
        mx = max(leafCount , mx);
    }
    cout << cnt - mx << '\n';

}
int32_t main() {
    fastio();
    int t = 1;
    cin >> t;
    while (t--) {
        
    }

    return 0;
}
