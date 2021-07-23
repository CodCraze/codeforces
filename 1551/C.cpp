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
		ll n;
		cin>>n;
		vector<string> st(n);
		vector<vector<ll>> v(n,vector<ll>(26,0));
		for(ll i=0;i<n;i++){
			string s;
			cin>>s;
			st[i]=s;
			for(char c:s){
				v[i][c-'a']++;
			}	
		}
		ll maxl=0;
		for(ll i=0;i<26;i++){
			vector<ll> al(n);
			ll len=0;
			for(ll j=0;j<n;j++){
				al[j]=2*v[j][i]-st[j].length();
			}
			sort(al.begin(),al.end(),greater<ll>());
			ll sum=al[0];
			if(sum>0)
				len=1;
			ll pos=1;
			while(sum>0 && pos<n){
				sum+=al[pos];
				if(sum>0)
					len=max(len,pos+1);
				else break;	
				pos++;
			}
			maxl=max(len,maxl);
		}
		cout<<maxl<<endl;
	}
	return 0;
}
