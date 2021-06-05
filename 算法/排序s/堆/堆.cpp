#include <iostream>
#include <vector>
using namespace std;

//假设是一个大根堆
void heapify(vector<int> arr,int n)
{
    if(n==0)
        return;
    else 
    {
        //找到父亲节点
        int father = (n%2==0)?n/2-1:n/2;
        if(arr[n]<=arr[father])//这时候子节点的值小于等于父节点 符合大根堆
        {
            return;
        }
        else 
        {
            //交换父子节点，同时继续处理
            swap(arr[n],arr[father]);
            heapify(arr,father);
        }
    }
    return;
}