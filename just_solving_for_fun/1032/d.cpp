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
void help_d(vector<int> &arr , vector<pair<int ,int>> &perform) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false; // check if any swap happens
        for (int j = 0; j < n - i - 1; j++) {
            // reverse the comparison for descending order
            if (arr[j] < arr[j + 1]) {
                perform.push_back({1 , j+1});
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // already sorted
    }
}
void help_a(vector<int> &arr , vector<pair<int ,int>> &perform , int one) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false; // check if any swap happens
        for (int j = 0; j < n - i - 1; j++) {
            // reverse the comparison for descending order
            if (arr[j] > arr[j + 1]) {
                if(one == 0){
                    perform.push_back({2 , j+1});
                }
                if(one == 1){
                    perform.push_back({1 , j+1});
                }
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // already sorted
    }
}
void solve() {
    int n ; cin >> n;
    vector<int> a(n) , b(n);

    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;

    vector<pair<int , int>>perform;
    help_d(a , perform);
    help_a(b , perform , 0);
    for(int i = 0 ; i < n ; i ++){
        if(a[i] > b[i]){
            perform.push_back({3 , i + 1});
        }
    }

    help_a(a , perform , 1);
    help_a(b, perform , 0);

    cout << perform.size() << '\n';
    for(int i = 0 ; i < perform.size() ; i++){
        int f = perform[i].first , s = perform[i].second;

        cout << f << " " << s << " " << '\n';
    }
    cout << '\n';
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

