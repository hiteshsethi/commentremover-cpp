#include <iostream.h>
#include <string>
#include <fstream>
using namespace std;
int main()
{
    string fname;
    cin>>fname;
    string line;
    fstream myfile(fname.c_str());
    int spaceindex=0;
    if (myfile.is_open())
    {spaceindex=0;
     while ( getline (myfile,line) )
     {
        while(line[spaceindex]==' '){
            spaceindex++;
        }
       if(line[spaceindex]=='/' and line[spaceindex+1]=='/')
       {
           cout<<"comment detected--> "<<line<<endl;
       }
       else
       {
           cout<<line<<endl;
       }
     }
     myfile.close();
  }
  else{
      cout << "Unable to open file";
      }
      char c;
      cin>>c;
    return 0;
}
