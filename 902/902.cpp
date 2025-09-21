#include <bits/stdc++.h>

using namespace std;
#define ll long long 


const ll MOD = 1e9 + 7;
 
vector<ll> pi(ll n,ll m) {
    vector<ll>t(n+1,0);
    vector<ll>it(n+1,0);
    vector<ll>s(n+1,0);
    for(ll i=1;i<=n;i++){
        ll a = ((MOD*i)%n) +1;
        t[i]=a;
        it[a]=i;
        ll val = i+1;
        for(ll k =1;k<=m;k++){
            if(i==(k*(k+1))/2){
                val = k*(k-1)/2 +1;
                break;
            }
        }
        s[i]=val;
    }
    vector<ll>piv;
    piv.push_back(0);
    for(ll i=1;i<=n;i++){
        ll res = it[s[t[i]]];
        piv.push_back(res);
    }
    return piv;
    
}



int main() {
    ll m;
    cin>>m;
    ll n = m*(m+1)/2;
    vector<ll>piv = pi(n,m);
    vector<ll>cycle(n+1,0);
    for(ll i=1;i<=n;i++){
        ll ncycle = 0;
        ll curr = i;
        while(true){
            ncycle++;
            curr = piv[curr];
            if(curr==i){
                // cout<<i<<"th no of cycle"<<ncycle<<endl;
                cycle[i]=ncycle;
                break;
            }
        
        }
        
    }
    ll x = cycle[1];
    ll a = 1;
    ll mx = 1;
    for(ll i =1;i<=x;i++){
        a = piv[a];
        cout<<a<<" ";
        mx = max(mx,a);
    }
    cout<<endl;
    cout<<mx<<endl;
    for(ll i=0;i<LLONG_MAX;i++){
        for(ll j=0;j<LLONG_MAX;j++){
            x++;
            x--;
        }
    }
   
    return 0;


}
