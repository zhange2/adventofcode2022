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
int eval(char a, char b) {
    if (b == a + 1 || (a == 'C' && b == 'A')) {
        return 6;
    }
    else if (b == a) {
        return 3;
    } 
    return 0;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("day2input.txt", "r", stdin);
    map<char, int>score;
    score['A'] = 1; score['B'] = 2; score['C'] = 3; score['X'] = 0; score['Y'] = 3; score['Z'] = 6;
    for (int i=0;i<2500;i++) {
        char a, b;
        cin >> a >> b;
        ans += score[b];
        if (b == 'X') {
            ans += score[((a - 'A') + 2) % 3 + 'A'];
        } else if (b == 'Y') {
            ans += score[a];
        } else {
            ans += score[((a - 'A') + 1) % 3 + 'A'];
        }
        dbg(ans);
    }
    cout << ans << nl;
}