#ifndef YOURCONCRETEWALL_HH
#define YOURCONCRETEWALL_HH

#include <G4Box.hh>
#include <G4LogicalVolume.hh>
#include <G4Material.hh>
#include <G4PVPlacement.hh>
#include <G4VisAttributes.hh>

#include <G4ThreeVector.hh>
#include <Materials.hh>

class YourConcreteWall {

    public:
        YourConcreteWall();
        ~YourConcreteWall();

        void Build(G4LogicalVolume* motherVolume);

    private:

    void Initialiseattributes();

    G4double xLength, yLength, zLength;
    Materials* materialsTable;

    G4Material* wallMaterial;
    G4ThreeVector wallShift;

    G4Box* wallSolid;
    G4LogicalVolume* wallLogicalVolume;
    G4VPhysicalVolume* wallPhysicalVolume;
};

#endif