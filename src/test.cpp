#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n,m;
	    cin >>n >> m;
	    vector<int> a(n);
	    vector<int> b(m);
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    for(int i = 0;i<m;i++){
	        cin >> b[i];
	    }
        
	    int min1 = 1000000;
	    int index = 0;
	    for(int i = 0;i<m;i++){
	        if(min1>=b[i]){
	            index = i;
	            min1 = b[i];
	            
	        }
	    }
        // for(auto &i : a){
        //     cout << i << endl;
        // // }
        vector<int> c = a;
	    rotate(b.begin(),b.begin()+index,b.end());
	    for (int i = 0; i < n; i++) {
            if (a[i] > min1 && i + m <= n) {
                for (int j = 0; j < m && (i + j) < n; j++) {
                    a[i + j] = b[j];
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (c[i] >= min1 && i + m <= n) {
                for (int j = 0; j < m && (i + j) < n; j++) {
                    c[i + j] = b[j];
                }
            }
        }
        bool flag = false;
        for(int i = 0;i<n;i++){
            if(c[i]<a[i]){
                for(auto &i : c){
                    cout << i << " ";
                }
                cout << endl;
                flag = true;
                break;
            }
            else if(a[i]<c[i]){
                for(auto &i : a){
                    cout << i << " ";
                }
                cout << endl;
                flag = true;
                
            }
            else{
                continue;
            }
        }
        //cout << flag << endl;
	    if(!flag){
	    for(auto &i : a)cout << i << " ";
	    cout << endl;
        }
	}
	return 0;

}   