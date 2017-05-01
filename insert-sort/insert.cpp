#include <iostream>
#include <array>

using namespace std;

array<int, 20> a;

int n;

void initArray()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
}

void mySort()
{
	for (int i = 1; i < n; i++)
	{
		int temp = a[i];
		int j = i - 1;
		while (j >= 0 && temp < a[j])
		{
			a[j + 1] = a[j];
			j--;

		}

		a[j + 1] = temp;

	}
}

int main()
{

	initArray();

	mySort();


	for_each(a.begin(), a.begin() + n, [](int num)
	{
		cout << num << " , ";
	});





	return 0;
}
