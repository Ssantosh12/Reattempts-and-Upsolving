#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        // only mathematical thinking required, each pair of cells can be covered by only 1 light
        if((n*m)&1)
            printf("%d\n",(n*m)/2+1);
        else printf("%d\n",(n*m)/2);
    }
}

// OLD SOLUTION: see the thinking difference
/*
#include <bits/stdc++.h>

using namespace std;

int main()
{   int t;
    scanf("%d",&t);
    while(t--){
        long long int n,m,i,sum=0;
        scanf("%lld%lld",&n,&m);
        if(n>=2&&m>=2){
            if(n%2==0){
                sum=sum+(n*m)/2;
            }
            else{
                sum=sum+((n-1)*m)/2;
                if(m%2==0)
                    sum=sum+m/2;
                else
                    sum=sum+(m/2)+1;
            }
            printf("%lld\n",sum);
        }
        else{
            if(n==1&&m==1) printf("1\n");
            else if(n==1&&m%2==0) printf("%lld\n",m/2);
            else if(m==1&&n%2==0) printf("%lld\n",n/2);
            else if(n==1&&m%2!=0) printf("%lld\n",m/2+1);
            else if(m==1&&n%2!=0) printf("%lld\n",n/2+1);
        }
    }
}
*/
