// docClass.h
// Madelyn Nelson
// CSE20212

#include<iostream>
#include<fstream>
#include<map>
#include<string>
#include<set>
#include<vector>
#include<stdexcept>

using namespace std;

class docClass{
    public:
        docClass(string); // constructor
        void countWords(); // counts word
        map<string,int> getMap(); // gets the private map variable
        void printMap(); // prints map
        double jaccard(map<string,int>); // calculates ratio of num of items in 2 files
        string htmlConverter(string); // turns html file into normal text, line by line
        void printHREF(); // prints href 
    private:
        map<string, int> wordMap; // map of words paired with their count
        string myFile; // file name
        set<string> hrefValues; // list of hrefs
};
