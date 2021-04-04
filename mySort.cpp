/*
user-defined sort function
using function object
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<char,int> CI_pair;
//function object 
struct cmp
{
    bool operator()(const CI_pair&e1,const CI_pair&e2){
        if(e1.second==e2.second) return e1.first<e2.first;
        return e1.second>e2.second;
    }
}myclass;
int main(){
    vector<CI_pair> vec;
    vec.push_back(make_pair('f',1));
    vec.push_back(make_pair('b',2));
    vec.push_back(make_pair('d',1));
    vec.push_back(make_pair('v',30));
    vec.push_back(make_pair('c',15));
    sort(vec.begin(),vec.end(),myclass);
    for(int i= 0;i<vec.size();++i){
        cout<<vec[i].first<<' '<<vec[i].second<<endl;
    }

}