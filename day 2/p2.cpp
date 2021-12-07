#include "bits/stdc++.h"
#define int long long
using namespace std;
signed main() {
    freopen("valitest.txt", "r", stdin);
    freopen("valitext.txt", "w", stdout);
    int u=0, r=0;
    string x;
    int y;
    int aim = 0;

    while(cin>>x>>y) {
        if(x == "forward") {
            r += y;
            u += aim * y;
        }
        else if(x == "down") aim += y;
        else aim -= y;
    }
    cout << abs(u) * abs(r) << "\n";
}
