void Merge(int a[],int left,int mid,int right){
	int i=left,j=mid+1,k=left;
	int b[100];
	while(i<=mid&&j<=right){
		if(a[i]>a[j]) b[k++]=a[i++];
		else b[k++]=a[j++];		
	}
	if(i>mid){
		while(j<=right) b[k++]=a[j++];		
	}
	else{
		while(i<=mid) b[k++]=a[i++];
	}
	for(int q=left;q<=right;q++){
		a[q]=b[q];
	}
}

void MergeSort(int a[],int left,int right){
	 if(left < right)    
    {
        int mid = (right + left)/2;
        MergeSort(a, left, mid);
        MergeSort(a, mid+1, right);
        Merge(a, left, mid, right); 
    }
}