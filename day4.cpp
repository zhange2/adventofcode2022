#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
#define ll long long
#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define dbg(c) cout << #c << '=' << c << endl
#define sz(x) (int)(x).size()
/*
2 4 6 8
2 3 4 5
5 7 7 9
2 8 3 7
6 6 4 6
2 6 4 8
*/
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("day4input.txt", "r", stdin);
    int n = 1000, ans = 0;
    vt<pair<int,int>>a(n), b(n);
    for (int i=0;i<n;i++) {
        int e, f, c, d;
        cin >> e >> f >> c >> d;
        a[i] = make_pair(e, f); b[i] = make_pair(c, d);
    }
    for (int i=0;i<n;i++) {
        pair<int,int>l = a[i];
        pair<int,int>r = b[i];
        if ((l.first <= r.first && r.first <= l.second )|| (r.first <= l.first && l.first <= r.second)) {
            ans++;
        }
    }
    cout << ans << nl;
    
}