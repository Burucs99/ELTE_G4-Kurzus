#include "YourDetectorConstruction.hh"
#include "G4Tubs.hh"
#include "G4SubtractionSolid.hh"
#include "G4UserLimits.hh"
#include <G4Material.hh>
#include <G4VisAttributes.hh>



YourDetectorConstruction::YourDetectorConstruction():G4VUserDetectorConstruction(){

    this->nistManager = G4NistManager::Instance();
    this->worldSize = 1 * m;

}

YourDetectorConstruction::~YourDetectorConstruction() {}


G4VPhysicalVolume* YourDetectorConstruction::Construct(){

    this->worldMaterial = this->nistManager->FindOrBuildMaterial("G4_AIR");
    this->solidWorldVolume = new G4Box("worldVolume", this->worldSize / 2, this->worldSize / 2, this->worldSize / 2);
    this->logicalVolume = new G4LogicalVolume(this->solidWorldVolume, this->worldMaterial,"logicalVolume")  ;
    this->physicalVolume = new G4PVPlacement(nullptr, G4ThreeVector(0,0,0), this->logicalVolume,"physicalWorld",nullptr, false, 0);

    BuildHPGe();
    
    
    return this->physicalVolume; 

}

void YourDetectorConstruction::BuildHPGe(){

    G4Material* defaultMaterial  = this->nistManager->FindOrBuildMaterial("G4_AIR");
    G4Material* absorberMaterial = this->nistManager->FindOrBuildMaterial("G4_Ge");
    G4Material* vacuum           = this->nistManager->FindOrBuildMaterial("G4_Galactic");
    G4Material* aluminium        = this->nistManager->FindOrBuildMaterial("G4_Al");
    G4Material* teflon           = this->nistManager->FindOrBuildMaterial("G4_TEFLON");


    const G4double crystalDiameter            = 48. *mm;
    const G4double crystalLength              = 54.5 *mm;
    const G4double crystalHoleDiameter        = 7.5 *mm;
    const G4double crystalHoleDepth           = 37.5*mm;
    
    const G4double endCapThickness            = 1.5 *mm;
    const G4double endCapOuterDiameter        = 7.6 *cm;
    const G4double endCapInnerDiameter        = endCapOuterDiameter - endCapThickness;
    const G4double endCapLength               = 7.  *cm;//TODO...

    const G4double crystalHolderThickness     = 0.76 *mm;
    const G4double crystalHolderInnerDiameter = crystalDiameter; //TODO actually there is a 0.5 mm boron layer on the outside of the crystal
    const G4double crystalHolderOuterDiameter = crystalHolderInnerDiameter + crystalHolderThickness;
    const G4double crystalHolderExtraLength   = 8. * mm;//TODO random guess
    const G4double crystalHolderLength        = crystalLength + crystalHolderExtraLength;
    const G4double crystalHolderEndThickness  = 3.2 *mm;

    const G4double protrusionLength           = 8. * mm;//TODO random guess
    const G4double protrusionThickness        = crystalHolderEndThickness;
    const G4double protrusionOuterDiameter    = 30 *mm;//TODO random guess
    const G4double protrusionInnerDiameter    = protrusionOuterDiameter - protrusionThickness;

    const G4double teflonDiameter             = protrusionInnerDiameter;
    const G4double teflonLength               = protrusionLength - protrusionThickness;//...

    const G4double sampleDiameter             = 6.  *cm;
    const G4double sampleHeight               = 0.5 *cm;
    const G4double sampleHolderThickness      = 1.  *mm;
    const G4double sampleHolderInnerDiameter  = sampleDiameter;
    const G4double sampleHolderOuterDiameter  = sampleDiameter + 2 * sampleHolderThickness;

 

    const G4double windowDistance          = 5. *mm;

    const G4double calorimeterShift        =  endCapLength / 2;
    const G4double START                   = -endCapLength / 2;

    const G4double endCapShift             = START + endCapLength / 2;
    const G4double endCapDisk1Shift        = START + endCapThickness / 2;
    const G4double endCapDisk2Shift        = START + endCapLength - endCapThickness / 2;

    const G4double crystalShift            = START + windowDistance + crystalLength / 2;
    const G4double crystalHoleRelShift     = crystalLength / 2 - crystalHoleDepth / 2;

    const G4double crystalHolderShift      = START + windowDistance + crystalHolderLength / 2;
    //const G4double crystalHolderDisk1Shift = START + windowDistance + crystalHolderThickness / 2;//What is on the front?
    const G4double crystalHolderDisk2Shift = START + windowDistance + crystalHolderLength - crystalHolderThickness / 2;

    const G4double protrusionShift         = START + windowDistance + crystalHolderLength + protrusionLength / 2;
    const G4double protrusionDiskShift     = START + windowDistance + crystalHolderLength + protrusionLength - protrusionThickness / 2;
    const G4double teflonShift             = START + windowDistance + crystalHolderLength + teflonLength / 2;

    

    G4Tubs* calorimeterSolid          = new G4Tubs ("Calorimeter", 0, endCapOuterDiameter/2, endCapLength/2, 0, 360*deg);
    G4LogicalVolume* calorimeterLogicalVolume  = new G4LogicalVolume (calorimeterSolid, vacuum, "Calorimeter");
    G4VPhysicalVolume* calorimeterPhysicalVolume = new G4PVPlacement (0, G4ThreeVector(0, 0, calorimeterShift),
                                                        calorimeterLogicalVolume,
                                                        "Calorimeter",
                                                        this->logicalVolume,
                                                        false, 0, this->fCheckOverlaps);
 
    //------------------------
    //--------Endcap----------
    G4Tubs* endCapSolid          = new G4Tubs ("EndCap", endCapInnerDiameter/2, endCapOuterDiameter/2, endCapLength/2, 0, 360*deg);
    G4LogicalVolume* endCapLogicalVolume  = new G4LogicalVolume (endCapSolid, aluminium, "EndCap");
    G4VPhysicalVolume* endCapPhysicalVolume = new G4PVPlacement (0, G4ThreeVector(0, 0, endCapShift),
                                                    endCapLogicalVolume,
                                                    "EndCap",
                                                    calorimeterLogicalVolume,
                                                    false, 0, fCheckOverlaps);
    
    auto endCapDisk1Solid          = new G4Tubs ("EndCapDisk1", 0, endCapOuterDiameter/2 - endCapThickness/2, endCapThickness/2, 0, 360*deg);
    auto endCapDisk1LogicalVolume  = new G4LogicalVolume (endCapDisk1Solid, aluminium, "EndCapDisk1");
    auto endCapDisk1PhysicalVolume = new G4PVPlacement (0, G4ThreeVector(0, 0, endCapDisk1Shift),
                                                        endCapDisk1LogicalVolume,
                                                        "EndCapDisk1",
                                                        calorimeterLogicalVolume,
                                                        false, 0, fCheckOverlaps);
    
    auto endCapDisk2Solid          = new G4Tubs ("EndCapDisk2", 0, endCapOuterDiameter/2 - endCapThickness/2, endCapThickness/2, 0, 360*deg);
    auto endCapDisk2LogicalVolume  = new G4LogicalVolume (endCapDisk2Solid, aluminium, "EndCapDisk2");
    auto endCapDisk2PhysicalVolume = new G4PVPlacement (0, G4ThreeVector(0, 0, endCapDisk2Shift),
                                                        endCapDisk2LogicalVolume,
                                                        "EndCapDisk2",
                                                        calorimeterLogicalVolume,
                                                        false, 0, fCheckOverlaps);
    
    //------------------------
    //--------Crystal---------

    G4cout<<absorberMaterial->GetTemperature()<<G4endl;
    const G4double DeadLayerZ = 1*mm;

    const G4double activeCrystalLength = crystalLength - DeadLayerZ;
    const G4double activeZShift = START + windowDistance + activeCrystalLength / 2;
    const G4double deadZShift   = activeZShift - activeCrystalLength / 2 + DeadLayerZ / 2;

    auto crystalCylinderSolid = new G4Tubs("CrystalBase", 0, crystalDiameter/2, activeCrystalLength/2, 0, 360*deg);
    auto crystalHoleSolid     = new G4Tubs("CrystalHole", 0, crystalHoleDiameter/2, crystalHoleDepth/2, 0, 360*deg);
    auto crystalSolid         = new G4SubtractionSolid("Crystal", crystalCylinderSolid, crystalHoleSolid, 0,
                                                    G4ThreeVector(0, 0, crystalHoleRelShift + DeadLayerZ));

    auto crystalLogicalVolume  = new G4LogicalVolume(crystalSolid, absorberMaterial, "Crystal");
    auto crystalPhysicalVolume = new G4PVPlacement(0, G4ThreeVector(0, 0, activeZShift+DeadLayerZ),
                                                crystalLogicalVolume,
                                                "Crystal",
                                                calorimeterLogicalVolume,
                                                false, 0, fCheckOverlaps);

    auto DeadLayerCylinderSolid = new G4Tubs("DeadLayerZ", 0, crystalDiameter/2, DeadLayerZ/2, 0, 360*deg);
    auto DeadLayerLogicalVolume = new G4LogicalVolume(DeadLayerCylinderSolid, absorberMaterial, "DeadLayer");
    auto DeadLayerPhysicalVolume = new G4PVPlacement(0, G4ThreeVector(0, 0, deadZShift),
                                                    DeadLayerLogicalVolume,
                                                    "DeadLayer",
                                                    calorimeterLogicalVolume,
                                                    false, 0, fCheckOverlaps);

    G4double endCapTopZ = calorimeterShift - endCapShift - endCapLength / 2;

    G4double maxStep = 0.0001*mm;

    G4UserLimits* stepLimits = new G4UserLimits(maxStep);
    DeadLayerLogicalVolume->SetUserLimits(stepLimits);
    crystalLogicalVolume->SetUserLimits(stepLimits);
    calorimeterLogicalVolume->SetVisAttributes(new G4VisAttributes(G4Color(1.0, 0.0, 0.0,0))); // two red circles at the top and bottom
    endCapDisk2LogicalVolume->SetVisAttributes(new G4VisAttributes(G4Color(1.0, 0.0, 0.0,0)));
    endCapDisk1LogicalVolume->SetVisAttributes(new G4VisAttributes(G4Color(0.0, 0.0, 1.0,0)));
    endCapLogicalVolume->SetVisAttributes(new G4VisAttributes(G4Color(0.0, 1.0, 1.0,0)));
    DeadLayerLogicalVolume->SetVisAttributes(new G4VisAttributes(G4Color(1.0, 0.0, 0.0,0.1)));

    G4VisAttributes* crystalVisAtt = new G4VisAttributes(G4Color(0.0, 1.0, 0.0,1.));
    crystalVisAtt->SetForceSolid(true);
    crystalLogicalVolume->SetVisAttributes(crystalVisAtt);
    this->ftargetLogical=crystalLogicalVolume;
    
}
