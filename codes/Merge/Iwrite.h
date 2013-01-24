
#include<fstream>
using namespace std;
class IWrite
{
public:
virtual void fileopen(char[],fstream *f)=0;
virtual void filewrite(char[],fstream *f,int csize)=0;
virtual int fileclose(fstream *f)=0;

};
