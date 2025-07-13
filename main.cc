#include <G4MTRunManager.hh>
#include <G4String.hh>
#include "G4RunManager.hh"
#include "G4RunManagerFactory.hh"
#include "G4UImanager.hh"
#include "G4UIExecutive.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"

#include "YourDetectorConstruction.hh"
#include "YourPhysicsList.hh"
#include "G4HadronicParameters.hh"

int main(int argc, char** argv){
    
    //#ifdef G4MULTITHREADED
        //G4MTRunManager* runManager = new G4MTRunManager;
    //#else 
        G4RunManager* runManager = new G4RunManager;
    //#endif

    G4HadronicParameters::Instance()->SetTimeThresholdForRadioactiveDecay(1.0e+60* CLHEP::year);

    YourDetectorConstruction* detector = new YourDetectorConstruction();
    YourPhysicsList* physics = new YourPhysicsList();
    runManager->SetUserInitialization(detector);
    runManager->SetUserInitialization(physics);

    G4UIExecutive* ui = nullptr;

    if(argc == 1){
        ui = new G4UIExecutive(argc, argv);
    }

    G4VisManager* visManager = new G4VisExecutive();
    visManager->SetVerboseLevel(0); 
    visManager->Initialize();

    runManager->Initialize();

    G4UImanager* UImanager = G4UImanager::GetUIpointer();
    UImanager->SetVerboseLevel(0);

    UImanager->ApplyCommand("/control/execute ../vis.mac");

    

    if(!ui){
        G4String exec = "control/execute ";
        G4String commandName = argv[1];
        UImanager->ApplyCommand(exec + commandName);
    }
    else{
        ui->SessionStart();
        delete ui;
    }


   


    return 0;

}