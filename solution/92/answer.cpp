#include <stdio.h>

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL){}
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
    ListNode* reverseBetween(ListNode* head, int m, int n){
        int submn = n-m+1;
        ListNode *result = head;
        ListNode *prehead = NULL;
        while(head&&--m){
            prehead = head;
            head = head->next;
        }
        ListNode *secondend = head;
        ListNode *secondbegin = NULL;
        while(head&&submn--){
            ListNode *next = head->next;
            head->next = secondbegin;
            secondbegin = head;
            head = next;
        }
        secondend->next = head;
        if(prehead){
            prehead->next = secondbegin;
            return result;
        }else{
            return secondbegin;
        }
    }

};

int main(){
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    ListNode f(6);
    ListNode g(7);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = &g;
    ListNode *head = &a;
    printList(head, "old");
    Solution s;
    head = s.reverseBetween(head, 3, 6);
    printList(head, "new");
}