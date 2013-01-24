#include<fstream>
#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
long int fsize,csize,current=0,cnt;
fstream f1,f2;
char buff,buff1[2048];

f1.open("magic.pdf",ios::binary|ios::in|ios::ate);
fsize = f1.tellg();
f1.seekg(0,ios::beg);

cout<<fsize;

f2.open("hello.pdf",ios::binary|ios::out);

cnt = fsize;

//if((fsize%512)==0)
//cnt++;

cout<<endl<<cnt;

//buff = (char*)malloc(2048);

while(cnt>0)
{
	if(fsize < 512)
	{
		csize = fsize;
		//buff1 = (char*)malloc(csize);
		//strcpy(buff,buff1);
	}
	else
		csize = 512;
	

  	f1.read(&buff,1);
	//cout<<endl<<buff;
	f2.write(&buff,1);
	//if(f1.eof())
	//break;
	current = current + csize;
	fsize = fsize - csize;
	cnt--;
}

f1.close();
f2.close();
return 0;
}
