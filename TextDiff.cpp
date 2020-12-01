// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "WinDiffD.h"
#include <list>
#include <vector>
using namespace std;

int main() {
    string line1; // временна променлива, използва се при мап-а
    int Liner = 1; // отново временна променлива, също се използва при мап-a
    ifstream myfile; // първия файл
    ifstream myfile2; // втория файл    
    map<int, string> LinesMapFirst; // Първи мап
    map<int, string> LinesMapSecond;// Втори мап
    map<int, string> HH;

    std::map<int, string>::iterator it = LinesMapFirst.begin(); // инициализиране на итератор 
    myfile.open("D:\\GameJams\\WinDiffC\\1.txt");
    if (myfile.is_open()) // при успешно стартиран файл :)
    {        
       // cout << "First .txt: \n";
        while (getline(myfile, line1))
        {                       
            LinesMapFirst.insert(it,std::pair<int,string>(Liner,line1));
            Liner++;                     
        }         
        for (it = LinesMapFirst.begin(); it != LinesMapFirst.end(); ++it)
        {
            //std::cout << it->first << " => " << it->second << '\n'; dobavi posle :)
//ATENSHAN            
            //create something like an 2D Array to store line indexes, 
            //pointing to lists of words in said line
//ATENSHAN
        }
        myfile.close();        
        // use map.size(); to get length.
    }
    else cout << "Unable to open file";

    /*if (LinesMapFirst.at(1) == "Zemqta e krugla!")//->second == "Zemqta")
        cout << "OPA";*/ // Use this to check lines..?

    //this part opens the second file :)
    myfile2.open("D:\\GameJams\\WinDiffC\\2.txt");
    Liner = 1;
    line1 = "";
    std::map<int, string>::iterator it2 = LinesMapSecond.begin();
    std::list<string> listTwo;
    //you need to make the map again ;')
    std::map<int, string>::iterator hh = HH.begin();
    if (myfile2.is_open())
    {
        //cout << "Second .txt: \n";
        while (getline(myfile2, line1))
        {
            LinesMapSecond.insert(it2, std::pair<int, string>(Liner, line1));
            Liner++;
        }
        for (it2 = LinesMapSecond.begin(); it2 != LinesMapSecond.end(); ++it2)
        {                     
           // std::cout << it2->first << " => " << it2->second << '\n'; dobavi posle :)
            
            //ATENSHAN            
                        //create something like an 2D Array to store line indexes, 
                        //pointing to lists of words in said line
            //ATENSHAN
        }
        myfile.close();
    }             
     
    string word;
    if (LinesMapFirst.size() > LinesMapSecond.size())
    {        
        for (it = LinesMapFirst.begin(); it != LinesMapFirst.end(); ++it)
        {
            for (it2 = LinesMapSecond.begin(); it2 != LinesMapSecond.end(); ++it2)
            {
                if (it->first == it2->first)
                    if (it->second != it2->second)
                    {                                                    
                        cout << "Otkriti sa razliki na redove " << it->first << '\n' << "Text 1: " << it->second << '\n'<< "Text 2: " << it2->second << '\n' << '\n';                                             
                    }
            }                                 
            // instead of printing whole lines blankly, print them with <ErrorWord> and sentance;
        }        
            cout << "\nPurviqt file e " << LinesMapFirst.size() - LinesMapSecond.size() << " reda po-dulug ot vtoriq. \n \n";
            cout << "Originali: \n";
            cout << "Purvi text: \n";
            for (it = LinesMapFirst.begin(); it != LinesMapFirst.end(); ++it)
                cout << it->first << ": " << it->second << '\n';
            cout << "\nVtori text: \n";
            for (it2 = LinesMapSecond.begin(); it2 != LinesMapSecond.end(); ++it2)
                cout << it2->first << ": " << it2->second << '\n';        
    }
    else {
        return 0;
    }


    return 0;
}
