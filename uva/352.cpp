#include <bits/stdc++.h>
using namespace std;
int N;
int arr[30][30];
vector<int> d = {-1, 0, 1};

void visit(int x, int y) {
    arr[x][y] = 0;
    for (auto dx : d) {
        for (auto dy : d) {
            int x1 = x + dx, y1 = y + dy;
            if (0 <= x1 && x1 < N && 0 <= y1 && y1 < N && arr[x1][y1]) {
                visit(x1, y1);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 0;

    while (cin >> N) {
        t++;
        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < 30; j++) {
                arr[i][j] = 0;
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                char c;
                cin >> c;
                arr[i][j] = c - '0';
            }
        }
        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (arr[i][j]) {
                    ans++;
                    visit(i, j);
                }
            }
        }
        cout << "Image number " << t << " contains " << ans << " war eagles." << endl;
    }

    return 0;
}
