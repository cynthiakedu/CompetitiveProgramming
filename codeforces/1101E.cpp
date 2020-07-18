#include <bits/stdc++.h>
using namespace std;
int N; 
int sMx = 0, lMx = 0; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N; 
    for (int i = 0; i < N; i++){
        char type;
        int x, y;  
        cin >> type >> x >> y;
        if (y < x) swap(x, y); 
        if (type == '+'){
            sMx = max(sMx, x); 
            lMx = max(lMx, y); 
        }else{
            if (sMx <= x && lMx <= y){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
    }

    return 0;
}
