#include <stdio.h>

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

void printList(ListNode* head, const char *name){
    printf("%s:", name);
    if(!head){
        printf("NULL\n");
        return;
    }
    while(head){
        printf("%d", head->val);
        head = head->next;
    }
    printf("\n");
}

class Solution{
public:
    ListNode* reverseList(ListNode* head){
        ListNode *newhead=NULL;
        while(head){
            ListNode *next = head->next;
            head->next = newhead;
            newhead = head;
            head = next;
        }
        return newhead;
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
    Solution s;
    ListNode *head = &a;
    printList(head, "old");
    head = s.reverseList(head);
    printList(head, "new");
    return 0;
}