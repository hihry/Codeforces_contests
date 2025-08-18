
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
    int n , m , L;
    cin >> n >> m >> L ;

    vector<pair<int ,int>> hur(n);
    for(int i = 0 ; i < n;  i++){
        cin >> hur[i].first >> hur[i].second;
    }
    vector<pair<int ,int>> val(m);
    for(int i = 0 ; i < m;  i++){
        cin >> val[i].first >> val[i].second;
    }

    int ans = 0 , power = 1 ;
    int posi = 0;
    for(int i = 0 ; i < m ; i++){
        int left = hur[i].first , right = hur[i].second;

        int jump_req = right - left;
        vector<int> pos;

        int x = posi;
        while(val[x].first < left){
            pos.push_back(val[x].second);
            x++;
        }
        posi = x;
        sort(pos.begin() , pos.end());
        
        int temp_power = 0;
        bool flag = false;
        for(int i = pos.size() - 1; i >= 0 ; i--){
            temp_power += pos[i];
            ans ++;
            if(temp_power + power > jump_req) {
                flag = true;
                break;
            }
        }
        power += temp_power;
        if(left - 1 + power >= L) break;
        if(!flag){
            cout << -1 << ""  << i << '\n';
            return; 
        }
    }
    cout << ans << '\n';

//     2 5 50
// 7 14
// 30 40

// 2 2
// 3 1
// 3 5
// 18 2
// 22 32
//first hurdle ==> 14 - 7 <= jump power , before 7 he has to collect
// if possible to collect more than 14-7 before first hurdle then ok
// second hurdle when start ==> 30 - 40 ,,, if(jump_power > secodn) no take 
// so go to next one and check if possible to get more power ups
// so in that interval the from the largest to take 
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
