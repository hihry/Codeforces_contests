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
vector<int> dp;
void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int help(int n , string &s , int i ){
    if(i >= n ) return 0;
    if(s[i] == '*') return 0;

    if(dp[i] != -1) return dp[i];
    int op1 = (i < n && s[i] == '@' ? 1 : 0) + help(n , s , i+1) ;
    int op2 = (i < n && s[i] == '@' ? 1 : 0) + help(n , s , i+2);

    return dp[i] = max(op1 , op2);
}
void solve() {
    dp.clear();
    int n; 
    string s;
    cin >> n >> s;

    dp.resize(n+1);
    for(int i = 0 ; i <=  n ; i++)dp[i] = -1;
    cout << help(n , s , 0 );

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
