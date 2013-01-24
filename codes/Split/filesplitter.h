
class filesplitter
{
char fileName[40];
char lpath[40],cpath[50],mpath[50],uname[50],part1[50],part2[50],part3[50];
long int fileSize;
public:
void set_file_name(char fname[]);
void set_path(char loc1[],char loc2[],char loc3[]);
void split();
void sendParts();
};
