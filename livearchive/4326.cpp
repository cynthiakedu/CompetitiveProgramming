#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, M;
double nodes[25];
double arr[25][25];
double dp1[(1 << 16)], dp2[(1 << 16)];
double ans;
int ans2;

double solve1(int state) {  //edge
    if (state == 0) return 0;
    if (dp1[state] != -1) return dp1[state];
    for (int i = N - 1; i >= 0; i--) {
        if (state & (1 << i)) {
            double amt = solve1(state ^ (1 << i));
            for (int j = i - 1; j >= 0; j--) {
                if (state & (1 << j)) {
                    int a = i + 1, b = j + 1;
                    amt += arr[a][b];
                }
            }
            return dp1[state] = amt;
        }
    }
    return 0;
}

double solve2(int state) {
    if (state == 0) return 0;
    if (dp2[state] != -1) return dp2[state];
    for (int i = N - 1; i >= 0; i--) {
        if (state & (1 << i)) {
            return dp2[state] = nodes[i + 1] + solve2(state ^ (1 << i));
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while ((cin >> N) && (cin >> M)) {
        if (!N && !M) return 0;
        ans = 2000;
        for (int i = 0; i < (1 << 16); i++) {
            dp1[i] = -1;
            dp2[i] = -1;
        }
        for (int i = 1; i <= N; i++) cin >> nodes[i];
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                cin >> arr[i][j];
            }
        }

        for (int i = 0; i < (1 << N); i++) {
            int ct = 0;
            for (int j = N - 1; j >= 0; j--) {
                if (i & (1 << j)) ct++;
            }
            if (ct == M) {
                double ret = solve1(i) / solve2(i);
                if (ret < ans) {
                    ans = ret;
                    ans2 = i;
                }
            }
        }

        vector<int> v;
        for (int j = 0; j <= N - 1; j++) {
            if (ans2 & (1 << j)) {
                v.push_back(j + 1);
            }
        }
        for (int i = 0; i < v.size(); i++) cout << v[i] << (i == v.size() - 1 ? "\n" : " ");
    }

    return 0;
}
