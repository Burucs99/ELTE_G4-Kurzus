#include "HPGeDetectorConstruction.hh"
#include <G4ios.hh>



HPGeDetectorConstruction::HPGeDetectorConstruction(){

    this->nistManager = G4NistManager::Instance();

    this->defaultMaterial = this->nistManager->FindOrBuildMaterial("G4_AIR");
    this->absorberbMaterial = this->nistManager->FindOrBuildMaterial("G4_Ge");
    this->vacuum = this->nistManager->FindOrBuildMaterial("G4_Galactic");
    this->aluminium = this->nistManager->FindOrBuildMaterial("G4_Al");
    this->teflon = this->nistManager->FindOrBuildMaterial("G4_TEFLON");

}

void HPGeDetectorConstruction::Build(G4LogicalVolume* motherWolrdVolume){

    this->calorimeterSolid = new G4Tubs ("Calorimeter", 0, endCapOuterDiameter/2, endCapLength/2, 0, 360*deg);
    this->calorimeterLogicalVolume  = new G4LogicalVolume (calorimeterSolid, vacuum, "Calorimeter");
    this->calorimeterPhysicalVolume = new G4PVPlacement (0, G4ThreeVector(0, 0, calorimeterShift),
                                                        calorimeterLogicalVolume,
                                                        "Calorimeter",
                                                        motherWolrdVolume,
                                                        false, 0, this->fCheckOverlaps);
 
    //------------------------
    //--------Endcap----------
    this->endCapSolid = new G4Tubs ("EndCap", endCapInnerDiameter/2, endCapOuterDiameter/2, endCapLength/2, 0, 360*deg);
    this->endCapLogicalVolume = new G4LogicalVolume (endCapSolid, aluminium, "EndCap");
    this->endCapPhysicalVolume = new G4PVPlacement (0, G4ThreeVector(0, 0, endCapShift), endCapLogicalVolume, "EndCap", calorimeterLogicalVolume, false, 0, fCheckOverlaps);
    
    this->endCapDisk1Solid = new G4Tubs ("EndCapDisk1", 0, endCapOuterDiameter/2 - endCapThickness/2, endCapThickness/2, 0, 360*deg);
    this->endCapDisk1LogicalVolume  = new G4LogicalVolume (endCapDisk1Solid, aluminium, "EndCapDisk1");
    this->endCapDisk1PhysicalVolume = new G4PVPlacement (0, G4ThreeVector(0, 0, endCapDisk1Shift),endCapDisk1LogicalVolume,"EndCapDisk1", calorimeterLogicalVolume, false, 0, fCheckOverlaps);
    
    this->endCapDisk2Solid= new G4Tubs ("EndCapDisk2", 0, endCapOuterDiameter/2 - endCapThickness/2, endCapThickness/2, 0, 360*deg);
    this->endCapDisk2LogicalVolume = new G4LogicalVolume (endCapDisk2Solid, aluminium, "EndCapDisk2");
    this->endCapDisk2PhysicalVolume  = new G4PVPlacement (0, G4ThreeVector(0, 0, endCapDisk2Shift), endCapDisk2LogicalVolume, "EndCapDisk2", calorimeterLogicalVolume, false, 0, fCheckOverlaps);
    
    //------------------------
    //--------Crystal---------

    G4cout << absorberbMaterial->GetTemperature() << G4endl;

    this->crystalCylinderSolid = new G4Tubs("CrystalBase", 0, crystalDiameter / 2, activeCrystalLength / 2, 0, 360 * deg);
    this->crystalHoleSolid = new G4Tubs("CrystalHole", 0, crystalHoleDiameter / 2, crystalHoleDepth / 2, 0, 360 * deg);
    this->crystalSolid = new G4SubtractionSolid("Crystal", crystalCylinderSolid, crystalHoleSolid, 0, G4ThreeVector(0, 0, crystalHoleRelShift + deadLayerZ));
    this->crystalLogicalVolume = new G4LogicalVolume(crystalSolid, absorberbMaterial, "Crystal");
    this->crystalPhysicalVolume = new G4PVPlacement(0, G4ThreeVector(0, 0, activeZShift + deadLayerZ), crystalLogicalVolume, "Crystal", calorimeterLogicalVolume, false, 0, fCheckOverlaps);

    this->deadLayerCylinderSolid = new G4Tubs("DeadLayerZ", 0, crystalDiameter / 2, deadLayerZ/2, 0, 360 * deg);
    this->deadLayerLogicalVolume = new G4LogicalVolume(deadLayerCylinderSolid, absorberbMaterial, "DeadLayer");
    this->deadLayerPhysicalVolume = new G4PVPlacement(0, G4ThreeVector(0, 0, deadZShift), deadLayerLogicalVolume, "DeadLayer", calorimeterLogicalVolume, false, 0, fCheckOverlaps);

    //We define all the visible properties of the HPGe components
    this->InitialiseAttributes();

}

void HPGeDetectorConstruction::InitialiseAttributes(){

    G4UserLimits* stepLimits = new G4UserLimits(maxStep);
    this->deadLayerLogicalVolume->SetUserLimits(stepLimits);
    this->crystalLogicalVolume->SetUserLimits(stepLimits);
    this->calorimeterLogicalVolume->SetVisAttributes(new G4VisAttributes(G4Color(1.0, 0.0, 0.0,0.5))); // two red circles at the top and bottom
    this->endCapDisk2LogicalVolume->SetVisAttributes(new G4VisAttributes(G4Color(1.0, 0.0, 0.0,0.5)));
    this->endCapDisk1LogicalVolume->SetVisAttributes(new G4VisAttributes(G4Color(0.0, 0.0, 1.0,0.5)));
    this->endCapLogicalVolume->SetVisAttributes(new G4VisAttributes(G4Color(0.0, 1.0, 1.0,0.5)));
    this->deadLayerLogicalVolume->SetVisAttributes(new G4VisAttributes(G4Color(1.0, 0.0, 0.0,0.5)));

    G4VisAttributes* crystalVisAtt = new G4VisAttributes(G4Color(0.0, 1.0, 0.0,0.5));
    crystalVisAtt->SetForceSolid(true);
    crystalLogicalVolume->SetVisAttributes(crystalVisAtt);

}


HPGeDetectorConstruction::~HPGeDetectorConstruction(){

}