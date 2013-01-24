#include"splitter.h"
#include"merge.h"
#include<iostream>
#include<string.h>
using namespace std;

class SecureShare
{
	Jsplitter s;
	Joiner j;	

 public: void Callsplitter(char file[20])
	 { 
		s.splitfile(file);
	 }

	 void Callmerger(char file1[20],char file2[20])
	 {
		j.merge(file1,file2);
	 }
};

int main(int argc,char *argv[])
{
	SecureShare s;
	
	if(argc>=3)
	{
		if(strcmp("-s",argv[1])==0)
		s.Callsplitter(argv[2]);

		if(strcmp("-j",argv[1])==0)
		s.Callmerger(argv[2],argv[3]);
		
	}
	
	if(argc==2)
	{
		//cout<<argv[1]<<argv[2];
		s.Callmerger(argv[1],argv[2]);	
	}
	
	return 0;
}
