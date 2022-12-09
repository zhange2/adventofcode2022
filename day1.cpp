#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
#define ll long long
#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define dbg(c) cout << #c << '=' << c << endl
#define sz(x) (int)(x).size()
int ans, t;
int main()
{
    vt<int>a;
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("day1input.txt", "r", stdin);
    for (int i=0;i<2223;i++) {
        string s;
        getline(cin, s);
        if (sz(s) == 0) a.pb(t), t = 0;
        else {
            t += stoi(s);
        }
    }
    sort(all(a));
    reverse(all(a));
    cout << a[0] + a[1] + a[2] << nl;
}