class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;          // Move 1 step
            fast = fast->next->next;    // Move 2 steps

            if (slow == fast) {
                return true;            // Cycle found
            }
        }

        return false;                   // No cycle
    }
};