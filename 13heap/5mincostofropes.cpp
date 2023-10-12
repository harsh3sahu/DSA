https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1
class Solution{
    private:
    void heapify(vector<int> &heap,int i,int n){
        
            int largest=i;
            int leftindex=(2*i)+1;
            int rightindex=(2*i)+2;
            
            
                        
           if(leftindex<n && heap[largest]<heap[leftindex]){
                largest=leftindex;               
           }
           
           if(rightindex<n && heap[largest]<heap[rightindex]){
               largest=rightindex;
           }
           
           
            if(largest!=i){
                swap(heap[i],heap[largest]);
                heapify(heap,largest,n);
            }
        
        
    }
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int> heap;
        
        
      for(auto i:a){
          heap.push_back(i);
      }
      
      for(auto j:b){
          heap.push_back(j);
      }
        
        int size=heap.size();
        
        for(int i=size/2-1;i>=0;i--){
            heapify(heap,i,size);
        }
        
        return heap;
        
        
        
    }
};