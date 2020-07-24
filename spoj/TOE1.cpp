#include <bits/stdc++.h>
using namespace std;
int N;
char arr[4][4];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int n = 0; n < N; n++) {
        int ctx = 0, cto = 0;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> arr[i][j];
                if (arr[i][j] == 'X') ctx++;
                if (arr[i][j] == 'O') cto++;
            }
        }
        if (abs(ctx - cto) > 1 || cto > ctx) {
            cout << "no" << endl;
        } else {
            bool ok = true;
            int ct3 = 0, ct3o = 0;
            for (int i = 0; i < 3; i++) {
                bool tf1 = true, tf1o = true, tf2 = true, tf2o = true;
                for (int j = 0; j < 3; j++) {
                    if (arr[i][j] != 'X') {
                        tf1 = false;
                    }
                    if (arr[i][j] != 'O') {
                        tf1o = false;
                    }
                }
                for (int j = 0; j < 3; j++) {
                    if (arr[j][i] != 'X') {
                        tf2 = false;
                    }
                    if (arr[j][i] != 'O') {
                        tf2o = false;
                    }
                }
                if (tf1) ct3++;
                if (tf2) ct3++;
                if (tf1o) ct3o++;
                if (tf2o) ct3o++;
            }
            if (arr[0][0] == 'X' && arr[1][1] == 'X' && arr[2][2] == 'X') ct3++;
            if (arr[0][2] == 'X' && arr[1][1] == 'X' && arr[2][0] == 'X') ct3++;
            if (arr[0][0] == 'O' && arr[1][1] == 'O' && arr[2][2] == 'O') ct3o++;
            if (arr[0][2] == 'O' && arr[1][1] == 'O' && arr[2][0] == 'O') ct3o++;
            if (ct3 >= 1 && ct3o >= 1) {
                cout << "no" << endl;
            } else {
                cout << "yes" << endl;
            }
        }
    }

    return 0;
}
