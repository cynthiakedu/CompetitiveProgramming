#include <bits/stdc++.h>
using namespace std;
vector<char> c = {'R', 'O', 'Y', 'G', 'B', 'I', 'V'};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string ans = "";
    int N;
    cin >> N;
    int amt = N / 7;
    for (int i = 0; i < amt; i++) {
        for (int j = 0; j < 7; j++) {
            ans += c[j];
        }
    }
    if (N % 7 <= 3) {
        for (int j = 0; j < N % 7; j++) {
            ans += c[3 + j];
        }
    } else {
        for (int j = 0; j < N % 7; j++) {
            ans += c[j];
        }
    }
    cout << ans << endl;

    return 0;
}
