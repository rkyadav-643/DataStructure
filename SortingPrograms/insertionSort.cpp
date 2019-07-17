#include<iostream>
using namespace std;
      
void print(int arr[],int size){
    
    for (int i=0;i<size ;++i){
        //cout <<"[ "<<i<<" ] => "<<arr[i]<<endl;
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}

// set element in proper place
void insertionSort(int arr[],int size){
    int temp,j;
    for (int i=1 ; i<size ; ++i){
        // set proper place
        temp=arr[i];
        for (j=i-1 ; arr[j] > temp && j >=0 ; --j){
            arr[j+1]=arr[j];
        }        
        arr[j+1]=temp;
    }
    
}

int main(){

int arr[]={ 4,10,5,2,6,9,7,0,23,12,45,10,6};
int n = sizeof(arr)/sizeof(arr[0]);
cout <<"Before insertion sort" <<endl;
print(arr,n);
cout <<"After insertion sort " <<endl;
insertionSort(arr,n);
print(arr,n);

}
