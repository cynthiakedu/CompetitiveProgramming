#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 3e5;
bool debug = false;
int N, M, arr[mxN + 5];
map<char, int> m = {{'A', 0}, {'T', 1}, {'G', 2}, {'C', 3}};
map<int, char> m2 = {{0, 'A'}, {1, 'T'}, {2, 'G'}, {3, 'C'}};
int ans1, ans2[mxN + 5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ans1 = INT_MAX;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;
            arr[i * M + j] = m[c];
        }
    }

    for (int t = 0; t < 2; t++) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    if (i == j || i == k || j == k) continue;
                    int l = 6 - i - j - k;
                    if (debug) cout << "START i j k l " << i << " " << j << " " << k << " " << l << endl;
                    int temp[mxN + 5], tmpAns = 0;
                    for (int a = 0; a < (t ? M : N); a++) {
                        int tmp2 = INT_MAX, id = -1;
                        for (int t1 = 0; t1 < 2; t1++) {
                            int s = 0;
                            for (int b = 0; b < (t ? N : M); b++) {
                                int n = temp[(t ? b : a) * M + (t ? a : b)];
                                if (a % 2 == 0) {
                                    n = (b % 2 == 0 ? (t1 == 0 ? i : j) : (t1 == 0 ? j : i));
                                    // n = (b % 2 == 0 ? i :j);

                                } else {
                                    n = (b % 2 == 0 ? (t1 == 0 ? k : l) : (t1 == 0 ? l : k));
                                }
                                if (n != arr[(t ? b : a) * M + (t ? a : b)]) s++;
                            }
                            if (s < tmp2) {
                                tmp2 = s;
                                id = t1;
                            }
                        }
                        for (int b = 0; b < (t ? N : M); b++) {
                            int coord = (t ? b : a) * M + (t ? a : b);
                            int& n = temp[coord];
                            if (a % 2 == 0) {
                                n = (b % 2 == 0 ? (id == 0 ? i : j) : (id == 0 ? j : i));
                            } else {
                                n = (b % 2 == 0 ? (id == 0 ? k : l) : (id == 0 ? l : k));
                            }
                            if (debug) cout << "temp " << a << " " << b << " " << coord << " " << n << " " << temp[coord] << " " << arr[coord] << endl;
                            if (n != arr[coord]) tmpAns++;
                        }
                    }
                    if (tmpAns < ans1) {
                        ans1 = tmpAns;
                        if (debug) cout << "ACTUAL " << tmpAns << endl;
                        for (int a = 0; a < (t ? M : N); a++) {
                            for (int b = 0; b < (t ? N : M); b++) {
                                int coord = (t ? b : a) * M + (t ? a : b);
                                if (debug) cout << "actual "
                                                << " " << a << " " << b << " " << coord << " " << m2[temp[coord]] << endl;
                                ans2[coord] = temp[coord];
                            }
                        }
                    }
                }
            }
        }
    }
    if (debug) cout << ans1 << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << m2[ans2[i * M + j]] << (j == M - 1 ? "\n" : "");
        }
    }

    return 0;
}
