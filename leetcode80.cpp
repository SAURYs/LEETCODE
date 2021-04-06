#include<iostream>
#include<vector>
using namespace std;
int removeDuplicates(vector<int>&nums){
    int size = nums.size();
    //如果小于3则直接返回i
    if(size<3) return size;
    int i = 2;int j=2;
    //i结果数组下标，j数组下标
    while(j<size){
        if(nums[j]!=nums[i-2]){
            nums[i] = nums[j];
            ++i;
        }
        ++j;
    }
    return i;

}
