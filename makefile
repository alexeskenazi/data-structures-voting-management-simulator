CXX = g++
CXXFLAGS = -Wall -g

COURSE = cs310
SEMESTER = fall2024
CP_NUMBER = 4
LASTNAME = Eskenazi
GITUSERID = alexeskenazi
REPODIR = ../$(COURSE)-$(SEMESTER)-cp$(CP_NUMBER)-$(GITUSERID)
TARFILE = ../CP$(CP_NUMBER)_$(LASTNAME)_$(USER)_$(GITUSERID).tar

all: lets_vote MaxHeapTest bstTest

lets_vote: lets_vote.o Voter.o VoterSystem.o MaxHeap.o AgeVector.o helper.o bst.o
	$(CXX) $(CXXFLAGS) lets_vote.o Voter.o VoterSystem.o MaxHeap.o AgeVector.o helper.o bst.o -o lets_vote

lets_vote.o: lets_vote.cpp
	$(CXX) $(CXXFLAGS) -c lets_vote.cpp

Voter.o: Voter.cpp Voter.h
	$(CXX) $(CXXFLAGS) -c Voter.cpp

VoterSystem.o: VoterSystem.cpp VoterSystem.h MaxHeap.h AgeVector.h Voter.h
	$(CXX) $(CXXFLAGS) -c VoterSystem.cpp

MaxHeap.o: MaxHeap.cpp MaxHeap.h
	$(CXX) $(CXXFLAGS) -c MaxHeap.cpp

AgeVector.o: AgeVector.cpp AgeVector.h
	$(CXX) $(CXXFLAGS) -c AgeVector.cpp

helper.o: helper.cpp helper.h
	$(CXX) $(CXXFLAGS) -c helper.cpp

bst.o: bst.cpp bst.h
	$(CXX) $(CXXFLAGS) -c bst.cpp

MaxHeapTest: MaxHeapTest.o MaxHeap.o Voter.o
	$(CXX) $(CXXFLAGS) MaxHeapTest.o MaxHeap.o Voter.o -o MaxHeapTest

bstTest: bstTest.o bst.o Voter.o
	$(CXX) $(CXXFLAGS) bstTest.o bst.o Voter.o -o bstTest

tar: clean
	mkdir -p $(REPODIR)
	cp -r * $(REPODIR)  # Copy all files to the REPODIR
	tar --exclude='.git' --exclude='.vscode' --exclude='.gitignore' -cvvf $(TARFILE) $(REPODIR)
	gzip $(TARFILE)
	rm -rf $(REPODIR)  # Clean up the temporary directory
	@echo "Tarred and gzipped file is in the directory one level up"
	@echo $(TARFILE)".gz"

clean:
	rm -f *.o lets_vote MaxHeapTest bstTest