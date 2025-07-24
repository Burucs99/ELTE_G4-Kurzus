#include "YourPhysicsList.hh"
#include <G4EmStandardPhysics_option4.hh>


YourPhysicsList::YourPhysicsList(){

    RegisterPhysics(new G4EmStandardPhysics_option4());
}

YourPhysicsList::~YourPhysicsList(){}