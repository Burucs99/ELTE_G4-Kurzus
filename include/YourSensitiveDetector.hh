#ifndef Sensdet
#define Sensdet



#include "G4VSensitiveDetector.hh"


class YourSensitiveDetector : public G4VSensitiveDetector{

public: 

    YourSensitiveDetector( G4String);
    ~YourSensitiveDetector();



private:
    virtual void Initialize(G4HCofThisEvent*) override;
    virtual void EndOfEvent(G4HCofThisEvent*) override;

    virtual G4bool ProcessHits(G4Step* , G4TouchableHistory* ) override;

    G4double fEdep ;
};





#endif