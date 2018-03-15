#include <stdio.h>
#include <vector>

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


class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        return mergeseLists(0, lists.size()-1, lists);
    }
    ListNode* mergeseLists(int s, int e, std::vector<ListNode*>& lists){
        if(lists.size()<1){return NULL;}
        if(s == e){return lists[s];}
        // if(e-s>1){
            int mid = (e + s)/2;
            ListNode* left = mergeseLists(s, mid, lists);
            ListNode* right = mergeseLists(mid, e, lists);
        // }
        ListNode newhead(0);
        ListNode* newheadp = &newhead;
        while(left&&right){
            if(left->val < right->val){
                newheadp->next = left;
                left = left->next;
            }else{
                newheadp->next = right;
                right = right->next;
            }
            newheadp = newheadp->next;
        }
        if(left){
            newheadp->next = left;
        }
        if(right){
            newheadp->next = right;
        }
        return newhead.next;
    }
};