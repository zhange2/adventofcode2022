#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
#define int long long
#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define dbg(c) cout << #c << '=' << c << endl
#define sz(x) (int)(x).size()
map<string, vt<string>>children;
map<string, int>sizes;
vt<string>toVisit;
map<string, bool>vis;
map<string, bool>isDir;
int dfs(string f) {
    int ans = sizes[f];
    vis[f] = 1;
    bool found = 0;
    for (auto x : children) if (x.first == f) found = 1;
    if (!found) return ans;
    for (string v : children[f]) {
        if (!vis[v]) ans += dfs(v);
    }
    return ans;
}
int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("day7input.txt", "r", stdin);
    int n = 1009;
    // freopen("day7sampleinput.txt", "r", stdin);
    // int n = 22;
    string curString = "top";
    isDir[curString] = 1;
    for (int i=0;i<n;i++) {
        // dbg(i);
        string s;
        getline(cin, s);
        if (s[0] == '$') {
            if (s[2] == 'l') {
                isDir[curString] = 1;
            } else {
                if (s[6] == '.') {
                    for (auto x : children) {
                        for (auto v : x.second) {
                            if (v == curString) {
                                curString = x.first;
                            }
                        }
                    }
                }
                else curString = s.substr(5), isDir[curString] = 1;
            }
        }
        else {
            if (s[0] <= '9' && s[0] >= '0') {
                int index = 0;
                while ('0' <= s[index] && s[index] <= '9') index++; index++;
                string tmp = s.substr(0, index-1);
                int size = stoi(tmp);
                string f = s.substr(index);
                sizes[f] = size;
                if (curString != f) children[curString].pb(f);
                dbg(curString);
                isDir[curString] = 1;
            } else {
                string f = s.substr(4); 
                if (curString != f) children[curString].pb(f);
                toVisit.pb(f);
                isDir[f] = 1;
            }
        }
    }
    for (auto x : children) cout << x.second.size() << ' ';
    cout << nl;
    for (auto x : children["rlvcvj"]) cout << x << ' ';
    cout << nl;
    int ans = 0;
    vt<int>dir_sizes;
    for (auto x : children) {
        vis.clear();
        if (!isDir[x.first]) continue;
        dbg(x.first);
        int t = dfs(x.first);
        dir_sizes.pb(t);
        if (t <= 100000) {
            ans += t;
        }
    }
    // Part 2
    sort(all(dir_sizes));
    vis.clear();
    int total = dfs("top");
    dbg(total);
    int minDelete = 30000000 - (70000000 - total);
    dbg(minDelete);
    int ans2 = INT_MAX;
    for (int i=0;i<dir_sizes.size();i++) {
        if (dir_sizes[i] >= minDelete) {
            ans2 = min(ans2, dir_sizes[i]);
        }
    }
    cout << ans << ' ' << ans2 << nl;
}