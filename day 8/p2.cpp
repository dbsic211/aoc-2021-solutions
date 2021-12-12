#include "bits/stdc++.h"
#define int long long
using namespace std;
vector<int> v;
int f(int x) {
    int ans = 0;
    for(int y : v) ans+=abs(y-x)*(abs(y-x)+1)/2;
    return ans;
}
int number(string x) {
    sort(x.begin(), x.end());
    if(x == "012456") return 0;
    if(x == "25") return 1;
    if(x == "02346") return 2;
    if(x == "02356") return 3;
    if(x == "1235") return 4;
    if(x == "01356") return 5;
    if(x == "013456") return 6;
    if(x == "025") return 7;
    if(x == "0123456") return 8;
    if(x == "012356") return 9;
    return -1;
}
signed main() {
    freopen("aoc_in.txt", "r", stdin);
    freopen("aoc_out.txt", "w", stdout);
    string s[200][15];
    int ans = 0;
    for(int i=0; i<200; i++) {
        for(int j=0; j<15; j++) {
            cin >> s[i][j];
            for(int k=0; k<s[i][j].size(); k++) {
                if(isalpha(s[i][j][k])) s[i][j][k] = s[i][j][k] - 'a' + '0';
            }
        }
        int p[7] = {0, 1, 2, 3, 4, 5, 6};
        do {
            bool ok = 1;
            int sum = 0;
            for(int j=0; j<15; j++) {
                if(j == 10) continue;
                string t;
                for(int k=0; k<s[i][j].size(); k++) {
                    t += to_string(p[s[i][j][k] - '0']);
                }
                ok &= (number(t) != -1);
                if(j > 10) {
                    sum *= 10;
                    sum += number(t);
                }
            }
            if(ok) {
                ans += sum;
                break;
            }
        }while(next_permutation(p, p+7));
    }
    cout << ans << "\n";
}
