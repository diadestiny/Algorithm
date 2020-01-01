#include <iostream>
#include <time.h>

#include<vector>
#define M 100 /* ִ�д��� */
#define N 5000 /* �����С */

using namespace std;
//1,��������
void InsertSort(int *arr, int n)
{
	for (int i = 1; i < n; i++) {
		int temp = arr[i];
		int j;
		for (j = i - 1; j >= 0; j--) {
			if (arr[j] > temp) {
				arr[j + 1] = arr[j];
			}
			else {
				break;
			}
		}
		arr[j + 1] = temp;
	}
}


//2,ѡ������
void SelectSort(int *arr, int n)
{
	for (int i = 0; i < n; i++) {
		int temp = arr[i];
		int flag;
		for (int j = i; j < n; j++) {
			if (arr[j] < temp) {
				temp = arr[j];
				flag = j;
			}
		}
		if (temp != arr[i]) {
			arr[flag] = arr[i];
			arr[i] = temp;
		}
		
	}
}
//3����������
int partition_array(int *arr, int l, int r)
// ���ʵ��arr[l, r]������ѡ��һ����׼����߱Ȼ�׼С���ұ߱Ȼ�׼��
// ���ػ�׼����λ��
{
	// �������ﲹ����룬��ɱ�������
	/********** Begin *********/
	int pivot = l;
	// �趨��׼ֵ
	int index = pivot + 1;
	for (int i = index; i <= r; i++) {
		if (arr[i] < arr[pivot]) {
			swap(arr[i], arr[index]);
			index++;
		}
	}
	swap(arr[pivot], arr[index - 1]);
	return index - 1;
	/********** End **********/
}
int* quick_sort(int *arr, int l, int r)
//  ���ʵ�ֿ����������϶��µĵݹ鷽��
//  ������������������arr ��ʼl=0��r=n-1
//  ��������ֵ�����ش�С��������������
{
	// �������ﲹ����룬��ɱ�������
	/********** Begin *********/
	if (l < r)
	{
		int m = partition_array(arr, l, r);
		// �ݹ�������
		quick_sort(arr, l, m - 1);
		quick_sort(arr, m + 1, r);
		return arr;
	}
	else
	{
		return arr;
	}
	/********** End **********/
}

//4����������
int* LSDSort(int *arr, size_t n)
{
	int i;
	int maxValue = arr[0];
	for (i = 1; i < n; i++) {
		if (arr[i] > maxValue) {
			maxValue = arr[i];
			// ���ݵ����ֵ
		}
	}
	const int radixCnt = 10;
	vector<int> radixs[radixCnt];
	int maxDigit = 0;
	while (maxValue) {
		maxValue /= 10;
		maxDigit++;
	}
	for (int i = 0, dev = 1; i < maxDigit; i++, dev *= 10) {
		for (int j = 0; j < radixCnt; j++) {
			radixs[j].clear();
		}
		for (int j = 0; j < n; j++) {
			int digit = (arr[j] / dev) % 10;
			radixs[digit].push_back(arr[j]);
		}
		for (int j = 0, t = 0; j < radixCnt; j++) {
			for (int k = 0; k<int(radixs[j].size()); k++) {
				arr[t++] = radixs[j][k];
			}
		}
	}
	return arr;
}

//5���鲢����
int* merge_array(int *arr1, int n1, int* arr2, int n2)
//  ���ʵ��������������arr1��arr2�ϲ�
//  ������������������arr1 ����arr1���� ��������arr2 ����arr2����
//  ��������ֵ�����ش�С���������ĺϲ�����
{
	int* arr = (int*)malloc(sizeof(int)*(n1 + n2));
	int p = 0;
	int p1 = 0;
	int p2 = 0;
	while (p1 < n1 || p2 < n2) {
		if (p1 < n1 && p2 < n2) {
			if (arr1[p1] < arr2[p2]) {
				arr[p++] = arr1[p1++];
			}
			else {
				arr[p++] = arr2[p2++];
			}
		}
		else if (p1 < n1) {
			arr[p++] = arr1[p1++];
		}
		else if (p2 < n2) {
			arr[p++] = arr2[p2++];
		}
	}
	return arr;
}
int* merge_sort(int *arr, int n)
//  ����merge_array�������ʵ�ֹ鲢�������϶��µĵݹ鷽��
//  ������������������arr ����arr����
//  ��������ֵ�����ش�С��������������
{
	if (n == 1) {
		return arr;
	}
	int m = n / 2;
	int* arr1 = (int*)malloc(sizeof(int)*(m));
	int* arr2 = (int*)malloc(sizeof(int)*(n - m));
	for (int i = 0, j = 0; i < m; i++, j++) {
		arr1[j] = arr[i];
	}
	for (int i = m, j = 0; i < n; i++, j++) {
		arr2[j] = arr[i];
	}
	arr1 = merge_sort(arr1, m);
	arr2 = merge_sort(arr2, n - m);
	return merge_array(arr1, m, arr2, n - m);
}

int main(void)
{
	
	int a[N], i, j, p;
	double start, finish; /* ���忪ʼ��ʱ��ͽ�����ʱ�� */
	srand(time(0));
	for (i = 0; i < N; i++) {
		a[i] = rand() % 50000;
	}
		start = (double)clock();
		InsertSort(a, N);
		finish = (double)clock();
		printf("��������:%.4fms\n", (finish - start));

		start = (double)clock();
		SelectSort(a, N);
		finish = (double)clock();
		printf("ѡ������:%.4fms\n", (finish - start));


		start = (double)clock();
		quick_sort(a, 0,N-1);
		finish = (double)clock();
		printf("��������:%.4fms\n", (finish - start));


		start = (double)clock();
		LSDSort(a, N);
		finish = (double)clock();
		printf("��������:%.4fms\n", (finish - start));


		start = (double)clock();
		merge_sort(a,N);
		finish = (double)clock();
		printf("�鲢����:%.4fms\n", (finish - start));

}