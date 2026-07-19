class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if (head == NULL || head->next == NULL || k == 0)
            return head;

        // Find length and tail
        int length = 1;
        ListNode* tail = head;

        while (tail->next) {
            tail = tail->next;
            length++;
        }

        k = k % length;

        if (k == 0)
            return head;

        // Make circular list
        tail->next = head;

        // Find new tail
        ListNode* newTail = head;

        for (int i = 1; i < length - k; i++)
            newTail = newTail->next;

        // New head
        ListNode* newHead = newTail->next;

        // Break the circle
        newTail->next = NULL;

        return newHead;
    }
};