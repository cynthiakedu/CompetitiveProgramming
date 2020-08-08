#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int arr[2][2][3];
bool can[2][2];

bool isCollide(int a[], int b[]) {
    if (a[2] > b[2]) swap(a, b);

    int d1 = (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
    int d2 = (a[2] + b[2]) * (a[2] + b[2]);
    int d3 = (b[2] - a[2]) * (b[2] - a[2]);
    cout << a[0] << " " << a[1] << " " << a[2] << endl;
    cout << b[0] << " " << b[1] << " " << b[2] << endl;
    cout << d1 << " " << d2 << " " << d3 << endl;

    if (d3 < d1 && d1 < d2) return true;
    cout << "false " << endl;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> arr[0][0][0] >> arr[0][0][1] >> arr[0][0][2] >> arr[0][1][2];
    cin >> arr[1][0][0] >> arr[1][0][1] >> arr[1][0][2] >> arr[1][1][2];
    for (int i = 0; i < 2; i++) {
        arr[i][1][0] = arr[i][0][0];
        arr[i][1][1] = arr[i][0][1];
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            can[i][j] = true;
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (isCollide(arr[0][i], arr[1][j])) {
                can[0][i] = false;
                can[1][j] = false;
            }
        }
    }
    int ct = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (can[i][j]) {
                ct++;
            }
        }
    }
    cout << ct << endl;

    return 0;
}
