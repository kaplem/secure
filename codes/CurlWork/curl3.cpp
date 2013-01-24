#include <stdio.h>
#include <curl/curl.h>
#include<iostream>
#include<string.h>
#include<fstream>
#include<stdlib.h>
using namespace std;
int count=0,flag=0,current=0,csize;
char tempbuff[512];
fstream f,f1;
struct WriteThis {
  char *readptr;
  int sizeleft;
};

static size_t read_callback(char *ptr, size_t size, size_t nmemb, void *userp)
{
  struct WriteThis *pooh = (struct WriteThis *)userp;
  int fsize,i;

  if(size*nmemb < 1)
    return 0;

  if(pooh->sizeleft) 
  {
    //strcpy(tempbuff,pooh->readptr);
	//if(flag==1)
  	//{
	
    //strcpy(ptr,pooh->readptr); /* copy one single byte */
    ptr = pooh->readptr;
    cout<<ptr;
    f1.seekg(current,ios::beg);
    f1.write(ptr,csize);
    //(char *)ptr = pooh->readptr;
    //*(char*)ptr = *(pooh->readptr);
    //pooh->readptr++;                 /* advance pointer */
    //cout<<pooh->sizeleft;
    pooh->sizeleft=0;                /* less data left */
    //pooh->sizeleft--;
    fsize = size*nmemb;
	
    if(csize<16384)
    {
	
	return csize;
    }
    cout<<"\n\n11111111\n"<<fsize;
    return (size*nmemb);             /* we return 1 byte at a time! */
    //return 1;
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


int main(void)
{

CURL *curl;
CURLcode res;
 char *buff,*buff1;
char header[10],temp[10],fname[10];
long int fsize,cnt,fullfile;
int i;
struct WriteThis pooh,pooh1;
struct curl_slist *chunk = NULL;

strcpy(fname,"magic.txt");
  f.open(fname,ios::in|ios::binary|ios::ate);
  fsize = f.tellg();
  cnt = fsize/16384;
  fullfile = fsize;

  if(fsize%16384!=0)
  cnt++;   

  f.close();
  buff = (char*)malloc(16384);//change
//cout<<"\n\n\ncnt";
f1.open("hello.txt",ios::out|ios::binary);
while(cnt>0)
{
  if(fsize<16384)
  {
  cout<<"\n\n\n\n";
	csize = fsize;
	buff1 = (char*)malloc(csize);
	buff = buff1;
	//buff = (char*)realloc(buff,csize);
	
  }
  else
  {
	csize = 16384; //change
  } 

        f.open(fname,ios::in|ios::binary);
  	f.seekg(current,ios::beg);
  	f.read(buff,csize);
	//cout<<endl<<buff;
  	f.close();
  	pooh.readptr = buff;
  	pooh.sizeleft = csize;
  	cout<<"\n\n\n222"<<pooh.sizeleft;
	//for(i=0;i<512;i++)
        //tempbuff[i]='\0';
 
curl = curl_easy_init();
if(curl) {
/*curl_easy_setopt(curl, CURLOPT_URL,"http://192.168.16.160:8080/SecureShare/rest/hello");
curl_easy_setopt(curl, CURLOPT_POSTFIELDS,postthis);
curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)strlen(postthis));
*/

    curl_easy_setopt(curl, CURLOPT_URL,"http://192.168.1.75:8080/SecureShare/rest/server/post/working.txt");

    /* Now specify we want to POST data */
    curl_easy_setopt(curl, CURLOPT_POST,1L);

    /* we want to use our own read function */
    curl_easy_setopt(curl, CURLOPT_READFUNCTION,read_callback);

    /* pointer to pass to our read function */
    curl_easy_setopt(curl, CURLOPT_READDATA,&pooh);

    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE_LARGE,(curl_off_t)pooh.sizeleft);

    /* get verbose debug output please */
    curl_easy_setopt(curl, CURLOPT_VERBOSE,1L);

    itoa(csize,temp);   
    strcpy(header,"fsize: ");
    //cout<<header<<"HHHHH\n\n\n";
    strcat(header,temp);
    chunk = curl_slist_append(chunk,header);
    //chunk = curl_slist_append(chunk,"Expect: 100-continue");
    //chunk = curl_slist_append(chunk, "Accept: application/vnd.pdf");
    //chunk = curl_slist_append(chunk, "Content-Type: application/vnd.pdf");
    chunk = curl_slist_append(chunk, "Content-Type: application/octet-stream");
    //chunk = curl_slist_append(chunk, "Content-Transfer-Encoding: base64");   
    //chunk = curl_slist_append(chunk, "Content-Type: /form-data");
    res = curl_easy_setopt(curl, CURLOPT_HTTPHEADER,chunk);
    
    res = curl_easy_perform(curl);
    if(res==CURLE_OK)
    {
	//cout<<buff<<endl;
    	cout<<"Done";
	
	current = current + csize;
	fsize = fsize - csize;
	cnt--;   

	//curl_easy_cleanup(curl);

	count++;
    }

}/*
if(cnt==1)
{

cout<<"\n\n\nLAST CHUNK";
	if(fsize<512)
 	 {
 		 cout<<"\n\n\n\n";
		csize = fsize;
		//buff1 = (char*)malloc(csize);
		//buff = buff1;
		//buff = (char*)realloc(buff,csize);
	
	  }
	  else
	  {
		csize = 512;
	  } 

	//buff1 = (char*)malloc(csize);
	f.open("hello.txt",ios::in|ios::binary);
  	f.seekg(current,ios::beg);
  	f.read(buff1,csize);
	//cout<<endl<<buff;
  	f.close();
  	pooh1.readptr = buff1;
  	pooh1.sizeleft = csize;


	curl = curl_easy_init();

if(curl) {

curl_easy_setopt(curl, CURLOPT_URL,"http://192.168.16.160:8050/SecureShare/rest/server/post/hello.txt");

    /* Now specify we want to POST data 
    curl_easy_setopt(curl, CURLOPT_POST, 1L);

    /* we want to use our own read function 
    curl_easy_setopt(curl, CURLOPT_READFUNCTION, read_callback);

    /* pointer to pass to our read function 
    curl_easy_setopt(curl, CURLOPT_READDATA, &pooh1);

    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (curl_off_t)pooh1.sizeleft);

    /* get verbose debug output please 
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

    itoa(csize,temp);   
    strcpy(header,"fsize: ");
    //cout<<header<<"HHHHH\n\n\n";
    strcat(header,temp);
    chunk = curl_slist_append(chunk,header);
    res = curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
    
    res = curl_easy_perform(curl);
    if(res==CURLE_OK)
    {
	cout<<buff1<<endl;
    	cout<<"Done";
	current = current + csize;
	fsize = fsize - csize;
	cnt--;   
	count++;
    }

}*/

    cout<<res;
}
/* always cleanup */
curl_easy_cleanup(curl);
//cout<<"\n\n"<<count;
f1.close();
return 0;
} 
