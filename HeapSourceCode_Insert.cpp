#include <stdio.h>
#include <Windows.h>
#include <algorithm>
#include <queue>
using namespace std;
#pragma warning(disable:4996)

#define MIN_HEAP_MODE true
#define MAX_HEAP_MODE false;

const int HEAP_SIZE = 1000;
int heap[HEAP_SIZE + 1] = { 0, };
int tail = 1;

bool isChange(int n, int m, bool asc) {
	int sign = (asc) ? 1 : -1;
	return (n * sign < m * sign) ? false : true;
}

void allPrintHeapData() {
	for (int i = 1; i < tail; ++i) printf("%d ", heap[i]);
	printf("\n");
}
int main(void) {
	int dataNum;
	scanf("%d", &dataNum);

	for (int i = 0; i < dataNum; ++i) {
		scanf("%d", &heap[tail++]);
		printf("#(%d Data)Not sorting data : ",i);
		allPrintHeapData();
		int nodeIdx = tail - 1;
		
		while (nodeIdx > 1) {
			if (isChange(heap[nodeIdx / 2], heap[nodeIdx], MIN_HEAP_MODE)) swap(heap[nodeIdx / 2], heap[nodeIdx]);
			nodeIdx /= 2;
		}
		printf("#(%d Data)sorting data : ",i);
		allPrintHeapData();
	}

	system("pause");
	return 0;
}