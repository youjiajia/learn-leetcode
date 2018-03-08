#include <stdio.h>
#include <set>

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL){}
};

class Solution{
public:
    bool hasCycle(ListNode *head){
        ListNode* Fasthead = head;
        ListNode* Slowhead = head;
        while(Fasthead && Slowhead){
            Fasthead = Fasthead->next;
            Slowhead = Slowhead->next;
            if(!Fasthead){return false;}
            Fasthead = Fasthead->next;
            if(Fasthead==Slowhead){
                return true;
            }
        }
        return false;
    }
};

int main(){
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &c;
    Solution s;
    bool x = s.hasCycle(&a);
    printf("%d\n", x);
}