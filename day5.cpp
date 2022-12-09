#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
#define ll long long
#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define dbg(c) cout << #c << '=' << c << endl
#define sz(x) (int)(x).size()

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("day5input.txt", "r", stdin);
    int n = 504, ans = 0;
    vt<char>a[9];
    for (int i=0;i<8;i++) {
        string s; getline(cin, s);
        for (int j=0;j<s.size();j++) {
            if (s[j] <= 'Z' && s[j] >= 'A') {
                a[j].pb(s[j]);
            }
        }
    }
    for (int i=0;i<9;i++) {
        for (char c : a[i]) cout << c;
        cout << nl;
    }
    for (int i=0;i<n;i++) {
        int num, from, to;
        cin >> num >> from >> to;
        from--, to--;
        vt<char>b;
        for (int j=0;j<num;j++) {
            b.pb(a[from][0]);
            cout << a[from][0] << nl;
            a[from].erase(a[from].begin());
        }
        reverse(all(b));
        for (char c : b) {
            a[to].insert(a[to].begin(), c);
        }
    }
    for (int i=0;i<9;i++) {
        if (a[i].size() > 0) {
            char c = a[i][0];
            cout << c;
        }
    }
}