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
    freopen("day3input.txt", "r", stdin);
    int n = 300, ans = 0;
    for (int i=0;i<n/3;i++) {
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        set<char>st;
        int tmp = 0;
        for (char c : s1) {
            if (st.find(c) == st.end() && count(all(s2), c) > 0 && count(all(s3), c) > 0) {
                tmp += ((c >= 'A' && c <= 'Z') ? c - 'A' + 27 : c - 'a' + 1);
                st.insert(c);
            }
        }
        dbg(tmp);
        ans += tmp;
    }
    cout << ans << nl;
}