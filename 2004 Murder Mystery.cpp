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
typedef vector<ll> vll;
typedef queue<ll> qll;
typedef queue<int> qi;

ll f(int x)
{
	if (x == 0) return 1;
	else return x * f(x - 1);
}

ll I(vi A)
{
	int summ = 0;

	for (auto x : A) summ += x;

	ll ret = f(summ); // WE PROBABLY CAN OVERFLOW ICI

	for (auto x : A) ret /= f(x);

	return ret;
}

int main()
{
	int n;
	cin >> n;

	vi out(n + 1, 0); // LMAO the number they killed
	vll number(n + 1, 1); // 1 I THINK
	vi length(n + 1, 1); // AGAIN 1 I THINK
	vb used(n + 1, false);
	
	vb row(n + 1, false);
	vvb kill(n + 1, row);

	for (int i = 1; i < n; i++)
	{
		int killer;
		cin >> killer; // killer kills i

		out[killer] += 1;

		kill[killer][i] = true;
	}

	for (int i = 1; i <= n; i++) // starting vertex
	{
		if (used[i]) continue;
		vi connected;
		bool works = true;

		for (int j = 1; j <= n; j++)
		{
			if (!kill[i][j]) continue;

			if (out[j] > 0)
			{
				works = false;
				break;
			}

			else connected.push_back(j);
		}

		if (works && connected.size()>0)
		{
			vi lengths;
			int max_length = 0;

			for (auto v : connected)
			{
				lengths.push_back(length[v]);
				max_length = max(max_length, length[v]);

				number[i] *= number[v];
				length[i] += length[v];

				used[v] = true;
			}

			number[i] *= I(lengths);
			out[i] = 0;

			if (i == n)
			{
				cout << number[i] << endl;

				cin >> n;
				return 0;
			}
		}

		if (i == n) i = 1; // rotate back to start
	}

	cin >> n;
	return 0;
}