#include <iostream>
#include <vector>
using namespace std;

//假设是一个大根堆
void heapify(vector<int> arr,int index)
{
    int left = 2 * index + 1;//左子节点
    int right = 2* index + 2;//右子节点
    int max_temp = index;
    if(left<arr.size()&&arr[left]>arr[index])
    {
        max_temp = left;
    }
    if(right<arr.size()&&arr[right]>arr[index])
    {
        max_temp = right;
    }
    if(max_temp!=index)
    {
        swap(arr[max_temp],arr[index]);
        heapify(arr,max_temp);
    }
}
void deleteRoot(vector<int> arr)
{
    //删除根节点，并且将最后一个节点放到根节点的位置
    //然后开始自上而下的堆化
    arr[0]=arr[arr.size()-1];
    arr.pop_back();
    heapify(arr,0);
}