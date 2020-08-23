#include <bits/stdc++.h>

using namespace std;

int N, M;

vector<int> solve(vector<vector<int>> operations) {
    int a = 0, ct = 0;
    for (auto p : operations) {
        if (p[0] == 1) {
            a = (a + p[1]) % N;
        } else {
            ct++;
            a = (p[1] - a + 2 * N) % N;
        }
    }
    if (ct % 2 == 0) {
        return vector<int>{1, a == 0 ? 0 : N - a};
    } else {
        return vector<int>{2, a};
    }
}