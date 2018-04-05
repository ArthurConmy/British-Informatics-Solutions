#include <vector>
#include <iostream>
#include <queue>
#include <string>
//#include <pair>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<ll> vll;
typedef queue<ll> qll;
typedef queue<int> qi;

int main()
{
	int n;
	cin >> n;
	
	priority_queue<pll> Q; // we have Q.top() and Q.pop()

	vi primes;

	for (int i = 0; i < n; i++)
	{
		int p;
		cin >> p;
		primes.push_back(p);
	}

	ll j;
	cin >> j;

	Q.push({ -primes[0], 0 }); // this is basically 1, timesed by the first prime

	for (ll i = 0; i < j; i++) // finding the ith prime
	{
		ll this_prime = Q.top().first;
		
		if (i == j - 1)
		{
			cout << -this_prime << endl;
			cin >> n; // to stop insta-close
			return 0;
		}

		//cin >> n; // for drip-drop running

		vpll replacements;

		while (Q.top().first == this_prime)
		{
			replacements.push_back(Q.top());
			Q.pop();

			if (Q.size() == 0) break;
		}

		for (auto r : replacements)
		{
			if (r.second < n - 1)
			{
				Q.push({ (r.first*primes[r.second+1])/(primes[r.second]), r.second + 1 });
			}
		}

		Q.push({ this_prime*primes[0], 0 });
	}

	cin >> n;
	return 0;
}