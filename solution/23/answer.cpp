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
        if(lists.size()==0)return NULL;
        if(lists.size()==1)return lists[0];
        if(lists.size()==2)return mergeseLists(lists[0], lists[1]);
        int mid = lists.size() / 2;
        std::vector<ListNode*> newlistl1;
        std::vector<ListNode*> newlistl2;
        for(int i = 0;i< mid;i++){
            newlistl1.push_back(lists[i]);
        }
        for(int i = mid;i< lists.size();i++){
            newlistl2.push_back(lists[i]);
        }
        ListNode* l1 = mergeKLists(newlistl1);
        ListNode* l2 = mergeKLists(newlistl2);
        return mergeseLists(l1, l2);
    }
    ListNode* mergeseLists(ListNode* l1, ListNode* l2){
        ListNode newhead(0);
        ListNode* newheadp = &newhead;
        while(l1&&l2){
            if(l1->val < l2->val){
                newheadp->next = l1;
                l1 = l1->next;
            }else{
                newheadp->next = l2;
                l2 = l2->next;
            }
            newheadp = newheadp->next;
        }
        if(l1){
            newheadp->next = l1;
        }
        if(l2){
            newheadp->next = l2;
        }
        return newhead.next;
    }
};