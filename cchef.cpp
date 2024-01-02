#include <bits/stdc++.h>
using namespace std;
int* Input_array(int n);
void print_array(int* ptr, int n);
void unique_arr(int* arr, int n);
void rmv(int* arr, int index, int n);
void max_repeat(int *arr, int n);
void mean(int* arr,int n);
bool check_sorted(int* arr, int n);
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt","w", stdout);
    int n;
    cin>>n;
    int* myArr= Input_array(n);
    print_array(myArr,n);
    sort(myArr, myArr+n);
    print_array(myArr,n);
    mean(myArr, n);
   // unique_arr(myArr, n); there's a bug here in this function
   // i will debug that tommororw,patience nai R :(
    max_repeat(myArr, n);
    bool x= check_sorted(myArr,n);
    if(x==true) cout<<"True"<<endl;
    else cout<<"False"<<endl;
    delete[] myArr;
    return 0;
}
int* Input_array(int n){
    int* arr= new int[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    return arr;
}
void print_array(int* ptr, int n){
    cout<<"Length of the array is: "<<n<<endl;
    for(int i=0; i<n; i++){
        cout<<*(ptr + i)<<" ";
    }
    cout<<endl;
}
void unique_arr(int* arr, int n){
    sort(arr, arr+n);
    for(int i=0; i<(n-1); i++){
        if((*(arr+i))==(*(arr+i+1))) rmv(arr, i, n);
    }

}
void rmv(int* arr, int index, int n){
    for(int i=index; i<(n-2); i++){
        *(arr+i)= *(arr+1+i);
    }
}
void mean(int* arr, int n){
    float s=0;
    for(int i=0; i<n; i++){
        s += *(arr+i);
    }
    cout<<"mean value: "<<(s/n)<<endl;
}

bool check_sorted(int* arr, int n){
    bool c= false;
    for (int i = 0; i < (n-1); i++)
    {
        if((*(arr+i))<(*(arr+i+1))) c= true;
        else{
            c= false;
            break;
        }
    }
    return c;
    
}
void max_repeat(int* arr, int n){
   int repeat_arr[n]={0};
   for(int i=0; i<n; i++){
    repeat_arr[*(arr+i)]++;
   }
   int max_count=0;
   int max_elem=0;
   for(int j=0; j<n; j++){
    if(max_count< repeat_arr[j]){
        max_count= repeat_arr[j];
        max_elem=j;
    }
   }
   cout<<max_elem<<endl; 
}