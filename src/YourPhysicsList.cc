#include "YourPhysicsList.hh"

YourPhysicsList::YourPhysicsList(){

    //electromagnetic interactions
    RegisterPhysics (new G4EmStandardPhysics_option4());
    //optical physics
    RegisterPhysics (new G4OpticalPhysics());
    RegisterPhysics (new G4DecayPhysics());
    RegisterPhysics (new G4RadioactiveDecayPhysics());
    RegisterPhysics(new G4EmExtraPhysics());

}

YourPhysicsList::~YourPhysicsList(){



}