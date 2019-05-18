#include <iostream>
#include <fstream>
#include <string>
#include <map>
#define FILE_PATH "result/"
#define P2_FILE_PATH "p2_result/"
#define PROBLEM_2_CLIENTS_NUMBER 6
using namespace std;
int main()
{
    //  map<int,int> book number , is show or not1  - 1.
    //  map<string,map<int,int>>   kind ticket , to  1.  - 2.
    //  map<string,map<string,map<int,int>>> concert name , to 2. 
    
    map<string,map<string,map<int,int>>> tester;
    fstream file;
    string concertname,ticketname,ticketnumber,subticketnumber;
    int ticket_time;
    int i;
    for(i = 0 ; i < PROBLEM_2_CLIENTS_NUMBER ; i++)
    {
		string filename = P2_FILE_PATH;
		filename+= to_string(i+1);
		filename+=".txt";
        file.open(filename.c_str());
        if(!file){
            cerr<<"filename = "<<filename<<" not exist\n";
            exit(-1);
        }
        while(file>>concertname){
            if(concertname == "sorry," || concertname == "exit"){
                break;
            }
            file>>ticketname>>ticketnumber>>ticket_time;
            subticketnumber = ticketnumber.substr(ticketname.length(),ticketnumber.length());
            if(tester[concertname][ticketname][ atoi(subticketnumber.c_str()) ]){
                cout<<"at file = "<<filename<<" concert name = "<<concertname<<" , ticket class = "<<ticketname<<" , ticket number = "<<subticketnumber<<", is alread exist"<<endl;
                //break;
            }
            else{
                tester[concertname][ticketname][ atoi(subticketnumber.c_str()) ] = 1;
                //cout<<concertname<<" "<<ticketname<<" "<<subticketnumber<<endl;
            }
        }
        cout<<filename<<"load finish"<<endl;
        file.close();
    }
}