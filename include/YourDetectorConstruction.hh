#ifndef YOURDETECTORCONSTRUCTION_HH
#define YOURDETECTORCONSTRUCTION_HH

// G4 prerequisites
#include "G4VUserDetectorConstruction.hh"
#include <G4Material.hh>
#include <G4NistManager.hh>
#include <G4VPhysicalVolume.hh>
#include "G4Box.hh"
#include "G4Types.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4Material.hh"
//#include "G4VisAttributes.hh"
#include <G4ios.hh>
#include "G4SDManager.hh"

// Other user created files
#include "YourSensitiveDetector.hh"
#include "HPGeDetectorConstruction.hh"

class YourDetectorConstruction : public G4VUserDetectorConstruction {
    public:
        YourDetectorConstruction();
        virtual ~YourDetectorConstruction();

        virtual G4VPhysicalVolume* Construct();

    private:

        virtual void ConstructSDandField();

        G4NistManager* nistManager;
        G4Material* worldMaterial;
        G4double worldSize;
        G4Box* solidWorldVolume;
        G4LogicalVolume* logicalVolume, *logicalSensitiveDetector;
        G4VPhysicalVolume* physicalVolume;

        HPGeDetectorConstruction* HPGe;

        G4bool fCheckOverlaps = true;
};

#endif