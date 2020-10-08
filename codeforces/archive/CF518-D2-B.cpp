#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
string s, t;
map<char, int> tmap;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s >> t;
    for (auto c : t) tmap[c]++;
    vector<char> S;
    int ans1 = 0, ans2 = 0;

    for (auto c : s) {
        if (tmap[c] > 0) {
            tmap[c]--;
            ans1++;
        } else {
            S.push_back(c);
        }
    }
    for (auto x : S) {
        if (isupper(x) && tmap[tolower(x)] > 0) {
            ans2++;
            tmap[tolower(x)]--;
        }
        if (islower(x) && tmap[toupper(x)] > 0) {
            ans2++;
            tmap[toupper(x)]--;
        }
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}
