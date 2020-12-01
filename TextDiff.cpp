#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "WinDiffD.h"
using namespace std;

int main() {    
    bool filesRead = true; // променя се на false ако някой от файловете не се отвори успешно
    string line1; // временна променлива, използва се при маповете
    int Liner = 1; // отново временна променлива, също се използва при маповете
    ifstream myfile; // първия файл
    ifstream myfile2; // втория файл    
    map<int, string> LinesMapFirst; // Първи мап, маповете съдържат <int{номерация на ред},string{самия ред}>
    map<int, string> LinesMapSecond;// Втори мап

    std::map<int, string>::iterator it = LinesMapFirst.begin(); // инициализиране на итератор за първи мап
    myfile.open("<DRIVE>:\\<FOLDER>\\<FOLDER>\\<FILENAME>.txt"); //опитваме да стартираме файл. За да промените файла, просто променете адреса му :).
    /*   !!!Обърнете внимание, текстовият файл не трябва да съдържа букви на кирилица!!!   */
    if (myfile.is_open()) // при успешно стартиран файл ;)
    {             
        try {
            while (getline(myfile, line1))
            {
                LinesMapFirst.insert(it, std::pair<int, string>(Liner, line1)); // "map-va" съответните редове със тяхното съдържание
                Liner++; // преминава се на следващия ред                             
            }
            myfile.close(); //garbage collection     
        }
        catch(exception e){
            filesRead = false;
        }
            
    }
    else { cout << "Unable to open the first file \n"; filesRead = false;} // при неуспешно стартиране на файла 
   
// Повтаряме същия процес за втория файл...
    myfile2.open("D:\\<FOLDER>\\<FOLDER>\\<FILENAME>.txt");
    Liner = 1;
    line1 = "";
    std::map<int, string>::iterator it2 = LinesMapSecond.begin();           
    if (myfile2.is_open())
    {
        try {
            while (getline(myfile2, line1))
            {
                LinesMapSecond.insert(it2, std::pair<int, string>(Liner, line1));
                Liner++;
            }
            myfile.close();
        }
        catch (exception e) {
            filesRead = false;
        }
    }
    else { cout << "---\nUnable to open the second file\n"; filesRead = false; }

// Щом вече имаме нужните ни data structures, можем да започваме с проверките:
    if (filesRead) { //Проверява дали и двата файла са отворени успешно, ако да, то програмата продължава
        if (LinesMapFirst.size() > LinesMapSecond.size()) //Големите if-ове служат само да разберем кой текст е по-голям,
                                                                                                //логиката в другите блокове е същата 
        {
            for (it = LinesMapFirst.begin(); it != LinesMapFirst.end(); ++it) // започваме итерацията върху първия текст
            {
                for (it2 = LinesMapSecond.begin(); it2 != LinesMapSecond.end(); ++it2) // правим същото със втория...
                {
                    if (it->first == it2->first) //продължаваме, само ако ще проверяваме текстовете от еднакви редове
                        if (it->second != it2->second) // ако съдържанието в реда е еднакво, няма смисъл да продължаваме и се връщаме към 
                        {                                                                             //цикъла от 52-ри ред
                            //отпечатваме редовете, в които има разлики
                            cout << "Otkriti sa razliki na redove " << it->first << '\n' << "Text 1: " << it->second << '\n' << "Text 2: " << it2->second << '\n' << '\n';
                        }
                }
            }
            //даваме разкликата в броя на редовете, ако има - очевидно има разлики в текстовете
            cout << "\nPurviqt file e " << LinesMapFirst.size() - LinesMapSecond.size() << " reda po-dulug ot vtoriq. \n \n";
            cout << "Originali: \n";
            cout << "Purvi text: \n";
            for (it = LinesMapFirst.begin(); it != LinesMapFirst.end(); ++it)
                cout << it->first << ": " << it->second << '\n';
            cout << "\nVtori text: \n";
            for (it2 = LinesMapSecond.begin(); it2 != LinesMapSecond.end(); ++it2)
                cout << it2->first << ": " << it2->second << '\n';
        }
        //Надолу правим същото, с малки промени, незасягащи логиката
        else if (LinesMapFirst.size() < LinesMapSecond.size()) {
            for (it2 = LinesMapSecond.begin(); it2 != LinesMapSecond.end(); ++it2)
            {
                for (it = LinesMapFirst.begin(); it != LinesMapFirst.end(); ++it)
                {
                    if (it2->first == it->first)
                        if (it2->second != it->second)
                        {
                            cout << "Otkriti sa razliki na redove " << it->first << '\n' << "Text 1: " << it->second << '\n' << "Text 2: " << it2->second << '\n' << '\n';
                        }
                }
            }
            cout << "\nVtoriqt file e " << LinesMapSecond.size() - LinesMapFirst.size() << " reda po-dulug ot purviq. \n \n";
            cout << "Originali: \n";
            cout << "Purvi text: \n";
            for (it = LinesMapFirst.begin(); it != LinesMapFirst.end(); ++it)
                cout << it->first << ": " << it->second << '\n';
            cout << "\nVtori text: \n";
            for (it2 = LinesMapSecond.begin(); it2 != LinesMapSecond.end(); ++it2)
                cout << it2->first << ": " << it2->second << '\n';
        }
        else
        {
            for (it = LinesMapFirst.begin(); it != LinesMapFirst.end(); ++it)
            {
                for (it2 = LinesMapSecond.begin(); it2 != LinesMapSecond.end(); ++it2)
                {
                    if (it->first == it2->first)
                        if (it->second != it2->second)
                        {
                            cout << "Otkriti sa razliki na redove " << it->first << '\n' << "Text 1: " << it->second << '\n' << "Text 2: " << it2->second << '\n' << '\n';
                        }
                }
            }
            cout << "Originali: \n";
            cout << "Purvi text: \n";
            for (it = LinesMapFirst.begin(); it != LinesMapFirst.end(); ++it)
                cout << it->first << ": " << it->second << '\n';
            cout << "\nVtori text: \n";
            for (it2 = LinesMapSecond.begin(); it2 != LinesMapSecond.end(); ++it2)
                cout << it2->first << ": " << it2->second << '\n';
        }
    }
    else
        cout << "---\nImashe problem pri izpulnqvaneto na programata, molq proverete prikachenite ot vas failove. \n";
    return 0;
}
