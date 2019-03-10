#include<stdio.h>
int main(void)
{
    int n,m,i,j,k,p,q;
    int a[100]={0};
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    p=0;
    q=0;
    for(i=0;i<n-2;i++)
    {
        for(j=i+1;j<n-1;j++)
        {
            for(k=j+1;k<n;k++)
            {
                p=a[i]+a[j]+a[k];
                if(p<=m)
                {
                    if(p<q)
                    {
                        q=q;
                    }
                    else
                    {
                        q=p;
                    }
                }
                else
                {
                    q=q;
                }
            }
        }
    }
    printf("%d",q);
    return 0;
}
