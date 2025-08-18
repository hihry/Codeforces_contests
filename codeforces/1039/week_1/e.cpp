#include <bits/stdc++.h>
using namespace std;
#define int long long

pair<bool , pair<int , int>> check(vector<int> &a ,int mid , int n , int k){
    vector<int> tmp(n) , prefix_sum(n , 0);
    for(int i = 0 ;i < n ; i++ ){
        if(a[i] >= mid) tmp[i] = 1;
        else tmp[i] = -1;
    }

    prefix_sum[0] = tmp[0];
    for(int i = 1 ; i < n ; i++){
        prefix_sum[i] = prefix_sum[i-1] + tmp[i];
    }

    int minl_pos = 0 , mn = 0 ;
    for(int i = k-1 ; i < n ; i++){
        if(prefix_sum[i] - mn >= 0) {
            return {true , {minl_pos , i}};
        }
        
        if(mn > prefix_sum[i - (k-1)]){
            mn = prefix_sum[i - (k-1)];
            minl_pos = i - (k-1);
        }
    }
    return {false , { -1 , -1}};
    
}

void solve() {
    int n , k;
    cin >> n >> k;

    vector<int> a(n);
    for(auto &x : a) cin >> x;

    int l = 0 , r = n-1 , md = 0;
    int L = -1 , R = -1;

    while(l <= r){
        int mid = (l+r)/2;

        pair<bool , pair<int , int>>ch = check(a , mid , n , k);

        if(ch.first){
            if(md < mid){
                md = mid;
                L = ch.second.first;
                R = ch.second.second;
            }
            l = mid+1;
        }
        else{
            R = mid - 1;
        }
    }
    cout << md << " " << L+1 << " " << R+ 1 << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}