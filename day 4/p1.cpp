#include "bits/stdc++.h"
#define int long long
using namespace std;
signed main() {
    freopen("aoc_in.txt", "r", stdin);
    freopen("aoc_out.txt", "w", stdout);
    string s;
    cin >> s;
    vector<int> v;
    int cur = 0;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == ',') {
            v.push_back(cur);
            cur = 0;
        }
        else {
            cur *= 10;
            cur += s[i] - 48;
        }
    }
    v.push_back(cur);
    int board[101][6][6];
    for(int i=1; i<=100; i++) {
        for(int j=1; j<=5; j++) {
            for(int k=1; k<=5; k++) {
                cin >> board[i][j][k];
            }
        }
    }
    int win = -1;
    int fin;
    for(int x: v) {
        fin=x;
        for(int i=1; i<=100; i++) {
            for(int j=1; j<=5; j++) {
                for(int k=1; k<=5; k++) {
                    if(board[i][j][k] == x) {
                        board[i][j][k] = -1;
                    }
                }
            }
            for(int j=1; j<=5; j++) {
                bool ok = 1;
                for(int k=1; k<=5; k++) {
                    ok &= (board[i][j][k] == -1);
                }
                if(ok) {
                    win = i;
                    break;
                }
                ok = 1;
                for(int k=1; k<=5; k++) {
                    ok &= (board[i][k][j] == -1);
                }
                if(ok) {
                    win = i;
                    break;
                }
            }
            if(win > -1) break;
        }
        if(win > -1) break;
    }
    int sum = 0;
    for(int i=1; i<=5; i++) {
        for(int j=1; j<=5; j++) {
            sum += (board[win][i][j] == -1 ? 0 : board[win][i][j]);
        }
    }
    cout << sum * fin << endl;
}
