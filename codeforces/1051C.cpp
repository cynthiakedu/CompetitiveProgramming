#include <bits/stdc++.h>
using namespace std;
int N; 
map<int,int> ct; 
map<int,vector<int>> idx; 
int ans[105]; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N; 
    for (int i = 0, x; i < N; i++){
        cin >> x; 
        ct[x]++; 
        idx[x].push_back(i); 
    }
    vector<int> a, b; 
    for (auto p : ct){
        if (p.second == 1){
            a.push_back(p.first); 
        }else if (p.second > 2){
            b.push_back(p.first); 
        }else{
           for (auto x : idx[p.first]){
               ans[x] = 0; 
           }
        }
    }
    if (a.size()%2 == 1){
        if(b.size() == 0){
            cout<<"NO"<<endl;
        return 0; 
        }else{
            cout<<"YES"<<endl;
            for (int i = 0; i < idx[b[0]].size(); i++){
                ans[idx[b[0]][i]] = i == 0?0:1;  
            }
            if (a.size() == 1){
                ans[idx[a[0]][0]]= 1; 
            }else{
            for (int i = 0; i <= a.size()/2-1; i++){
                ans[idx[a[i]][0]] = 0; 
             }
            for (int i = a.size()/2; i < a.size(); i++){
                ans[idx[a[i]][0]] = 1; 
            }
            }
           
            for (int i = 1; i < b.size(); i++){
                for (auto x : idx[b[i]]){
                    ans[x] = 1; 
                }
            }
           
        }
    }else{
        cout<<"YES"<<endl;
        for (int i = 0; i < a.size()/2; i++){
            ans[idx[a[i]][0]] = 0; 
        }
        for (int i = a.size()/2; i < a.size(); i++){
            ans[idx[a[i]][0]] = 1; 
        }
        for (auto x : b){
            for (auto y : idx[x]){
                ans[y] = 1; 
            }
        }
    }
    for (int i = 0; i < N; i++) cout<<(ans[i]?"B":"A"); 
    cout<<endl;
   
    return 0;
}