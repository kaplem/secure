#ifndef __IREAD_H
#define __IREAD_H
#include<iostream>
#include<fstream>
using namespace std;
class IRead
{
public:
virtual long int fileopen(char fname[])=0;
virtual void fileread(char fname[],int csize)=0;
virtual void fileclose()=0;
};
#endif
