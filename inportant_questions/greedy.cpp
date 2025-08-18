//https://codeforces.com/contest/2131/problem/E

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

void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int n;
vector<vector<int>> adj;
void solve() {
    int n; cin>> n;
    vector<int> a(n) , b(n);
    
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;
    
    if(a[n-1] != b[n-1]){
        cout << "NO" << '\n';
        return;
    }
    for(int i = n-2 ; i >= 0 ; i--){
        if(a[i] == b[i]) continue;
        
        a[i] = a[i] ^ a[i+1];
        if(a[i] != b[i]){
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';

}
int32_t main() {
    fastio();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
