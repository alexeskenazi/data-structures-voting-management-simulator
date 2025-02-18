#pragma once

#include <iostream>
#include <stdlib.h>
using namespace std;

class Voter {
   public:
      string first;
      string last;
      unsigned int age;

      unsigned int strength;
      float likelihood;
      bool voted;
   private:
      float impact;

   public:
      Voter();
      Voter(string firstname, string lastname, unsigned int voterage);
      Voter(const Voter& other);
      ~Voter();
      float getImpact() const;
      void setImpact(float i);
      void reduceLikelihood(float reduction);
      void setStrength(unsigned int s) ;
      void updateImpact();
      void show() const;
      bool operator==(const Voter& other) const;
      bool operator!=(const Voter& other) const;
      Voter& operator=(const Voter& other);
      bool operator<(const Voter& other);
      bool operator>(const Voter& other);
      
      friend ostream& operator<<(ostream& os, const Voter& voter);

};

