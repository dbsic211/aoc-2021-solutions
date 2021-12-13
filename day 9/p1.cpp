#include "bits/stdc++.h"
#define int long long
using namespace std;
signed main() {
    freopen("aoc_in.txt", "r", stdin);
    freopen("aoc_out.txt", "w", stdout);
    vector<string>v;
    string s;
    while(cin>>s)  {
        v.push_back(s);
    }
    int ib = 0;
    pair<int, int> dirs[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for(int i=0; i<v.size(); i++) {
        for(int j=0; j<s.size(); j++) {
            bool ok = 1;
            for(int k=0; k<4; k++) {
                int mi = i + dirs[k].first;
                int mj = j + dirs[k].second;
                if(mi >= 0 && mi < v.size() && mj >= 0 && mj < s.size()) {
                    ok &= (v[i][j] < v[mi][mj]);
                }
            }
            if(ok) {
                ib += 1 + v[i][j] - '0';
            }
        }
    }
    cout << ib << endl;
}
