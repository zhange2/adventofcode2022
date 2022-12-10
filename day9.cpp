#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
#define ll long long
#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define dbg(c) cout << #c << '=' << c << endl
#define sz(x) (int)(x).size() 
pair<int,int> tails[10];
set<pair<int,int>>st;
bool touch(int i) {
    assert(i != 0);
    if (tails[i].first != tails[i-1].first && tails[i].second != tails[i-1].second) {
        if (abs(tails[i].first - tails[i-1].first) == 1 && abs(tails[i].second - tails[i-1].second) == 1) return true;
        return false;
    }
    else {
        if (tails[i].first == tails[i-1].first) return abs(tails[i].second - tails[i-1].second) <= 1;
        return abs(tails[i].first - tails[i-1].first) <= 1;
    }
}
void upd(int i) {
    assert(i != 0);
    if (tails[i].first != tails[i-1].first && tails[i].second != tails[i-1].second) {
        if (tails[i].first < tails[i-1].first) tails[i].first++;
        if (tails[i].first > tails[i-1].first) tails[i].first--;
        if (tails[i].second < tails[i-1].second) tails[i].second++;
        if (tails[i].second > tails[i-1].second) tails[i].second--;
    } else if (tails[i].second != tails[i-1].second) { //tails[i].second == tails[i-1].second
        if (tails[i].second < tails[i-1].second) tails[i].second++;
        else tails[i].second--;
    }
    else { //tails[i].first == tails[i-1].first
        if (tails[i].first < tails[i-1].first) tails[i].first++;
        else tails[i].first--;
    }
    if (i == 9) st.insert(tails[i]);
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("day9input.txt", "r", stdin);
    int n = 2000;
    for (int i=0;i<10;i++) tails[i].first = 0, tails[i].second = 0;
    map<char, pair<int,int>>d; d['L'] = make_pair(0, -1); d['R'] = make_pair(0, 1); d['D'] = make_pair(1, 0); d['U'] = make_pair(-1, 0);
    st.insert(make_pair(0, 0));
    for (int _=0;_<n;_++) {
        char dir;
        int x;
        cin >> dir >> x;
        for (int j=0;j<x;j++) {
            tails[0].first += d[dir].first, tails[0].second += d[dir].second;
            for (int i=1;i<10;i++) if (!touch(i)) upd(i);
        }
    }
    cout << st.size() << nl;
}