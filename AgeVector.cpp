#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include "helper.h"
#include "AgeVector.h"


bool AgeVector::AddVoter(Voter* voter){
   unsigned int age = voter->age;
    if (age >= ages.size()) {
        ages.resize(age + 1);
    }

    ages[age].push_back(voter);
    return true;
}


string AgeVector::getVotersString(){
    string strOut = "";
    for(unsigned int i = 0; i < ages.size(); ++i){
        vector<Voter*> vect = ages[i];
        if(vect.size() == 0){
            continue;
        }
        
        for(unsigned int j = 0; j<vect.size(); ++j){
            Voter* v = vect[j];
            if(v->voted){
                continue;
            }
        
            strOut += v->first + " " + v->last + " (" + to_string(v->age) + "): strength of support: " + to_string(v->strength) + ", likelihood: " + to_string_with_precision(v->likelihood, 2) + ", impact: " + to_string_with_precision(v->getImpact(), 2) + "\n";
        }
    }
    return strOut;
}

