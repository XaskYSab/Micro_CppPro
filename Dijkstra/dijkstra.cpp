#include <iostream>

#define  INF 999999

using namespace std;


int graphicArray[10][10];

int dis[10] = { 0 };

bool book[10] = { false };


int n, m;

void initGraphic();

int main()
{
	initGraphic();

	for (int i = 1; i <= n; i++){
		dis[i] = graphicArray[1][i];
	}

	book[1] = true;

	for (int i = 1; i <= n - 1; i++)
	{
		int min = INF;

		int u = -1;

		for (int j = 1; j <= n; i++)
		{
			if (book[j] == false && dis[j] < min)
			{
				u = j;
				min = dis[j];
			}
		}

		if (u != -1)
		{
			book[u] = true;
		}


		for (int k = 1; k <= n; i++)
		{
			if (dis[k] > dis[u] + graphicArray[u][k])
			{
				dis[k] = dis[u] + graphicArray[u][k];
			}
		}
		
	}

	for (int i = 1; i <= n; i++)
	{
		cout << dis[i] << " " << endl;	
	}
	


	return 0 ;
}


void initGraphic() {

	cin >> n >> m;


	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j)
				graphicArray[i][j] = 0;
			else
				graphicArray[i][j] = INF;
		}
	}

	for (int i = 1; i <= m; ++i) {
		int a, b, c;

		cin >> a >> b >> c;
		graphicArray[a][b] = c;
	}
}
