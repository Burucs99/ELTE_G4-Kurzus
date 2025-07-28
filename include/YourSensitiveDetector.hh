#ifndef YOURSENSITIVEDETECTOR_HH
#define YOURSENSITIVEDETECTOR_HH

#include <G4LogicalVolume.hh>
#include <G4VSensitiveDetector.hh>
#include <G4Types.hh>
#include <G4Step.hh>
#include <G4TouchableHistory.hh>
#include <G4RNGHelper.hh>
#include <G4Step.hh>
#include <G4TouchableHistory.hh>
#include <G4Types.hh>
#include <G4VSensitiveDetector.hh>
#include <trkdefs.hh>
#include <G4StepPoint.hh>
#include <G4ThreeVector.hh>
#include <G4RunManager.hh>
#include "G4AnalysisManager.hh"

class YourSensitiveDetector : public G4VSensitiveDetector{

    public:
        YourSensitiveDetector(G4String name);
        ~YourSensitiveDetector();

        virtual void Initialize(G4HCofThisEvent*);
        virtual void EndOfEvent(G4HCofThisEvent*);

    private:
        // with this function we are able to process some hits: this is where the logic actually happens
        virtual G4bool ProcessHits(G4Step* theStep, G4TouchableHistory* history);

        G4double fTotalEnergyDeposited;

};

#endif