#include <stdio.h>

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL){}
};

void printALL(ListNode *head, const char *name){
    printf("%s: ", name);
    if(!head){
        printf("NULL\n");
        return;
    }
    while(head){
        printf("%d", head->val);
        head = head->next;
    }
    printf("\n");
};


class Solution{
public:
    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2){
        ListNode newhead(0);
        ListNode *newpoint = &newhead;
        while(l1&&l2){
            if(l1->val<l2->val){
                newpoint->next = l1;
                l1 = l1->next;
            }else{
                newpoint->next = l2;
                l2 = l2->next;
            }
            newpoint = newpoint->next;
        }
        if(l1){
            newpoint->next = l1;
        }
        if(l2){
            newpoint->next = l2;
        }
        return newhead.next;
    }
};

int main(){
    ListNode a(1);
    ListNode b(3);
    ListNode c(5);
    a.next = &b;
    b.next = &c;
    ListNode *l1 = &a;
    ListNode d(2);
    ListNode e(6);
    ListNode f(9);
    d.next = &e;
    e.next = &f;
    ListNode *l2 = &d;
    ListNode *newhead = NULL;
    printALL(l1, "l1");
    printALL(l2, "l2");
    Solution s;
    newhead = s.mergeTwoLists(l1, l2);
    printALL(newhead, "newhead");
}