#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 10e5;
int N;
string arr[mxN + 5];
map<int, int> m, m2;
int seen[27];
bool hasIn[27];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= N; i++) {
        string s = arr[i];
        bool temp[27] = {};
        for (int j = 0; j < s.size(); j++) {
            int c = s[j] - 'a';
            if (temp[c]) {
                cout << "NO" << endl;
                return 0;
            }
            seen[c] = 1;
            temp[c] = true;
        }
        for (int j = 1; j < s.size(); j++) {
            int a = s[j - 1] - 'a', b = s[j] - 'a';
            if (m.count(a) > 0 && m[a] != b) {
                cout << "NO" << endl;
                return 0;
            }
            if (m2.count(b) > 0 && m2[b] != a) {
                cout << "NO" << endl;
                return 0;
            }
            m2[b] = a;
            m[a] = b;
            hasIn[b] = true;
        }
    }
    string ans = "";
    for (int i = 0; i < 26; i++) {
        int c = i;
        if (seen[i] != 1) continue;  //already processed by others
        if (hasIn[c]) continue;
        ans += (char)(c + 'a');
        seen[c] = 2;
        while (m.count(c) > 0) {
            c = m[c];
            ans += (char)(c + 'a');
            seen[c] = 2;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (seen[i] == 1) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << ans << endl;

    return 0;
}
