#ifndef __HTTPSEND_H
#define __HTTPSEND_H

#include"Iwrite.h"
#include"localread.h"
#include<curl/curl.h>
struct WriteThis 
{
  char *readptr;
  int sizeleft;
};

class HttpSend:public IWrite
{
 long int fsize,csize,cnt;
 int current;
 char *buff,*buff1,header[20],temp[20];
 struct WriteThis pooh,pooh1;
 struct curl_slist *chunk;
 CURL *curl;
 CURLcode res;
 LocalRead r;
 public: 
	HttpSend()
	{
		current =0;
		chunk = NULL;
	} 

	void fileopen(char[]);
	void filewrite(char[],int csize);
	void fileclose();

};
#endif
