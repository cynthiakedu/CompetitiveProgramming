#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int t1, N, M, arr[100005];
string T, P;
int b[100005];

void kmpPreprocess() {
    int i = 0, j = -1;
    b[0] = -1;
    while (i < M) {
        while (j >= 0 && P[i] != P[j]) j = b[j];
        i++;
        j++;
        b[i] = j;
    }
}

bool kmpSearch() {
    int i = 0, j = 0;
    while (i < N) {
        while (j >= 0 && T[i] != P[j]) j = b[j];
        i++;
        j++;
        if (j == M) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t1;
    for (int t = 0; t < t1; t++) {
        T = "";

        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            if (i > 0) {
                T += arr[i] > arr[i - 1] ? "G" : arr[i] < arr[i - 1] ? "L" : "E";
            }
        }
        N--;
        cin >> P;
        M = P.size();
        kmpPreprocess();
        // cout << "PREPROCESS" << endl;
        // for (int i = 0; i < P.size(); i++) cout << b[i] << " ";
        // cout << endl;
        cout << (kmpSearch() ? "YES" : "NO") << endl;
    }
    return 0;
}

// 4
// 5
// 1 2 3 4 1
// GGL
// 5
// 1 2 3 4 1
// GGL
// 5
// 1 2 3 4 1
// GL
// 5
// 1 2 3 4 1
// LG