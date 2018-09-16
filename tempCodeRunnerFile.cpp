#include<stdio.h>
#include<stack>
#include<string.h>
using namespace std;
int calcu(int num1,int num2,char op);
stack <int> s1;
char s[1000];
int a[1000];
int main()
{
 int n,i,num1,num2;
 int result;
 
 gets(s);
 
 n=strlen(s);
 
 for(i=0; i<n; i++)
 {
  if(s[i]>=48&&s[i]<=57)
  {
   a[i]=s[i]-'0';
   result=a[i];
   s1.push(a[i]);
  }
  else
  {
   num2=s1.top();
   s1.pop();
   num1=s1.top();
   s1.pop();
   result=calcu(num1,num2,s[i]);
   s1.push(result);
  }
 }
 printf("%d\n",result);
}

int calcu(int num1,int num2,char op)
{
 int result; 
 if(op=='+')
 {
  result=num1+num2;
 }
 if(op=='-')
 {
  result=num1-num2;
 }
 if(op=='*')
 {
  result=num1*num2;
 }
 if(op=='/')
 {
  result=num1/num2;
 }
 return result;
}