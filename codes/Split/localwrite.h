#ifndef __LOCALWRITE_H
#define __LOCALWRITE_H
#include"Iwrite.h"
#include<fstream>
#include<iostream>

class LocalWrite:public IWrite
{
	fstream f;
	public: void fileopen(char[]);
	        void filewrite(char[],int csize);
		void fileclose();

LocalWrite()
{

}

};
#endif
