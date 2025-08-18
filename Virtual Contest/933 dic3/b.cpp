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
bool is_valid(string &s){
    for(int i = 0 ; i < s.size() ; i++){
        int num = s[i] - '0';

        if(num != 0) return false;
    }
    return true;
}
void solve() {
    int n;
    cin >> n;

    string s = "";
    for(int i = 0 ; i < n ; i++){
        int x;
        cin >> x;
        s += to_string(x);
    }

    bool flag = true;
    
        for(int i = 0 ; i < n - 2 ; i ++){
            int fi = s[i] - '0', se = s[i+1] - '0', th = s[i+2] - '0';
            if(fi == 0 || se == 0 || th == 0) continue;
            if(fi > th){
                flag = false;
                break;
            }
            if(se - (fi * 2) >= 0){
                s[i]   = '0' + 0;
                s[i+1] = '0' + (se - (fi * 2));
                s[i+2] = '0' + (th - fi);
            }
        }
    
    if(!flag) cout << "NO" << '\n';
    else {
        if(is_valid(s)) cout << "YES" << '\n';
        else cout << "NO" << '\n';
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
