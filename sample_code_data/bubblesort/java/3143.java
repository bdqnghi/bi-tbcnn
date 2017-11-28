import java.util.Scanner;
class sort
{
public static void main(String [] args)
{
Scanner sc=new Scanner(System.in);
int i,j,s,temp;
int a[]=new int[10];
System.out.print("Enter size of array:");
s=sc.nextInt();
System.out.println("Enter array element:");
for(i=0;i<s;i++)
{
a[i]=sc.nextInt();
}
System.out.println("Array before sorting:");
for(i=0;i<s;i++)
{
System.out.println(a[i]);
}
System.out.println("Array after sorting:");
for(i=0;i<s-1;i++)
{
  for(j=0;j<s-1-i;j++)
  {
   if(a[j]>a[j+1])
   {
    temp=a[j];
    a[j]=a[j+1];
    a[j+1]=temp;
   }
  }
}
for(i=0;i<s;i++)
{
System.out.println(a[i]);
}
}
}