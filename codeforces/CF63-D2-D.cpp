#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int a, b, c, d, N;
int arr[30], cum[30];
vector<ii> v;
char ans[150][150];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b >> c >> d >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        cum[i] = arr[i] + cum[i - 1];
    }

    for (int i = 0; i < max(b, d); i++) {
        for (int j = 0; j < a + c; j++) {
            ans[i][j] = '.';
        }
    }
    for (int j = 0; j < a + c; j++) {
        int colAmt = j < a ? b : d;
        vector<int> v1;
        for (int i = 0; i < colAmt; i++) {
            v1.push_back(i);
        }
        if (j % 2 != a % 2) {
            reverse(v1.begin(), v1.end());
        }
        for (auto x : v1) {
            v.push_back({x, j});
        }
    }
    for (int i = 1; i <= N; i++) {
        char c = (char)('a' + i - 1);
        for (int j = cum[i - 1]; j < cum[i]; j++) {
            ans[v[j].first][v[j].second] = c;
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < max(b, d); i++) {
        for (int j = 0; j < a + c; j++) {
            cout << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}
