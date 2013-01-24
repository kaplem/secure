#include <stdio.h>
#include <curl/curl.h>
#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{
CURL *curl;
CURLcode res;
static const char postthis[]="Secure Share";

curl = curl_easy_init();
if(curl) 
{
	curl_easy_setopt(curl, CURLOPT_URL,"http://192.168.1.75:8080/SecureShare/rest/Hello");
	curl_easy_setopt(curl, CURLOPT_POSTFIELDS,postthis);
	curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)strlen(postthis));

	/* get verbose debug output please */
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

res = curl_easy_perform(curl);
cout<<res;
/* always cleanup */
curl_easy_cleanup(curl);
}
return 0;
} 
