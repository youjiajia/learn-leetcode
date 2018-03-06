#include <stdio.h>

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL){}
};

void printAll(ListNode *head, const char *name){
    printf("%s:", name);
    if(!head){
        printf("NULL\n");
        return;
    }
    while(head){
        printf(" %d", head->val);
        head = head->next;
    }
    printf("\n");
}

int getListNodeLen(ListNode *head){
    int len = 0;
    while(head){
        len++;
        head = head->next;
    };
    return len;
}

ListNode* forward_long_ListNode(int longlen, int shortlen, ListNode *head){
    int subab = longlen - shortlen;
    while(head && subab){
        head = head->next;
        subab--;
    };
    return head;
}

class Solution{
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB){
        int lenA = getListNodeLen(headA);
        int lenB = getListNodeLen(headB);
        if(lenA>lenB){
            headA = forward_long_ListNode(lenA, lenB, headA);
        }else{
            headB = forward_long_ListNode(lenB, lenA, headB);
        }
        while(headA&&headB){
            if(headA==headB){
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
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
    e.next = &f;
    f.next = &g;
    g.next = &c;
    ListNode *headA = &a;
    ListNode *headB = &e;
    ListNode *result = NULL;
    Solution s;
    printAll(headA, "headA");
    printAll(headB, "headB");
    result = s.getIntersectionNode(headA, headB);
    printAll(result, "result");
}