#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N;

bool isInside(int x, int y) {
    int d = 4 * (x * x + y * y);
    int d2 = (2 * N - 1) * (2 * N - 1);
    return d <= d2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ct = 0;
    while (cin >> N) {
        ct++;
        if (ct != 1) {
            cout << endl;
        }
        int ans1 = 0, ans2 = 0;
        for (int i = -N; i < N; i++) {
            for (int j = -N; j < N; j++) {
                int ctIn = 0;
                for (int a = 0; a <= 1; a++) {
                    for (int b = 0; b <= 1; b++) {
                        if (isInside(i + a, j + b)) {
                            ctIn++;
                        }
                    }
                }
                if (ctIn == 4) {
                    ans2++;
                } else {
                    if (ctIn >= 1) {
                        ans1++;
                    }
                }
            }
        }
        cout << "In the case n = " << N << ", " << ans1 << " cells contain segments of the circle." << endl;
        cout << "There are " << ans2 << " cells completely contained in the circle." << endl;
    }

    return 0;
}
