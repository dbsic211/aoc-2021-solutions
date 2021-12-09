#include "bits/stdc++.h"
using namespace std;
int main() {
    freopen("aoc_in.txt", "r", stdin);
    freopen("aoc_out.txt", "w", stdout);
    string s;
    vector<string> v;
    while(cin >> s) v.push_back(s);
    long long ans = 0;
    long long ans2 = 0;
    int cnt[2][s.size()];
    for(int i=0; i<2; i++) {
        for(int j=0; j<s.size(); j++) {
            cnt[i][j] = 0;
        }
    }
    for(int i=0; i<v.size(); i++) {
        for(int j=0; j<s.size(); j++) {
            if(v[i][j] == '0') cnt[0][j]++;
            else cnt[1][j]++;
        }
    }
    for(int i=0; i<s.size(); i++) {
        if(cnt[0][i] < cnt[1][i]) ans += (1<<(s.size() - 1 - i));
        if(cnt[0][i] > cnt[1][i]) ans2 += (1<<(s.size() - 1 - i));
    }
    cout << ans * ans2 << "\n";
}
