struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr)
    {
    }
};

class Solution
{
  public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr)
        {
            return true;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            if (fast->next == slow || fast->next->next == slow)
            {
                return true;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        return false;
    }
};