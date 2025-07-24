#include "YourPrimaryGenerator.hh"

#include "G4IonTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include <G4ThreeVector.hh>
YourPrimaryGeneratorAction::YourPrimaryGeneratorAction()
: G4VUserPrimaryGeneratorAction(),
 fPGun(nullptr){
    fPGun = new G4ParticleGun(1);
}

YourPrimaryGeneratorAction::~YourPrimaryGeneratorAction(){
    delete fPGun;

}

void YourPrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent){
   
    G4ParticleDefinition* gamma_foton = G4ParticleTable::GetParticleTable()->FindParticle("gamma");
    fPGun->SetParticleDefinition(gamma_foton);
    fPGun->SetParticleMomentumDirection(G4ThreeVector(0,0,1.0));
    fPGun->SetParticlePosition(G4ThreeVector(0,0,-10*CLHEP::cm));
    fPGun->SetParticleEnergy(0.662*CLHEP::MeV);

    fPGun->GeneratePrimaryVertex(anEvent);
}