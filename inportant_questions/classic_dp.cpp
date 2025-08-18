//https://atcoder.jp/contests/dp/tasks/dp_d
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
int help(int n, int i , int remw, vector<int>&w, vector<int>&val , vector<vector<int>> &dp){
    if(i == val.size() || remw == 0) return 0;
    if(remw < 0) return INT_MIN;

    if(dp[i][remw] != -1) return dp[i][j];
    int op1 = val[i] + help(n , i+1 , remw - w[i] ,w , val , dp);
    int op2 = help(n , i+1 , remw-w[i] , w , val , dp);


    return dp[i][remw] = max(op1 , op2);
}
void solve() {
    int n , cap;
    cin >> n >> cap;

    vector<int> w(n) , val(n);
    for(int i = 0; i < n; i++){
        cin >> w[i] >> val[i];
    }
    vector<vector<int>> dp(n , vector<int>(cap + 1 , 0));

    for (int i = 1; i <= n; i++) {            // Loop over items
        for (int j = 0; j <= cap; j++) {      // Loop over capacity
            dp[i][j] = dp[i - 1][j];          // Skip current item
            if (j >= w[i - 1]) {              // If we can take it
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i - 1]] + val[i - 1]);
            }
        }
    }
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

