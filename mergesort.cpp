#include <iostream>
#include <cassert>
#include <cstdlib>


using namespace std;


void merge(int a[], int x[], int s, int m, int e );
void msort(int a[], int x[], int s, int e) {

    if ((e-s) > 1){
        int middle = (s + e)/2;
        msort(a, x, s, middle);
        msort(a, x, middle + 1 , e);
        merge(a, x, s, middle + 1, e);
    }
}

void merge(int a[], int x[], int s, int m, int e ){
    int i = s , j = m;
    
    for(; i < e ; i++){
        x[i] = a[i];    
    }
    
    i = s;
    
    
    while ( i < m and j < e){
        if (x[i] < x[j])
        {
            a[s] = x[i];
            s++;
            i++;
        }
        else
        {
           a[s] = x[j];
           s++;
           j++;
        }
    }
    
    while( i < m){
        a[s] = x[i];
        s++;
        i++;
    }
    
    while(j < e){
        a[s] = x[j];
        s++;
        j++;
    }
}

void mergesort(int a[], int x[], int n) {
    if (n > 1 ){
        msort(a,x,0,n-1);
    }
}

bool sorted(int a[], int n) {
	for(int i = 1 ; i < n ; i++){
	    if (a[i-1] > a[i]){
	        return false;
	    }
	}
	return true;
}

int main(int argc, char * args[]) {

	int a[10];
	int x[10];
	for (int i = 0; i < 10; i++) a[i] = -50 + rand() % 100;
	
	for (int i = 0 ; i < 10; i++){
	    cout << a[i] << " " ;
	}
	cout << endl;
	
	mergesort(a, x, 10);
	//assert(sorted(a, 1000));
	
	for (int i = 0 ; i < 10; i++){
	    cout << a[i] << " " ;
	}
	
/*
	int b[1001];
	for (int i = 0; i < 1001; ++i) b[i] = -50 + rand() % 100;
	mergesort(b, 1001);
	assert(sorted(b, 1001));
	int c[] = { 2 };
	mergesort(c, 1);
	assert(sorted(c, 1));
	int d[] = { 1, 2, 3, 4, 5 };
	mergesort(d, 5);
	assert(sorted(d, 5));
*/
	cout << "All tests passed." << endl;	
}