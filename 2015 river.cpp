#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int,int> pii;

#define REP(i, a, b) \
for (int i = int(a); i <= int(b); i++)
#define REPb(j, d, c) \
for (int j = int(d); j >= int(c); j--)
#define ff \
first
#define ss \
second
#define pb \
push_back

ll dp[4][1025][1025];

/*  let dp[0][n][c] be

	the max fertility in the first n fields, planting c crops, and in the nth field *using neither region*

	other dp states defined similarly, where dp[1][n][c] has the nth field only planted in in the upper section,
                                           dp[2][n][c]                                in the lower section.
                                  AND FINALLY 
*/
int main()
{
	int n;
	cin>>n;

	int c;
	cin>>c;

	vector<ll> upper;
	vector<ll> lower;

	REP(i,1,n)
	{
		ll f, s;
		cin>>f>>s;
		upper.push_back(f);
		lower.push_back(s);
	}

	ll global_max=0;

	REP(s,1,n) // s for section
	{
		REP(p,1,c) // p for plants
		{
			dp[0][s][p] = max({dp[0][s-1][p], dp[1][s-1][p], dp[2][s-1][p], dp[3][s-1][p]});

			if(s>1) dp[1][s][p] = upper[s-1] + upper[s-2] + max({dp[2][s-1][p-1], dp[0][s-1][p-1]});

			if(s>1) dp[2][s][p] = lower[s-1] + lower[s-2] + max({dp[1][s-1][p-1], dp[0][s-1][p-1]});

			dp[3][s][p] = upper[s-1] + lower[s-1] + max({dp[0][s-1][p-1],dp[1][s-1][p-1],dp[2][s-1][p-1],dp[3][s-1][p-1]});
			if(s>1 && p>1) dp[3][s][p] = max(dp[3][s][p], dp[0][s-1][p-2] + upper[s-1] + upper[s-2] + lower[s-1] + lower[s-2]);
		
			global_max = max({global_max, dp[0][s][p], dp[1][s][p], dp[2][s][p], dp[3][s][p]});
		}
	}

	cout << global_max << endl;

	return 0;
}
