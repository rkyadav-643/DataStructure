#include<iostream>
using namespace std;

void swap(int & first, int & second ){
    
    int temp=first;
    first=second;
    second=temp; 
    
}
    
    
void print(int arr[],int size){
    
    for (int i=0;i<size ;++i){
        //cout <<"[ "<<i<<" ] => "<<arr[i]<<endl;
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}
//Smallest is out
    
void selectionSort(int arr[],int size){
    
    for (int i=0 ; i<size -1 ; ++i){
        for (int j=i+1 ; j < size ; ++j){
            
            if(arr[i] > arr[j]) {
                swap(arr[i],arr[j]);
            }
        } 
    }
}

int main(){

int arr[]={ 4,5,6,7,8,9,0,23,12,45,10,6};
int n = sizeof(arr)/sizeof(arr[0]);
cout <<"Before selection sort : " <<endl;
print(arr,n);
cout <<"After selection sort : " <<endl;
selectionSort(arr,n);
print(arr,n);

}
