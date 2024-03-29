#include <curl/curl.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include"httpsend.h"
using namespace std;


static size_t read_callback(void *ptr, size_t size, size_t nmemb, void *userp)
{
  struct WriteThis *pooh = (struct WriteThis *)userp;
  int fsize,i;

  if(size*nmemb < 1)
    return 0;

  if(pooh->sizeleft) 
  {
    strcpy((char *)ptr,pooh->readptr); /* copy one single byte */
    pooh->sizeleft=0;                /* less data left */
    return (size*nmemb);             /* we return 1 byte at a time! */
  }

  return 0;                          /* no more data left to deliver */
}


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


void itoa(int n,char *num)
{
int x,i=0;
char *p,*q,a;
p = num;

	while(n!=0)
	{
		x = n%10;
		n = n/10;
		x = x+48;
		a = (char)x;
		*p = a;
		p++;
	}

 *p = '\0';
 strrev(num);
}


void HttpSend::fileopen(char fname[])
{
	fsize = r.fileopen(fname);		
	cnt = fsize/16384;
	if(fsize%16384!=0)
	cnt++;
}

void HttpSend::filewrite(char fname[],int maxcsize)
{
 int flag=0;
 buff = (char*)malloc(16384);//change
 
 while(cnt>0)
 {
 	if(fsize<16384)
 	{
 		csize = fsize;
		buff1 = (char*)malloc(csize);
		buff = buff1;
  	}
  	else
  	{
		csize = 16384; //change
	} 

	if(flag==0)
	{
		r.fileread(buff,csize);
		flag=1;
	}
	
	pooh.readptr = buff;
  	pooh.sizeleft = csize;
	curl = curl_easy_init();

	if(curl) 
	{


    		curl_easy_setopt(curl, CURLOPT_URL,"http://192.168.1.75:8080/SecureShare/rest/server/post/hello.txt");

    		/* Now specify we want to POST data */
    		curl_easy_setopt(curl, CURLOPT_POST, 1L);

    		/* we want to use our own read function */
    		curl_easy_setopt(curl, CURLOPT_READFUNCTION, read_callback);

    		/* pointer to pass to our read function */
    		curl_easy_setopt(curl, CURLOPT_READDATA, &pooh);

    		curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (curl_off_t)pooh.sizeleft);

    		/* get verbose debug output please */
    		curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
		
		itoa(csize,temp);   
    		strcpy(header,"fsize: ");
    		strcat(header,temp);
    		chunk = curl_slist_append(chunk,header);
		chunk = curl_slist_append(chunk,"Content-Type: application/octet-stream");
    		res = curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
    
    		res = curl_easy_perform(curl);
    		if(res==CURLE_OK)
    		{
			current = current + csize;
			fsize = fsize - csize;
			cnt--;   
			flag=0;
		}
	}
 cout<<res;
}

/* always cleanup */
curl_easy_cleanup(curl);

}	

void HttpSend::fileclose()
{
	r.fileclose();
}

/*
int main()
{
cout<<"Start";
HttpSend s;
char fname[20];
strcpy(fname,"hello.txt");
s.fileopen(fname);

s.filewrite(fname,16384);
/*s.fileclose();
return 0;
}*/
