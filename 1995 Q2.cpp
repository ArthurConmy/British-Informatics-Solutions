#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef vector< int > vi;
typedef vector< long > vl;
typedef vector< vector< int > > vvi;
typedef vector< vector< long > > vvl;
typedef vector< vector< vector< int > > > vvvi;
typedef vector< vector< vector< long > > > vvvl;
typedef long long ll;
typedef vector< long long > vll;
typedef vector< string > vs;
typedef vector< bool > vb;
typedef vector< vector< bool > > vvb;

int main()
{
	int x, y;
	cin >> x >> y;

	int P = (y - 1) * 5 + (x - 1);

	// PROBLEM A

	if (P % 5 <= 1) cout_P(P + 3);
	if (P % 5 >= 3) cout_P(P - 3);
	if (P + 15 < 25) cout_P(P + 15);
	if (P - 15 >= 0) cout_P(P - 15);
	if (P % 5 <= 2 && P / 5 <= 2) cout_P(P + 12);
	if (P % 5 >= 2 && P / 5 >= 2) cout_P(P - 12);

	// PROBLEM A DONE

	return 0;
}
