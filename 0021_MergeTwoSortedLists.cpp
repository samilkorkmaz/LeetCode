//https://leetcode.com/problems/merge-two-sorted-lists/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void printList(ListNode* l) { //for debugging
        ListNode* start = l;
        while(l) {
            printf("%d, ", l->val);
            l = l->next;
        }
        printf("\n");
        l = start; //point to start of list
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 && l2 ) { //both lists have elements
            ListNode* ml = new ListNode();
            ListNode* cp = ml; //current element
            ListNode* pp = NULL; //previous element
            while(l1 || l2) {
                if((l1 && l2) && (l1->val < l2->val)) {
                    cp->val = l1->val;
                    l1 = l1->next;
                } else if (l2){
                    cp->val = l2->val;
                    l2 = l2->next;
                } else {
                    cp->val = l1->val;
                    l1 = l1->next;
                }
                //printf("cp->val = %d\n", cp->val);
                //printList(ml);                    
                pp = cp;                
                cp->next = new ListNode();
                cp = cp->next;                
            }
            pp->next = NULL; //remove last element which has a default value of zero
            return ml;
        } else { //at least one of the lists is empty
            if(l1 && !l2) return l1;            
            if(!l1 && l2) return l2;
            return NULL; //both lists are empty            
        }
    }
};
