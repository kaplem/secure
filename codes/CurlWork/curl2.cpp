#include <stdio.h>
#include <curl/curl.h>
#include<iostream>
#include<string.h>
using namespace std;

struct WriteThis {
  const char *readptr;
  int sizeleft;
};

static size_t read_callback(void *ptr, size_t size, size_t nmemb, void *userp)
{
  struct WriteThis *pooh = (struct WriteThis *)userp;

  if(size*nmemb < 1)
    return 0;

  if(pooh->sizeleft) 
  {
    //strcpy((char *)ptr,pooh->readptr); /* copy one single byte */
    *(char*)ptr = *(pooh->readptr);
    pooh->readptr++;                 /* advance pointer */
    //cout<<pooh->sizeleft;
    //pooh->sizeleft=0;                /* less data left */
    pooh->sizeleft--;
    //return (size*nmemb);             /* we return 1 byte at a time! */
	return 1;
  }

  return 0;                          /* no more data left to deliver */
}

int main(void)
{
CURL *curl;
	CURLcode res;
static const char postthis[]="Secure";

struct WriteThis pooh;
struct curl_slist *chunk = NULL;

  pooh.readptr = postthis;
  pooh.sizeleft = strlen(postthis);

curl = curl_easy_init();
if(curl) {
/*curl_easy_setopt(curl, CURLOPT_URL,"http://192.168.16.160:8080/SecureShare/rest/hello");
curl_easy_setopt(curl, CURLOPT_POSTFIELDS,postthis);
curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)strlen(postthis));
*/

    curl_easy_setopt(curl, CURLOPT_URL,"http://192.168.1.75:8080/SecureShare/rest/Hello");

    /* Now specify we want to POST data */
    curl_easy_setopt(curl, CURLOPT_POST, 1L);

    /* we want to use our own read function */
    curl_easy_setopt(curl, CURLOPT_READFUNCTION, read_callback);

    /* pointer to pass to our read function */
    curl_easy_setopt(curl, CURLOPT_READDATA, &pooh);

    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (curl_off_t)pooh.sizeleft);

    /* get verbose debug output please */
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

     

      chunk = curl_slist_append(chunk, "fsize: 100");
      res = curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);

res = curl_easy_perform(curl);
cout<<res;
/* always cleanup */
curl_easy_cleanup(curl);
}
return 0;
} 
