#include <bits/stdc++.h>
using namespace std;
int K, R;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> K >> R;
    int num = 0;
    while (true) {
        num++;
        if (K * num % 10 == R) {
            cout << num << endl;
            return 0;
        } else if (K * num % 10 == 0 && K * num >= 10) {
            cout << num << endl;
            return 0;
        }
    }

    return 0;
}
