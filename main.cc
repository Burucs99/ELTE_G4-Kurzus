#include <G4MTRunManager.hh>
#include <G4String.hh>
#include <G4ios.hh>
#include <system_error>
#include "G4RunManager.hh"
#include "G4RunManagerFactory.hh"
#include "G4UImanager.hh"
#include "G4UIExecutive.hh"
#include "G4VisManager.hh"
#include "G4HadronicParameters.hh"
#include "G4VisExecutive.hh"

#include "YourDetectorConstruction.hh"
#include "YourPhysicsList.hh"
#include "YourActionInitialisation.hh"


int main(int argc, char** argv){
    
    #ifdef G4MULTITHREADED
        G4MTRunManager* runManager = new G4MTRunManager;
    #else 
        G4RunManager* runManager = new G4RunManager;
    #endif


    G4HadronicParameters::Instance()->SetTimeThresholdForRadioactiveDecay(1.0e+60* CLHEP::year);

    YourDetectorConstruction* detector = new YourDetectorConstruction();
    YourPhysicsList* physics = new YourPhysicsList();
    YourActionInitialisation* action = new YourActionInitialisation();

    runManager->SetUserInitialization(detector);
    runManager->SetUserInitialization(physics);
    runManager->SetUserInitialization(action);

    G4UIExecutive* ui = nullptr;
    
    // if we have not provided any macro files
    if(argc == 1){
        ui = new G4UIExecutive(argc, argv);
    }

    G4VisManager* visManager = new G4VisExecutive();
    visManager->Initialize();
    visManager->SetVerboseLevel(0);

    G4UImanager* UImanager = G4UImanager::GetUIpointer();
    UImanager->SetVerboseLevel(0);

    // if macros were not provided:
    if(ui){
        UImanager->ApplyCommand("/control/execute ../Macros/vis.mac");
        ui->SessionStart();
        delete ui;
    }
    // if macros were provided
    else{
        G4cout << "No visualisation.\n";
        G4String execute = "/control/execute ";
        G4String macro = argv[1];
        UImanager->ApplyCommand(execute + macro); 
    }

    return 0;

}