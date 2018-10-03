#include <iostream>
#define MAXN 100000
using namespace std;
int main() {
	int S, W, C, K, M;
	while(scanf("%d%d%d%d%d", &S, &W, &C, &K, &M) != EOF) {
		int heap[MAXN], rem = 10000, t = 0;
		if(9999 / C + 1 < K)
			K = 9999 / C + 1;
		for(int i = 0; i < K; ++i)
			heap[i] = (i + 1) * M + S;
		make_heap(heap, heap + K, greater<int>());
		while(rem > 0) {
			pop_heap(heap, heap + K, greater<int>());
			if(heap[K - 1] <= t) {
				t += W;
				heap[K - 1] = t + 2 * S;
			}
			else {
				t = heap[K - 1] + W;
				heap[K - 1] += W + 2 * S;
			}
			push_heap(heap, heap + K, greater<int>());
			rem -= C;
		}
		t += S;
		printf("%d\n", t);
	}
	return 0;
}
