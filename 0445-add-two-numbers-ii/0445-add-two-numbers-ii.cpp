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
    // Helper function to reverse the linked list
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next; // Save next node
            curr->next = prev; // Reverse current node's pointer
            prev = curr; // Move prev and curr one step forward
            curr = nextTemp;
        }
        return prev; // New head of the reversed list
    }

    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
        // Reverse both lists
        ListNode* l1 = reverse(head1);
        ListNode* l2 = reverse(head2);

        // Initialize a dummy node to build the result list
        ListNode dummy(0);
        ListNode* curr = &dummy;
        int carry = 0;

        // Traverse both lists
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            if (l1 != nullptr) {
                carry += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                carry += l2->val;
                l2 = l2->next;
            }
            // Add the carry (sum of current digits) to the new list
            curr->next = new ListNode(carry % 10);
            carry /= 10;
            curr = curr->next;
        }

        // The result list is currently reversed
        return reverse(dummy.next);
    }
};
