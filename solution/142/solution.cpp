#include <stdio.h>
#include <set>

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL){}
};

class Solution{
public:
    ListNode* hasCycle(ListNode *head){
        std::set<ListNode*> nodeset;
        while(head){
            if(nodeset.find(head)!=nodeset.end()){
                return head;
            }
            nodeset.insert(head);
            head = head->next;
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
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &c;
    Solution s;
    ListNode* x = s.hasCycle(&a);
    printf("%d\n", x->val);
}