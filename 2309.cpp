#include<stdio.h>
int main(void)
{
    int arr[9];
    int brr[7];
    int sum=0,i,j,ansi,ansj,sml,sml_id,temp;
    for(i=0;i<9;i++)
    {
        scanf("%d",&arr[i]);
        sum=sum+arr[i];
    }
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            if(sum-(arr[i]+arr[j])==100)
            {
                ansi=i;
                ansj=j;
            }
        }
    }
    j=0;
    for(i=0;i<9;i++)
    {
        if(i==ansi||i==ansj) continue;
        brr[j]=arr[i];
        j=j+1;
    }
    for(i=0;i<7;i++)
    {
        sml=brr[i];
        sml_id=i;
        for(j=i;j<7;j++)
        {
            if(sml>=brr[j])
            {
                sml=brr[j];
                sml_id=j;
            }
        }
        temp=brr[i];
        brr[i]=brr[sml_id];
        brr[sml_id]=temp;
    }
    for(i=0;i<7;i++)
    {
        printf("%d\n",brr[i]);
    }
    return 0;
}
