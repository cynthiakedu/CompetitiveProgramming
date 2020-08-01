#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
vector<int> primes;
bool vis[40000];

int p(int a, int b) {
    if (b == 0) return 1;
    int z = p(a, b / 2);
    return z * z * (b % 2 == 1 ? a : 1);
}

int getNum(vector<int> v) {
    int num = 1;
    for (int i = 0; i < v.size(); i += 2) {
        num *= p(v[i], v[i + 1]);
    }
    return num;
}

vector<int> getRep(int num) {
    vector<int> v;
    for (int i = primes.size() - 1; i >= 0; i--) {
        int x = primes[i];
        int ct = 0;
        while (num % x == 0) {
            ct += 1;
            num /= x;
        }
        if (ct > 0) {
            v.push_back(x);
            v.push_back(ct);
        }
    }
    return v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 2; i < 40000; i++) {
        if (vis[i]) continue;
        primes.push_back(i);
        for (int j = i; j < 40000; j += i) {
            vis[j] = true;
        }
    }
    string line;
    while (getline(cin, line)) {
        istringstream sline(line);
        vector<int> v;
        int x;
        while (sline >> x) {
            v.push_back(x);
        }
        if (v[0] == 0) return 0;
        vector<int> ans = getRep(getNum(v) - 1);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");
        }
    }
    return 0;
}
