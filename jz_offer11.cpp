#include<vector>
#include<iostream>
#include<sstream>
using namespace std;
int helper(vector<int>&numbers,int index1,int index2);
int minArray(vector<int>& numbers);

int main(){
    string input;
    getline(cin,input);
    if(input.size()==2){
        cout<<"Invalid Parameters";
        return 0;
    }
    input = input.substr(1,input.size()-2);
    vector<int> nums;
    istringstream input_str(input);
    string input_elem;
    while(getline(input_str,input_elem,',')){
        nums.push_back(stoi(input_elem));
        //cout<<input_elem<<" ";
    }
    cout<<endl;
    int res = minArray(nums);
    cout<<res<<endl;
    
    
}
int minArray(vector<int>& numbers){
    int length = numbers.size();
    if(!length) throw "Invalid Parameters";
    int index1 = 0;
    int index2 = numbers.size()-1;
    int midIndex = index1;
    while(numbers[index1]>=numbers[index2]){
        if((index2-index1)==1) return numbers[index2];
        midIndex = index1+(index2-index1)/2;
        if(numbers[index2]==numbers[index1]&&numbers[index2]==numbers[midIndex])
            return helper(numbers,index1,index2);
        if(numbers[midIndex]>=numbers[index1]){
            index1 = midIndex;
        }
        else if(numbers[midIndex]<=numbers[index2]){
            index2 = midIndex;
        }

    }
    return numbers[midIndex];

}
int helper(vector<int>&numbers,int index1,int index2){
    int res = numbers[index1];
    for(int i = index1+1;i<=index2;++i){
        if(res>numbers[i])
            res = numbers[i];
    }
    return res;
}