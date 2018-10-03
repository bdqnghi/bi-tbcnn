struct node
{
    int l,r,dis,val,dad;
} heap[100005];
int finds(int x)
{
    return heap[x].dad == x ? x : heap[x].dad = finds (heap[x].dad);
}
int merge(int x, int y)
{
    if (!x) return y;
    if (!y) return x;
    if (heap[y].val > heap[x].val) swap (x, y);
    heap[x].r = merge (heap[x].r, y);
    heap[heap[x].r].dad = x;
    if (heap[heap[x].l].dis < heap[heap[x].r].dis)
        swap (heap[x].l, heap[x].r);
    if (heap[x].r == 0) heap[x].dis = 0;
    else heap[x].dis = heap[heap[x].r].dis + 1;
    return x;
}
int pop(int x)
{
    int l = heap[x].l;
    int r = heap[x].r;
    heap[l].dad = l;
    heap[r].dad = r;
    heap[x].l = heap[x].r = heap[x].dis = 0;
    return merge(l, r);
}
void init(int n)
{
    for (int i=1; i<=n; i++)
    {
        heap[i].l = heap[i].r = heap[i].dis = 0;
        heap[i].dad = i;
    }
}
int main()
{
    int n;
    while(cin>>n)
    {
        init(n);
        for (int i=1; i<=n; i++)
            scanf("%d",&heap[i].val);
        int m;
        cin>>m;
        while(m--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            x=finds(x);
            y=finds(y);
            if (x==y) puts("-1");
            else
            {
                heap[x].val>>=1;
                heap[y].val>>=1;
                x=merge(pop(x),x);//因为堆顶改变所以要重新pop再merge
                y=merge(pop(y),y);
                printf("%d\n",heap[merge(x,y)].val);
            }
        }
    }
    return 0;
}

