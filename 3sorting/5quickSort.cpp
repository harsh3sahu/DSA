
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;


class Solution

{
    
    private:
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        

        if(high<=low){
            return ;
        }
        
        int pos=partition(arr,low,high);
        
        quickSort(arr,low,pos-1);
        quickSort(arr,pos+1,high);
        
        
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       // Your code here
       int pivot = arr[high];
        int count =0;
        
        for(int i= low; i<high;i++){
            if(arr[i]<=pivot){
                count ++;
            }
        }
        
        
        int i =low;
        int j=high;
        int pivotIndex=low+count;
        swap(arr[high],arr[pivotIndex]);
        
        
        while(i <= pivotIndex && j >= pivotIndex){
            while(arr[i]<=pivot){
                i++;
            }
            while(arr[j]>pivot){
                j--;
            }
            
            if(i<pivotIndex && j>pivotIndex ){
                swap(arr[i],arr[j]);
                i++;
                j--;
            }
            
        }
        
        return pivotIndex;
    }
};