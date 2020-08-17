#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>

int N;
char arr1[15][15], arr2[15][15];

void rotate(char a[15][15], char (&b)[15][15]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            b[i][j] = a[N - 1 - j][i];
        }
    }
}
void reflect(char a[15][15], char (&b)[15][15]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            b[i][j] = a[N - 1 - i][j];
        }
    }
}

bool isSame(char a[15][15], char b[15][15]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (a[i][j] != b[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void copy(char a[15][15], char (&b)[15][15]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            b[i][j] = a[i][j];
        }
    }
}

void print(char a[15][15]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ct = 0;
    while (cin >> N) {
        ct++;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> arr1[i][j];
            }
            for (int j = 0; j < N; j++) {
                cin >> arr2[i][j];
            }
        }

        char rot90[15][15];
        rotate(arr1, rot90);

        char rot180[15][15];
        rotate(rot90, rot180);

        char rot270[15][15];
        rotate(rot180, rot270);

        char vert[15][15];
        reflect(arr1, vert);

        char vert90[15][15];
        rotate(vert, vert90);

        char vert180[15][15];
        rotate(vert90, vert180);

        char vert270[15][15];
        rotate(vert180, vert270);

        if (isSame(arr2, arr1)) {
            cout << "Pattern " << ct << " was preserved." << endl;
        } else if (isSame(arr2, rot90)) {
            cout << "Pattern " << ct << " was rotated 90 degrees." << endl;
        } else if (isSame(arr2, rot180)) {
            cout << "Pattern " << ct << " was rotated 180 degrees." << endl;
        } else if (isSame(arr2, rot270)) {
            cout << "Pattern " << ct << " was rotated 270 degrees." << endl;
        } else if (isSame(arr2, vert)) {
            cout << "Pattern " << ct << " was reflected vertically." << endl;
        } else if (isSame(arr2, vert90)) {
            cout << "Pattern " << ct << " was reflected vertically and rotated " << 90 << " degrees." << endl;
        } else if (isSame(arr2, vert180)) {
            cout << "Pattern " << ct << " was reflected vertically and rotated " << 180 << " degrees." << endl;
        } else if (isSame(arr2, vert270)) {
            cout << "Pattern " << ct << " was reflected vertically and rotated " << 270 << " degrees." << endl;
        } else {
            cout << "Pattern " << ct << " was improperly transformed." << endl;
        }
    }

    return 0;
}
