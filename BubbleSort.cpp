#include <iostream>
using namespace std;

void sort(int arr[], int n)
{   
   int counter =1; 
   while(counter<n)
   {
    for (int i = 0; i < n-counter; i++)
    {
        if (arr[i]>arr[i+1])
        {
            int temp = arr[i];
            arr[i]= arr[i+1];
            arr[i+1]= temp;
        }
        
    }
    counter++;
   }

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
    
}



int main()
{
    int arr[]= {1,5,6,8,24,6,0};
    int n;
    cout<<"sorted array: "<<endl;
    sort(arr,7);




    return 0;
}