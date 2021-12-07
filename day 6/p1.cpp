#include "bits/stdc++.h"
using namespace std;
mt19937_64 rng(122690412);
int main() {
    freopen("valitext.txt", "r", stdin);
    freopen("valitest.txt", "w", stdout);
    string s;
    cin >> s;
    vector<int> v;
    int cur1 = 0;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == ',') {
            v.push_back(cur1);
            cur1 = 0;
        }
        else {
            cur1 *= 10;
            cur1 += s[i] - '0';
        }
    }
    v.push_back(cur1);
    int cur[9] = {};
    for(int i=0; i<v.size(); i++) {
        cur[v[i]]++;
    }
    long long dp[257][9];
    for(int i=0; i<9; i++) dp[0][i] = cur[i];
    for(int i=1; i<=256; i++) {
        for(int j=0; j<9; j++) {
            dp[i][j] = 0;
        }
        for(int j=0; j<8; j++) {
            dp[i][j] += dp[i-1][j+1];
        }
        dp[i][6] += dp[i-1][0];
        dp[i][8] += dp[i-1][0];
    }
    long long sum = 0;
    for(int i=0; i<9; i++) sum += dp[256][i];
    cout << sum << "\n";
}
