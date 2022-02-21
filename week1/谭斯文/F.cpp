#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
int main()
{
    int n,i,max,min,sum=0;
    cin>>n;
    int arr[n];
    cin>>arr[0];
    max=arr[0];
    min=arr[0];
    sum+=arr[0];
    for(i=1;i<n;i++)
    {
    	cin>>arr[i];
    	sum+=arr[i];
    	if(min>arr[i])
    	min=arr[i];
    	if(max<arr[i])
    	max=arr[i];
	}
    cout<<max<<endl;
    cout<<min<<endl;
    cout<<fixed<<setprecision(2)<<1.0*sum/n<<endl;
	return 0;
}
