#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>

string s;
int N;
map<string, int> points;
string a, b, c, d, e;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string n1, n2;
        int p;
        cin >> n1 >> b;
        if (b == "likes") {
            cin >> c >> d;
            n2 = c.substr(0, c.size() - 2);
            p = 5;
        } else {
            cin >> c >> d >> e;
            n2 = d.substr(0, d.size() - 2);
            if (b == "posted")
                p = 15;
            else
                p = 10;
        }

        if (n1 == s) {
            points[n2] += p;
        } else if (n2 == s) {
            points[n1] += p;
        } else {
            if (points.count(n1) == 0) points[n1] = 0;
            if (points.count(n2) == 0) points[n2] = 0;
        }
    }
    vector<pair<int, string>> v;
    for (auto p : points) {
        v.push_back({-p.second, p.first});
    }
    sort(v.begin(), v.end());
    for (auto x : v) {
        cout << x.second << endl;
    }

    return 0;
}
