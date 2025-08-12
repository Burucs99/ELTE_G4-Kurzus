#include "YourConcreteWall.hh"



YourConcreteWall::YourConcreteWall() {
    this->materialsTable = new Materials();
    this->wallMaterial = materialsTable->GetConcreteMaterial();

    this->xLength = 5.0 * m;
    this->yLength = 5.0 * m;
    this->zLength = 0.2 * m; // adjustments needed here
    this->wallShift = G4ThreeVector(0, 0, -32 * cm); // position in the world volume

}

void YourConcreteWall::Build(G4LogicalVolume* motherVolume) {

    this->wallSolid = new G4Box("ConcreteWall", xLength / 2, yLength / 2, zLength / 2);
    this->wallLogicalVolume = new G4LogicalVolume(wallSolid, wallMaterial, "ConcreteWall");
    this->wallPhysicalVolume = new G4PVPlacement(nullptr, this->wallShift, wallLogicalVolume, "ConcreteWall", motherVolume, false, 0);

    this->Initialiseattributes();
}

void YourConcreteWall::Initialiseattributes() {
    G4VisAttributes* wallVisAttributes = new G4VisAttributes(G4Colour(0.0, 0.0, 1.0, 0.5));
    wallVisAttributes->SetVisibility(true);
    wallVisAttributes->SetForceSolid(true);
    wallLogicalVolume->SetVisAttributes(wallVisAttributes);
}

YourConcreteWall::~YourConcreteWall() {
    delete this->materialsTable;
    delete this->wallSolid;
    delete this->wallLogicalVolume;
    delete this->wallPhysicalVolume;
    delete this->wallMaterial;
}