#include<iostream>
#include"splitter.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fstream>
using namespace std;
int Jsplitter::openfile(char file[20],fstream *f1)
{
	int end;
	f1->open(file,ios::in|ios::binary|ios::ate);
	end = f1->tellg();
	f1->seekg(0,ios::beg);
	if(!f1)
	{
		cout<<"could not open file";
		exit(0);
	}

	return end;
}

void Jsplitter::splitfile(char file[20])
{
 char buff,*p,*q,fname[20],ext[4],part1[20],part2[20],part3[20];
 fstream f1,f2,f3,f4;
	//pair1 fx1[3];
 int i,fx[3],temp,buff1,end;
	

 end = openfile(file,&f1);
	p = file;
	q = fname;

	while(*p != '.')
	{
		*q = *p;
		p++;
		q++;
	}
	
	*q = '\0';
	q = ext;

	while(*p!='\0')
	{
		*q = *p;
		q++;
		p++;
	}
	
	*q = '\0';
	
	strcpy(part1,fname);
	strcpy(part2,fname);
	strcpy(part3,fname);

	strcat(part1,"1");	
	strcat(part2,"2");	
	strcat(part3,"3");	

	strcat(part1,ext);	
	strcat(part2,ext);
	strcat(part3,ext);

	f2.open(part1,ios::out|ios::binary);
	f3.open(part2,ios::out|ios::binary);
	f4.open(part3,ios::out|ios::binary);
	
		if(!f2 || !f3 || !f4)
		{			
			cout<<"could not open";
			exit(0);
		}
		
	temp = 2;
	buff = temp;
	f2.write(&buff,1);
	
	temp = 4;
	buff = temp;
	f3.write(&buff,1);

	temp = 3;
	buff = temp;
	f4.write(&buff,1);
	
	while(end > 0)
	{
		f1.read(&buff,1);		
		buff1 = buff;	
		cout<<buff1<<endl;

		i=0;	
		fx[i++] = (50*2)+buff1;
		fx[i++] = (50*4)+buff1;							
		fx[i++] = (50*3)+buff1;
	
		i=0;
		buff = fx[i++];
		f2.write(&buff,1);
		//cout<<fx[i]<<endl;
		buff = fx[i++];
		f3.write(&buff,1);
		buff = fx[i++];
		f4.write(&buff,1);
		end--;				
	}
	
f1.close();
f2.close();
f3.close();
f4.close();

}

void Jsplitter::read_xml(char file[20])
{

}



