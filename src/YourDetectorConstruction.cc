#include "YourDetectorConstruction.hh"



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
    
    return this->physicalVolume; 

}
