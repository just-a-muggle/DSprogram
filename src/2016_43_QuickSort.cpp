////////////////////
/// Author: Achang
/// Date: 2025/9/3
/// Version: 2.0
////////

#include <iostream>
using namespace std;
const int N = 100010;
int a[N];
int n, k;

int func(int a[], int mid, int n){
    int sumS1 = 0, sumS2 = 0;
  
    for(int i = 0; i <= mid; i ++) {
        sumS1 += a[i]; 
    }
    for(int i = mid + 1; i < n; i ++) {
        sumS2 += a[i]; 
    }
    // cout << "  s1 s2----- "<< sumS1 << " " << sumS2 << endl;
    return sumS2 - sumS1;
}


int findK(int a[], int l, int r, int k){
    //数组中就剩一个数了，就是要找的那个数字
    if(l >= r) return func(a,l,n);
    //选分界线，划分数组。这里选的是中间的数字
    int x = a[l + r >> 1];
    int i = l - 1, j = r + 1;
    while(i < j){
        while(a[++i] < x);
        while(a[--j] > x);
        if(i < j){
            swap(a[i], a[j]);
        }
    }
    //判断分界线与k的关系，
    //如果k在分界线左边，处理左半部分数组
    //注意：这里j是数组下标从0开始，k是从1开始编号的，
    //j指向的是第 j + 1 个元素。
    if(j + 1 >= k)
        return findK(a, l, j, k);
    //否则k在分界线右边，处理左半部分数组
    else 
        return findK(a, j + 1, r, k);
}


int main(){

    cout << "2016_43 V2.0 O(nlogn)" << endl;
    
    cin >> n;
    k = n/2;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << "------" << endl;
    int res = findK(a, 0, n - 1, k);
    cout << res << endl;
    // for (int i = 0; i < n; i ++) cout << a[i] << " " ;
    cout << "press enter to exit" << endl;
    cin.get();
    cin.get();

}
