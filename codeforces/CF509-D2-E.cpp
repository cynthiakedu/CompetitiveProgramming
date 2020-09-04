#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 5e5;
int N;
double arr[mxN + 5], cumL[mxN + 5], cumR[mxN + 5];
string S;
string vowels = "IEAOUY";

double ans = 0, ct;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> S;
    N = S.size();

    for (int i = 1; i <= N; i++) {
        if (vowels.find(S[i - 1]) != string::npos) {
            arr[i] = 1;
            ct++;
        }
    }
    ans = ct * N;

    for (int i = 1; i <= N; i++) {
        cumL[i] = cumL[i - 1] + arr[i];
    }
    for (int i = N; i >= 1; i--) {
        cumR[i] = cumR[i + 1] + arr[i];
    }

    double cum1 = 0, cum2 = 0;
    for (int i = 2; i <= N; i++) {
        cum1 += cumL[i - 1];
        cum2 += cumR[N + 1 - (i - 1)];
        ans -= cum1 / i + cum2 / i;
    }
    cout << setprecision(16) << ans << endl;

    return 0;
}
