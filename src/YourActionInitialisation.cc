#include "YourActionInitialisation.hh"
#include "YourPrimaryGenerator.hh"
#include "YourRunAction.hh"

YourActionInitialisation::YourActionInitialisation(){

}

void YourActionInitialisation::Build() const {

    YourPrimaryGeneratorAction* primaryGenerator = new YourPrimaryGeneratorAction();
    YourRunAction* runAction = new YourRunAction();
    
    SetUserAction(primaryGenerator);
    SetUserAction(runAction);

}

YourActionInitialisation::~YourActionInitialisation(){



}