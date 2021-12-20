#include "bits/stdc++.h"
#define int long long
using namespace std;

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    return a.second > b.second;
}
signed main() {
    freopen("aoc_in.txt", "r", stdin);
    freopen("aoc_out.txt", "w", stdout);
    int s[10][10];
    for(int i=0; i<10; i++) {
        string t;
        cin >> t;
        for(int j=0; j<10; j++) {
            s[i][j] = t[j] - '0';
        }
    }
    int step = 1e9;
    int flash = 0;
    pair<int, int> dirs[8] = {{-1,0},{-1,1},{-1,-1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    int cnt= 0;
    while(step--) {
        int ok[10][10];
        for(int i=0; i<10; i++) {
            for(int j=0; j<10; j++) {
                ok[i][j] = 0;
            }
        }
        for(int i=0; i<10; i++) {
            for(int j=0 ;j<10; j++) {
                s[i][j]++;
            }
        }
        int now = 0;
        for(int h=0; h<20; h++) {
            for(int i=0; i<10; i++) {
                for(int j=0; j<10; j++) {
                    if(s[i][j] > 9 && ok[i][j] == 0) {
                        ok[i][j] = 1;
                        flash++;
                        now++;
                        for(int k=0; k<8; k++) {
                            int newr = i + dirs[k].first;
                            int newc = j + dirs[k].second;
                            if(max(newr, newc) <= 9 && min(newr, newc) >= 0) {
                                s[newr][newc]++;
                            }
                        }
                    }
                }
            }
        }
        for(int i=0; i<10; i++) {
            for(int j=0; j<10; j++) {
                if(s[i][j] > 9) s[i][j] = 0;
            }
        }
        cnt++;
        if(now == 100) {
            cout << cnt << endl;
            return 0;
        }
    }
    cout << flash << endl;
}
