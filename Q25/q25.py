# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        def reverseGroup(head: ListNode, k: int) -> ListNode:
            FirstNode = head
            PreNode = head
            CurrentNode = head.next
            for i in range(k-1):
                head = CurrentNode.next
                CurrentNode.next = PreNode
                PreNode = CurrentNode
                CurrentNode = head
            FirstNode.next = CurrentNode
            return PreNode
        reverse = k
        first = 0
        firstNode = head
        if reverse == 0 or reverse == 1:
            return firstNode
        ReverseHead = head
        while head:
            if reverse == k:
                LastReverse = ReverseHead
                ReverseHead = head
            reverse-=1
            head = head.next
            if reverse == 0:
                Current = reverseGroup(ReverseHead, k)
                if first == 0:
                    firstNode = Current
                    first = 1
                else:
                    LastReverse.next = Current
                reverse = k
        return firstNode
a = ListNode(1)
print("INPUT:",a.val, end="")
c = a
for i in range(0,5):
    b=ListNode(i+2)
    a.next = b
    a = a.next
    print(a.val, end="")
for i in range(0,3):
    d=Solution.reverseKGroup(c, c, i)
    print("\nk = ",i)
    while d:
        print(d.val,end="")
        d=d.next
