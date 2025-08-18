#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> sub(n);
    for(auto &x : sub) cin >> x;

    vector<int> dp(n+1);
    dp[0] = 1;
    for(int i = 1 ; i < n ; i++){
        if(sub[i] > sub[i-1]){
            dp[i] = dp[i-1] + 1;
        }
        else{
            dp[i] = dp[i-1] + i + 1;
        }
    }
    int sum = 0 ;
    for(int i = 0 ; i < n ; i++){
        sum += dp[i];
    }
    cout << sum << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}