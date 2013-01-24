#include"Iread.h"
#include<fstream>
class LocalRead:public IRead
{
fstream f;
	public: long int fileopen(char fname[]);
		void fileread(char fname[],int csize);
		int fileclose();

};
