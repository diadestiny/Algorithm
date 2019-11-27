#include <bits/stdc++.h>
using namespace std;
int a[1000];
void input()
{
    for (int i = 0; i < 1000; i++)
        cin >> a[i];
}
void myswap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void straightInsert(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j;
        for (j = i - 1; j >= 0; j--)
        {
            if (a[j] > temp)
            {
                a[j + 1] = a[j];
            }
            else
            {
                break;
            }
        }
        a[j + 1] = temp;
        print(arr, n);
    }
}
void binaryInsert(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int get = a[i];
        int left = 0;
        int right = i - 1;
        while (left <= right)
        {
            int min = (left + right) / 2;
            if (arr[min] > get)
            {
                right = min - 1;
            }
            else
            {
                left = min + 1;
            }
        }
        for (int j = i - 1; j >= left; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[left] = get;
        print(arr, n);
    }
}
void selectsort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int temp = a[i];
        int index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < temp)
            {
                index = j;
                temp = a[j];
            }
        }
        if (temp < a[i])
        {
            a[index] = a[i];
            a[i] = temp;
        }
        print(arr, n);
    }
}
void buttlesort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                myswap(arr[j + 1], arr[j]);
            }
        }
        print(arr, n);
    }
}
int partition(int arr[], int left, int right) //找基准数 划分
{
    int i = left + 1;
    int j = right;
    int temp = arr[left];
    while (i <= j)
    {
        while (arr[i] < temp)
        {
            i++;
        }
        while (arr[j] > temp)
        {
            j--;
        }
        if (i < j)
            swap(arr[i++], arr[j--]);
        else
            i++;
    }
    swap(arr[j], arr[left]);
    print(arr, 7);
    return j;
}
void adjust(int *arr, int len, int index)
{
    int left = 2 * index + 1;  // index的左子节点
    int right = 2 * index + 2; // index的右子节点

    int maxIdx = index;
    if (left < len && arr[left] > arr[maxIdx])
        maxIdx = left;
    if (right < len && arr[right] > arr[maxIdx])
        maxIdx = right;

    if (maxIdx != index)
    {
        swap(arr[maxIdx], arr[index]);
        adjust(arr, len, maxIdx);
    }
}
// 堆排序
void heapSort(int *arr, int size)
{
    // 构建大根堆（从最后一个非叶子节点向上）
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        adjust(arr, size, i);
    }

    // 调整大根堆
    for (int i = size - 1; i >= 1; i--)
    {
        swap(arr[0], arr[i]); // 将当前最大的放置到数组末尾
        adjust(arr, i, 0);    // 将未完成排序的部分继续进行堆排序
        print(arr, 7);
    }
}
void quick_sort(int arr[], int left, int right)
{

    if (left > right)
        return;
    int j = partition(arr, left, right);
    quick_sort(arr, left, j - 1);
    quick_sort(arr, j + 1, right);
}

int max(int arr[], int n)
{ //此函数用于求解所给数组中最大数有几位
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        int count = 1, tem = arr[i];
        while (tem / 10 != 0)
        { //计算每个数的位数，用count计数
            tem = tem / 10;
            count++;
        }
        if (count > max)
            max = count; //把最大位数赋值max
    }
    return max;
}
void basesort(int arr[], int n)
{
    int maxx = max(arr, n); //取得最大位数
    int num = 1;
    for (int i = 0; i < maxx; i++)
    {                      //位数决定排序循环次数
        int count[10];     //声明count为了统计每个桶放了几个数
        int temp[10]['n']; //temp相当于桶，前一个数标记第几个篮子，后一个为了标记放的个数
        for (int f = 0; f < 10; f++)
        { //对声明数组初始化
            count[f] = 0;
        }
        for (int g = 0; g < 10; g++)
        { //对声明数组初始化
            for (int z = 0; z < n; z++)
            {
                temp[g][z] = 0;
            }
        }
        for (int j = 0; j < n; j++)
        {
            int fg = arr[j] / num; //num是变量，因为每次循环比较的位是不同的
            int k = fg % 10;
            count[k]++;
            int te = count[k] - 1;
            temp[k][te] = arr[j]; //把数据放k桶的te位上存储
        }
        int b = 0;
        for (int h = 0; h < 10; h++)
        {
            if (count[h] > 0)
            { //h>0说明h桶内有数字存储
                for (int v = 0; v < count[h]; v++)
                {                        //count[h]是h桶的存储个数
                    arr[b] = temp[h][v]; //把桶内排好的数全都倒给要排序的数组，进行下轮排序
                    b++;
                }
            }
        }
        print(a, n);
        num = num * 10;
    }
}
/*该函数将数组下标范围[l1,r1]和[l2,r2]的有序序列合并成一个有序序列*/
void merge(int *arr, int l1, int r1, int l2, int r2)
{
    int i = l1;                            //左半部分起始位置
    int j = l2;                            //右半部分起始位置
    int n = (r1 - l1 + 1) + (r2 - l2 + 1); //要合并的元素个数
    vector<int> temp(n);                   //辅助数组
    int k = 0;                             //辅助数组其起始位置
    while (i <= r1 && j <= r2)
    { //挑选两部分中最小的元素放入辅助数组中
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    //如果还有剩余，直接放入到辅助数组中
    while (i <= r1)
        temp[k++] = arr[i++];
    while (j <= r2)
        temp[k++] = arr[j++];
    //更新原始数组元素
    for (int i = 0; i < n; i++)
    {
        arr[l1 + i] = temp[i];
    }
    //print(arr,7);
}

/*二路归并排序（递归实现）*/
void MergeSort(int *arr, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) >> 1;         //分割序列
        MergeSort(arr, start, mid);           //对序列左半部分进行规并排序
        MergeSort(arr, mid + 1, end);         //对序列右半部分进行规并排序
        merge(arr, start, mid, mid + 1, end); //合并已经有序的两个序列
    }
}
void shellsort(int arr[], int n)
{
    int i,j,gap;
	for(gap = n/2;gap>0;gap/=2)
	{
		// 每组进行插入排序
		for(i=0;i<n;i++)
		{
			for(j=i-gap;j>=0;j-=gap)
			{
				if(arr[i]>arr[j])
					break;
			}
			int temp = arr[i];
			for(int k=i;k>j;k-=gap)
				 arr[k] = arr[k-gap];
			arr[j+gap] = temp;
		}
        print(arr, n);
    }
    
}

int main()
{
    //freopen("numbig.txt", "r", stdin);
    //1000
    freopen("numsmall.in", "r", stdin);
    //7
    input();
    print(a, 7);
    // straightInsert(a, 7);
    // binaryInsert(a, 7);
    // selectsort(a, 7);
    // buttlesort(a, 7);
    // quick_sort(a, 0, 6);
    // heapSort(a, 7);
    // basesort(a, 7);
    // MergeSort(a, 0, 6);
    shellsort(a, 7);
    return 0;
}