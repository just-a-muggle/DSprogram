#include <iostream>
using namespace std;

void Reverse(int A[], int start, int end)
{
    int switchNum;

    for(int i = start,j = end;i < j; i ++, j--)
    {
        ///////
        switchNum = A[i];
        A[i] = A[j];
        A[j] = switchNum;
        ///////可以用std::swap(A[i], A[j]);代替
    }
}


////改进


void ReverseNew(int A[], int start, int end){
    int i = start;
    int j = end;
    while(i < j){
        swap(A[i], A[j]);
        i ++;
        j --;
    }

}

void ReverseTotal(int m, int n, int A[])
{
    ReverseNew(A, 0, m - 1);
    ReverseNew(A, m, m + n - 1);
    ReverseNew(A, 0, m + n - 1);
}