#include "YourPrimaryGenerator.hh"

#include "G4ParticleGun.hh"
#include <G4ParticleDefinition.hh>
#include <G4ParticleTable.hh>
#include <G4String.hh>
#include <G4SystemOfUnits.hh>
#include <G4ThreeVector.hh>

YourPrimaryGeneratorAction::YourPrimaryGeneratorAction():G4VUserPrimaryGeneratorAction(), fPGun(nullptr){
    this->fPGun = new G4ParticleGun(1);
}

YourPrimaryGeneratorAction::~YourPrimaryGeneratorAction(){
    delete this->fPGun;

}

void YourPrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent){

    G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
    G4String particleName = "mu-";
    G4ParticleDefinition* particle = particleTable->FindParticle(particleName);

    G4ThreeVector pos (0*mm, 0, -70*mm); // 7cm-rol gneralodik ki a sok muon
    G4ThreeVector direction(0, 0, 1);

    this->fPGun->SetParticleMomentumDirection(direction);
    this->fPGun->SetParticlePosition(pos);
    this->fPGun->SetParticleMomentum(20*MeV);
    //this->fPGun->SetParticleEnergy(40*MeV);
    this->fPGun->SetParticleDefinition(particle);

    //adjustments are needed here!
    fPGun->GeneratePrimaryVertex(anEvent);
}