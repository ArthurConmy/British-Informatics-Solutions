# Competitive Programming Solutions

Solutions to competitive programming problems I've done. My current template is 

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define len(x) int((x).size())

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define randint(n) uniform_int_distribution<int>(1, (n))(rng)

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	#ifdef ARTHUR_LOCAL
		ifstream cin("input.txt");
	#endif

	
}
```

though this has been different in the past.
