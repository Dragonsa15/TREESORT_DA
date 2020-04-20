#include <bits/stdc++.h>
using namespace std;
long long int dfs(long long int i,vector<long long int> & l,vector<long long int> & r,vector<long long int> & m,vector<long long int> & M){
    if(l[i]==-1){
        m[i]=M[i]=r[i];
        return 0;
    }else{
        long long int lVal=dfs(l[i],l,r,m,M);
        long long int rVal=dfs(r[i],l,r,m,M);
        if(lVal==-1 || rVal==-1){
            return -1;
        }else{
            if(M[l[i]]<=m[r[i]]){
                M[i]=M[r[i]];
                m[i]=m[l[i]];
                return lVal+rVal;
            }else{
                if(M[r[i]]<=m[l[i]]){
                    M[i]=M[l[i]];
                    m[i]=m[r[i]];
                    return (1+rVal+lVal);
                }else{
                    return -1;
                }
            }
        }
    }
}
int main(){
    long long int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        vector<long long int> l(n+1);
        vector<long long int> r(n+1);
        vector<long long int> m(n+1);
        vector<long long int> M(n+1);
        for(long long int i=1;i<=n;i++){
            cin >> l[i] >> r[i];
        }
        cout << dfs(1,l,r,m,M) << '\n';
        l.clear();
        r.clear();
        m.clear();
        M.clear();
    }
    return 0;
}
