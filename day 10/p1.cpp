#include "bits/stdc++.h"
#define int long long
using namespace std;

signed main() {
    freopen("aoc_in.txt", "r", stdin);
    freopen("aoc_out.txt", "w", stdout);
    string s;
    string o = "([<{";
    int ans = 0;
    map<char, int> mp;
    map<char, char> comp;
    mp[')'] = 3;
    mp[']'] = 57;
    mp['}'] = 1197;
    mp['>'] = 25137;
    comp[')'] = '(';
    comp[']'] = '[';
    comp['}'] = '{';
    comp['>'] = '<';
    while(cin >> s) {
        stack<char> st;
        for(char c : s) {
            string x;
            x += c;
            if(o.find(x) != -1) {
                st.push(c);
            }
            else {
                if(st.empty()) {
                    ans += mp[c];
                    break;
                }
                else if(st.top() == comp[c]) {
                    st.pop();
                }
                else {
                    ans += mp[c];
                    break;
                }
            }
        }
    }
    cout<<ans<<"\n";
}
