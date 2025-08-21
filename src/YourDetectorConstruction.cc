#include "YourDetectorConstruction.hh"
#include "HPGeDetectorConstruction.hh"
#include "YourSensitiveDetector.hh"


YourDetectorConstruction::YourDetectorConstruction() : G4VUserDetectorConstruction(){

    this->nistManager = G4NistManager::Instance();
    this->worldSize = 10000 * m;
    this->logicalSensitiveDetector = nullptr;
    this->concreteWall = new YourConcreteWall();
    this->HPGe = new HPGeDetectorConstruction();

}


G4VPhysicalVolume* YourDetectorConstruction::Construct(){

    this->worldMaterial = this->nistManager->FindOrBuildMaterial("G4_Galactic");
    this->solidWorldVolume = new G4Box("worldVolume", this->worldSize / 2, this->worldSize / 10, this->worldSize / 10);
    this->logicalVolume = new G4LogicalVolume(this->solidWorldVolume, this->worldMaterial,"logicalVolume")  ;
    this->physicalVolume = new G4PVPlacement(nullptr, G4ThreeVector(0,0,0), this->logicalVolume,"physicalWorld",nullptr, false, 0);

    //Build the HPGe
    
    this->HPGe->Build(this->logicalVolume);
    this->concreteWall->Build(this->logicalVolume);

    this->logicalSensitiveDetector = this->HPGe->GetCrystalLogicalVolume();
    //this->logicalSensitiveDetector = this->concreteWall->GetLogicalVolume();

    return this->physicalVolume; 

}


void YourDetectorConstruction::ConstructSDandField(){

    /*YourSensitiveDetector* sensitiveDetector = new YourSensitiveDetector("SensitveHPGe");
    G4SDManager::GetSDMpointer()->AddNewDetector(sensitiveDetector);
    this->logicalSensitiveDetector->SetSensitiveDetector(sensitiveDetector);*/

    // for the concrete wall to be sensitive
    YourSensitiveDetector* concreteSensitiveDetector = new YourSensitiveDetector("ConcreteWall");
    G4SDManager::GetSDMpointer()->AddNewDetector(concreteSensitiveDetector);
    this->logicalSensitiveDetector->SetSensitiveDetector(concreteSensitiveDetector);


}

YourDetectorConstruction::~YourDetectorConstruction() {

}
