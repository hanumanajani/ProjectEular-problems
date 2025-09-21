#include <bits/stdc++.h>

using namespace std;
#define ll long long 


const ll MOD = 1e9 + 7;

ll lcm(ll a, ll b){ return a / __gcd(a,b) * b; }

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
    vector<ll>piv(n+1,0);
    
    for(ll i=1;i<=n;i++){
        ll res = it[s[t[i]]];
        piv[i] = res;
    }
    return piv;
    
}
vector<ll> cycle(vector<ll>&piv,ll n){
    vector<ll>cyl(n+1,0);
    for(ll i=1;i<=n;i++){
        ll ncycle = 0;
        ll curr = i;
        while(true){
            ncycle++;
            curr = piv[curr];
            if(curr==i){
                cyl[i]=ncycle;
                break;
            }
        
        }
        
    }
    return cyl;
}
ll mfbyli(ll m, ll li){
    ll res = 1;
    for(ll i=1;i<=m;i++){
        if(i!=li){
            res = (res*i)%MOD;
        }
    }
    return res;
}
ll mfbylij(ll m, ll lij){
    ll fact = 1;
    for(ll i = 1; i <= m; i++){
        fact = (fact * i) % MOD;
    }
    ll inv_lij = 1;
    ll base = lij, exp = MOD - 2;
    while(exp > 0){
        if(exp & 1) inv_lij = (inv_lij * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return (fact * inv_lij) % MOD;
}
ll funB(ll n,ll m,vector<ll>&piv,vector<ll>cyl,vector<ll>fact){
    ll B = 0;
    for(ll i = 1;i<=n;i++){
        ll li = cyl[i];
        ll x = mfbyli(m,li);
        ll y = fact[n-i];
        ll z = 0;
        ll curr = piv[i];
        for(ll t = 1;t<=li;t++){
            z = (z+curr-1)%MOD;
            curr = piv[curr];
        }
        B = (B+(((x*y)%MOD)*z)%MOD)%MOD;

    }
    return B;
}
ll funC(ll n,ll m,vector<ll>&piv,vector<ll>cyl,vector<ll>fact){
    ll C = 0;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<i;j++){
            ll li = cyl[i];
            ll lj = cyl[j];
            ll lij = lcm(li,lj);
            ll x = mfbylij(m,lij);
            ll y = fact[n-i];
            ll curri = piv[i];
            ll currj = piv[j];
            ll cnt = 0;
            for(ll t=1;t<=lij;t++){
                if(currj<curri){
                    cnt++;
                }
                curri = piv[curri];
                currj = piv[currj];

            }
            C = (C + (((x*y)%MOD)*cnt)%MOD)%MOD;

        }

    }
    return C;
    
}
vector<ll> facti(ll n){
    vector<ll>fact(n+1,1);
    ll f = 1;
    for(ll i=1;i<=n;i++){
        f = (f*i)%MOD;
        fact[i]=f;
    }
    return fact;
}

int main() {
    ll m;
    cin>>m;
    ll n = m*(m+1)/2;
    vector<ll>piv = pi(n,m);
    vector<ll>cyl = cycle(piv,n);
    vector<ll>fact = facti(n);
    ll A = fact[m];
    cout<<"A"<<A<<endl;
    ll B = funB(n,m,piv,cyl,fact);
    cout<<"B"<<B<<endl;
    ll C = funC(n,m,piv,cyl,fact);
    cout<<"C"<<C<<endl;
    ll ans = (A+B-C+MOD)%MOD;
    cout<<"P(m): "<<ans<<endl;
    

    return 0;


}
