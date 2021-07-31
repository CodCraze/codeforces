//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>

#define endl "\n"
#define inputv(x,n) for(ll i=0;i<n;i++) cin>>x[i];
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--){
		ll m;
		cin>>m;
		vector<vector<ll>> v(2,vector<ll>(m));
		for(ll i=0;i<2;i++){
			for(ll j=0;j<m;j++){
				cin>>v[i][j];
			}
		}
		vector<ll> up(m);
		vector<ll> down(m);
		up[0]=v[0][0];
		down[0]=v[1][0];
		for(ll i=1;i<m;i++){
			up[i]=up[i-1]+v[0][i];
			down[i]=down[i-1]+v[1][i];
		}
		ll max_pos=min(up[m-1]-v[0][0],down[m-1]-v[1][m-1]);
		for(ll i=1;i<m-1;i++){
			max_pos=min(max_pos,max(down[i-1],up[m-1]-up[i]));
		}
		cout<<max_pos<<endl;
	}
	return 0;
}
