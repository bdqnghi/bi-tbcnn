void onePack(int cost, int value)
{
  for(int i=m;i>=cost;--i)
    f[i]=max(f[i], f[i-cost]+value);
}

void comPack(int cost, int value)
{
  for(int i=cost;i<=m;++i)
    f[i]=max(f[i], f[i-cost]+value);
}

void multiPack(int cost, int value, int num)
{
  if(cost*num>=m)
    comPack(cost, value);
  else
  {
    int k=1;
    while(k<num)
    {
      onePack(k*cost, k*value);
      num-=k;
      k<<=1;
    }
    onePack(num*cost, num*value);
  }
}

void groupPack(int group)
{
  for(int i=m;i>=0;--i)
    for(int j=0;j<data[group].size();++j)
      if(i>=data[group][j].cost)
        f[i]=max(f[i], f[i-data[group][j].cost]+data[group][j].value);
}
