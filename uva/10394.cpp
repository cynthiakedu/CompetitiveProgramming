#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int S;
bool vis[20000000];
set<int> primes;
vector<ii> twins;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 2; i < 20000000; i++) {
        if (!vis[i]) primes.insert(i);
        for (int j = i; j < 20000000; j += i) {
            vis[j] = true;
        }
    }
    for (auto x : primes) {
        if (primes.count(x + 2) > 0) {
            twins.push_back(ii(x, x + 2));
        }
    }
    while (cin >> S) {
        cout << "(" << twins[S - 1].first << ", " << twins[S - 1].second << ")" << endl;
    }

    return 0;
}
