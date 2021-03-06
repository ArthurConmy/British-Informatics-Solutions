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
	int n;
	cin >> n;

	vi a;
	vi a_min;
	
	int score;
	cin >> score;

	a.push_back(score);
	a_min.push_back(0); //.push_back(min(score, 0));

	int running_max = a.back() - a_min.back();

	for (int i = 1; i < n; i++)
	{
		int score;
		cin >> score;

		a_min.push_back(min(a_min.back(), a.back())); // moved to before a.push_back so that runs are at least length 1.
		a.push_back(a.back() + score);

		running_max = max(running_max, a.back()-a_min.back());
	}

	cout << running_max << endl;

	cin >> n; // just to stop the window closing immediatly
	return 0;
}
