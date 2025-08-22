
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

// int val(int x){
//     int cnt = 0 , num = 1; 

//     while(cnt < x){
//         num *= 1;
//         cnt ++;
//     }
//     return num;
// }
// void binary_search(int n , int k){
//     int l = 1 , r = k;

//     int ans;
//     while (l < r){
//         int mid = l + (r - l)/2;

//         if(val(mid) < n) {
//             ans = 
//         }
//     }
// }
void solve() {
    int k ; cin >> k;

    // you can not make more than 1 deals 
    //        3^x (9 + x ) / 3 == cost for buying 3^x
    //       what is minimum number of deals to make?
    //         if( k > n)  then possible 3 * n
    //         k == n === >  3 * k;
    //         k < n ==>   3 ^ (n/2) biary search ?? 
    //         for minimum value binary search of k  ? 

    //          number 12345678910111213141516171811912021222324252627282930
    int l = 1 , r = 1e15;
    // break the problem ??? 

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
