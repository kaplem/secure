#include<iostream>
#include<fstream>
#include"localwrite.h"
#include<stdlib.h>
using namespace std;

void LocalWrite::fileopen(char fname[],fstream *f)
{
	long int fsize;
	f->open(fname,ios::out|ios::binary);
	if(!f)
	cout<<"Could not open file";
}


void LocalWrite::filewrite(char fname[],fstream *f,int csize)
{
	f->write(fname,csize);
}


int LocalWrite::fileclose(fstream *f)
{
	f->close();
} 
