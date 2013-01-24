#include"Ixmlparser.h"
#include<tinyxml.h>
class XmlParser:public IXmlParser
{
 TiXmlDocument XMLdoc;
 TiXmlElement *pRoot,*pParm,*selection,*filter,*file,*storagepaths,*cloudpath,*mobilepath,*localpath;
 public: void get_file_list(char fname[20]);
       	 void get_cloud_path(char cpath[50]);
	 void get_mobile_path(char mpath[50]);
	 void get_local_path(char lpath[50]);
	 int loadFile(char fname[20]);
	
XmlParser()
{
	
}

};
