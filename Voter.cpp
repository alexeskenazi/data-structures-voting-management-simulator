#include "Voter.h"

Voter::Voter(string firstname, string lastname, unsigned int voterage) {
	first = firstname;
	last = lastname;
	age = voterage;
	strength = 75; // teacher: The initial strength of support of each voter should be set at 75.
	likelihood = 75; // teacher: Initially all voters' likelihood should be set at 75%
	voted = false;
	impact = 0;
	updateImpact();
}

Voter::Voter() {
	first = "";
	last = "";
	age = 0;
	strength = 75; // teacher: The initial strength of support of each voter should be set at 75.
	likelihood = 75; // teacher: Initially all voters' likelihood should be set at 75%
	voted = false;
	impact = 0;
	updateImpact();
}

Voter::Voter(const Voter& other) {
	first = other.first;
	last = other.last;
	age = other.age;
	strength = other.strength;
	likelihood = other.likelihood;
	voted = other.voted;
	impact = other.impact;
}

Voter::~Voter() {
	// cout << "Deleting Voter: " << first << " " << last << endl;
}

float Voter::getImpact() const {
	return impact;
}

void Voter::setImpact(float i) {
	impact = i;
}

void Voter::show() const { 
	// sample output: Alice Flanders (18): strength of support: 150, likelihood: 50, impact: 3.00
	cout << first << " " << last << " (" << age << "): strength of support: " << strength << ", likelihood: " << likelihood << ", impact: " << impact << endl;
}


bool Voter::operator==(const Voter& other) const {
	return (first == other.first && last == other.last);	// && age == other.age (Not sure if needed yet)
}

bool Voter::operator!=(const Voter& other) const {
	return !(*this == other);
}

Voter& Voter::operator=(const Voter& other) {
	if (this != &other) { 
		this->first = other.first;
		this->last = other.last;
		this->age = other.age;
		this->strength = other.strength;
		this->likelihood = other.likelihood;
		this->voted = other.voted;
		this->impact = other.impact;
	}
	return *this;
}

bool Voter::operator<(const Voter& other) {
	// teacher: Voters should be ordered by last name, then first name, 
	// then age. In other words, if all last names are different, 
	// then last name is the field that determines order... among voters 
	// with the same last name, the first name determines the order... so 
	// Aaron Judge would come before Corrupt Judge (A before C).  
	// If a Voter has the same first and last name as another voter, then the 
	// younger voter comes first in sorted order.

	if (last != other.last) {
		return (last < other.last);
	}
	if (first != other.first) {
		return (first < other.first);
	}
	
	return (age < other.age);
}

bool Voter::operator>(const Voter& other) {
	if (last != other.last) {
		return (last > other.last);
	}
	if (first != other.first) {
		return (first > other.first);
	}
	
	return (age > other.age);
}

void Voter::reduceLikelihood(float reduction) {
	likelihood = likelihood * (100-reduction) / 100;

	updateImpact();
}

void Voter::setStrength(unsigned int s) {
	strength = s;
	updateImpact();
}

void Voter::updateImpact() {
	impact = strength/likelihood;
}

ostream& operator<<(ostream& os, const Voter& voter) {
    os << voter.last << ", " << voter.first << ", age: " << voter.age << " strength: "  << voter.strength << " likelihood: " << voter.likelihood << " impact: " << voter.impact;
    return os;
}

