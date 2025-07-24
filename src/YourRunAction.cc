#include "YourRunAction.hh"
#include "G4AnalysisManager.hh"
#include <CLHEP/Units/SystemOfUnits.h>
#include <G4String.hh>
#include <G4UserRunAction.hh>
#include "YourDetectorConstruction.hh"

YourRunAction::YourRunAction()
: G4UserRunAction(){


    G4cout<<"Building YourRunAction"<<G4endl;
   
    G4AnalysisManager* analysisMan = G4AnalysisManager::Instance();
    analysisMan->CreateH1("Edep","Energy Deposited",1000,0,3.1*CLHEP::MeV);


}

YourRunAction::~YourRunAction(){}


void YourRunAction::BeginOfRunAction(const G4Run* ) {
    G4cout<<"Beginning Of Run Action"<<G4endl;
    G4AnalysisManager* analysisMan = G4AnalysisManager::Instance();

    G4String fileName = "Filename.root";
    analysisMan->OpenFile(fileName);
}

void YourRunAction::EndOfRunAction(const G4Run* ) {
    G4AnalysisManager* analysisMan = G4AnalysisManager::Instance();
    analysisMan->Write();
    analysisMan->CloseFile();


}