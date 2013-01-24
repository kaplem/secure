//#ifndef __SPLITTER_H_INCLUDED__
//#define __SPLITTER_H_INCLUDED__
#include<fstream>
using namespace std;
class Jsplitter
{
	
	public: int openfile(char file[20],fstream *f1);
        	void splitfile(char file[20]);	
		void read_xml(char file[20]);
};
