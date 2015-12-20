// sevenLetterWord.cpp
// Madelyn Nelson
// CSE20212

#include<iostream>

using namespace std;

int main(){
    long int count=0; // counts number of possible words of length 7

    for (int prim=0; prim<26; prim++){ // trying to use spanish variables, practing for this summer!:)
        for (int segu=0; segu<26; segu++){
            for (int terc=0; terc<26; terc++){
                if (terc == segu && terc == prim){
                }
                else {
                    for (int cuarto=0; cuarto<26; cuarto++){
                        if (terc == segu && terc == cuarto){
                        }
                        else { // sexto, septimo, octavo
                            for (int quinto=0; quinto<26; quinto++){
                                if (terc ==  quinto && terc == cuarto){
                                }
                                else {
                                    for (int sexto=0; sexto<26; sexto++){
                                        if (sexto ==  quinto && sexto == cuarto){
                                        }
                                        else {
                                            for (int sept=0; sept<26; sept++){
                                                if (sexto ==  quinto && sexto == sept){
                                                }
                                                else {
                                                    count++;
                                                }
                                            }
                                        }
                                    }    
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "count for seven letters : " << count << endl;
}
