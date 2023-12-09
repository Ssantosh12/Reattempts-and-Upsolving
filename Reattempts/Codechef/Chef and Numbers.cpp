#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n,i,left=0,right=0,mxChoices=0,eleSubSize;
        scanf("%d",&n);
        int arr[n];
        for(i=0;i<=n-1;i++)
            scanf("%d",&arr[i]);

        // we will have to store the max possible choices/choosings for each particular element type
        // we can use any key-value data structure to store that, ex-map
        map<int,int> eleChoices;

        // use of two pointer algorithm using left and right pointers to contain a subarray
        // NOTE : right will ask left pointer to determine if subarray of same element type has ended

        while(right<=n-1){
            if(arr[right]!=arr[left]){
                eleSubSize=(right-1)-left+1;   // target element type here is arr[left] or arr[right-1]
                if(eleSubSize&1)
                    eleChoices[arr[right-1]]+=eleSubSize/2+1;
                else
                    eleChoices[arr[right-1]]+=eleSubSize/2;
                left=right;
            }

            if(right==n-1){      // NOTE : focus on 'if' condition type here , 'else if(right==n-1)' will be incorrect because it will be dependent on upper ifs
                eleSubSize=right-left+1;   // target element type here is arr[left] or arr[right], NOTE: here target ele arr[right-1] is incorrect
                if(eleSubSize&1)
                    eleChoices[arr[left]]+=eleSubSize/2+1;
                else
                    eleChoices[arr[left]]+=eleSubSize/2;
            }

            right++;
        }

        for(auto x: eleChoices){
            if(x.second>mxChoices)
                mxChoices=x.second;
        }

        for(auto x: eleChoices){
            if(x.second==mxChoices){
                cout<<x.first<<"\n";
                break;
            }
        }
    }
}

// OLD Solution using counting technique to contain a subarray instead of two pointers left and right
/*
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int ele,n,i,continuous=0,maxChoice=0;
        scanf("%d",&n);
        map<int,int> choices;
        int arr[n];
        for(i=0;i<=n-1;i++)
            scanf("%d",&arr[i]);
        for(i=0;i<=n-1;i++){
            continuous++;
            if(i==(n-1)){
                if(continuous%2==0)
                    choices[arr[i]]=choices[arr[i]]+continuous/2;
                else choices[arr[i]]=choices[arr[i]]+(continuous/2)+1;
                continuous=0;
            }
            else if(arr[i]!=arr[i+1]){
                if(continuous%2==0)
                    choices[arr[i]]=choices[arr[i]]+continuous/2;
                else choices[arr[i]]=choices[arr[i]]+(continuous/2)+1;
                continuous=0;
            }
        }
        for(auto x: choices){
            if(x.second>maxChoice)
                maxChoice=x.second;
        }
        for(auto x: choices){
            if(x.second==maxChoice){
                cout<<x.first<<"\n";
                break;
            }
        }
    }
}
*/
