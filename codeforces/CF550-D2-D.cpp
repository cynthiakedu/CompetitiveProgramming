#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int K;
int ct = 0;

vector<int> v1, v2;
vector<ii> ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> K;
    if (K % 2 == 0) {
        cout << "NO" << endl;
        return 0;
    }
    if (K == 1) {
        cout << "YES" << endl;
        cout << "2 1" << endl;
        cout << "1 2" << endl;
        return 0;
    }
    for (int i = 2; i <= K; i++) {
        ans.push_back({1, i});
    }
    for (int i = K + 1; i <= 2 * K - 1; i++) {
        ans.push_back({2, i});
    }
    for (int i = 2 * K; i <= 3 * K - 1; i++) {
        for (int j = i + 1; j <= 3 * K - 1; j++) {
            ans.push_back({i, j});
            ans.push_back({i + K, j + K});
        }
        v2.push_back(i);
        v2.push_back(i + K);
    }
    for (int i = 3; i <= 2 * K - 1; i++) v1.push_back(i);
    vector<int> v3(v1.size());
    int idx = 0;
    for (int i = 0; i < v1.size(); i++) {
        ans.push_back({v1[i], v2[idx]});
        idx++;

        v3[i]++;
        if (i < 3) {
            ans.push_back({v1[i], v2[idx]});
            idx++;
            v3[i]++;
        }
    }
    for (int i = 0; i < v1.size(); i++) {
        for (int j = i + 1; j < v1.size(); j++) {
            if (v3[i] < K - 1 && v3[j] < K - 1) {
                ans.push_back({v1[i], v1[j]});
                v3[i]++;
                v3[j]++;
            }
        }
    }
    cout << "YES" << endl;
    cout << 8 * K - 2 << " " << 2 * (int)ans.size() + 1 << endl;
    cout << 1 << " " << 4 * K << endl;
    for (auto p : ans) {
        cout << p.first << " " << p.second << endl;
        cout << p.first + 4 * K - 1 << " " << p.second + 4 * K - 1 << endl;
    }

    return 0;
}
