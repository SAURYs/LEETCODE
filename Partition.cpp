#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
int Partition(vector<int>&a,int start, int end){
    int pivot = rand()%(end-start+1)+start;
    swap(a[pivot],a[end]);
    int i = start-1;
    for(int j=start;j<end;++j){
        if(a[j]<a[end]){
            ++i;
            if(a[j]!=a[i])
                swap(a[i],a[j]);
        }
        
    }
    swap(a[i+1],a[end]);
    return i+1;
}

void QuickSort(vector<int>&data,int start,int end){
    if(start==end) return;
    int index = Partition(data,start,end);
    if(index>start)
        QuickSort(data,start,index-1);
    if(index<end)
        QuickSort(data,index+1,end);
}

int main(){
   
    vector<int> data = {1,3,1,2,1};

    QuickSort(data,0,4);
    for(int i = 0;i<5;++i){
        cout<<data[i]<<' ';
    }
  
    return 0;
}