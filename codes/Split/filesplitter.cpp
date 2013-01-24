#include<iostream>
#include"filesplitter.h"
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"localread.h"
#include"localwrite.h"
#include"httpsend.h"
using namespace std;

void filesplitter::set_file_name(char fname[])
{
	strcpy(fileName,fname);
}


void filesplitter::set_path(char loc1[],char loc2[],char loc3[])
{
	strcpy(lpath,loc1);
	strcpy(cpath,loc2);
	strcpy(mpath,loc3);
}


void filesplitter::split()
{
 char buff,file[60],header1[80],header2[80],header3[80];
 int i,fx[3],temp,buff1,res;
 long int end;
 LocalWrite w1,w2,w3;
 LocalRead r;
 
strcpy(uname,"sanket");
strcpy(file,lpath);
strcat(file,fileName);
fileSize = r.fileopen(file);

end = fileSize;
//cout<<"\n file:"<<fileLocation;
strcpy(header1,"Cloud path:");
strcat(header1,uname);
strcat(header1,"/2");
strcat(header1,fileName);
strcat(header1,"\n");
strcat(header1,"Usb path:");
strcat(header1,uname);
strcat(header1,"/3");		
strcat(header1,fileName);
strcat(header1,"\n");		


strcpy(header2,"Local path:");
strcat(header2,uname);
strcat(header2,"/");
strcat(header2,fileName);
strcat(header2,"\n");
strcat(header2,"Usb path:");	
strcat(header2,uname);
strcat(header2,"/3");		
strcat(header2,fileName);
strcat(header2,"\n");	


strcpy(header3,"Cloud path:");
strcat(header3,uname);
strcat(header3,"/2");
strcat(header3,fileName);
strcat(header3,"\n");
strcat(header3,"LocalPath:");		
strcat(header3,uname);
strcat(header3,"/");
strcat(header3,fileName);
strcat(header3,"\n");		

	strcpy(part1,lpath);
	strcpy(part2,cpath);
	strcpy(part3,mpath);

	strcat(part1,uname);	
	strcat(part2,uname);	
	strcat(part3,uname);
	strcat(part1,"/");
	strcat(part2,"/2");
	strcat(part3,"/3");	
	strcat(part1,fileName);	
	strcat(part2,fileName);	
	strcat(part3,fileName);

	w1.fileopen(part1);
	w2.fileopen(part2);
	w3.fileopen(part3);
        
	
	
	w1.filewrite(header1,80);

	w2.filewrite(header2,80);

	w3.filewrite(header3,80);	

//cout<<header1<<endl<<header2<<endl<<header3;
/*	temp = 2;
	buff = temp;
	f2.write(&buff,1);
	
	temp = 4;
	buff = temp;
	f3.write(&buff,1);

	temp = 3;
	buff = temp;
	f4.write(&buff,1);
*/
	while(end > 0)
	{
		r.fileread(&buff,1);		
		buff1 = buff;	
		//cout<<buff1<<endl;

		i=0;	
		fx[i++] = (50*2)+buff1;
		fx[i++] = (50*4)+buff1;							
		fx[i++] = (50*3)+buff1;
	
		i=0;
		buff = fx[i++];
		w1.filewrite(&buff,1);
		//cout<<fx[i]<<endl;
		buff = fx[i++];
		w2.filewrite(&buff,1);
		buff = fx[i++];
		w3.filewrite(&buff,1);
		end--;				
	}
	
r.fileclose();
w1.fileclose();
w2.fileclose();
w3.fileclose();
cout<<"DONE!!!!";
}

void filesplitter::sendParts()
{
	HttpSend h;
	h.fileopen(part3);
	h.filewrite(part3,16384);
	h.fileclose();	
}
