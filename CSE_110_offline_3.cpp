//pointers
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int m, n;
	cin>>m>>n;
	unsigned char** mat = new unsigned char*[m];
	unsigned char* mat_data= new unsigned char[m*m];
	for(int i=0; i<m; i++) *(mat+i)= mat_data+ i*m;
	for(int i=0; i<m; i++){
		for(int j=0; j<m; j++){
			cin>>*(*(mat+i)+j); 
		}
	}
	cout<<"Original matrix: "<<endl;
	for(int k=0; k<m; k++){
		for(int l=0; l<m; l++){
			cout<< *(*(mat+k)+l)<< " "; 
		}
		cout<<endl;
	}
	//unsigned char** mat_1=new unsigned char* [m];
	//unsigned char* mat_data_1= new unsigned char[m*m];
	n = n%4;	
	for(int k=0; k<n; k++){
		for(int i=0; i<m; i++){
			for(int j=i+1; j<m; j++){
				swap(*(*(mat+i)+j), *(*(mat+j)+i));
			}
		}
		for(int x=0; x<m/2; x++){
			for(int y=0; y<m; y++){
				swap(*(*(mat+x)+y), *(*(mat+m-1-x)+y));
			}
		}
		cout<<"Rotating after "<<k+1<<" times: "<<endl;
		for(int p=0; p<m; p++){
			for(int q=0; q<m; q++){
				cout<< *(*(mat+p)+q)<< " "; 
			}
			cout<<endl;
		}
	}
	//delete [] mat_1;
	//delete [] mat_data_1;
	delete [] mat;
	delete [] mat_data;
	return 0;
}
