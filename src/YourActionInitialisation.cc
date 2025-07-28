#include "YourActionInitialisation.hh"
#include "YourPrimaryGenerator.hh"
#include "YourRunAction.hh"

YourActionInitialisation::YourActionInitialisation() : G4VUserActionInitialization(){

}

void YourActionInitialisation::Build() const {

    YourPrimaryGeneratorAction* primaryGenerator = new YourPrimaryGeneratorAction();
    YourRunAction* runAction = new YourRunAction();
    
    SetUserAction(primaryGenerator);
    SetUserAction(runAction);

}


YourActionInitialisation::~YourActionInitialisation(){



}

void YourActionInitialisation::BuildForMaster() const{

    YourPrimaryGeneratorAction* primaryGenerator = new YourPrimaryGeneratorAction();
    YourRunAction* runAction = new YourRunAction();
    
    //SetUserAction(primaryGenerator);
    SetUserAction(runAction);

}