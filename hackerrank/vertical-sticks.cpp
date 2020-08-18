#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>

double fact[55];

// Complete the solve function below.
vector<double> solve(vector<int> y) {
    fact[0] = 1;
    for (int i = 1; i < 51; i++) fact[i] = 1.0 * i * fact[i - 1];
    sort(y.begin(), y.end(), greater<int>());
    int idx = 0;
    double ret = 0;
    while (idx < (int)y.size()) {
        int j = idx;
        while (j < (int)y.size() && y[j] == y[idx]) j++;
        // cout<<"idx j "<<idx<<" "<<j<<endl;
        int ct = j - idx;
        double temp = 1 + ((1.0 * ((int)y.size() - j) / (j + 1)));
        // cout<<"temp "<<temp<<" "<<(1.0*((int)y.size()-j)/(j+1))<<endl;
        ret += 1.0 * ct * temp;
        idx = j;
    }
    // cout<<fixed<<setprecision(2)<<ret<<endl;
    return vector<double>{ret};
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
