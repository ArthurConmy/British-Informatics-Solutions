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

//vi move1(vi vect)
//{
//
//
//}

void cout_P(int P)
{
	cout << P % 5 + 1 << " " << P / 5 + 1 << endl;
}

int 1995_main()
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

	vi blank(25, 0);
	blank[P] = 1;

	vvvi breadth = { {}, {blank} };

	for (int depth = 2; depth <= 25; depth++)
	{
		vvi new_states;

		// for state in breadth[depth-1]

		// for index in [0, 24] 

		// if breadth[depth-1][index] == depth-1

		// for possible moves (copy from above)

		// if breadth[depth-1][move] == 0

		// vi new_thing = breadth ...

	//	vi new_state;

	//	for (auto leaf : breadth[depth - 1])
	//	{
	//		for (int index = 0; index < 25; index++)
	//		{
	//			if (leaf[index] == depth - 1)
	//			{
	//				P = index;
	//
	//				//cout << P;
	//
	//				if (P % 5 <= 1)
	//				{
	//					/*cout_P(P + 3);*/
	//					if (leaf[P + 3] == 0)
	//					{
	//						new_state = leaf;
	//						new_state[P + 3] = depth;
	//						new_states.push_back(new_state);
	//					}
	//				}
	//				if (P % 5 >= 3) //cout_P(P - 3)
	//				{
	//					if (leaf[P - 3] == 0)
	//					{
	//						new_state = leaf;
	//						new_state[P - 3] = depth;
	//						new_states.push_back(new_state);
	//					}
	//				}
	//				if (P + 15 < 25) //cout_P(P + 5);
	//				{
	//					/*cout_P(P + 3);*/
	//					if (leaf[P + 15] == 0)
	//					{
	//						new_state = leaf;
	//						new_state[P + 15] = depth;
	//						new_states.push_back(new_state);
	//					}
	//				}
	//				if (P - 15 >= 0) //cout_P(P - 5);
	//				{
	//					/*cout_P(P + 3);*/
	//					if (leaf[P - 15] == 0)
	//					{
	//						new_state = leaf;
	//						new_state[P - 15] = depth;
	//						new_states.push_back(new_state);
	//					}
	//				}
	//				if (P % 5 <= 2 && P / 5 <= 2) //cout_P(P + 12);
	//				{
	//					/*cout_P(P + 3);*/
	//					if (leaf[P + 12] == 0)
	//					{
	//						new_state = leaf;
	//						new_state[P + 12] = depth;
	//						new_states.push_back(new_state);
	//					}
	//				}
	//				if (P % 5 >= 2 && P / 5 >= 2) //cout_P(P - 12);
	//				{
	//					/*cout_P(P + 3);*/
	//					if (leaf[P -12] == 0)
	//					{
	//						new_state = leaf;
	//						new_state[P -12] = depth;
	//						new_states.push_back(new_state);
	//					}
	//				}
	//				if (P % 5 >= 2 && P / 5 <= 2) //cout_P(P - 12);
	//				{
	//					/*cout_P(P + 3);*/
	//					if (leaf[P + 8] == 0)
	//					{
	//						new_state = leaf;
	//						new_state[P + 8] = depth;
	//						new_states.push_back(new_state);
	//					}
	//				}
	//				if (P % 5 <= 2 && P / 5 >= 2) //cout_P(P - 12);
	//				{
	//					/*cout_P(P + 3);*/
	//					if (leaf[P - 8] == 0)
	//					{
	//						new_state = leaf;
	//						new_state[P - 8] = depth;
	//						new_states.push_back(new_state);
	//					}
	//				}
	//			}
	//		}
	//	}

	//	//for (auto s : new_states)
	//	//{
	//	//	for (auto x : s)
	//	//	{
	//	//		cout << x << " ";
	//	//	}

	//	//	cout << endl;
	//	//}

	//	//cin >> x;

	//	breadth.push_back(new_states);
	//}

	//// BEGIN SEARCH FOR CYCLICAL TOUR

	//for (auto cycle : breadth[25])
	//{
	//	for (int ind = 0; ind < 25; ind++)
	//	{
	//		if (cycle[ind] == 25)
	//		{
	//			P = ind;

	//			if (P % 5 <= 1)
	//			{
	//				/*cout_P(P + 3);*/
	//				if (cycle[P + 3] == 1)
	//				{
	//					for (auto x : cycle)
	//					{
	//						cout << x << " ";
	//						//return 0;
	//					}
	//					cin >> P;
	//				}
	//			}
	//			if (P % 5 >= 3) //cout_P(P - 3)
	//			{
	//				if (cycle[P - 3] == 1)
	//				{
	//					for (auto x : cycle)
	//					{
	//						cout << x << " ";
	//					}
	//					cin >> P;
	//				}
	//			}
	//			if (P + 15 < 25) //cout_P(P + 5);
	//			{
	//				/*cout_P(P + 3);*/
	//				if (cycle[P + 15] == 1)
	//				{
	//					for (auto x : cycle)
	//					{
	//						cout << x << " ";
	//					}
	//					cin >> P;
	//				}
	//			}
	//			if (P - 15 >= 0) //cout_P(P - 5);
	//			{
	//				/*cout_P(P + 3);*/
	//				if (cycle[P - 15] == 1)
	//				{
	//					for (auto x : cycle)
	//					{
	//						cout << x << " ";
	//					}
	//					cin >> P;
	//				}
	//			}
	//			if (P % 5 <= 2 && P / 5 <= 2) //cout_P(P + 12);
	//			{
	//				/*cout_P(P + 3);*/
	//				if (cycle[P + 12] == 1)
	//				{
	//					for (auto x : cycle)
	//					{
	//						cout << x << " ";
	//					}
	//					cin >> P;
	//				}
	//			}
	//			if (P % 5 >= 2 && P / 5 >= 2) //cout_P(P - 12);
	//			{
	//				/*cout_P(P + 3);*/
	//				if (cycle[P - 12] == 1)
	//				{
	//					for (auto x : cycle)
	//					{
	//						cout << x << " ";
	//					}
	//					cin >> P;
	//				}
	//			}
	//			if (P % 5 >= 2 && P / 5 <= 2) //cout_P(P - 12);
	//			{
	//				/*cout_P(P + 3);*/
	//				if (cycle[P + 8] == 1)
	//				{
	//					for (auto x : cycle)
	//					{
	//						cout << x << " ";
	//					}
	//				}
	//				cin >> P;
	//			}
	//			if (P % 5 <= 2 && P / 5 >= 2) //cout_P(P - 12);
	//			{
	//				/*cout_P(P + 3);*/
	//				if (cycle[P - 8] == 1)
	//				{
	//					for (auto x : cycle)
	//					{
	//						cout << x << " ";
	//					}
	//				}
	//				cin >> P;
	//			}
	//		}
	//	}
	//}

	// END SEARCH

	//cout << breadth[25].size() << endl;

	// OKAY SEE SHEETS OF PAPER

	

	cin >> x;
	return 0;
}