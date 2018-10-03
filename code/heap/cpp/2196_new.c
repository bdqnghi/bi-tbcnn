#include <stdio.h>

int heap[5020];
int NumOfHeap;

void insertHeap(int num) {
	int i;
	NumOfHeap++;
	for(i=NumOfHeap;i > 1;i/=2) {
		if(num < heap[i/2])
			heap[i] = heap[i/2];
		else	break;
	}
	heap[i] = num;
}

int deleteHeap() {
	int i,tmp,a;
	tmp = heap[NumOfHeap];
	a = heap[1];
	NumOfHeap--;
	for(i=1;i*2<=NumOfHeap;) {
		if(heap[i*2] <= heap[i*2+1]) {
			if(tmp <= heap[i*2])	break;
			heap[i] = heap[i*2];
			i = i*2;
		} else {
			if(tmp <= heap[i*2+1])	break;
			heap[i] = heap[i*2+1];
			i = i*2+1;
		}
		
	}
	heap[i] = tmp;
	return a;
}

int main() {

	int i,j,n,num;
	int tmp1,tmp2;
	long long ans;
	
	while(scanf("%d",&n) && n) {
		NumOfHeap = 0;
		for(i=0;i<n;i++) {
			scanf("%d",&num);
			insertHeap(num);
		}
		ans = 0;
		for(i=1;i<n;i++) {
			tmp1 = deleteHeap();
			tmp2 = deleteHeap();
			ans += tmp1+tmp2;
			insertHeap(tmp1+tmp2);
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}
