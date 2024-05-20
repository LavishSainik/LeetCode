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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* temp2=nullptr;
        ListNode* temp1=nullptr;
        while(curr!=nullptr){
            
            temp2 = curr->next;
            curr->next=temp1;
            temp1=curr;
            curr=temp2;
        }
        return temp1;
    }
};