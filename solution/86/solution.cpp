#include <stdio.h>

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL){}
};

void printALL(ListNode* head, const char* name){
    printf("%s: ", name);
    if(!head){printf("\n");return;}
    while(head){
        printf(" %d", head->val);
        head = head->next;
    }
    printf("\n");

}

class Solution{
public:
    ListNode* partition(ListNode* head, int x){
        ListNode leftpart(0);
        ListNode* leftpindex = &leftpart;
        ListNode rightpart(0);
        ListNode* rightpindex = &rightpart;
        while(head){
            if(head->val < x){
                leftpindex->next = head;
                leftpindex = leftpindex->next;
            }else{
                rightpindex->next = head;
                rightpindex = rightpindex->next;
            }
            head = head->next;
        }
        leftpindex->next = rightpart.next;
        rightpindex->next = NULL;
        return leftpart.next;

    }
};

int main(){
    ListNode a(1);
    ListNode b(4);
    ListNode c(3);
    ListNode d(2);
    ListNode e(5);
    ListNode f(2);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    Solution s;
    ListNode* result = s.partition(&a, 3);
    printALL(result, "result");
}