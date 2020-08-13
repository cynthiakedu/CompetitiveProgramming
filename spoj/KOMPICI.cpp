#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
map<string, ll> m;
int N;

string process(string num) {
    set<char> s;
    for (auto c : num) s.insert(c);
    string ret = "";
    for (auto c : s) ret += c;
    return ret;
}

bool isIntersect(string a, string b) {
    set<int> s;
    for (auto c : a) s.insert(c);
    for (auto c : b) {
        if (s.count(c) > 0) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        m[process(s)]++;
    }
    ll ans = 0;
    for (auto p1 : m) {
        for (auto p2 : m) {
            if (isIntersect(p1.first, p2.first)) {
                ans += p1.second * p2.second;
            }
        }
    }
    ans -= N;
    cout << ans / 2 << endl;

    return 0;
}
