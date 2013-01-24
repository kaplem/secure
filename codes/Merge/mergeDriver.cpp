#include<iostream>
#include<string.h>
#include"mergeparser.h"
#include"merge.h"
#include"localread.h"
using namespace std;

class Driver
{
 MergeParser p;
 Joiner j;
 LocalRead r;
 char cpath[50],mpath[50],fname[20],lpath[50],file1[50],file2[50],temp[20],*q,ext[5];
 
 public:void getPath(char xmlFile[20]);
	void getList();
	void callJoiner();
	void extract_header();
};

void Driver::extract_header()
{
	int i=0,k=0;
	char buff[80],buff1[50];
	
	r.fileopen(file1);
	r.fileread(buff,80);
	
	i=11;
	while(buff[i]!='\n')
	{
		buff1[k]=buff[i];
		i++;
		k++;
	}
	buff1[k] = '\0';
	r.fileclose();

	strcat(file2,buff1);
	
}

void Driver::callJoiner()
{
	int i=0;
	
	strcpy(file1,lpath);
	strcpy(file2,cpath);
	q = temp;
	while(fname[i]!='.')
	{
		*q = fname[i];	
		i++;
		q++;
	}
	*q = '\0';
	i++;
	q = ext;
	while(fname[i]!='\0')
	{
		*q = fname[i];
		i++;
		q++;
	}
	*q = '\0';

	strcat(file1,temp);	
	strcat(file1,".");
	strcat(file1,ext);	

	extract_header();
	j.merge(file1,file2);
}

void Driver::getPath(char xmlFile[20])
{
	p.loadFile(xmlFile);
	p.get_cloud_path(cpath);
	p.get_mobile_path(mpath);
	p.get_local_path(lpath);
}

void Driver::getList()
{
	p.get_file_list(fname);
	//cout<<endl<<cpath;
	//cout<<endl<<mpath;
	//cout<<endl<<fname;
	//cout<<endl<<lpath;
}

int main(int argc,char *argv[])
{

Driver d;
char fname[20];

d.getPath(argv[1]);

d.getList();

d.callJoiner();
//d.callSplitter(argv[2]);
return 0;
}
