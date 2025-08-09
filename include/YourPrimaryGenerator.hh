#ifndef YOURPRIMARYGENERATOR_HH
#define YOURPRIMARYGENERATOR_HH


#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "G4GeneralParticleSource.hh"
#include <G4SystemOfUnits.hh>
#include <random>


class YourPrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction {
public:


    YourPrimaryGeneratorAction();
    virtual ~YourPrimaryGeneratorAction();

    virtual void GeneratePrimaries(G4Event* anEvent);

private:
    //G4ParticleGun* fPGun;
    G4GeneralParticleSource* fGps;

        std::random_device m_randomDevice{};
        std::mt19937 m_engine{m_randomDevice()};

        G4double GenerateRandomNumber(G4double low, G4double high){
            return std::uniform_real_distribution<G4double>(low, high)(m_engine);
        };

        G4double detectorHeight = (5.45) * cm;
        G4double detectorDiamater = 4.8 * cm;
        G4double apparentHeight;

};
#endif