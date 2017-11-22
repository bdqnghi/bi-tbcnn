#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct ListNode {
	int element;
	ListNode *prev, *next;
};

// node 이전/이후 노드의 포인터를 바꿔서 node 를 리스트에서 삭제한다
void deleteNode(ListNode* node) {
	node->prev->next = node->next;
	node->next->prev = node->prev;
}

// node 이전/이후 노드의 포인터를 바꿔서 자기 자신을 다시 리스트에 삽입한다
void recoverNode(ListNode* node) {
	node->prev->next = node;
	node->next->prev = node;
}

int main() {
    int cases;
    cin >> cases;
    for(int cc = 0; cc < cases; ++cc) {

    }
}

