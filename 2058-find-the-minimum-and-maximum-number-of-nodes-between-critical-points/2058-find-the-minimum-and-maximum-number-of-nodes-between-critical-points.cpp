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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return {-1, -1};
        ListNode* prev = head;
        ListNode* curr = head->next;
        int pos = 1;
        vector<int> critical;
        while (curr->next != nullptr) {
            ListNode* next = curr->next;
            if ((curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val)) {
                critical.push_back(pos);
            }
            prev = curr;
            curr = curr->next;
            pos++;
        }
        if (critical.size() < 2)
            return {-1, -1};
        int minDis = INT_MAX;
        for (int i = 1; i < critical.size(); i++) {
            minDis = min(minDis, critical[i] - critical[i - 1]);
        }
        int maxDis = critical.back() - critical.front();
        return {minDis, maxDis};
    }
};