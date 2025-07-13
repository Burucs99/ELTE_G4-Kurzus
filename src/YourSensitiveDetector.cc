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

    G4cout << "Position of the particle: " << posParticle;

    return true;


}

