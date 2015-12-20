// docClass.cpp
// Madelyn Nelson
// CSE20212

#include<boost/regex.hpp>
#include<set>
#include<ctype.h>
#include<iostream>
#include<fstream>
#include<map>
#include<string>
#include"docClass.h"
#include<algorithm>
#include<boost/algorithm/string.hpp>
#include<vector>
#include<boost/foreach.hpp>

using namespace std;
using namespace boost;

docClass::docClass(string file){
    myFile = file; // constructor intakes a file, sets equal to private variable
}

void docClass::countWords(){
    string line;
    vector<string> tolkien; // tolkien sounds better than token
    ifstream file(myFile.c_str()); // must be a c string to work
    if (file.is_open()){ // checks if file opens correctly
       while(getline(file,line)){
            line = htmlConverter(line); // checks if theres any html things, like <>, and if so gets rid of them
            string result; 
            remove_copy_if(line.begin(), line.end(), back_inserter(result),ptr_fun<int,int>(&ispunct));
            split(tolkien,result,is_any_of(" ")); // reads words, separated by spaces

            for(int i=0; i<tolkien.size(); i++){
                to_lower(tolkien[i]); // makes all words tolower, so count is not case sensitive
                wordMap[tolkien[i]]++;
            }
            tolkien.clear();
       }

        file.close(); // closes file
    }
    else { // only checks if file is opened, not that it exists
        cout << "Error. File could not open." << endl;
    }
}

void docClass::printMap(){

    pair<string,int> p;
    BOOST_FOREACH(p,wordMap){
        cout << p.first << ", " << p.second << endl; // prints map pair by pair
    }
}

map<string,int> docClass::getMap(){
    return wordMap;
}

string docClass::htmlConverter(string line){
    regex htmlTagRegex("<[^<>]*>"); // looks for spots that have html characteristics
    regex hrefTag("href=\"(.*?)\"");
    smatch result;
    if (regex_search(line, htmlTagRegex)){
        if (regex_search(line,result,hrefTag)){
            string submatch(result[1]);
            hrefValues.insert(submatch);
        }
        // removes the html tags, makes the line not html anymore
        line = regex_replace(line,htmlTagRegex, "");
    }
    return line;
}

void docClass::printHREF(){
    cout << "HREF tags : ";
    BOOST_FOREACH(const string& s, hrefValues){
        cout << s << endl; // prints the href vals
    }
}

double docClass::jaccard(map<string,int> wordMap2){ // finds the jaccard similarity between the two files
    set<string> word1,word2,output;
    vector<string> intersection;

    pair<string, int> stuff;

    BOOST_FOREACH(stuff,wordMap){
        word1.insert(stuff.first);
    }
    BOOST_FOREACH(stuff,wordMap2){
        word2.insert(stuff.first);
    }
    set_intersection(word1.begin(),word1.end(),word2.begin(),word2.end(),back_inserter(intersection));

    output=word1;
    output.insert(word2.begin(),word2.end());

    double interSize = intersection.size(); // size of the intersection of words
    double outputSize = output.size(); // size of union of files

    cout << "Jaccard Similarity : " << interSize/outputSize << endl;
    return interSize/outputSize; // prints the ratio as well, but returns it too
}
