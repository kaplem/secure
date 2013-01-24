#include"xmlparser.h"
#include<iostream>
#include<string.h>
#include<tinyxml.h>
#include<fstream>
using namespace std;

void XmlParser::get_local_path(char lpath[50])
{
	pRoot = XMLdoc.FirstChildElement("SplitInfo");
	storagepaths = pRoot->FirstChildElement("StoragePaths");
	localpath = storagepaths->FirstChildElement("LocalPath");
	strcpy(lpath,localpath->GetText());
}

void XmlParser::get_cloud_path(char cpath[50])
{
	pRoot = XMLdoc.FirstChildElement("SplitInfo");
	storagepaths = pRoot->FirstChildElement("StoragePaths");
	cloudpath = storagepaths->FirstChildElement("BaseCloudPath");
	strcpy(cpath,cloudpath->GetText());
}

void XmlParser::get_mobile_path(char mpath[50])
{
	pRoot = XMLdoc.FirstChildElement("SplitInfo");
	storagepaths = pRoot->FirstChildElement("StoragePaths");
	mobilepath = storagepaths->FirstChildElement("BaseMobilePath");
	strcpy(mpath,mobilepath->GetText());
}

void XmlParser::get_file_list(char fname[20])
{
	pRoot = XMLdoc.FirstChildElement("SplitInfo");
	selection = pRoot->FirstChildElement("Selection");
	filter = selection->FirstChildElement("Filter");
	file = filter->FirstChildElement("File");
	strcpy(fname,file->GetText());
}

int XmlParser::loadFile(char fname[20]) //Problem here !!
{
    bool loadOkay = XMLdoc.LoadFile(fname);

        if (loadOkay)
        {
		return 1;
	}
	else
	{
		cout<<"\nSplit Xml Load Error";
		return 0;					
	}
}


