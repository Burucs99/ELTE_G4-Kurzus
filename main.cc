#include <iostream>
#include <G4MTRunManager.hh>

#include "G4RunManager.hh"
#include "G4RunManagerFactory.hh"
#include "G4UImanager.hh"

#include "G4UIExecutive.hh"

#include "G4VisManager.hh"
#include "G4VisExecutive.hh"

#include "YourDetectorConstruction.hh"

int main(){
    G4UIExecutive* ui;
    
    #ifdef G4MULTITHREADED
        G4MTRunManager * runManager = new G4MTRunManager;
    #else 
        G4RunManager *runManager = new G4RunManager;
    #endif


    YourDetectorConstruction * detector = new YourDetectorConstruction ;
    runManager->SetUserInitialization(detector);



    std::cout<<"Hello World"<<std::endl;


    return 0;

}