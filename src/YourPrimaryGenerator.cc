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

YourPrimaryGeneratorAction::YourPrimaryGeneratorAction():G4VUserPrimaryGeneratorAction(), fGps(nullptr){
    this->fGps = new G4GeneralParticleSource();
}

YourPrimaryGeneratorAction::~YourPrimaryGeneratorAction(){
    delete this->fGps;
}

void YourPrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent){

    //adjustments are needed here!
    this->fGps->GeneratePrimaryVertex(anEvent);

    //Needed to so that the particles go through the detector center
    G4ThreeVector dir = anEvent->GetPrimaryVertex()->GetPrimary()->GetMomentumDirection();

    // lekérjük a müon koordinátáit
    G4double x = dir.x();
    G4double y = dir.y();
    G4double z = dir.z();
    // annyival shifteljük jobbra vagy balra, hogy a detector közepén menjen át
    G4double shiftX = dir.x() / dir.z() * (7 + 1.775) * cm;

    G4cout << "Muon direction: " << dir << G4endl;

    //Hogy a theta majd [0, 90] fok között legyen
    G4double theta = std::atan2(x, z);

    //Az a és b számok a rajzon
    G4double a = std::sin(theta) * this->detectorHeight;
    G4double b = std::cos(theta) * this->detectorDiamater;
    //A látszólagos magasság a kettő összege
    this->apparentHeight = a + b;
    //A pozitiv és negativ irányba (a z tengely mentén) mennyire toljuk el

    //Kigeneráljuk a random z eltolást
    G4double randLength = GenerateRandomNumber(-b, a);
    G4double displX = std::sin(theta) * randLength;
    G4double displZ = std::cos(theta) * randLength;
    displX *= 1.1;
    displZ *= 1.1;

    // Egyszerű
    G4double randY = GenerateRandomNumber(-this->detectorDiamater / 2, this->detectorDiamater / 2);
    //A faktor
    randY *= 1.1;

    G4cout << "Position: " << -shiftX - displX << ", " << randY << ", " << -7 * cm + displZ << G4endl;

    anEvent->GetPrimaryVertex()->SetPosition(-shiftX /*- displX*/, /*randY*/0, -7 * cm /*+ displZ*/);

}