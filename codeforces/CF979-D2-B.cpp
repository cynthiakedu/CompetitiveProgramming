#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N;
string a, b, c;
map<int, int> m1, m2, m3;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    cin >> a >> b >> c;
    for (auto x : a) m1[x]++;
    for (auto x : b) m2[x]++;
    for (auto x : c) m3[x]++;

    int ct1 = 0, ct2 = 0, ct3 = 0;
    for (auto p : m1) ct1 = max(ct1, p.second);
    for (auto p : m2) ct2 = max(ct2, p.second);
    for (auto p : m3) ct3 = max(ct3, p.second);
    if (ct1 == a.size()) {
        ct1 = N != 1 ? a.size() : a.size() - 1;
    } else {
        ct1 = min((int)a.size(), ct1 + N);
    }
    if (ct2 == b.size()) {
        ct2 = N != 1 ? b.size() : b.size() - 1;
    } else {
        ct2 = min((int)b.size(), ct2 + N);
    }
    if (ct3 == c.size()) {
        ct3 = N != 1 ? c.size() : c.size() - 1;
    } else {
        ct3 = min((int)c.size(), ct3 + N);
    }

    if (ct1 > ct2 && ct1 > ct3) {
        cout << "Kuro" << endl;
    } else if (ct2 > ct1 && ct2 > ct3) {
        cout << "Shiro" << endl;
    } else if (ct3 > ct1 && ct3 > ct2) {
        cout << "Katie" << endl;
    } else {
        cout << "Draw" << endl;
    }

    return 0;
}
