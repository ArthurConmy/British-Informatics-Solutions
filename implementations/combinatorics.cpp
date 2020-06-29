const int MAXN=100000;
const ll p = 7LL + ll(1e9); // both of these may need to be edited, problem dependent
 
ll fac[MAXN];
ll inv_fac[MAXN];
 
ll mod_exp(ll a, ll b)
{
	if(b==0LL) return 1LL;
 
	ll ans = mod_exp(a,ll(b/2LL));
	ans*=ans;
	ans%=p;
 
	if(b%2LL==1LL) ans*=a;
	ans%=p;
 
	return ans;
}
 
ll C(int n, int k)
{
	if(k<0 || k>n) return 0;

	ll ans = fac[n]*inv_fac[k];
	ans%=p;
	return (ans*inv_fac[n-k])%p;
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	#ifdef ARTHUR_LOCAL
		ifstream cin("input.txt");
	#endif
 
	fac[0]=1LL;
	inv_fac[0]=1LL;
 
	for(int i=1; i<=MAXN; i++)
	{
		fac[i] = ll(i)*fac[i-1];
		fac[i] %= p;
 
		inv_fac[i] = mod_exp(fac[i],p-2LL);
		// if(i<10) cout << i << " " << fac[i] << " " << inv_fac[i] << endl;
	}
}
