#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>

vector<int> primes;
bool vis[100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 2; i < 55; i++) {
        if (vis[i]) continue;
        primes.push_back(i);
        for (int j = i; j < 55; j += i) {
            vis[j] = true;
        }
    }
    int ct = 0;
    bool ok = true;
    for (auto x : primes) {
        string s;
        cout << x << endl;
        cin >> s;
        if (s == "yes") ct++;
    }
    if (ct > 1) ok = false;
    for (auto x : primes) {
        if (x * x <= 100) {
            string s;
            cout << x * x << endl;
            cin >> s;
            if (s == "yes") ok = false;
        }
    }
    cout << (!ok ? "composite" : "prime") << endl;
    return 0;
}
