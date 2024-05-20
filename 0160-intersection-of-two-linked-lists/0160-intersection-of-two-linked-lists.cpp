/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curr1 = headA;
        ListNode* curr2 = headB;
        int count1=0;
        int count2=0;
        while(curr1!=nullptr){
            curr1=curr1->next;
            count1++;
        }
        while(curr2!=nullptr){
            curr2=curr2->next;
            count2++;
        }
        int l1=0;
        int l2=0;
        if(count1>count2){
             l1=count1;
             l2=count2;
            curr1=headA;
            curr2=headB;
        }
        else{
             l2=count1;
            l1=count2;
            curr2=headA;
            curr1=headB;
        }
       cout<<l1<<" "<<l2<<endl;
        int diff = l1-l2;
        for(int i=0;i<diff;i++){
            curr1=curr1->next;
        }
        while(curr1!=curr2){
            curr1=curr1->next;
            curr2=curr2->next;
        }
        return curr1;


    }
};