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
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        
        // Step 2: Save the next node's address so we can delete it (optional for LeetCode, good for memory)
        ListNode* temp = node->next;
        
        // Step 3: Point the current node to the node after the next one
        node->next = node->next->next;
        
        // Step 4: Delete the redundant node from memory
        delete temp;
        
    }
};