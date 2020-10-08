#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N;
string S;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> S;
    int ans = INT_MAX;
    vector<char> v = {'r', 'b'};
    for (int i = 0; i < 2; i++) {
        int a = 0, b = 0;
        for (int j = 0; j < N; j++) {
            if (S[j] != v[(j + i) % 2]) {
                if (S[j] == 'r')
                    a++;
                else
                    b++;
            }
        }
        ans = min(ans, max(a, b));
    }
    cout << ans << endl;

    return 0;
}
