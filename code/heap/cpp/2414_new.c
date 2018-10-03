
#include "fibonacci.h"
 
int keys[10] = {1, 2, 3, 4, 5, 6, 7, 9, 10, 11};
 
int main() {
    FibHeap * heap = NULL;
    FibNode * x = NULL;
    heap = FibHeapMake();
    FibHeapInsertKeys(heap, keys, 10);
    printf("print the heap:\n");
    FibHeapPrint(heap);
 
    x = FibHeapExtractMin(heap);
    printf("抽取最小值%d之后：\n", x->key);
    FibHeapPrint(heap);
 
    x = FibHeapSearch(heap, 11);
    if (NULL != x) {
        printf("查找%d成功,", x->key);
        FibHeapDecrease(heap, x, 8);
        printf("减小到%d后：\n", x->key);
        FibHeapPrint(heap);
    }
 
 
    x = FibHeapSearch(heap, 7);
    if (NULL != x) {
        printf("删除%d成功:\n", x->key);
        FibHeapDelete(heap, x);
        FibHeapPrint(heap);
    }
 
    FibHeapDestory(heap);
    return 0;
}
