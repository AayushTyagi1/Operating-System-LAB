#include<stdio.h>
#define max 20

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


int main()

{
    int i,j,n,p[max],min,k = 1,b1= 0;
    int bt[max],at[max],wt[max],tt[max],ta=0,sum=0,temp;
    float total_wt=0,total_tat=0,sum_tat=0,sum_wt=0;

    printf("Enter Number of process  :");
    scanf("%d", & n);
    printf("\n");

    printf("Enter the Burst time for each process:" );
    for (i = 0; i < n; i++) {
        scanf(" %d", & bt[i]);
    }

    printf(" enter arrival time for each process:" );
    for (i = 0; i < n; i++) {
        scanf(" %d", & at[i]);
	p[i]=i;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (at[i] < at[j]) {
                    swap(&p[i],&p[j]);
                    swap(&at[i],&at[j]);
                    swap(&bt[i],&bt[j]);
            }
        }
    }

	for (j = 0; j < n; j++) {
        b1+= bt[j];
        min = bt[k];
        for (i = k; i < n; i++) {
            if ( bt[i] < min && b1 >= at[i] ) {
                    swap(&p[i],&p[k]);
                    swap(&at[i],&at[k]);
                    swap(&bt[i],&bt[k]);

            }
        }
        k++;
    }
    wt[0] = 0;
    for (i = 1; i < n; i++) {
        sum = sum + bt[i - 1];
        wt[i] = sum - at[i];
        sum_wt = sum_wt + wt[i];
    }

    total_wt = (sum_wt / n);
    for (i = 0; i < n; i++) {
        ta = ta + bt[i];
        tt[i] = ta - at[i];
        sum_tat = sum_tat + tt[i];
    }

    total_tat = (sum_tat / n);

    printf("\nGANTT CHART :");
    for (i = 0; i < n; i++) {
        printf(" P%d", p[i]);
	printf("|");
    }

    printf("\nAVG. WAITING TIME : %0.2f", total_wt);
    printf("\nAVG TURN AROUND TIME : %0.2f", total_tat);
    return 0;
}
