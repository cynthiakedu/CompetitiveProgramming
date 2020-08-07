#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>

vector<int> fd(int n) {
    vector<int> v;
    if (n == 1) return {1};
    if (n == 2) return {1, 2};
    if (n == 3) return {1, 1, 3};
    vector<int> v1 = fd(n / 2);
    for (int& x : v1) x *= 2;
    for (int i = 0; i < (n + 1) / 2; i++) v.push_back(1);
    v.insert(v.end(), v1.begin(), v1.end());
    return v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;

    vector<int> ans = fd(N);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");
    }

    return 0;
}
