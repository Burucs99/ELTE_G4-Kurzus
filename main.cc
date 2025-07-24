#include <iostream>
#include <G4MTRunManager.hh>

#include "G4RunManager.hh"
#include "G4RunManagerFactory.hh"
#include "G4UImanager.hh"

#include "G4UIExecutive.hh"

#include "G4VisManager.hh"
#include "G4VisExecutive.hh"

#include "include/YourDetectorConstruction.hh"
#include "YourActionInitialization.hh"
#include "include/YourActionInitialization.hh"
#include "include/YourPhysicsList.hh"
int main(int argc, char** argv){
    G4UIExecutive* ui = new G4UIExecutive(argc, argv);
    
    #ifdef G4MULTITHREADED
        G4MTRunManager * runManager = new G4MTRunManager;
    #else 
        G4RunManager *runManager = new G4RunManager;
    #endif


    YourDetectorConstruction * detector = new YourDetectorConstruction ;
    runManager->SetUserInitialization(detector);
    runManager->SetUserInitialization(new YourPhysicsList());
    runManager->SetUserInitialization(new YourActionInitialization());

    G4VisManager* visManager = new G4VisExecutive();
    visManager->SetVerboseLevel(0);
    visManager->Initialise();
    std::cout<<"Idáig eljut"<<std::endl;
    G4UImanager* uiManager = G4UImanager::GetUIpointer();
    uiManager->SetVerboseLevel(0);
    if(ui){
    ui->SessionStart();
}

    std::cout<<"Hello World"<<std::endl;


    return 0;

}