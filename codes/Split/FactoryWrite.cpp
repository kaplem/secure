#include<iostream>
#include<fstream>
#include<string.h>
#include<ctype.h>
//#include"Iwrite.h"
#include"FactoryWrite.h"
using namespace std;

class WriteLocalPart:public  IWrite
{
  public:
  int status;
  char filename[40]; 
  int fileopen(char[],fstream*);
  void filewrite(char[],fstream*);
  int fileclose(fstream*);
  int notify(fstream *,fstream *);
  void getfilename(char []);
};
/*class WriteCloudPart:public  IWrite
{
  public:
  int fileopen(char[],fstream*);
  void filewrite(char[],fstream*);
  int fileclose(fstream*);
};
class WriteUsbPart:public  IWrite
{
  public:
  int fileopen(char[],fstream*);
  void filewrite(char[],fstream*);
  int fileclose(fstream*);
};*/
void WriteLocalPart::getfilename(char name[40])
{
cout<<"\n mmmm"<<name;
strcpy(filename,name);
}

IWrite* FactoryWrite::createInstance(char *path)
{
  char subPath[10];
  int flag=0;
  flag=check(path);
  switch(flag)
  {
    case 0: return new WriteLocalPart();
            break;
    /*case 1: return new WriteCloudPart();
            break;
    case 2: return new WriteUsbPart();
            break;*/
    case 3: return NULL;
            break;
  }
  
}
/*char* FactoryWrite::getString(char* path)
{
   char subPath[10];
   int i=0;
   while(path[i]!=':')
   {
     subPath[i]=path[i];
     i++;
   }
   subPath[i]='\0';
   return subPath;
}*/
int FactoryWrite::check(char *path)
{
   int i=0,j=0;
   if(strstr(path,"/local/"))
    return(0);
   else if(strstr(path,"/cloud/"))
    return(1);
   else if(strstr(path,"/usb/"))
    return(2);
    else    
   return(3);
  
}
 /*void FactoryWrite::strrev(char* finalSubPath,char* tempSubPath)
{
  int i=0,j=0,len=0;
  while(tempSubPath[i]!='\0')
  {
     len=len+1;
     i++;
  }
  len=len-1;
  i=len;
  j=0;
  while(len>=0)
  {
     finalSubPath[j]=tempSubPath[i];
     i--;
     j++;
  }
  finalSubPath[j]='\0';
 }*/

int WriteLocalPart::fileopen(char file[60],fstream* fout)
{
   cout<<"\n name"<<file;
   fout->open(file,ios::out|ios::binary);
   cout<<*fout;
   if(*fout)
   return(1);
   else
   return(0);
}

void WriteLocalPart::filewrite(char file[60],fstream *fout)
{
   fstream fin,f1;
   int fileSize=0,buffSize=256,totalRead=0,rem=0;
   status=fileopen(file,fout);
   cout<<"\nstatus:"<<status;
   cout<<"\nfilename:"<<filename;
   f1.open(filename,ios::in|ios::binary|ios::ate);
   fileSize=f1.tellg();
   f1.close();
   fin.open(filename,ios::in|ios::binary);
   cout<<fileSize;
   fileSize=fileSize-1;
   
   if(status==1)
   {
     if(fileSize<256)
      buffSize=fileSize;
    
     while(totalRead<fileSize)
     {
      char buff[buffSize];
      fin.read(buff,buffSize);
      fout->write(buff,buffSize);
      totalRead=totalRead+buffSize; 
      rem=fileSize-totalRead;
      if(rem>buffSize)  //Try changing the sign to < here
      buffSize=rem;    
     }
   }
   notify(fout,&fin);
  
}

int WriteLocalPart::notify(fstream *fin,fstream *fout)
{
  int notification=0;
  if(status==0)
  notification=0;
  else
  {
    fileclose(fin);
    fileclose(fout);
    notification=1;
  }

  return(notification);
}
int WriteLocalPart::fileclose(fstream *f1 )
{
  f1->close();
  return(0);
}
/*int main()
{
   IWrite *write;
   fstream fout;
   char path[60];
   strcpy(path,"/home/madhura/Desktop/local/temp.txt");
   FactoryWrite factory;
   write=factory.createInstance("/home/madhura/Desktop/local/hello.txt");
   write->filewrite(path,&fout);
   return(0);
}*/
