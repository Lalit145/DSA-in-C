#include<stdio.h>
void fun(int n)
{
    if(n==0)
        return;
    fun(n-1);
    printf("%d ",n);
}
int main()
{
    int n;
    printf("Enter a number:");
    scanf("%d",&n);
    fun(n);
    // return 0;

}