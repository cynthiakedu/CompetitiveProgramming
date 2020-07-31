#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, T;
string s1, s2;
char ans[100005];
vector<int> same, diff;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> T;
    cin >> s1 >> s2;

    for (int i = 0; i < N; i++) {
        if (s1[i] == s2[i])
            same.push_back(i);
        else
            diff.push_back(i);
    }
    int x = (N - T) - same.size();
    if (x > 0 && x > diff.size() / 2) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < min((int)same.size(), N - T); i++) {
        int j = same[i];
        ans[j] = s1[j];
    }
    if (x > 0) {
        for (int i = 0; i < x; i++) {
            int j = diff[i];
            ans[j] = s1[j];
        }
        for (int i = x; i < 2 * x; i++) {
            int j = diff[i];
            ans[j] = s2[j];
        }
    }

    for (int i = 0; i < N; i++) {
        if (ans[i]) continue;
        for (int j = 0; j < 26; j++) {
            char c = (char)('a' + j);
            if (s1[i] != c && s2[i] != c) {
                ans[i] = c;
                break;
            }
        }
    }
    for (int i = 0; i < N; i++) cout << ans[i] << (i == N - 1 ? "\n" : "");
    return 0;
}
