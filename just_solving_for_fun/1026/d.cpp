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

vector<vector<pair<int ,int>>> adj ;
void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

bool help(int n , vector<int>&b , int maxW){
    vector<int> best(n+1 , 0);

    for(int i = 1 ; i <= n ; i++){
        if(i > 1 && best[i] == 0) continue;

        best[i] += b[i];
        best[i] = min(best[i] , maxW);
        for(auto nb : adj[i]){
            int to = nb.first , w = nb.second;

            if(w <= best[i]){
                best[to] = max(best[to] , best[i]);
            }
        }
    }
    return best[n] > 0;
}

void solve() {
    int n , m ;
    cin >> n >> m;

    vector<int> b(n+1 , 0);
    for(int i = 1 ; i <= n ;i++) cin >> b[i];

    adj.clear();
    adj.resize(n+1);
    for(int i = 0 ; i < m; i++){
        int u , v , w;
        cin >> u >> v >> w;
        
        adj[u].push_back({v , w});
    }

    if(!help(n , b , INF)){
        cout << -1 << endl;
        return;
    }
    
    int l = 0, r = INF;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (help(n , b , mid)) {
            r = mid; // try smaller
        } else {
            l = mid; // need bigger
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
