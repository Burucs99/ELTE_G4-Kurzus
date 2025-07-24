#include "YourActionInitialization.hh"
#include "YourPrimaryGenerator.hh"
#include "YourDetectorConstruction.hh"
#include "YourRunAction.hh"
YourActionInitialization::YourActionInitialization()
: G4VUserActionInitialization(){

    G4cout<<"Inside Your Action Initialization Constructor"<<G4endl;
}
YourActionInitialization::~YourActionInitialization(){}

void YourActionInitialization::BuildForMaster() const{

    G4cout<<"Inside Build for Master"<<G4endl;
    

    YourRunAction* run = new YourRunAction();
    SetUserAction(run);

}


void YourActionInitialization::Build() const{

    G4cout<<"Inside Build"<<G4endl;
    YourPrimaryGeneratorAction* prim = new YourPrimaryGeneratorAction();
    SetUserAction(prim);

    YourRunAction* run = new YourRunAction();
    SetUserAction(run);

}

