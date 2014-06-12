// This file is generated from test alphabets program by code generator in alphaz
// To compile this code, use -lm option for math library.

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <float.h>

#include "external_functions.h"

// Common Macros
#define MAX(x,y)    ((x)>(y) ? (x) : (y))
#define max(x,y)    ((x)>(y) ? (x) : (y))
#define MIN(x,y)    ((x)>(y) ? (y) : (x))
#define min(x,y)    ((x)>(y) ? (y) : (x))
#define CEILD(n,d)  (int)ceil(((double)(n))/((double)(d)))
#define ceild(n,d)  (int)ceil(((double)(n))/((double)(d)))
#define FLOORD(n,d) (int)floor(((double)(n))/((double)(d)))
#define floord(n,d) (int)floor(((double)(n))/((double)(d)))
#define CDIV(x,y)    CEILD((x),(y))
#define div(x,y)    CDIV((x),(y))
#define FDIV(x,y)    FLOORD((x),(y))
#define LB_SHIFT(b,s)  ((int)ceild(b,s) * s)
#define MOD(i,j)   ((i)%(j))
#define mallocCheck(v,s,d) if ((v) == NULL) { printf("Failed to allocate memory for %s : size=%lu\n", "sizeof(d)*(s)", sizeof(d)*(s)); exit(-1); }


//Local Function Declarations
int reduce_Nussinov_M_1(long, int, int, int*, int**, int*);

//Memory Macros
#define RNA(n) RNA[n]
#define M(i,j) M[i][j]

void Nussinov(long L, int* RNA, int* opt){
	///Parameter checking
	if (!((L >= 2))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	//Memory Allocation
	int mz1, mz2;
	
	int* _lin_M = (int*)malloc(sizeof(int)*((L) * (L)));
	mallocCheck(_lin_M, ((L) * (L)), int);
	int** M = (int**)malloc(sizeof(int*)*(L));
	mallocCheck(M, (L), int*);
	for (mz1=0;mz1 < L; mz1++) {
		M[mz1] = &_lin_M[(mz1*(L))];
	}

	#define S0(i,j) M(-i+L,j) = 0
	#define S1(i,j) M(-i+L,j) = 0
	#define S2(i,j) M(-i+L,j) = max((M(-i+L+1,j-1))+(BasePair(RNA(-i+L),RNA(j))),reduce_Nussinov_M_1(L,-i+L,j,RNA,M,opt))  //speed up by 71%
	#define S3(i0,i1) *opt = M(0,L-1)
	{
		//Domain
		//{i,j|j>=0 && L>=i+j && i>=1 && L>=2 && L>=j+1 && L>=i}
		//{i,j|i+j==L+1 && L>=i && i>=2 && L>=2}
		//{i,j|L>=i && i+j>=L+2 && L>=j+1 && L>=2 && j>=1 && i>=2}
		//{i0,i1|i1==0 && i0==L+1 && L>=2}
		int c1,c2;
		M(L-1,L-1) = 0; //optimized
//		for(c2=0;c2 <= L-1;c2+=1)
//		 {
//		 	S0((1),(c2));
//		 }
		M(L-2,L-2) = 0; //optimized
//		for(c2=0;c2 <= L-2;c2+=1)
//		 {
//		 	S0((2),(c2));
//		 }
		M(L-2,L-1) = 0;
		for(c1=3;c1 <= L;c1+=1)
		 {
//		 	for(c2=0;c2 <= -c1+L;c2+=1) //optimized out
//		 	 {
//		 	 	S0((c1),(c2)); //l
//		 	 }
		 	S0((c1),(L-c1));
		 	S1((c1),(-c1+L+1));
		 	for(c2=-c1+L+2;c2 <= L-1;c2+=1)
		 	 {
		 	 	S2((c1),(c2));
		 	 }
		 }
		S3((L+1),(0));
	}
	#undef S0
	#undef S1
	#undef S2
	#undef S3
	
	//Memory Free
	free(_lin_M);
	free(M);
}
inline int reduce_Nussinov_M_1(long L, int ip, int jp, int* RNA, int** M, int* opt){
	int reduceVar = (M(ip,ip))+(M(ip+1,jp)); //optimized

	#define S0(i,j,k) {reduceVar = max(reduceVar,(M(i,k))+(M(k+1,j))); } //optimized
	{
		//Domain
		//{i,j,k|ip>=0 && jp>=ip+2 && L>=jp+1 && jp>=1 && L>=ip+2 && L>=2 && k>=i+1 && j>=k+1 && j>=i+2 && i>=0 && L>=i+2 && k>=0 && L>=k+2 && j>=1 && L>=j+1 && ip==i && jp==j}
		for(int c3=ip+1;c3 <= jp-1;c3+=1) //optimized
		{
			S0((ip),(jp),(c3));
		}
	}
	#undef S0

	return reduceVar;
}

//Memory Macros
#undef RNA
#undef M


//Common Macro undefs
#undef MAX
#undef max
#undef MIN
#undef min
#undef CEILD
#undef ceild
#undef FLOORD
#undef floord
#undef CDIV
#undef FDIV
#undef LB_SHIFT
#undef MOD
