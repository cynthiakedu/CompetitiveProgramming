#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii; 
typedef long long ll; 
int N, M, K; 
vector<ii> v1; 
vector<int> v2; 
ll ans = 0; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K; 
    for (int i = 1, x; i <=N; i++){
        cin >> x; 
        v1.push_back(ii(-x, i)); 
    }
    sort(v1.begin(), v1.end()); 
    for (int i = 0; i < M*K; i++){
        ans += -v1[i].first;
        v2.push_back(v1[i].second);  
    }
    sort(v2.begin(), v2.end()); 
    cout<<ans<<endl;
    for (int i = 0; i < K-1; i++){
        cout<<v2[M*i+M-1]<<(i == K-2?"\n":" "); 
    }
    return 0;
}
