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
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("day8input.txt", "r", stdin);
    int n = 99;
    vt<string>g(n);
    for (int i=0;i<n;i++) cin >> g[i];
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            char cell = g[i][j];
            int cur = 0, left = 0, right = 0, up = 0, down = 0;
            for (int k=i-1;k>=0;k--) if (g[k][j] >= cell) up = i-k;
            for (int k=i+1;k<n;k++) if (g[k][j] >= cell) down = k-i;
            for (int k=j-1;k>=0;k--) if (g[i][k] >= cell) right = j-k;
            for (int k=j+1;k<n;k++) if (g[i][k] >= cell) left = k-j;
            cur = left * right * up * down;
            // dbg(i); dbg(j); dbg(left); dbg(right); dbg(up); dbg(down);
            ans = max(ans, cur);
        }
    }
    cout << ans << nl;
}