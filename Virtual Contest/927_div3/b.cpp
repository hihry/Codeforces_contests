
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
int power(int x, int y, int p)
{
    int res = 1;
    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int modInverse(int a, int m) { return power(a, m - 2, m); }

int modDiv(int a, int b, int m)
{
    a = a % m;
    int inv = modInverse(b, m);
    return (inv * a) % m;
}

void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for(auto &x : a) cin >> x;

    int year = a[0];
    for(int i = 1 ; i < n ; i++){
        int y = ((year + 1) / a[i] ) ;
        
        if(((year + 1) % a[i]) != 0) y += 1; 

        year = a[i]*y;
    }
    cout << year << '\n';
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

