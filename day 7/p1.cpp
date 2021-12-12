#include "bits/stdc++.h"
#define int long long
using namespace std;
vector<int> v;
int f(int x) {
    int ans = 0;
    for(int y : v) ans+=abs(y-x);
    return ans;
}
signed main() {
    freopen("aoc_in.txt", "r", stdin);
    freopen("aoc_out.txt", "w", stdout);
    string str;
    cin >> str;
    int cur = 0;
    for(char c : str) {
        if(c == ',') {
            v.push_back(cur);
            cur=0;;
        }
        else {
            cur=cur*10+c-48;
        }
    }
    v.push_back(cur);;
    int lb = 0, rb = 1e9;
    while(lb < rb) {
        int mid = (lb+rb) >> 1;
        if(f(mid) > f(mid+1)) lb = mid+1;
        else rb = mid;
    }
    cout << f(lb) << "\n";
}
