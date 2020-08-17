#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int T, N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        stack<set<string>> S;

        for (int i = 1; i <= N; i++) {
            string type;
            cin >> type;
            if (type == "PUSH") {
                S.push(set<string>{});
                cout << 0 << endl;
            } else if (type == "DUP") {
                set<string> a = S.top();
                S.push(a);
                cout << a.size() << endl;
            } else if (type == "UNION") {
                set<string> a = S.top();
                S.pop();
                set<string> b = S.top();
                S.pop();
                set<string> c;
                // set_union(a.begin(), a.end()
            }
        }
    }

    return 0;
}
