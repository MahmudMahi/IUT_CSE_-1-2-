#include <bits/stdc++.h>
using namespace std;
int* Input_array(int n);
void print_array(int* ptr, int n);
void unique_arr(int* arr, int n);
void rmv(int* arr, int index, int n);
void max_repeat(int *arr, int n);
void mean(int* arr,int n);
bool check_sorted(int* arr, int n);
void Union(int* arr1, int* arr2, int n1, int n2);
void mat_input(int row, int col);
void mat_input(int row, int col){
    int* mat= new int[row*col];
    for(int k=0; k<(row*col); k++){
        cin>>*(mat+k);
    }
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<*(mat+j+(i*col))<<" ";
            
        }cout<<endl;
    }
    delete[] mat;
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt","w", stdout);
    char ans;
    cout<<"Want matrix or array?"<<endl;
    cout<<"(type 'm' for matrix, 'a' for array)"<<endl;
    cin>>ans;
    if(ans== 'm'){
        int row, col;
        cin>>row>>col;
        mat_input(row, col);
    }
    else if(ans == 'a'){
        int n1, n2;
        cin>>n1>>n2;
        int* myArr= Input_array(n1);
        int* myArr1= Input_array(n2);
        print_array(myArr, n1);
        print_array(myArr1, n2);
        delete[] myArr;
        delete[] myArr1;
    }
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
void Union(int* arr1, int* arr2, int n1, int n2){
    int* arr= new int[n1+n2];
    for(int i=0; i<n1; i++){
        *(arr+i)= *(arr1+i);
    }
    for(int j=n1; j<(n2+n1); j++){
        *(arr+j)= *(arr2+j-n1);
    }
    for(int k=0; k<(n1+n2); k++) cout<<*(arr+k)<<" ";
    cout<<endl;
    delete[] arr;
}
