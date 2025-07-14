#include "YourRunAction.hh"
#include <G4AnalysisManager.hh>
#include <G4ios.hh>

YourRunAction::YourRunAction(){

    G4AnalysisManager* manager = G4AnalysisManager::Instance();
    manager->SetVerboseLevel(2);

    manager->CreateNtuple("Hits", "Hits");
    manager->CreateNtupleIColumn("fEvenet");
    manager->CreateNtupleDColumn("fX");
    manager->CreateNtupleDColumn("fY");
    manager->CreateNtupleDColumn("fZ");
    manager->FinishNtuple(0); // the id of the ntuple

}

void YourRunAction::BeginOfRunAction(const G4Run* theRun){

    G4cout << "Hiiiii my name is Jeff!" << G4endl;

    G4AnalysisManager* manager = G4AnalysisManager::Instance();

    manager->OpenFile("test.root");
    G4cout << "Hii, my name WAS Jeff." << G4endl;

}

void YourRunAction::EndOfRunAction(const G4Run* theRun) {

    G4cout << "Hello hello hello \n";

    G4AnalysisManager* manager = G4AnalysisManager::Instance();
    manager->SetVerboseLevel(2);

    manager->Write();
    manager->CloseFile();

    G4cout << "Hello hello hello \n\n\n\n\n\n\n";
}

YourRunAction::~YourRunAction(){

}