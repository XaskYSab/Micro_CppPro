#include<iostream>
#include <array>
using namespace std;


array<int, 50>my_array;

void merge(int start, int mid, int end)
{

	int n1 = mid - start + 1;
	int n2 = end - mid;


	array<int, 30>array1, array2;

	for (int i = 0; i < n1; i++)
	{
		array1[i] = my_array[start + i];
	}

	for (int i = 0; i < n2; i++)
	{
		array2[i] = my_array[mid + 1 + i];
	}


	int i = 0, j = 0, k = start;

	while (i < n1 && j < n2){
		if (array1[i] < array2[j])
		{
			my_array[k++] = array1[i++];
		}
		else
		{
			my_array[k++] = array2[j++];

		}
	}


	while (i < n1){

		my_array[k++] = array1[i++];
	}

	while (j < n2){

		my_array[k++] = array2[j++];
	}


}

void mysort(int start, int end)
{

	if (start >= end)
		return;

	int mid = (start + end) / 2;

	mysort(start, mid);

	mysort(mid + 1, end);

	merge(start, mid, end);

}

int main()
{

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> my_array[i];
	}


	mysort(0, n - 1);


	for_each(my_array.begin(), my_array.begin() + n, [](int num){
		cout << num << ",";
	});


	cin.get();
	cin.get();


	return 0;
}
