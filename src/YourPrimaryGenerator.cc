#include "YourPrimaryGenerator.hh"

#include "G4ParticleGun.hh"

YourPrimaryGeneratorAction::YourPrimaryGeneratorAction()
: G4VUserPrimaryGeneratorAction(),
 fPGun(nullptr){
    fPGun = new G4ParticleGun(1);
}

YourPrimaryGeneratorAction::~YourPrimaryGeneratorAction(){
    delete fPGun;

}

void YourPrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent){


    fPGun->GeneratePrimaryVertex(evt);
}