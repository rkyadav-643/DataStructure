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
//Longest is out
    
void bubbleSort(int arr[],int size){
    
    for (int i=0 ; i<size ; ++i){
        for (int j=0 ; j < size - i ; ++j){
            
            if(arr[j] > arr[j+1]) {
                swap(arr[j],arr[j+1]);
            }
            
        }        
    }
    
}

int main(){

int arr[]={ 4,5,6,7,8,9,0,23,12,45,10,6};
int n = sizeof(arr)/sizeof(arr[0]);
cout <<"Before Bubble sort" <<endl;
print(arr,n);
cout <<"After Bubble sort " <<endl;
bubbleSort(arr,n);
print(arr,n);

}
