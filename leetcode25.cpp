#include <iostream>
#include <vector>
#include<string>
#include<sstream>

typedef struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode() : val(0), next(NULL) {}
    ListNode(ListNode *node) : val(node->val), next(node->next) {}
} ListNode;

//
// reverse nodes between node a and node b[a,b)
ListNode *reverse(ListNode *a, ListNode *b)
{
    if (a == NULL)
        return NULL;
    ListNode *pre = NULL;
    ListNode *cur = a;
    ListNode *nxt = a;
    while (cur != b)
    {
        nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }
    return pre;
}

// reverse the nodes of a linked list k at a time and return its modified list
ListNode* reverseKgroup(ListNode *head, int k)
{
    if (head == NULL)
        return head;
    ListNode *a, *b;
    a = b = head;
    while (k--)
    {
        if (b == NULL)
            return head;
        b = b->next;
    }
    //reverse node between a and b [a,b)
    ListNode *newHead = reverse(a, b);
    // link a and  next newHead
    a->next = reverseKgroup(b, k);
    return newHead;
}
ListNode* buildList(const std::vector<int> &vec)
{
    if (vec.empty())
        return NULL;
    ListNode *head = new ListNode(vec[0]);
    ListNode *pHead = head;
    for (int i = 1; i < vec.size(); i++)
    {
        pHead->next = new ListNode(vec[i]);
        pHead = pHead->next;
    }
    pHead->next = NULL;
    return head;
}

void printLink(ListNode* head){
    if(head==NULL) return;
    ListNode* pHead = head;;
    while(pHead){
        std::cout<<pHead->val<<' ';
        pHead = pHead->next;
    }
    std::cout<<std::endl;
    return;
}
//input1: [1,2,3,4,5],4
//input2:[1],4
//input:[],1
int main()
{
    using namespace std;
    cout<<"please input as the format below:"<<endl;
    cout<<"[1,2,3,4,5],2"<<endl;
    cout<<"-------------------"<<endl;
    string input;
    if(!(getline(cin,input))) exit(-1);
    istringstream inputStream(input);
    string linkValueString;
    if(!getline(inputStream,linkValueString,']')) exit(-1);
    string groupStr;
    getline(inputStream,groupStr);
    linkValueString = linkValueString.substr(1,linkValueString.size()-1);
    vector<int>valueVec;
    istringstream valueInput(linkValueString);
    string tmp;
    while(getline(valueInput,tmp,',')){
        valueVec.push_back(stoi(tmp));
    }
    int group = stoi(groupStr.substr(1,groupStr.size()-1));
    ListNode* head = buildList(valueVec);
    cout<<"before:"<<endl;
    printLink(head);
    ListNode* res = reverseKgroup(head,group);
    cout<<endl;

    cout<<"after:"<<endl;
    printLink(res);
    exit(0);

    

    
}