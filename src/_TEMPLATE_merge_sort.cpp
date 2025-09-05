#include <iostream>

using namespace std;

const int N = 100010;
int n;
int a[N];
int temp[N];

void merge_sort(int a[], int l, int r)
{
    //只剩一个元素的时候已经有序，返回
    if(l >= r) return;
    //寻找数组重点下标
    int mid = (l + r) >> 1;
    //递归给左半边排序
    merge_sort(a, l, mid);
    //递归给右半边排序
    merge_sort(a, mid + 1, r);

    //以下是合并排序好的两个数组
    // k:遍历合并后的数组下标
    int k = 0;
    // i:左半边数组的下标 
    // j:右半边数组的下标
    int i = l, j = mid + 1;

    while (i <= mid && j <= r)
    {
        //左边的元素小于右边的元素
        if(a[i] < a[j])
            temp[k ++] = a[i ++];
        else
            temp[k ++] = a[j ++];
    }
    //如果左边数组有剩余，则放入临时数组
    while(i <= mid) temp[k ++] = a[i ++];
    //如果有边数组有剩余，则放入临时数组
    while(j <= r) temp[k ++] = a[j ++];
    //把临时数组中的元素拷贝至原数组
    k = 0;
    for(int i = 1; i <= r; i ++)
    {
        a[i] = temp[k ++];
    }

}

int main(){
    cin >> n;

    for(int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }

    merge_sort(a, 0, n - 1);

    for(int i = 0; i < n; i ++)
    {
        cout << a[i] << " ";
    }
}