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

int help(vector<vector<int>> &matrix , int r , int c , int n , int m , int max_ele){
    int cnt = 0;
    for(int i = 0 ; i < m ; i ++){
        if(matrix[r][i] == max_ele) cnt ++;
    }
    for(int j = 0 ;j < n ; j++){
        if(j == r) continue;
        if(matrix[j][c] == max_ele) cnt ++;
    }
    return cnt;
}
void solve() {
    int n , m ; cin >> n >> m;

    int ele = INT_MIN , cnt = 0;
    vector<vector<int>> matrix(n , vector<int>(m));
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j ++){
            bool flag = false;
            cin >> matrix[i][j] ;

            if(ele < matrix[i][j]){
                ele = matrix[i][j];
                flag = true;
            }
            if(flag) cnt = 0;

            if(ele == matrix[i][j]) cnt ++;
        }
    }
    if(cnt > n+m-1 ){
        cout << ele << '\n';
        return ;
    }

    vector<pair<int , int>> p;
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j++){
            if(ele == matrix[i][j]){
                p.push_back({i , j});
            }
        }
    }


    for(int i = 0 ;  i < p.size() - 1 ; i ++){
        int x1 = p[i].first , y1 = p[i].second;
        int x2 = p[i+1].first , y2 = p[i+1].second;

        if(help(matrix , x1 , y2 , n , m , ele) == cnt){
            cout << ele - 1 << '\n';
            return;
        }
        if(help(matrix , x2 , y1 , n , m , ele) == cnt){
            cout << ele - 1 << '\n';
            return;
        }
    }
    cout << ele << '\n';
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

