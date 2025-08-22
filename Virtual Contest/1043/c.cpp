
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
    int n ; cin >> n;

    if( n == 1) {
        cout << 3 << '\n';
        return;
    }
    else if( n == 2 ) {
        cout << 6 << '\n';
        return;
    }

    int x = 0 , cost = 1 ;
    while(cost < n){
        cost *= 3;
        x ++;
    }
    if(cost == n) {
        cout << (cost * (9 + x))/ 3 << '\n';
        return;
    }
    cost /= 3; x --;
    int ans = 0 , cnt = 0 , actuL_cost = 0 ;
    while((n- ans) >= 3){
        while(cost > (n - ans)) {
            cost /= 3;
            x --;
        }
        ans += cost;
        actuL_cost += ((cost * (9 + x))/ 3) ;
    } 
    cout << actuL_cost + (n - ans == 1 ? 3 : 0) + (n - ans  == 2 ? 6 : 0) << '\n';
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

