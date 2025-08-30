
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

void solve() {
    int n;  cin >> n;

    vector<int> a(n + 1);
    for(int i = 1 ; i <= n ; i ++) cin >> a[i];

    int ans = 0 ; 
    for(int i = 2 ; i <= n-1 ; i+=2){

        if(a[i-1] > a[i]) {
            ans += (a[i-1] - a[i]);
            a[i-1] = a[i];
        }
        if(a[i+2] > a[i]){
            ans += (a[i+2] - a[i]);
        }

        if(a[i-1] + a[i+2] > a[i]){
            int dif = (a[i-1] + a[i+2]) - a[i];

            if(a[i+2] - dif >= 0){
                a[i+2] -= (a[i+2] - dif);
            }else if(a[i+2] - dif < 0){
                int cut1 = dif - a[i+2];
                ans += (a[i+2]);
                ans += (cut1);
                a[i+2] = 0;
            }
        }
        cout << ans << '\n';
    }
}
int32_t main() {
    fastio();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
;