#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, arr[125][6];
int subs[6];

double getMaxScore(int a, int b) {
    if (2 * a > b) return 500;
    if (4 * a > b) return 1000;
    if (8 * a > b) return 1500;
    if (16 * a > b) return 2000;
    if (32 * a > b) return 2500;
    return 3000;
}

double getScore(int min, int a, int b) {
    if (min == -1) return 0;
    return getMaxScore(a, b) * (1 - 1.0 * min / 250.0);
}
bool can(int x) {
    double scores[3] = {};
    for (int i = 1; i <= 5; i++) {
        int a = subs[i], b = x + N;
        if (arr[1][i] != -1 && arr[2][i] != -1 && arr[1][i] >= arr[2][i]) {
            a += x;
        }
        for (int j = 1; j <= 2; j++) {
            scores[j] += getScore(arr[j][i], a, b);
        }
    }
    return scores[1] > scores[2];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    vector<int> nums;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 5; j++) {
            cin >> arr[i][j];
            if (arr[i][j] != -1) {
                subs[j]++;
            }
        }
    }
    for (int i = 1; i <= 5; i++) {
        for (int j = 0; j < 6; j++) {
            int x = subs[i] * (1 << j);
            nums.push_back(max(x, N));
        }
    }
    sort(nums.begin(), nums.end());
    for (int x : nums) {
        if (can(x - N)) {
            cout << x - N << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
