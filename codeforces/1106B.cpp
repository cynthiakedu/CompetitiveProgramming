#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll; 
int N, M, a[100005], c[100005]; 
vector<ii> food; //cost, idx 
int idx = 0; 


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M; 
    for (int i = 1; i <= N; i++){
        cin >> a[i]; 
    }
    for (int i = 1; i <= N; i++){
        cin >> c[i]; 
        food.push_back(ii(c[i], i)); 
    }
    sort(food.begin(), food.end()); 

    for (int i= 0; i < M; i++){
        // cout<<"customer "<<i<<endl;
        int t, d; 
        cin >> t >> d; 
        ll pay = 0; 
        while (d > 0 && a[t] > 0){
            // cout<<t<<endl;
            a[t]--; 
            d--; 
            pay += c[t]; 
        }
       while (d > 0){
           while (idx < N && a[food[idx].second] == 0){
               idx++; 
           }
           if (idx == N){
               break; 
           }
           a[food[idx].second]--; 
           pay += c[food[idx].second]; 
        //    cout<<food[idx].second<<endl;
           d--; 
       }
       if (d > 0){
           pay = 0; 
       }
       cout<<pay<<endl;
       
    }


    return 0;
}
