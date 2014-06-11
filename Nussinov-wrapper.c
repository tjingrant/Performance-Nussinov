// This file is generated from test alphabets program by code generator in alphaz
// To compile this code, use -lm option for math library.

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#include <sys/time.h>
#include <sys/errno.h>


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
#define EPSILON 1.0E-9





//Memory Macros
#define RNA(n) RNA[n]
#define M(i,j) M[i][j]

#define opt_verify() opt_verify
#define var_opt() opt
#define var_opt_verify() opt_verify

//function prototypes
void Nussinov(long, int*, int*);
void Nussinov_verify(long, int*, int*);

//main
int main(int argc, char** argv) {
	//Check number of args
	if (argc <= 1) {
		printf("Number of argument is smaller than expected.\n");
		printf("Expecting L\n");
		exit(0);
	}
	
	char *end = 0;
	char *val = 0;
	//Read Parameters
	//Initialisation of L
	errno = 0;
	end = 0;
	val = argv[1];
	long L = strtol(val,&end,10);
	if ((errno == ERANGE && (L == LONG_MAX || L == LONG_MIN)) || (errno != 0 && L == 0)) {
		perror("strtol");
		exit(EXIT_FAILURE);
	}
	if (end == val) {
		fprintf(stderr, "No digits were found for L\n");
		exit(EXIT_FAILURE);
	}
	if (*end != '\0'){
		printf("For parameter L: Converted part: %ld, non-convertible part: %s\n", L, end);
		exit(EXIT_FAILURE);
	}
	
	
	///Parameter checking
	if (!((L >= 2))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	
	
	//Memory Allocation
	int mz1, mz2;
	int* RNA = (int*)malloc(sizeof(int)*(L));
	mallocCheck(RNA, (L), int);
	int opt;
	#ifdef VERIFY
		int opt_verify;
	#endif

	//Initialization of rand
	srand((unsigned)time(NULL));
	 
	//Input Initialization
	{
		#if defined (RANDOM)
			#define S0(n) (RNA(n) = rand()) 
		#elif defined (CHECKING) || defined (VERIFY)
			#ifdef NO_PROMPT
				#define S0(n) scanf("%d", &RNA(n))
			#else
				#define S0(n) printf("RNA(%ld)=",(long) n); scanf("%d", &RNA(n))
			#endif
		#else
			#define S0(n) (RNA(n) = 1)   //Default value
		#endif
		
		
		int c1;
		for(c1=0;c1 <= L-1;c1+=1)
		 {
		 	S0((c1));
		 }
		#undef S0
	}
	
	//Timing
	struct timeval time;
	double elapsed_time;
	
	//Call the main computation
	gettimeofday(&time, NULL);
	elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000);
	
	Nussinov(L, RNA, &opt);

	gettimeofday(&time, NULL);
	elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000) - elapsed_time;

	// timing information
	printf("Execution time : %lf sec.\n", elapsed_time);
	
	#ifdef TIMING
		FILE * fp = fopen( "trace.dat","a+");
		if (fp == NULL) {
				printf("I couldn't open trace.dat for writing.\n");
				exit(EXIT_FAILURE);
		}
		fprintf(fp, "%ld\t%lf\n",L,elapsed_time);
		fclose(fp);
	#endif
	
	//Verification Run
	#ifdef VERIFY
		#ifdef TIMING
			gettimeofday(&time, NULL);
			elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000);
		#endif
    	Nussinov_verify(L, RNA, &opt_verify);
    	#ifdef TIMING
    		gettimeofday(&time, NULL);
			elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000) - elapsed_time;
			
			FILE * fp_verify = fopen( "trace_verify.dat","a+");
			if (fp == NULL) {
					printf("I couldn't open trace_verify.dat for writing.\n");
					exit(EXIT_FAILURE);
			}
			fprintf(fp, "%ld\t%lf\n",L,elapsed_time);
			fclose(fp_verify);
		#endif
	#endif
    	
	#ifdef CHECKING
    	//Print Outputs
		{
			#ifdef NO_PROMPT
				#define S0() printf("%d\n",var_opt())
			#else
				#define S0() printf("opt=");printf("%d\n",var_opt())
			#endif
			S0();
			#undef S0
		}
	#elif VERIFY
		//Compare outputs for verification
		if (abs(var_opt() - var_opt_verify()) > EPSILON) {
			printf("Error (%s) : 1\n", "opt");
		}
    #endif
    
	//Memory Free
	free(RNA);
	#ifdef VERIFY
	#endif
	
	return EXIT_SUCCESS;
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
#undef EPSILON
