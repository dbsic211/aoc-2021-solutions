#include "bits/stdc++.h"
#define int long long
using namespace std;
bool vis[100][100];
int ok = 0;
pair<int, int> dirs[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<string>v;
void dfs(int i, int j) {
    vis[i][j] = 1;
    ok++;
    for(int k=0; k<4; k++) {
        int mi = i + dirs[k].first;
        int mj = j + dirs[k].second;
        if(mi >= 0 && mi < 100 && mj >= 0 && mj < 100) {
            if(!vis[mi][mj] && v[mi][mj] != '9') dfs(mi, mj);
        }
    }
}
signed main() {
    freopen("aoc_in.txt", "r", stdin);
    freopen("aoc_out.txt", "w", stdout);
    string s;
    while(cin>>s)  {
        v.push_back(s);
    }
    int V = v.size(), S = s.size();
    int ib = 1;
    
    priority_queue<int> pq;
    for(int i=0; i<v.size(); i++) {
        for(int j=0; j<s.size(); j++) {
            if(v[i][j] != '9') {
                ok = 0;
                dfs(i, j);
                pq.push(ok);
            }
        }
    }
    for(int i=0; i<3; i++) {
        ib *= pq.top(); pq.pop();
    }
    cout << ib << endl;
}
