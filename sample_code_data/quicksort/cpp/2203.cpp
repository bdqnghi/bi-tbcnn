#include "stdafx.h"
#include "ECG.h"
#include "ECGDlg.h"
#include "quicksort.h"

int quicksortClass::randomSelect(struct st_distance_index *&input, int p, int r, int ith)
{
	m_data = input;
	
	int q = 0;
	int k = 0;
	
	if( p == r )
		return m_data[p].index;
	q = randomized_partition(m_data, p, r);
	k = q - p + 1;

	if( ith == k )
		return m_data[q].index;
	else if( ith < k )
		return randomSelect(m_data, p, q-1, ith);
	else
		return randomSelect(m_data, q+1, r, ith - k);
}

void quicksortClass::myquicksort(struct st_distance_index *&input, int p, int r)
{
	m_data = input;

	int q = 0;

	if( p < r )
		q = randomized_partition(m_data, p, r);
	else
		return ;
	myquicksort(m_data, p, q-1);
	myquicksort(m_data, q+1,r);
}

int quicksortClass::randomized_partition(struct st_distance_index *&input, int p, int r)
{
	m_data = input;
	//pick_pivot(m_data, p, r);

	double temp;
	int idx;
	double x = m_data[r].data;
	int i = p - 1;
	for(int j = p; j < r ; j++)
	{
		if(m_data[j].data <= x)
		{
			i++;
			temp = m_data[j].data;
			m_data[j].data = m_data[i].data;
			m_data[i].data = temp;

			idx = m_data[j].index;
			m_data[j].index = m_data[i].index;
			m_data[i].index = idx;
		}
	}
	temp = m_data[i+1].data;
	m_data[i+1].data = m_data[r].data;
	m_data[r].data = temp;

	idx = m_data[i+1].index;
	m_data[i+1].index = m_data[r].index;
	m_data[r].index = idx;
	return i+1;
}


/*void quicksortClass::pick_pivot(struct st_distance_index *&a, int p, int r)
{
	srand(time(NULL));

	int rnd = rand()%(r-p+1) + p;

	double temp = a[r].data;
	a[r].data = a[rnd].data;
	a[rnd].data = temp;

	int idx = a[r].index;
	a[r].index = a[rnd].index;
	a[rnd].index = idx;
}*/
