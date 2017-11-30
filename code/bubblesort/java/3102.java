import java.util.Scanner;
class Bubblesort
{
public static void main(String args[])
{
int n;
System.out.println("enter no. of elements");
Scanner w=new Scanner(System.in);
n=w.nextInt();
int a[]=new int[n];
System.out.println("enter nos");
Scanner sc=new Scanner(System.in);
for(int i=0;i<n;i++)
{
a[i]=sc.nextInt();
}
for(int i=0;i<n;i++)
{
System.out.println(a[i]);
}
for(int i=0;i<n;i++)
{
for(int j=0;j<n-i-1;j++)
{
if(a[j]>a[j+1])
{
int temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}}
for(int i=0;i<n;i++)
{
System.out.print(a[i]);
}
}}