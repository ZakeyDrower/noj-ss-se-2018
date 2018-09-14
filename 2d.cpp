// find all close number pairs not greater than 10000
#include <math.h>
#include <stdio.h>  // stdio run faster than iostream

#define MAX_NUM 10000

// more memory , less time
int *fsa; // factors sum array 

bool is_close_numbers(int num_a, int num_b);
int factor_sum(int num);

int main()
{
    fsa = new int[MAX_NUM+1]();
    for (int i = 1; i <= MAX_NUM; i++)
        fsa[i] = factor_sum(i);

    // min pair: 2 3
    for (int i = 2; i <= MAX_NUM; i++){
        for (int j = i + 1; j <= MAX_NUM; j++){
            if(is_close_numbers(i, j))
                //cout << i << " " << j << endl;
                printf("%d %d\n", i, j); 
        }
    }

    return 0;
}

bool is_close_numbers(int num_a, int num_b)
{
   if(fsa[num_a]==num_b && fsa[num_b]==num_a)
       return true;
   return false;
}

int factor_sum(int num)
{
    int sum = 1;
    for (int i = 2; i <= sqrt(num); i++)
        if(num%i==0){
            sum += i;
            if(i!=sqrt(num))
                sum += num / i;
        }
    return sum;
}