#include<iostream> #include<cmath> using namespace std; int a[1000]; int m, n; void init(); void output();

int main() {  int i, j, counter, k;  cin >> m>> n;  init();  counter = 0;  k = 1;  i = 0;  while(counter < m)  {   if(a[i] == 1)   {    if(k == n)    {     a[i] = 0;     counter++;     k = 1;    }    else    {     k++;    }   }   if(counter==m)   {    i=(i-1) % (2*m);   }   else   {    i=(i+1)%(2*m);   }  }  while(counter<2*m-1)  {   if(a[i] == 1)   {    if(k == n)    {     a[i] = 0;     counter++;     k = 1;    }    else    {     k++;    }   }    i = (i - 1+100*m) % (2*m);  }  output();  return 0; }

void init() {  int i;

 for(i = 0; i < 2*m; i++)  {   a[i] = 1;  } }

void output() {  int i;

 for(i = 0; i <2*m; i++)  {   if(a[i] == 1)   {    cout << i + 1 << endl;    break;   }  } }