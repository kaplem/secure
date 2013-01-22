#include"merge.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;


int Joiner::openfile(char file[20])
{
	int end;
/*	f1.open(file,ios::in|ios::binary|ios::ate);
	end = f1.tellg();
	f1.seekg(0,ios::beg);
	if(!f1)
	{
		cout<<"could not open file";
		exit(0);
	}

	return end;
*/
}

void Joiner::merge(char part1[20],char part2[20])
{
	fstream f1,f2,f3,f4;
	int x0,x1,fx[2],d1,d2,final,i=0;
	int end1,end2;
	int t11,t12;
	char x[3],y[3],buff1,buff2,ext[4],*p,*q,fname[20],buff[80];
	//pair1 fx1[3];
	f2.open(part1,ios::in|ios::binary|ios::ate);
	f3.open(part2,ios::in|ios::binary|ios::ate);
	end1 = f2.tellg();
	end2 = f3.tellg();
	end1--;
	end2--;
	f2.seekg(0,ios::beg);
	f3.seekg(0,ios::beg);	

	p = part1;
	q = ext;

	while(*p!='.')
	p++;
	
	while(*p!='\0')
	{
		*q = *p;
		p++;
		q++;
	}
	*q = '\0';

	strcpy(fname,"magic\0");
	strcat(fname,ext);
	f4.open(fname,ios::out|ios::binary);
	
	if(!f2 || !f3 || !f4)
	{
		cout<<"Enter the correct file name";
		exit(0);
	}
/* original logic
	f2.read(&buff1,1);
	x0 = buff1;

	f3.read(&buff2,1);	
	x1 = buff2;
*/	
	//cout<<endl<<x0<<x1;

x0 = 2;
x1 = 4;
f2.read(buff,80);
f3.read(buff,80);
end1 = end1 - 80;
end2 = end2 - 80;
	while(end1>0 && end2>0)
	{
		f2.read(&buff1,1);
		f3.read(&buff2,1);
		
		fx[0] = buff1;
		fx[1] = buff2;
		//cout<<endl<<fx[0]<<endl<<fx[1];		

		d1 = x0 - x1;
		d2 = x1 - x0;
		//cout<<d1<<endl<<d2;

		t11 = fx[0]*(-x1);
		t11 = t11/d1;
		t12 = fx[1]*(-x0);
		t12 = t12/d2;
		
		//cout<<endl<<t11<<endl<<t12;
		t11 = t11 + t12;
		final = t11;
		buff1 = final;
		//cout<<t11<<endl;

		f4.write(&buff1,1);
		end1--;
		end2--;
	}
	f2.close();
	f3.close();
	f4.close();
}

void Joiner::read_xml(char file[20])
{

}
