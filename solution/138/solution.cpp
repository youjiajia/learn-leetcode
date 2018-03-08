#include <stdio.h>
#include <map>
#include <vector>

struct RandomListNode{
    int label;
    ListNode * next, random;
    RandomListNode(int x):label(x), next(NULL), random(NULL){}
};


class Solution{
public:
    RandomListNode* copyRandomList(RandomListNode* head){
        std::map<RandomListNode*, int> oldmap;
        std::vector<RandomListNode*> newmap;
        RandomListNode *ptr = head;
        int i = 0;
        while(ptr){
            oldmap[ptr] = i;
            newmap.push_back(new RandomListNode(ptr->label));
            ptr = ptr->next;
            i ++;
        }
        newmap.push_back(NULL);
        ptr = head;
        i = 0;
        while(ptr){
            newmap[i]->next = newmap[i+1];
            if(ptr->random){
                int index = oldmap[ptr->random];
                newmap[i]->random = newmap[index];
            }
            ptr = ptr->next;
            i++;
        }
        return newmap[0];
    }
}