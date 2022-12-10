#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
#define ll long long
#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define dbg(c) cout << #c << '=' << c << endl
#define sz(x) (int)(x).size()
int ans;
int x = 1, cycNum = -1;
void check() {
    if (cycNum == 20 || cycNum == 60 || cycNum == 100 || cycNum == 140 || cycNum == 180 || cycNum == 220) ans += cycNum * x;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("day10input.txt", "r", stdin);
    int n = 138;
    // freopen("day10sample.txt", "r", stdin);
    // int n = 146;
    vt<string>g(6);
    string tmp = "";
    for (int i=0;i<40;i++) tmp += "?";
    for (int i=0;i<6;i++) g[i] = tmp;
    for (int i=0;i<n;i++) {
        string type; cin >> type;
        if (type == "noop") {
            cycNum++;
            g[cycNum/40][cycNum%40] = (abs(x-(cycNum%40)) < 2 ? '#' : ' ');
        } else {
            int p; cin >> p;
            cycNum++;
            g[cycNum/40][cycNum%40] = (abs(x-(cycNum%40)) < 2 ? '#' : ' ');
            cycNum++;
            g[cycNum/40][cycNum%40] = (abs(x-(cycNum%40)) < 2 ? '#' : ' ');
            x += p;
        }
    }
    for (int i=0;i<6;i++) cout << g[i] << nl;
}