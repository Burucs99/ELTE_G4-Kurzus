#include "YourSensitiveDetector.hh"
#include <G4ParticleDefinition.hh>
#include <G4StepPoint.hh>
#include <G4Types.hh>
#include "G4Step.hh"


YourSensitiveDetector::YourSensitiveDetector(G4String name)
:G4VSensitiveDetector(name)
{

    G4cout<<"Building YourSensdet \n";

}

YourSensitiveDetector::~YourSensitiveDetector()
{

}

void YourSensitiveDetector::Initialize(G4HCofThisEvent* ){


    G4cout<<"Initialized Sensdet \n";
}

void YourSensitiveDetector::EndOfEvent(G4HCofThisEvent* ){


    G4cout<<"Initialized Sensdet \n";



}

G4bool YourSensitiveDetector::ProcessHits(G4Step* aStep, G4TouchableHistory* ){
    
    
    G4StepPoint* preStepPoint = aStep->GetPreStepPoint();
    G4cout<<"Itt van a labda \n";
    G4cout<<" X  "<<preStepPoint->GetPosition().x()<<G4endl;
    G4cout<<" Y  "<<preStepPoint->GetPosition().y()<<G4endl;
    G4cout<<" Z "<<preStepPoint->GetPosition().z()<<G4endl;
    G4cout<<"-------------------"<<G4endl;
    G4cout<<"-------------------"<<G4endl;
    G4cout<<"-------------------"<<G4endl;
    G4cout<<"A labda ennyi energiát adott le "<<aStep->GetTotalEnergyDeposit()<<G4endl;
    G4cout<<"-------------------"<<G4endl; 
    G4ParticleDefinition* part_def = aStep->GetTrack()->GetDefinition();
    G4cout<<"A labda ilyen típusú volt "<<part_def->GetParticleName()<<G4endl;

    return true;
}