#include "YourSensitiveDetector.hh"
#include <G4ParticleDefinition.hh>
#include <G4StepPoint.hh>
#include <G4Types.hh>
#include "G4Step.hh"
#include "G4AnalysisManager.hh"

YourSensitiveDetector::YourSensitiveDetector(G4String name)
:G4VSensitiveDetector(name)
{
    fEdep = 0.0;
    G4cout<<"Building YourSensdet \n";

}

YourSensitiveDetector::~YourSensitiveDetector()
{

}

void YourSensitiveDetector::Initialize(G4HCofThisEvent* ){


}

void YourSensitiveDetector::EndOfEvent(G4HCofThisEvent* ){

    G4AnalysisManager* analysisMan = G4AnalysisManager::Instance();
    analysisMan->FillH1(0,fEdep);

    fEdep = 0.0;

}

G4bool YourSensitiveDetector::ProcessHits(G4Step* aStep, G4TouchableHistory* ){
    
    
    G4StepPoint* preStepPoint = aStep->GetPreStepPoint();
    
    fEdep+=aStep->GetTotalEnergyDeposit();
    return true;
}