#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

void strrev(char *str)
{
 char *str1,*p,*q;
 int i=0,cnt=0,size;

 p = str;

 while(*p!='\0')
 {
	cnt++;
	p++;
 }

 p--;
 cnt++;
 size = cnt * sizeof(char);
 str1 = new char(size);
 q = str1;

 while(cnt>1)
 {
 	*q = *p;
	q++;
	p--;
	cnt--;
 }
  *q = '\0';

 strcpy(str,str1);
}


int main()
{
int x,i=0,n;
char num[10],*p,*q,a;
p = num;
cin>>n;

while(n!=0)
{
	x = n%10;
	n = n/10;
	x = x+48;
	a = (char)x;
	*p = a;
	//cout<<*p;
	p++;
}
 *p = '\0';

strrev(num);
cout<<num;		
}
