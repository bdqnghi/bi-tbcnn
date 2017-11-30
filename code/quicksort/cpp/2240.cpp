#include "inc\mc.h"
#include "inc\mui.h"
#include "inc\sort.h"

#define MAXSTACK 2048		// ������������ ������ �����
#define SWAP(x, y) { void* t = a[x]; a[x] = a[y]; a[y] = t;  }

void quickSort(void** a, long size, IsGreaterFunc gt)
{

	long i, j;   		// ���������, ����������� � ����������
	long lb, ub;  		// ������� ������������ � ����� ���������
	long* lbstack = new long[MAXSTACK];
	if (!lbstack)
	{
		MsgBoxError(muitxt(ind_err_nomemory));
		return;
	}
	long* ubstack = new long[MAXSTACK]; // ���� ��������
	if (!ubstack)
	{
		delete (lbstack);
		MsgBoxError(muitxt(ind_err_nomemory));
		return;
	}
	// ������ ������ �������� ����� ��������,
	// � ������: �����(lbstack) � ������(ubstack) 
	// ��������� ����������
	long stackpos = 1;   	// ������� ������� �����
	long ppos;			// �������� �������
	void* pivot;		  // ������� �������

	lbstack[1] = 0;
	ubstack[1] = size-1;

	do
	{
		// ����� ������� lb � ub �������� ������� �� �����.
		lb = lbstack[stackpos];
		ub = ubstack[stackpos];
		stackpos--;

		do
		{
			// ��� 1. ���������� �� �������� pivot
			ppos = ( lb + ub ) >> 1;
			i = lb; j = ub; pivot = a[ppos];

			do
			{
				while (gt(pivot, a[i])) i++;
				while (gt(a[j], pivot)) j--;

				if (i <= j)
				{
					SWAP(i, j);
					i++; j--;
				}
			}
			while ( i <= j );

			// ������ ��������� i ��������� �� ������ ������� ����������,
			// j - �� ����� ������ (��. ����������� ����), lb ? j ? i ? ub.
			// �������� ������, ����� ��������� i ��� j ������� �� ������� �������

			// ���� 2, 3. ���������� ������� ����� � ����  � ������� lb,ub

			if (i < ppos) // ������ ����� ������
			{	 
				if (i < ub) //  ���� � ��� ������ 1 �������� - ����� 
				{	 
					stackpos++;	   //  �����������, ������ � ����
					lbstack[stackpos] = i;
					ubstack[stackpos] = ub;
				}
				ub = j;			 //  ��������� �������� ����������
				//  ����� �������� � ����� ������
			}
			else // ����� ����� ������
			{	   		
				if ( j > lb )
				{ 
					stackpos++;
					lbstack[stackpos] = lb;
					ubstack[stackpos] = j;
				}
				lb = i;
			}

		}
		while (lb < ub);		// ���� � ������� ����� ����� 1 ��������
	}
	while (stackpos != 0);	// ���� ���� ������� � �����
	
	delete (ubstack);
	delete (lbstack);
}

void quickSort1(void** a, long size, IsGreaterFunc gt)
{
  long i = 0, j = size - 1; // ��������� ��������
  void *temp;
  void *p = a[ size>>1 ]; // �������� ��������
  // ��������� ����������
  do {
    while (gt(p,a[i])) i++;
    while (gt(a[j],p)) j--;
    
    if (i <= j) {
      SWAP(i, j);
      i++; j--;
    }
  } while (i <= j);
  
  // ����������� ������, ���� ����, ��� �����������
  if ( j > 0 ) quickSort(a, j,gt);
  if ( size > i ) quickSort(a+i, size-i,gt);
}