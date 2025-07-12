#ifndef YOURDETECTORCONSTRUCTION_HH
#define YOURDETECTORCONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"
#include <G4Material.hh>
#include <G4NistManager.hh>
#include <G4VPhysicalVolume.hh>
#include "G4SystemOfUnits.hh"
#include "G4Box.hh"
#include "G4Types.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4VPhysicalVolume.hh"
#include "G4VUserDetectorConstruction.hh"

class YourDetectorConstruction : public G4VUserDetectorConstruction {
    public:
        YourDetectorConstruction();
        virtual ~YourDetectorConstruction();

        virtual G4VPhysicalVolume* Construct();

    private:
        G4NistManager* nistManager;
        G4Material* worldMaterial;
        G4double worldSize;
        G4Box* solidWorldVolume;
        G4LogicalVolume* logicalVolume;
        G4VPhysicalVolume* physicalVolume;
        G4LogicalVolume* ftargetLogical;

        G4bool fCheckOverlaps = true;

        void BuildHPGe();
};

#endif