#include "YourRunAction.hh"
#include <G4AnalysisManager.hh>
#include <G4RunManager.hh>
#include <G4SystemOfUnits.hh>
#include <G4ios.hh>

YourRunAction::YourRunAction() : G4UserRunAction(){

    G4AnalysisManager* manager = G4AnalysisManager::Instance();

    manager->CreateNtuple("Hits", "Hits");
    manager->CreateNtupleDColumn("EnergyDeposit");
    manager->CreateH1("Edep","Energy Deposited - Spectrum",170,1 * MeV,171*MeV);
    manager->FinishNtuple(0); // the id of the ntuple

    this->timer = new G4Timer();

}

void YourRunAction::BeginOfRunAction(const G4Run* theRun){

    this->timer->Start();

    G4AnalysisManager* manager = G4AnalysisManager::Instance();

    manager->OpenFile("withHoleFullGeAndEneDistrPerturbation.root");

}

void YourRunAction::EndOfRunAction(const G4Run* theRun) {

    G4AnalysisManager* manager = G4AnalysisManager::Instance();

    this->timer->Stop();
    G4cout << "Simulation run time: " << timer->GetRealElapsed() << " seconds" << G4endl;

    manager->Write();
    manager->CloseFile();
}

YourRunAction::~YourRunAction(){
    delete this->timer;
}