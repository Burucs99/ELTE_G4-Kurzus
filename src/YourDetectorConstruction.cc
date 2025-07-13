#include "YourDetectorConstruction.hh"
#include "HPGeDetectorConstruction.hh"
#include "YourSensitiveDetector.hh"


YourDetectorConstruction::YourDetectorConstruction() : G4VUserDetectorConstruction(){

    this->nistManager = G4NistManager::Instance();
    this->worldSize = 1 * m;
    this->logicalSensitiveDetector = nullptr;
    this->HPGe = new HPGeDetectorConstruction();

}


G4VPhysicalVolume* YourDetectorConstruction::Construct(){

    this->worldMaterial = this->nistManager->FindOrBuildMaterial("G4_AIR");
    this->solidWorldVolume = new G4Box("worldVolume", this->worldSize / 2, this->worldSize / 2, this->worldSize / 2);
    this->logicalVolume = new G4LogicalVolume(this->solidWorldVolume, this->worldMaterial,"logicalVolume")  ;
    this->physicalVolume = new G4PVPlacement(nullptr, G4ThreeVector(0,0,0), this->logicalVolume,"physicalWorld",nullptr, false, 0);

    //Build the HPGe
    
    this->HPGe->Build(this->logicalVolume);
    this->logicalSensitiveDetector = this->HPGe->GetCrystalLogicalVolume();
    
    return this->physicalVolume; 

}


void YourDetectorConstruction::ConstructSDandFields(){

    this->sensitiveDetector = new YourSensitiveDetector("Sensitve_HPGe");
    this->logicalSensitiveDetector->SetSensitiveDetector(this->sensitiveDetector);

}

YourDetectorConstruction::~YourDetectorConstruction() {

    delete this->logicalSensitiveDetector;
    delete this->HPGe;
    delete this->worldMaterial;
    delete this->solidWorldVolume;
    delete this->logicalVolume;
    delete this->logicalSensitiveDetector;
    delete this->physicalVolume;

}
