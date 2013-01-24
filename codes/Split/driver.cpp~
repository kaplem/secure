#include<iostream>
#include<string.h>
#include"xmlparser.h"
#include"filesplitter.h"
using namespace std;

class Driver
{
 XmlParser p;
 filesplitter s;
 char cpath[50],mpath[50],fname[20],lpath[50],uname[50];
 
 public:void getPath(char xmlFile[20]);
	void getList();
	void callSplitter();
	
};

void Driver::callSplitter()
{
	s.set_file_name(fname);
	s.set_path(lpath,cpath,mpath); 
	s.split();
        s.sendParts();
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
}

int main(int argc,char *argv[])
{

Driver d;
char fname[20];
d.getPath(argv[1]);
d.getList();
d.callSplitter();
return 0;
}
