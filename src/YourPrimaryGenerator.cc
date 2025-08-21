#include "YourPrimaryGenerator.hh"

#include "G4ParticleGun.hh"
#include <CLHEP/Units/SystemOfUnits.h>
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
#include <G4MuonMinus.hh>

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

    /*G4ThreeVector dir = anEvent->GetPrimaryVertex()->GetPrimary()->GetMomentumDirection();

    G4double x = dir.x();
    G4double y = dir.y();
    G4double z = dir.z();
    G4double shiftX = dir.x() / dir.z() * (700 + 0.6) * cm;

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

    anEvent->GetPrimaryVertex()->SetPosition(-shiftX - displX, randY, -700 * cm + displZ);

    G4double particleMomentum = anEvent->GetPrimaryVertex()->GetPrimary()->GetTotalMomentum();
    G4double newMomentum = particleMomentum * std::cos(theta) * std::cos(theta);
    G4double muonMass = G4MuonMinus::MuonMinus()->GetPDGMass();
    anEvent->GetPrimaryVertex()->GetPrimary()->SetKineticEnergy(std::sqrt(muonMass * muonMass + newMomentum * newMomentum) - muonMass);*/

    /*G4double ro = 2.30; // g/cm3
    G4double muonPathLength = (500 / std::cos(theta)); // cm
    G4double massThickness = muonPathLength * ro;

    G4double maximalMassThickness = (0.4682 * newMomentum + 10.0671) / MeV;
    G4double maximalMassThicknessSigma = std::sqrt((newMomentum / MeV) * (newMomentum / MeV) * 0.00338 + 20.9805 * 20.9805 + 2 * (newMomentum / MeV) * (-0.03672));

    std::cout << "maximalMassThickness: " << maximalMassThickness << " g/cm2\n";
    std::cout << "maximalMassThicknessSigma: " << maximalMassThicknessSigma << " g/cm2\n";

    if(massThickness < maximalMassThickness){
        std::cout << "The muon may potentially reach the detector.\n";
        std::cout << "Muon momentum: " << newMomentum / MeV << " MeV\n";
        std::cout << "Muon mass thickness: " << massThickness << " cm\n";
        std::cout << "Maximal mass thickness: " << maximalMassThickness << " cm\n";
    }
    else{
        anEvent->GetPrimaryVertex()->GetPrimary()->SetKineticEnergy(0);
    }*/

    //checking for the angular and energy distribution
    /*G4double momentum = anEvent->GetPrimaryVertex()->GetPrimary()->GetTotalMomentum();

    momentum /= 1000; // convert to GeV

    G4int binIndex = int(50 * momentum) - 1;
    if(binIndex <= 1000 && binIndex >= 0)
        this->momentuBbins[binIndex]++;

    binIndex = G4int(theta / (2 * std::acos(0.0) / 2000)) - 1;
    if(binIndex <= 1000 && binIndex >= 0)
        this->thetaBins[binIndex]++;

    if(anEvent->GetEventID() == 999){

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