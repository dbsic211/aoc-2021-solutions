#include "bits/stdc++.h"
#define int long long
using namespace std;
signed main() {
    freopen("aoc_in.txt", "r", stdin);
    freopen("aoc_out.txt", "w", stdout);
    int arr[1000][1000];
    for(int i=0; i<1000; i++) {
        for(int j=0; j<1000; j++) {
            arr[i][j] = 0;
        }
    }
    int a, b, c, d;
    char x;
    while(cin >> a) {
        cin >> x >> b >> x;
        cin >> x >> c >> x;
        cin >> d;
        if(a == c) {
            for(int i=min(b, d); i<=max(b, d); i++) {
                arr[a][i]++;
            }
        }
        else {
            if(b != d) continue;
            for(int i=min(a, c); i<=max(a, c); i++) {
                arr[i][b]++;
            }
        }
    }
    int nas = 0;
    for(int i=0; i<1000; i++) {
        for(int j=0; j<1000; j++) {
            nas += (arr[i][j] > 1);
        }
    }
    cout << nas << endl;
}
