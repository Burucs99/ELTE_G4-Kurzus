#include "YourPrimaryGenerator.hh"

#include "G4ParticleGun.hh"
#include <G4GeneralParticleSource.hh>
#include <G4ParticleDefinition.hh>
#include <G4ParticleTable.hh>
#include <G4String.hh>
#include <G4SystemOfUnits.hh>
#include <G4ThreeVector.hh>
#include <G4Types.hh>
#include <G4ios.hh>
#include <cmath>
#include <fstream>

YourPrimaryGeneratorAction::YourPrimaryGeneratorAction():G4VUserPrimaryGeneratorAction(), fGps(nullptr){
    this->fGps = new G4GeneralParticleSource();
    this->momentuBbins.assign(1000, 0);
    this->thetaBins.assign(1000, 0);
}

YourPrimaryGeneratorAction::~YourPrimaryGeneratorAction(){

    delete this->fGps;
}

void YourPrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent){

    this->fGps->GeneratePrimaryVertex(anEvent);

    G4ThreeVector dir = anEvent->GetPrimaryVertex()->GetPrimary()->GetMomentumDirection();

    G4double x = dir.x();
    G4double y = dir.y();
    G4double z = dir.z();
    G4double shiftX = dir.x() / dir.z() * (7 + 0.6) * cm;

    G4double theta = std::atan2(x, z);

    G4double a = std::sin(theta) * this->detectorHeight;
    G4double b = std::cos(theta) * this->detectorDiamater;
    this->apparentHeight = a + b;

    G4double randLength = GenerateRandomNumber(-b, a);
    G4double displX = std::sin(theta) * randLength;
    G4double displZ = std::cos(theta) * randLength;
    displX *= 1.1;
    displZ *= 1.1;

    G4double randY = GenerateRandomNumber(-this->detectorDiamater / 2, this->detectorDiamater / 2);
    randY *= 1.1;

    anEvent->GetPrimaryVertex()->SetPosition(-shiftX - displX, randY, -7 * cm + displZ);


    //checking for the angular and energy distribution
    /*G4double momentum = anEvent->GetPrimaryVertex()->GetPrimary()->GetTotalMomentum();

    momentum /= 1000; // convert to GeV

    G4int binIndex = int(50 * momentum) - 1;
    if(binIndex <= 1000 && binIndex >= 0)
        this->momentuBbins[binIndex]++;

    binIndex = G4int(theta / (2 * std::acos(0.0) / 2000)) - 1;
    if(binIndex <= 1000 && binIndex >= 0)
        this->thetaBins[binIndex]++;

    if(anEvent->GetEventID() == 9999){

        std::ofstream outMomentum("momentum_distribution.txt");
        for (int x: this->momentuBbins) {
            outMomentum << x << std::endl;
        }
        outMomentum.close();

        std::ofstream outTheta("theta_distribution.txt");
        for (int x: this->thetaBins) {
            outTheta << x << std::endl;
        }
        outTheta.close();
    }*/

}