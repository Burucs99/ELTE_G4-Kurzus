#ifndef YOURPHYS
#define YOURPHYS


#include "G4VModularPhysicsList.hh"
#include "G4EmStandardPhysics_option4.hh"

class YourPhysicsList : public G4VModularPhysicsList{
public:
    YourPhysicsList();
    ~YourPhysicsList();

private:

};

#endif