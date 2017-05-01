#include <iostream>
#include <array>
#include <algorithm>
#include <queue>

#define  INF 999999

using  namespace std;


array<int, 50>heap;
vector<int >myvec;

int n;


void craeteHeap();

void siftDown(int i);

void deletemin();

int main() {


	int num;
	cin >> num;

	for (int i = 1; i <= num; i++){
		cin >> heap[i];
	}

	n = num;


	craeteHeap();

	for (int i = 1; i <= num; i++){
		deletemin();
	}


	auto ib = myvec.begin();
	auto ie = myvec.end();



	auto fun = [](int it){
		cout << it << ",";
	};

	for_each(ib, ie, fun);


	system("pause");

	return 0;

}

void deletemin() {

	myvec.push_back(heap[1]);

	heap[1] = heap[n];

	n--;

	siftDown(1);



}

void craeteHeap() {

	for (int i = n / 2; i >= 1; i--){

		siftDown(i);

	}

}

void siftDown(int i) {

	int t;

	int flag = 0;

	while (i * 2 <= n&&flag == 0){
		if (2 * i <= n&&heap[i] > heap[2 * i]){
			t = 2 * i;
		}
		else{
			t = i;
		}

		if (2 * i + 1 <= n&&heap[t] > heap[2 * i + 1]){
			t = 2 * i + 1;
		}

		if (t != i){

			int temp = heap[i];
			heap[i] = heap[t];
			heap[t] = temp;

			i = t;
		}
		else{
			flag = 1;

		}
	}


}
