#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii; 
int T, N, R[100005], ans[100005]; 

void solve(){
    cin >> N; 
    vector<ii> v; 
    for (int i = 0; i < N; i++){
        int l, r; 
        cin >> l >> r; 
        R[i] = r; 
        v.push_back(ii(l,i)); 
    }
    sort(v.begin(), v.end()); 

    int r = R[v[0].second]; 
    for (int i = 1; i < N; i++){
        if (v[i].first <= r){
            r = max(R[v[i].second], r); 
        }else{
            for (int j = 0; j < N; j++){
                ans[v[j].second] = j < i?1:2; 
            }
            for (int j = 0; j < N; j++){
                cout<<ans[j]<<(j == (N-1)?"\n":" "); 
            }
            return;
        }
    }
    cout<<-1<<endl;
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
