#include "bits/stdc++.h"
#define int long long
using namespace std;
signed main() {
    freopen("valitest.txt", "r", stdin);
    vector<int> v;
    for(int i=0; i<2000; i++) {
        int x; cin >> x;
        v.push_back(x);
    }
    int ans = 0;
    for(int i=2; i<1999; i++) {
        ans += (v[i-2] + v[i-1] + v[i] < v[i-1] + v[i] + v[i+1]);
    }
    cout << ans << "\n";
}
