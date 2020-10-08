#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int T, N, arr[105];
string ans[105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        for (int i = 1; i <= N; i++) cin >> arr[i];

        string s;
        for (int i = 0; i < 55; i++) s += 'a';
        cout << s << endl;

        for (int i = 1; i <= N; i++) {
            string s1 = s;
            s1[arr[i]] = (char)((s[arr[i]] - 'a' + 1) % 26 + 'a');
            cout << s1 << endl;
            s = s1;
        }
    }

    return 0;
}
