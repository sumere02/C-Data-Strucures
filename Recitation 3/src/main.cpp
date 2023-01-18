#include <stdio.h>
#include <iostream>
#include "ExpandingArray.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[]){

    string line;
    fstream infile;
    ExpandingArray* ea=NULL;

    if(argc < 1)
        cout<<"Provide a file name"<<endl;

    infile.open(argv[1],ios::in);
    if (infile.is_open()){   
        int line_no=0;

        while(getline(infile, line)){ 
            stringstream ss(line);
            if(line_no==0){
                int x = 0;
                ss >> x;
                ea = new ExpandingArray(x);
            }
            else{
                string word; 
                ss >> word;
                if(word.compare("SS")==0){
                    ss >> word;
                    if(word.compare("TWICE")==0)
                        ea->set_strategy(TWICE);
                    else if(word.compare("LOG")==0)
                        ea->set_strategy(LOG);
                    else if(word.compare("CAP_BY_CAP")==0)
                        ea->set_strategy(CAP_BY_CAP);
                    else cout<<"UNKNOWN STRATEGY COMMAND"<<word<<endl;
                }
                else if(word.compare("ADD")==0){
                    int x = 0;
                    vector<int> v;
                    while (ss >> x)
                        v.push_back(x);
                    ea->addAll(&v[0], v.size());
                }
                else if(word.compare("GC")==0){
                    cout<<ea->get_capacity()<<" ";
                }
                else if(word.compare("GS")==0){
                    cout<<ea->get_size()<<" ";
                }
                else if(word.compare("PRINT")==0){
                    ea->print();
                }
                else if(word.compare("CONTAINS")==0){
                    int x = 0;
                    ss >> x;
                    if(ea->contains(x)>=0)
                        cout<<x<<" is at index "<< ea->contains(x)<<" ";
                    else cout<<x<<" is not in the array ";
                }
                else if(word.compare("REMOVE")==0){
                    int x = 0;
                    vector<int> v;
                    while (ss >> x)
                        v.push_back(x);
                    ea->removeAll(&v[0], v.size());
                }
                else if(word.compare("CLEAR")==0){
                    ea->clear();
                }
                else{
                    cout<<"WRONG COMMAND IN LINE "<<line_no<<endl;
                }
                //while (ss >> word) 
                //{
                //    cout << word << endl;
                //}
            }
            line_no++;
        }
        infile.close();
    }
        else
            cout<<"Cannot find file"<<endl;
    /*
    ExpandingArray ea(10);
    ea.set_strategy(CAP_BY_CAP);
    int myarray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    ea.addAll(myarray,15);
    ea.print();
    cout<<ea.get_capacity()<<endl;

    ea.addAll(myarray,15);
    ea.print();
    cout<<ea.get_capacity()<<endl;

    ea.addAll(myarray,15);
    ea.print();
    cout<<ea.get_capacity()<<endl;

    ea.removeAll(myarray,15);
    ea.print();
    cout<<ea.get_capacity()<<endl;

    ea.removeAll(myarray,15);
    ea.print();
    cout<<ea.get_capacity()<<endl;

    ea.removeAll(myarray,15);
    ea.print();
    cout<<ea.get_capacity()<<endl;
*/
    //getchar();
    return EXIT_SUCCESS;
}

