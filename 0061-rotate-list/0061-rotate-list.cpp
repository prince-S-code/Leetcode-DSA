class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // Edge cases
        if (!head || !head->next || k == 0) return head;

        // Step 1: find length and tail
        ListNode* tail = head;
        int n = 1;

        while (tail->next) {
            tail = tail->next;
            n++;
        }

        // Step 2: make it circular
        tail->next = head;

        // Step 3: reduce k
        k = k % n;

        // Step 4: find new tail
        int steps = n - k - 1;
        ListNode* newTail = head;

        while (steps--) {
            newTail = newTail->next;
        }

        // Step 5: break the cycle
        ListNode* newHead = newTail->next;
        newTail->next = NULL;

        return newHead;
    }
};
