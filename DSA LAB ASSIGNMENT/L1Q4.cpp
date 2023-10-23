#include<iostream>
using namespace std;

class matrix{
	int **p;
	int r;
	int c;
	int *rowmajor;
	int *multiply1D;
	public:
	matrix(int row, int col);
	// Constructor
	void disp2D(){
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				cout<<p[i][j]<<"\t";
			}
			cout<<endl;	
		}
	}
	// displays the elements of **p
	void dispRowMajor(){
		int arr[r*c],x=0;
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				arr[x]=p[i][j];
				x++;
			}	
		}
		for(int i=0;i<r*c;i++){
			cout<<arr[i]<<endl;
		}
	}
	// converts 2D into 1D using row major
	//and displays the elements Row Major Order Matrix
	void Multiply_rowMajor(matrix & x){
		int k=0;
		int A[r * c],B[x.r * x.c];
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				A[k]=p[i][j];
				k++;
			}
		}
		k=0;
		for(int i=0;i<x.r;i++){
			for(int j=0;j<x.c;j++){
				B[k]=x.p[i][j];
				k++;
			}
		}
	    int res[r * x.c];
	
	    int i, j;
	
	    for (i = 0; i < r; i++) {
	        for (j = 0; j < x.c; j++) {
	            res[j + i * x.c] = 0;
	
    	        for (k = 0; k < c; k++) {
    	            res[j + i * x.c] += A[k + i * c] * B[j + k * x.c];
    	        }
    	    }
    	}
		cout<<endl<<endl;
    	for (i = 0; i < r * x.c; i++) 
    	cout<<res[i]<<endl;
	}
	void rowMajor_2D(){
		return;
	}
	// Maps the elements stored in row major order to
	// the 2D array and print the results
	~matrix(){
		delete p;
	}
	// Destructor
};

int main()
{
	matrix a(4,3);
	matrix b(3,4);
	a.disp2D();
	a.dispRowMajor();
	b.disp2D();
	b.dispRowMajor();
	a.Multiply_rowMajor(b);
	a.rowMajor_2D();
}

matrix::matrix(int row,int col)
{
	r=row;
	c=col;
	p = new int*[r];
	for(int i=0;i<r;i++)
	{
		p[i]=new int[c];
		for(int j=0;j<c;j++)
		p[i][j]=(i+j);
	}
	// CODE FOR STORING DATA FROM
	// **P TO *rowmajor ROW MAJOR
}