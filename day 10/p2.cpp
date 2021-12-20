#include "bits/stdc++.h"
#define int long long
using namespace std;

signed main() {
    freopen("aoc_in.txt", "r", stdin);
    freopen("aoc_out.txt", "w", stdout);
    string s;
    string o = "([<{";
    vector<int> wow;
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
        int score = 0;
        stack<char> st;
        for(char c : s) {
            string x;
            x += c;
            if(o.find(x) != -1) {
                st.push(c);
            }
            else {
                if(st.empty()) {
                    break;
                }
                else if(st.top() == comp[c]) {
                    st.pop();
                }
                else {
                    while(st.size()) st.pop();
                    break;
                }
            }
        }
        if(st.size()) {
            while(st.size()) {
                score *= 5;
                    if(st.top() == '(') score++;
                    else if(st.top() == '[') score += 2;
                    else if(st.top() == '{') score += 3;
                    else score += 4;
                st.pop();
            }
            //cout << score << "\n";
            wow.push_back(score);
        }
        
    }
    sort(wow.begin(), wow.end());
    cout << wow[wow.size() / 2];
}
