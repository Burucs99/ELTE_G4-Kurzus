#include "YourSensitiveDetector.hh"
#include <G4Threading.hh>
#include <G4ios.hh>

YourSensitiveDetector::YourSensitiveDetector(G4String name) : G4VSensitiveDetector(name){
}

YourSensitiveDetector::~YourSensitiveDetector(){
}

G4bool YourSensitiveDetector::ProcessHits(G4Step* theStep, G4TouchableHistory* history){

    // basically the trajectory, the track of the particle
    G4Track* track = theStep->GetTrack();

    G4double energyDeposit = theStep->GetTotalEnergyDeposit();

    this->fTotalEnergyDeposited += energyDeposit;

    G4AnalysisManager* manager = G4AnalysisManager::Instance();
    manager->FillNtupleDColumn(0, energyDeposit);
    manager->AddNtupleRow(0); // finishing the


    return true;

}

void YourSensitiveDetector::Initialize(G4HCofThisEvent * hce) 
{

    this->fTotalEnergyDeposited = 0.;

}

void YourSensitiveDetector::EndOfEvent(G4HCofThisEvent *)
{

    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();

    std::ofstream myFile("../data/muonEdep20-300-halfGe-Center/20MeV_1000event.txt", std::ios::app);
    if (myFile.is_open()) {
        myFile << this->fTotalEnergyDeposited << "\n";
    } else {
        G4cerr << "Nem sikerült megnyitni a fájlt!" << G4endl;
    }
    
    analysisManager->FillH1(0,this->fTotalEnergyDeposited);

}
