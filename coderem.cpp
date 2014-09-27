#include <iostream.h>
#include <string>
#include <fstream>
#include <stdio.h>
using namespace std;
int main()
{
    string fname;
    cin>>fname;
    string line;
    fstream myfile(fname.c_str());
    ofstream temp;
    temp.open("temp.txt");
    int spaceindex=0;
    if (myfile.is_open())
    {
     while ( getline (myfile,line) )
     {
         spaceindex=0;
        while(line[spaceindex]==' '){
            spaceindex++;
        }
       if(line[spaceindex+1]=='/' and line[spaceindex+2]=='/'){
           cout<<" comment detected--> "<<line<<endl;
       }
       else
       {
           temp<<line<<endl;
           cout<<line<<endl;
       }
     }
     temp.close();
       myfile.close();
     if( remove(fname.c_str()) != 0 )
        perror( "Error" );
  
    rename("temp.txt","test.cpp");

  }
  else{
      cout << "Unable to open file";
      }
      char c;
      cin>>c;
    return 0;
}
