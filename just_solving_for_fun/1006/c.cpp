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

    vector<int> a(n);
    for(auto &x : a ) cin >> x;
    vector<int> inver(n);

    if(is_sorted(a.begin() , a.end())){
        cout << 1 << " " << 1 << '\n';
        return;
    }
    int ans_l = 0 , ans_r = 0;
    for(int l = 0 ; l < n;  l++){
        int tmp = a[l] , inv = 0;
        for(int r = l+1 ; r < n;  r ++){
            if(a[r] < tmp) inv ++; 
        }
        inver[l] = inv;
    }

    int ans_l = 0 , ans_r = 0 , max_can_go = INT_MIN;
    for(int i =  0 ; i < n;  i++){
        int tmp = a[i] , num_g = 0 , num_s = 0 ;
        if(inver[i] == 0) continue;
        for(int j = i+1 ; j < n && num_s <= inver[i];  j++){
            if(tmp > a[j]) num_s ++;
            else if(tmp < a[j]) num_g ++;

            int tmp_max = inver[i] + num_g - num_s;
            if(tmp_max > max_can_go){
                max_can_go = tmp_max;
                ans_l = i;
                ans_r = j;
            }
        }
    }
    cout << ans_l + 1 << " " << ans_r+1 << '\n';
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
