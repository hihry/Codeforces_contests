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
int g(int a, int b){
    
}
bool check(vector<int> &p , vector<int> &s){
    int n = p.size();

    if(n == 1) return p[0] == s[0];
    if(p[n-1] != s[0]) return false;

    for(int i = 0 ; i < n -1 ; i++){
        if(__gcd(p[i] , s[i+1]) != p[n-1]) return false;
        if(p[i + 1] > p[i] || p[i] % p[i+1] != 0) return false;
    }
    for(int i = n-1 ; i > 0 ; i--){
        if(s[i] < s[i-1] || s[i] % s[i-1] != 0) return false;
    }
    for(int i = 0 ; i < n ; i++){
        int ma = max(p[i] , s[i]) , mi = min(p[i] , s[i]);
        if(ma % mi != 0) return false;
    }
    
    return true;

}
void solve() {
    int n; cin >> n;

    vector<int> p(n) , s(n);
    for(int i = 0 ; i < n ; i++) cin >> p[i];
    for(int i = 0 ; i < n ; i++) cin >> s[i];

    cout << (check(p , s) == true ? "YES" : "NO") << '\n';
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
