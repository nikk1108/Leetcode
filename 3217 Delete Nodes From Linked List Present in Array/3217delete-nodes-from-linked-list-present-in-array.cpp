class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());
        ListNode* dummy = new ListNode(0, head);
        ListNode* curr = dummy;
        while (curr->next) {
            if (st.count(curr->next->val))
                curr->next = curr->next->next;
            else
                curr = curr->next;
        }
        return dummy->next;
    }
};
