class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1};

        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return ans;

        ListNode* prev = head;
        ListNode* curr = head->next;

        int pos = 1;
        int first = -1;
        int last = -1;
        int minDist = INT_MAX;

        while (curr->next != nullptr) {
            if ((curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val)) {

                if (first == -1) {
                    first = pos;
                } else {
                    minDist = min(minDist, pos - last);
                }

                last = pos;
            }

            prev = curr;
            curr = curr->next;
            pos++;
        }

        if (first == last)
            return ans;

        int maxDist = last - first;

        ans[0] = minDist;
        ans[1] = maxDist;

        return ans;
    }
};