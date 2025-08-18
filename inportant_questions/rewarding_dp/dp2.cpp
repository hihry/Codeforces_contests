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
void solve(int n , int cost , vector<vector<int>> &rew) {
    vector<vector<int>> dp(n , vector<int>(n , 0 ));

    int gloCurMax = INT_MIN , gloSecMax = INT_MIN;
    for(int i = 0 ; i < n;  i ++){
        int curMax = INT_MIN , secMax = INT_MIN;
        for(int j = 0 ; j < n ; j ++){
            if(i == 0) dp[i][j] = rew[i][j];
            else{
                int fromDiffcity = (dp[i - 1][j] == gloCurMax ? gloSecMax : gloCurMax);
                dp[i][j] = rew[i][j] + max(fromDiffcity - cost , dp[i - 1][j]);
            }

            if(dp[i][j] >= curMax){
                secMax = curMax ; 
                curMax = dp[i][j];
            }else if(dp[i][j] >= secMax){
                secMax = dp[i][j];
            }
        }
        gloCurMax = curMax;
        gloSecMax = secMax;
    }

    int ans = 0 ;
    for(int i = 0 ; i < n ; i++){
        ans = max(ans , dp[n-1][i]);
    }
    cout << ans << '\n';

}
int32_t main() {
    fastio();
    int t = 1;
    cin >> t;
    while (t--) {
        int n , cost; cin >> n >> cost;
        vector<vector<int>> rew(n , vector<int>(n));

        for(int i= 0 ; i < n; i++){
            for(int j = 0 ;j < n ; j++){
                cin >> rew[i][j];
            }
        }
        solve(n , cost , rew);
    }

    return 0;
}
