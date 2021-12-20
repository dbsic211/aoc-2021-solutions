#include "bits/stdc++.h"
#define int long long
using namespace std;

signed main() {
    freopen("aoc_in.txt", "r", stdin);
    
    string e;
    cin >> e;
    int sz = 100;
    int f = 7;
    string s[sz * f];
    for(int i=0; i<sz * (f/2); i++) {
        for(int j=0; j<sz * f; j++) s[i] += ".";
    }
    for(int i=sz * (f/2); i<sz * (f/2 + 1); i++) {
        string w;
        for(int j=0; j<sz * (f/2); j++) s[i] += ".";
        cin >> w;
        s[i] += w;
        for(int j=0; j<sz * (f/2); j++) s[i] += ".";
    }
    for(int i=sz * (f/2 + 1); i < sz * f; i++) {
        for(int j=0; j<sz * f; j++) s[i] += ".";
    }
    for(int i=0; i<2; i++) {
        cout << "Enhancement #"<<i<<":\n";
        string wow[sz * f];
        for(int j=0; j<sz*f; j++) {
            for(int k=0; k<sz*f; k++) {
                wow[j] += " ";
            }
        }
        for(int j=0; j<sz*f; j++) {
            for(int k=0; k<sz*f; k++) {
                string t;
                for(int l=-1; l<2; l++) {
                    for(int m=-1; m<2; m++) {
                        int nj = j + l, nk = k + m;
                        if(max(nj, nk) <= sz * f - 1 && min(nj, nk) >= 0) {
                            t += s[nj][nk];
                        }
                        else {
                            t += ".";
                        }
                    }
                }
                int nums = 0;
                for(int l=0; l<9; l++) {
                    nums *= 2;
                    nums += (t[l] == '#');
                }
                wow[j][k] = e[nums];
            }
        }
        for(int j=0; j<sz*f; j++) s[j] = wow[j];
    }
    freopen("aoc_out.txt", "w", stdout);
    int cnt = 0;
    for(int i=sz*(f/2 - 1); i<sz*(f/2 + 2); i++) {
        for(int j=sz*(f/2 - 1); j<sz*(f/2 + 2); j++) {
            cnt += (s[i][j] == '#');
            cout << s[i][j];
        }
        cout << "\n";
    }
    cout << cnt;
}
