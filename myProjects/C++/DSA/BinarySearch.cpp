#include <iostream>
#include "MergeSort.cpp"
using namespace std;

int binarySearch(int arr[], int target, int l, int r){
    mergeSort(arr,l,r);
    while(l<=r){
        int mid= l+(r-l)/2;
        if (arr[mid]==target){
            return mid;
        }
        if(arr[mid]<target){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    //return l if you want to find the spot it is supposed to be in if not found and return -1 if you just want to be told that nothing was found
    return l;
}
int main(){
    int arr[5]={3,4,5,2,10};
    cout<<"Original Array: ";
    for(int i: arr){
        cout<<i<<" ";
    }
    cout<<endl;
    int size=sizeof(arr)/sizeof(0);
    int indexOfTarget= binarySearch(arr, 4,0,size-1);
    cout<<"Sorted Array: ";
    for(int i: arr){
        cout<<i<<" ";
    }
    cout<< endl;
    cout<<"Index of your target number: " <<indexOfTarget<<endl;
    return 0;
}