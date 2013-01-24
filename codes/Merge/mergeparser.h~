#include"Ixmlparser.h"
#include<iostream>
#include<string.h>
#include<tinyxml.h>
#include<fstream>
using namespace std;

class MergeParser:public IXmlParser
{
 TiXmlDocument XMLdoc;
 TiXmlElement *pRoot,*pParm,*selection,*filter,*file,*storagepaths,*cloudpath,*mobilepath,*localpath;
 public: void get_file_list(char fname[20]);
       	 void get_cloud_path(char cpath[50]);
	 void get_mobile_path(char mpath[50]);
	 void get_local_path(char lpath[50]);
	 int loadFile(char fname[20]);
	
MergeParser()
{
	
}

};
