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
    freopen("day6input.txt", "r", stdin);
    string s;
    cin >> s;
    for (int i=0;i<s.size()-14;i++) {
        bool ok = 1;
        map<char, int>mp;
        for (int j=0;j<14;j++) {
            if (mp[s[i+j]] > 0) {
                ok = 0;
                break;
            }
            mp[s[i+j]]++;
        }
        mp.clear();
        if (ok) {
            cout << i + 14 << nl;
            break;
        }
    }
}