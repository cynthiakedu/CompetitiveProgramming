#include <bits/stdc++.h>
using namespace std;
int T;
char arr[35][85];
int sz[35];
int x1, Y1;
bool vis[35][85];
int ct = 0;

void dfs(int x, int y) {
    if (x < 0 || x >= ct || y < 0 || y >= sz[x]) return;
    if (arr[x][y] == 'X') return;
    if (vis[x][y]) return;
    vis[x][y] = true;
    arr[x][y] = '#';
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y - 1);
    dfs(x, y + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string T1;
    getline(cin, T1);
    T = stoi(T1);
    for (int t = 0; t < T; t++) {
        for (int i = 0; i < 35; i++) {
            for (int j = 0; j < 85; j++) {
                arr[i][j] = ' ';
                vis[i][j] = false;
            }
        }
        string sep;
        string s;
        ct = 0;
        while (true) {
            getline(cin, s);
            if (s[0] == '_') {
                sep = s;
                break;
            }
            for (int j = 0; j < s.size(); j++) {
                arr[ct][j] = s[j];
                if (s[j] == '*') {
                    x1 = ct, Y1 = j;
                }
            }
            sz[ct] = s.size();
            ct++;
        }
        dfs(x1, Y1);
        for (int i = 0; i < ct; i++) {
            for (int j = 0; j < sz[i]; j++) {
                cout << arr[i][j];
            }
            cout << endl;
        }
        cout << sep << endl;
    }

    return 0;
}

// 2
// XXXXXXXXX
// X   X   X
// X*      X
// X   X   X
// XXXXXXXXX
// X   X
// X   X
// X   X
// XXXXX
// _____
// XXXXX
// X   X
// X * X
// X   X
// XXXXX
// ____