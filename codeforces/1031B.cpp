#include <bits/stdc++.h>
using namespace std;
int N, a[100005], b[100005];
int TA[100005], TB[100005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N - 1; i++)
        cin >> a[i];
    for (int i = 1; i <= N - 1; i++)
        cin >> b[i];

    for (int t = 0; t <= 3; t++) {
        cout << "t " << t << endl;
        bool tf = true;
        TA[N] = t;
        TB[N] = t;
        for (int i = N - 1; i >= 1; i--) {
            TA[i] = a[i] | TA[i + 1];
            if ((TA[i] & TA[i + 1]) != b[i]) {
                tf = false;
                break;
            }
        }
        if (tf) {
            cout << "YES" << endl;
            for (int i = 1; i <= N; i++) {
                cout << TA[i] << (i == N ? "\n" : " ");
            }
            return 0;
        }
    }
    cout << "NO" << endl;

    return 0;
}
