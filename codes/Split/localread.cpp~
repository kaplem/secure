#include"localread.h"
#include<iostream>
#include<string.h>
#include<fstream>
#include<stdlib.h>
using namespace std;

long int LocalRead::fileopen(char fname[])
{
	int fsize;

	f.open(fname,ios::in|ios::ate|ios::binary);
	if(!f)
	{
		cout<<"\ncould not open file...";
		cout<<endl<<fname;
		exit(0);
	}
	fsize = f.tellg();
	f.seekg(0,ios::beg);
	return fsize;
	
}

void LocalRead::fileread(char buff[],int csize)
{
	f.read(buff,csize);
}

void LocalRead::fileclose()
{
	f.close();
}
