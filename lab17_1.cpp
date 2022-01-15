#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *,int,int);

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void findColSum(const double *,double *,int,int);

int main(){
	srand(time(0));
	// const int N = 6, M = 8;
	// double data[N][M] = {};
	// double sum1[N] = {};
	// double sum2[M] = {};
	// double *dPtr = data[0];
	// randData(dPtr,N,M);
	// showData(dPtr,N,M);

	// cout << "---------------------------------------------\n";

	// findRowSum(dPtr,sum1,N,M);
	// showData(sum1,N,1);
	
	// cout << "---------------------------------------------\n";
	
	// findColSum(dPtr,sum2,N,M); 
	// showData(sum2,1,M);
	
	
	double a[3][2] = {1,2,3,4,5,6};
	double b[3];
	findRowSum(a[0],b,3,2);
	showData(b,3,1);
}

void showData(double *dPtr, int N, int M){
    cout << fixed << setprecision(2);
    for(int i = 0; i < N*M; i++){
        cout << dPtr[i];
        if((i+1)%(M) == 0) cout << endl;
        else cout << " ";
    }
}

void randData(double *dPtr, int N, int M){
    for(int i = 0; i < N*M; i++){
        dPtr[i] = (rand()%101)/100.00;
    }
}

void findRowSum(const double *dPtr,double *sum1,int N,int M){
	int count = 0;
	if (M == 1){
		for (int i  = 0; i < N; i++){
			sum1[i] = dPtr[i];
		}
	}
	else{
		for (int i  = 0; i < M*N; i++){
			sum1[count] += dPtr[i];
			if((i+1)%M == 0) count++;
		}
	}
}

void findColSum(const double *dPtr,double *sum1,int N,int M){
	if(N == 1){
		for (int i  = 0; i < M; i++){
			sum1[i] = dPtr[i];
		}
	}
	else{
		for (int i  = 0; i < M*N; i++){
			sum1[(i)%M] += dPtr[i];
		}
	}
}
