#include<vector>
using namespace std;
class Solution {
public:
    void maxHeapify(vector<int>& a,int i,int heapsize){
        int l = i * 2 + 1;
        int r = i * 2 + 2;
        int largest = i;
        if (l < heapsize && a[l] > a[largest]){
            largest = l;
        }
        if (r < heapsize && a[r] > a[largest]){
            largest = r;
        }
        if (largest != i){
            swap(a[i],a[largest]);
            maxHeapify(a,largest,heapsize);
        }
    }
    void buildMaxHeap(vector<int>& a,int heapSize){
        for(int i = heapSize/2;i>=0;--i){
            maxHeapify(a,i,heapSize);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        int heapSize = nums.size();
        buildMaxHeap(nums, heapSize);
        for(int i = nums.size() - 1; i >= nums.size()-k+1;--i){
            swap(nums[0],nums[i]);
            --heapSize;
            maxHeapify(nums,0,heapSize);            
        }
        return nums[0];
    }
};