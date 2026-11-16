
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        // Check empty list or single node
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }

        // Find length and last node
        int n = 1;
        ListNode* tail = head;

        while (tail->next != nullptr) {
            tail = tail->next;
            n++;
        }

        // Calculate effective rotations
        k = k % n;

        if (k == 0) {
            return head;
        }

        // Make circular linked list
        tail->next = head;

        // Find new tail
        int steps = n - k;
        ListNode* newTail = head;

        for (int i = 1; i < steps; i++) {
            newTail = newTail->next;
        }

        // Find new head
        ListNode* newHead = newTail->next;

        // Break circular connection
        newTail->next = nullptr;

        return newHead;
    }
};
