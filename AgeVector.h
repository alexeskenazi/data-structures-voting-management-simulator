#pragma once

#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Voter.h"

using namespace std;



class AgeVector {
    public:
        vector< vector<Voter*> > ages;
        bool AddVoter(Voter* voter);
        string getVotersString();
};