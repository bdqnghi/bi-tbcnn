void merge(int a[], int begin, int mid, int last, int temp[]){
    int i = begin, j = mid + 1;
    int n = mid, m = last;
    int k = 0;
    while(i <= n && j <= m)
    {
	if(a[i] < a[j])
	    temp[k++] = a[i++];
        else
	    temp[k++] = a[j++];
    }
    while(i <= n)
	temp[k++] = a[i++];
    while(j <= m)
	temp[k++] = a[j++];
    for(i = 0; i < k; i++)
    {
	a[begin + i] = temp[i];
    }
}

void sort(int a[], int begin, int last, int temp[]){
    if(begin < last){
	int mid = begin + (last - begin) / 2;
	sort(a, begin, mid, temp);
	sort(a, mid + 1, last, temp);
	merge(a, begin, mid, last, temp);
    }
}

