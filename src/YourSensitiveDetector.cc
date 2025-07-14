#include "YourSensitiveDetector.hh"





YourSensitiveDetector::YourSensitiveDetector(G4String name) : G4VSensitiveDetector(name){

}

YourSensitiveDetector::~YourSensitiveDetector(){

}

G4bool YourSensitiveDetector::ProcessHits(G4Step* theStep, G4TouchableHistory* history){

    // basically the trajectory, the track of the particle
    G4Track* track = theStep->GetTrack();

    G4StepPoint* preStepPoint = theStep->GetPreStepPoint();
    G4StepPoint* postStepPoint = theStep->GetPostStepPoint();

    G4ThreeVector posParticle = preStepPoint->GetPosition();

    // kerjodel? Ezt igy csak le lehet kerdezni?
    G4int eventNumber = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();

    G4cout << "what the fck is up with this???????????????\n\n\n\n";


    G4AnalysisManager* manager = G4AnalysisManager::Instance();
    manager->FillNtupleIColumn(0, eventNumber);
    manager->FillNtupleDColumn(1, posParticle[0]);
    manager->FillNtupleDColumn(2, posParticle[1]);
    manager->FillNtupleDColumn(3, posParticle[2]);
    manager->AddNtupleRow(0); // finishing the


    return true;


}

