#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T, K, arr[10], cum[10]; 

void solve(){
    cin >> K; 
    for (int i = 1; i <= 7; i++) cin >> arr[i]; 
    for (int i= 1; i <= 7; i++) cum[i] = cum[i-1]+arr[i]; 
    ll ans = INT_MAX; 

    for (ll i = 0; i <= 7; i++){
        for (ll j = 0; j <= 7; j++){
            ll x = (cum[7]-cum[7-i])+(cum[j]); 
            ll num = i+j; 
            if (K >= x){
                if ((K-x)%cum[7] == 0){
                    num += 7*((K-x)/cum[7]); 
                    ans = min(ans, num); 
                }
            }
        }
    }

    if (K <= 7){
        for (ll i = 1; i <= 7; i++){
            for (ll j = i; j <= 7; j++){
                if (cum[j]-cum[i-1] == K){
                    ans = min(ans,j-i+1); 
                }
            }
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T; 
    for (int t = 0; t < T; t++){
        solve(); 
    }

    return 0;
}
