#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
ll N, P;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        cin >> N >> P;
        if (!N && !P) return 0;
        ll xCoord = (N + 1) / 2, yCoord = (N + 1) / 2;
        if (P == 1) {
            cout << "Line = " << yCoord << ", column = " << xCoord << "." << endl;
            continue;
        }
        ll x = sqrt(P);
        while (1 + x * (x + 1) >= P) x--;
        if (x % 2 == 1) x--;

        ll sumSoFar = 1 + x * (x + 1);
        xCoord += x / 2, yCoord -= x / 2;

        if (P <= sumSoFar + x + 1) {
            yCoord += P - sumSoFar;
            cout << "Line = " << yCoord << ", column = " << xCoord << "." << endl;
            continue;
        }
        sumSoFar += x + 1;
        yCoord += x + 1;
        if (P <= sumSoFar + x + 1) {
            xCoord -= P - sumSoFar;
            cout << "Line = " << yCoord << ", column = " << xCoord << "." << endl;
            continue;
        }
        sumSoFar += x + 1;
        xCoord -= x + 1;

        if (P <= sumSoFar + x + 2) {
            yCoord -= P - sumSoFar;
            cout << "Line = " << yCoord << ", column = " << xCoord << "." << endl;
            continue;
        }
        sumSoFar += x + 2;
        yCoord -= x + 2;

        xCoord += P - sumSoFar;
        cout << "Line = " << yCoord << ", column = " << xCoord << "." << endl;
    }

    return 0;
}
