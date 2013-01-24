#include <curl/curl.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include"httpread.h"
int flag=0;
static size_t write_callback(void *ptr, size_t size, size_t nmemb, void *userp)
{
  //struct WriteThis *pooh = (struct WriteThis *)userp;
  int fsize=0;
  char *buff;
  buff = (char*)userp;
  
  if(buff!=NULL)
  {
    //strcpy(buff,(char*)ptr); /* copy one single byte */
    
    cout<<buff;                /* less data left */
    buff = (char*)ptr;
    cout<<"\n"<<buff;
    flag=1;
    return (size*nmemb);             /* we return 1 byte at a time! */
  }

  return 0;                          /* no more data left to deliver */
}


long int HttpRead::fileopen(char fname[])
{
	//w.fileopen(fname);
}

void HttpRead::fileread(char fname[],int maxcsize)
{
 char *buff; 
 //buff = (char*)malloc(16384);//change
 
 //while(flag!=1)
 {
 	
	curl = curl_easy_init();

	if(curl) 
	{

		pooh.readptr=NULL;

    		curl_easy_setopt(curl, CURLOPT_URL,"http://192.168.43.120:8080/SecureShare/rest/send/getdata");

    		/* Now specify we want to POST data */
    		curl_easy_setopt(curl,CURLOPT_NOPROGRESS,1L);

    		/* we want to use our own read function */
    		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);

    		/* pointer to pass to our read function */
    		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buff);

    		//curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (curl_off_t)pooh.sizeleft);

    		/* get verbose debug output please */
    		curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
		
		//itoa(csize,temp);   
    		//strcpy(header,"fsize: 100");
    		//strcat(header,temp);
    		//chunk = curl_slist_append(chunk,header);
		chunk = curl_slist_append(chunk,"Content-Type: application/octet-stream");
    		res = curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
    
    		res = curl_easy_perform(curl);
    		if(res==CURLE_OK)
    		{
			cout<<buff;
			if(strcmp(buff,"end")==0)
			flag=1;
			buff = NULL;
			flag=0;
		}
	}
 cout<<res;
}

/* always cleanup */
curl_easy_cleanup(curl);

}	


void HttpRead::fileclose()
{
	//w.fileclose();
}

int main()
{
HttpRead r;
char *str;
r.fileopen(str);
r.fileread(str,5);
r.fileclose();
return 0;
}
