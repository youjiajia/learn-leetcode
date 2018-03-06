#include <stdio.h>
#include <set>

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL){}
};

void printALL(ListNode *head, const char *name){
    printf("%s: ", name);
    if(!head){
        printf("\n");
        return;
    }
    while(head){
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

class Solution{
public:
    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB){
        std::set<ListNode*> listaset;
        while(headA){
            listaset.insert(headA);
            headA = headA->next;
        }
        while(headB){
            if(listaset.find(headB)!=listaset.end()){
                return headB;
            }
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
    g.next = &b;
    ListNode *headA = &a;
    ListNode *headB = &e;
    ListNode *result = NULL;
    printALL(headA, "headA");
    printALL(headB, "headB");
    Solution s;
    result = s.getIntersectionNode(headA, headB);
    printALL(result, "result");
}