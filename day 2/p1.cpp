#include "bits/stdc++.h"
#define int long long
using namespace std;
signed main() {
    freopen("valitest.txt", "r", stdin);
    freopen("valitext.txt", "w", stdout);
    int u=0, r=0;
    string x;
    int y;
    while(cin>>x>>y) {
        if(x == "forward") r += y;
        else if(x == "down") u += y;
        else u -= y;
    }
    cout << abs(u) * abs(r) << "\n";
}
