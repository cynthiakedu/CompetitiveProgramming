#include <bits/stdc++.h>
using namespace std;
int N, arr[100005];
int a = -1, b = -1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    for (int i = 2; i <= N; i++) {
        if (arr[i] < arr[i - 1]) {
            if (b != -1) {
                cout << "no" << endl;
                return 0;
            } else if (a == -1) {
                a = i;
            }
        } else {
            if (a != -1 && b == -1) {
                b = i;
            }
        }
    }
    if (a == -1 && b == -1) {
        cout << "yes" << endl;
        cout << 1 << " " << 1 << endl;
        return 0;
    }
    a -= 1;
    if (b == -1) {
        if (arr[N] > arr[a - 1]) {
            cout << "yes" << endl;
            cout << a << " " << N << endl;
        } else {
            cout << "no" << endl;
        }
        return 0;
    }
    if (arr[a - 1] < arr[b - 1] && arr[a] < arr[b]) {
        cout << "yes" << endl;
        cout << a << " " << b - 1 << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}
