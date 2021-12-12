#include "bits/stdc++.h"
#define int long long
using namespace std;
signed main() {
    freopen("aoc_in.txt", "r", stdin);
    freopen("aoc_out.txt", "w", stdout);
    string s[1000];
    for(int i=0; i<1000; i++){
        cin >> s[i];
    }
    string S, T;
    bool gg[1000];
    for(int i=0; i<1000; i++) gg[i] = 0;
    int rem = 1000;
    for(int i=0; i<12; i++) {
        int cnt[2] = {0, 0};
        for(int j=0; j<1000; j++) {
            if(!gg[j]) {
                cnt[s[j][i] - '0']++;
            }
        }
        if(cnt[0] <= cnt[1]) { // keep 1
            for(int j=0; j<1000; j++) {
                if(s[j][i] == '0' && !gg[j]) {
                    gg[j] = 1;
                    rem--;
                }
                if(rem == 1) {
                    for(int j=0; j<1000; j++) {
                        if(!gg[j]) S = s[j];
                    }
                    break;
                }
            }
        }
        else {
            for(int j=0; j<1000; j++) {
                if(s[j][i] == '1' && !gg[j]) {
                    gg[j] = 1;
                    rem--;
                }
                if(rem == 1) {
                    for(int j=0; j<1000; j++) {
                        if(!gg[j]) S = s[j];
                    }
                    break;
                }
            }
        }
        if(rem == 1) {
            break;
        }
    }
    rem =1000;
    for(int i=0; i<1000; i++) gg[i] = 0;
    for(int i=0; i<12; i++) {
        int cnt[2] = {0, 0};
        for(int j=0; j<1000; j++) {
            if(!gg[j]) {
                cnt[s[j][i] - '0']++;
            }
        }
        if(cnt[0] <= cnt[1]) { // keep 0
            for(int j=0; j<1000; j++) {
                if(s[j][i] == '1' && !gg[j]) {
                    gg[j] = 1;
                    rem--;
                }
                if(rem == 1) {
                    for(int j=0; j<1000; j++) {
                        if(!gg[j]) T = s[j];
                    }
                    break;
                }
            }
        }
        else {
            for(int j=0; j<1000; j++) {
                if(s[j][i] == '0' && !gg[j]) {
                    gg[j] = 1;
                    rem--;
                }
                if(rem == 1) {
                    for(int j=0; j<1000; j++) {
                        if(!gg[j]) T = s[j];
                    }
                    break;
                }
            }
        }
        if(rem == 1) {
            break;
        }
    }
    int a1 = 0, a2 = 0;
    for(int i=0; i<12; i++) {
        if(S[i] == '1') a1 += (1<<(11-i));
        if(T[i] == '1') a2 += (1<<(11-i));
    }
    cout << a1 * a2 << "\n";
}
