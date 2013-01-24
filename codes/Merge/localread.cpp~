#include"localread.h"
#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

long int LocalRead::fileopen(char fname[])
{
	int fsize;

	f.open(fname,ios::in|ios::ate|ios::binary);
	if(!f)
	{
		cout<<"\ncould not open file...";
		cout<<endl<<fname;
	}
	fsize = f.tellg();
	f.seekg(0,ios::beg);
	return fsize;
	
}

void LocalRead::fileread(char buff[],int csize)
{
	f.read(buff,csize);
}

int LocalRead::fileclose()
{
	f.close();
}
