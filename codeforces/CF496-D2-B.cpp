#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N;
string S;
vector<string> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> S;
    for (int i = 0; i < S.size(); i++) {
        int add = 10 - (S[i] - '0');
        string s1 = "";
        for (int j = 0; j < S.size(); j++) {
            int o = S[(i + j) % S.size()] - '0';
            s1 += (char)((o + add) % 10 + '0');
        }
        ans.push_back(s1);
    }
    sort(ans.begin(), ans.end());
    cout << ans[0] << endl;

    return 0;
}
