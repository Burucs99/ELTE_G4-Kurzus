#ifndef HPGEDETECTORCONSTRUCTION_HH
#define HPGEDETECTORCONSTRUCTION_HH

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
#include "G4Tubs.hh"
#include "G4SubtractionSolid.hh"
#include "G4UserLimits.hh"
#include "G4Material.hh"
#include "G4VisAttributes.hh"

class HPGeDetectorConstruction{

    public:
        HPGeDetectorConstruction();
        ~HPGeDetectorConstruction();

        void Build(G4LogicalVolume* motherWorldVolume);
        G4LogicalVolume* GetCrystalLogicalVolume() {return this->crystalLogicalVolume; }

    private:

        void InitialiseAttributes();

        G4NistManager* nistManager;
        G4Material* defaultMaterial, *absorberbMaterial, *vacuum, *aluminium, *teflon;
        const G4bool fCheckOverlaps = true;
        const G4double  crystalDiameter            = 48. *mm,
                        crystalLength              = 54.5 *mm,
                        crystalHoleDiameter        = 7.5 *mm,
                        crystalHoleDepth           = 37.5*mm,
                        
                        endCapThickness            = 1.5 *mm,
                        endCapOuterDiameter        = 7.6 *cm,
                        endCapInnerDiameter        = endCapOuterDiameter - endCapThickness,
                        endCapLength               = 7.  *cm,//TODO...

                        crystalHolderThickness     = 0.76 *mm,
                        crystalHolderInnerDiameter = crystalDiameter, //TODO actually there is a 0.5 mm boron layer on the outside of the crystal
                        crystalHolderOuterDiameter = crystalHolderInnerDiameter + crystalHolderThickness,
                        crystalHolderExtraLength   = 8. * mm,//TODO random guess
                        crystalHolderLength        = crystalLength + crystalHolderExtraLength,
                        crystalHolderEndThickness  = 3.2 *mm,

                        protrusionLength           = 8. * mm,//TODO random guess
                        protrusionThickness        = crystalHolderEndThickness,
                        protrusionOuterDiameter    = 30 *mm,//TODO random guess
                        protrusionInnerDiameter    = protrusionOuterDiameter - protrusionThickness,

                        teflonDiameter             = protrusionInnerDiameter,
                        teflonLength               = protrusionLength - protrusionThickness,//...

                        sampleDiameter             = 6.  *cm,
                        sampleHeight               = 0.5 *cm,
                        sampleHolderThickness      = 1.  *mm,
                        sampleHolderInnerDiameter  = sampleDiameter,
                        sampleHolderOuterDiameter  = sampleDiameter + 2 * sampleHolderThickness,

                    

                        windowDistance          = 5. *mm,

                        calorimeterShift        =  endCapLength / 2,
                        START                   = -endCapLength / 2,

                        endCapShift             = START + endCapLength / 2,
                        endCapDisk1Shift        = START + endCapThickness / 2,
                        endCapDisk2Shift        = START + endCapLength - endCapThickness / 2,

                        crystalShift            = START + windowDistance + crystalLength / 2,
                        crystalHoleRelShift     = crystalLength / 2 - crystalHoleDepth / 2,

                        crystalHolderShift      = START + windowDistance + crystalHolderLength / 2,
                        // crystalHolderDisk1Shift = START + windowDistance + crystalHolderThickness / 2,//What is on the front?
                        crystalHolderDisk2Shift = START + windowDistance + crystalHolderLength - crystalHolderThickness / 2,

                        protrusionShift         = START + windowDistance + crystalHolderLength + protrusionLength / 2,
                        protrusionDiskShift     = START + windowDistance + crystalHolderLength + protrusionLength - protrusionThickness / 2,
                        teflonShift             = START + windowDistance + crystalHolderLength + teflonLength / 2;

        const G4double  deadLayerZ = 1 * mm;
        const G4double  activeCrystalLength = crystalLength - deadLayerZ,
                        activeZShift = START + windowDistance + activeCrystalLength / 2,
                        deadZShift   = activeZShift - activeCrystalLength / 2 + deadLayerZ / 2;

        const G4double endCapTopZ = calorimeterShift - endCapShift - endCapLength / 2;
        const G4double maxStep = 0.0001*mm;

        G4Tubs *calorimeterSolid, *endCapSolid, *endCapDisk1Solid, *endCapDisk2Solid, *crystalCylinderSolid, *crystalHoleSolid, *deadLayerCylinderSolid;
        G4LogicalVolume *calorimeterLogicalVolume, *endCapLogicalVolume, *endCapDisk1LogicalVolume, *endCapDisk2LogicalVolume, *crystalLogicalVolume, *deadLayerLogicalVolume;
        G4VPhysicalVolume *calorimeterPhysicalVolume, *endCapPhysicalVolume, *endCapDisk1PhysicalVolume, *endCapDisk2PhysicalVolume, *crystalPhysicalVolume, *deadLayerPhysicalVolume;
        G4SubtractionSolid* crystalSolid; 

        
};




#endif