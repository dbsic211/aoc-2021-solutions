#include "bits/stdc++.h"
#define int long long
using namespace std;
vector<int> v;
int f(int x) {
    int ans = 0;
    for(int y : v) ans+=abs(y-x)*(abs(y-x)+1)/2;
    return ans;
}
signed main() {
    freopen("aoc_in.txt", "r", stdin);
    freopen("aoc_out.txt", "w", stdout);
    string s[200][15];
    int ans = 0;
    for(int i=0; i<200; i++) {
        for(int j=0; j<15; j++) {
            cin >> s[i][j];
        }
        for(int j=11; j<15; j++) {
            if(s[i][j].size() <= 4 ||s[i][j].size() == 7) ans++;
        }
    }
    cout << ans << "\n";
}
