#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
int N, L, R; 
#define MOD 1000000007
ll dp[200005][3]; 

vector<int> m3(int x){
    int y = x/3; 
    vector<int> v {y, y, y}; 
    for (int i = 3*y+1; i <= x; i++){
        v[i%3]++; 
    }
    return v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> L >> R; 
    vector<int> v1 = m3(R); 
    vector<int> v2 = m3(L-1); 
    for (int i= 0; i < 3; i++) v1[i] = v1[i]-v2[i]; 

    for (int i = 0; i <= N; i+= 2){
        int c = N-2; 
    }

    for (int i = N+1; i >= 1; i--){
        for (int j = 0; j < 3; j++){
            if (i == N+1){
                dp[i][j] = j == 0?1:0; 
                continue; 
            }
        for (int k = 0; k < 3; k++){
            dp[i][j] = (dp[i][j]+(v1[k]*dp[i+1][((j-k)+3)%3])%MOD)%MOD; 
            }
        }
    }
    cout<<dp[1][0]<<endl;


    return 0;
}
