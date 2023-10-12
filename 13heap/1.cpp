#include<iostream>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    heap(){
        arr[0]=-1;
        size=0;
    }

    void insert(int val){
        size++;
        int index=size;
        arr[index]=val;


        // while(index>1){
        //     int parent=index/2;

        //     if(arr[parent]<arr[index]){
        //         swap(arr[index],arr[parent]);
        //         index=parent;
        //     }

        //     else{
        //         return ;
        //     }
        // }

    }

    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<"  ";
        }
        cout<<endl;
    }

    void deletefromHeap(){
        if(size==0){
            return ;
        }

        arr[1]=arr[size];

        size--;

        int i=1;
        while(i<size){
            int leftindex=2*i;
            int rightindex=2*i+1;

            if(leftindex<size && arr[i]<arr[leftindex]){
                swap(arr[i], arr[leftindex]);
                i=leftindex;
            }

            else if(rightindex<size && arr[i]<arr[rightindex]){
                swap(arr[i],arr[rightindex]);
                i=rightindex;
            }

            else{
                return ;
            }
        }


    }

    // void heapify(){
    //     int n=size;

    //     for(int i = n/2 ; i>0 ; i--){
    //         int leftindex=2*1;
    //         int rightindex=2*i+1;
    //         if(arr[i]<arr[leftindex] && leftindex<=size){
    //             swap(arr[i],arr[leftindex]);
    //             i++;
    //         }

    //         if(arr[i]<arr[rightindex] && rightindex <= size){
    //             swap(arr[i],arr[rightindex]);
    //             i++;
    //         }
    //     }

    // }


};

void heapify(int arr[],int size){

        int n=size;

        for(int i = n/2 ; i>0 ; i--){
            int leftindex=2*1;
            int rightindex=2*i+1;
            if(arr[i]<arr[leftindex] && leftindex<=size){
                swap(arr[i],arr[leftindex]);
                i++;
            }

            if(arr[i]<arr[rightindex] && rightindex <= size){
                swap(arr[i],arr[rightindex]);
                i++;
            }
        }

    return ;

}

void heapify(vector<int> arr,int size, int i ){

    int largest=i;
    int left=2*i+1;
    int right =2*i+2;

    if(left < n && arr[largest]< arr[left]){
        largest = left;
    }

    if(right< n && arr[largest]<arr[right]){
        largest =right;
    }

    if( largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr,n,largest);
    }


}
void heapSort(int arr[], int size){
    int n=size-1;

    while(n>1){
        swap(arr[1], arr[n]);
        n--;

        heapify(arr,n);

    }
}

int main(){

    heap h; 
    h.insert(54);
    h.insert(53);
    h.insert(55);
    h.insert(52);
    h.insert(50);
    // h.insert(54);

    h.print();

    // h.deletefromHeap();
    // h.print();

    // h.heapify();
    // h.print();

    int arr[6]={-1,54,53,55,52,50};

    heapify(arr,6);

    for(int i=1;i<6;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
    heapSort(arr,6);

    for(int i=1;i<6;i++){
        cout<<arr[i]<<" ";
    }






    return 0;
}