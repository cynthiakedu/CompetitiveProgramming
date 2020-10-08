#include <bits/stdc++.h>
using namespace std;

int arr[105] = {};
int N, P;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int j = 0; j < 2; j++) {
        cin >> P;
        for (int i = 0; i < P; i++) {
            int x;
            cin >> x;
            arr[x] = 1;
        }
    }
    int ct = 0;
    for (int i = 1; i <= N; i++) {
        if (arr[i] == 0) ct++;
    }
    cout << (ct ? "Oh, my keyboard!" : "I become the guy.") << endl;

    return 0;
}
