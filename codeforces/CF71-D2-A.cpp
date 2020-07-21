#include <bits/stdc++.h>
using namespace std;
int N;
string S;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S;
        if (S.size() <= 10) {
            cout << S << endl;
        } else {
            char l = S[0], r = S[S.size() - 1];
            cout << l << S.size() - 2 << r << endl;
        }
    }

    return 0;
}
