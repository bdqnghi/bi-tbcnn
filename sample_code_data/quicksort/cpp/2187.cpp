#include <stdio.h>
#define MaxSize 100

typedef int KeyType;       /*�ؼ�������*/

typedef char ElemType[10]; /*��������������*/

typedef struct {
    KeyType key;                            /*�ؼ�����*/
    ElemType data;                          /*����������*/
} LineList;                                 /*���Ա�Ԫ������*/

void QuickSort(LineList R [], int s, int t) /*��R[s]��R[t]��Ԫ�ؽ��п�������*/
{
    int i = s, j = t;
    LineList tmp;

    if (s < t) {       /*���������ٴ���һ��Ԫ�ص����*/
        tmp = R[s];    /*������ĵ�1����¼��Ϊ��׼*/

        while (i != j) { /*���������˽������м�ɨ��,ֱ��i=jΪֹ*/
            while (j > i && R[j].key > tmp.key)
                j--;     /*��������ɨ��,�ҵ�1���ؼ���С��tmp.key��R[j]*/

            R[i] = R[j]; /*�ҵ�������R[j],��R[i]��R[j]����*/

            while (i < j && R[i].key < tmp.key)
                i++;     /*��������ɨ��,�ҵ�1���ؼ��ִ���tmp.key��R[i]*/

            R[j] = R[i]; /*�ҵ�������R[i],��R[i]��R[j]����*/
        }

        R[i] = tmp;
        QuickSort(R, s, i - 1); /*��������ݹ�����*/
        QuickSort(R, i + 1, t); /*��������ݹ�����*/
    }
}
void main()
{
    LineList R[MaxSize];
    KeyType a [] = {
        75, 87, 68, 92, 88, 61, 77, 96, 80, 72
    };
    int n = 10, i;

    for (i = 0; i < n; i++)
        R[i].key = a[i];

    printf("����ǰ:");

    for (i = 0; i < n; i++)
        printf("%3d", R[i].key);

    printf("\n");
    QuickSort(R, 0, n - 1);
    printf("�����:");

    for (i = 0; i < n; i++)
        printf("%3d", R[i].key);

    printf("\n");
}
