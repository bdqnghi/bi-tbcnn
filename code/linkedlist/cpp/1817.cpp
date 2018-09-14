#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int val): val(val) {}
};

ListNode* search(ListNode* head, int k) {
  while (head != NULL && head->val != k) {
    head = head->next;
  }
  return head;
}

struct LLNode {
  int val;
  unique_ptr<LLNode> next;
  LLNode(int val): val(val) {}
};

LLNode* search(LLNode* head, int k) {
  while (head != NULL && head->val != k) {
    head = head->next.get();
  }
  return head;
}

void insert(LLNode* head, int k) {
  if (head->next) {
    insert(head->next.get(), k);
  } else {
    head->next.reset(new LLNode(k));
  }
}

int main() {
  unique_ptr<LLNode> head_ptr(new LLNode(1));
  LLNode* runner = head_ptr.get();
  for (int i = 2; i < 10; i++) {
    insert(runner, i);
    runner = runner->next.get();
  }

  LLNode* head = head_ptr.get();

  while (head) {
    cout << head->val << " ";
    head = head->next.get();
  }
  cout << endl;
  return 0;
}
