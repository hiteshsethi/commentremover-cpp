#include <iostream.h>
#include <string>
#include <fstream>
#include <stdio.h>
using namespace std;
int main()
{
    //assuming each \n is there in test file
    string fname;
    cin>>fname;
    string line;
    fstream myfile(fname.c_str());
    ofstream temp;
    temp.open("temp.txt");
    int spaceindex=0;
    if (myfile.is_open())
    {
        int flagOpen=0;
     while ( getline (myfile,line) )
     {
         spaceindex=0;
        while(line[spaceindex]==' ' || line[spaceindex]=='\t'){
            spaceindex++;
        }
       if(line[spaceindex]=='/' and line[spaceindex+1]=='/'){
           cout<<" comment detected--> "<<line<<endl;
       }
       else if(line[spaceindex+1]=='/' and line[spaceindex+2]=='*')
       {
           flagOpen=1;
           for(int i=spaceindex+3;i<line.length()-1;i++)
           {
               if(line[i]=='*' and line[i+1]=='/')
               {
                   flagOpen=0;
                   break;
               }
           }
       }
       else if(line[spaceindex+1]=='*' and line[spaceindex+2]=='/')
       {
           flagOpen=0;
       }
       else if(flagOpen==0)
       {
            // a lot can be done here. no case handled like printf("ff");//ckckdkkd
           temp<<line<<endl;
           cout<<line<<endl;
       }
     }
     temp.close();
       myfile.close();
     if( remove(fname.c_str()) != 0 )
        perror( "Error" );

    rename("temp.txt",fname.c_str());

  }
  else{
      cout << "Unable to open file";
      }
      char c;
      cin>>c;
    return 0;
}
