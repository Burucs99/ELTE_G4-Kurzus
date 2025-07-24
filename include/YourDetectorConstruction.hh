#ifndef YOURDETECTORCONSTRUCTION_HH
#define YOURDETECTORCONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"

class YourDetectorConstruction : public G4VUserDetectorConstruction {
public:
    //Konstruktór
    YourDetectorConstruction();
    //Destruktór
    virtual ~YourDetectorConstruction() override;

    virtual G4VPhysicalVolume* Construct() override;

private:
    virtual void ConstructSDandField();
    G4LogicalVolume* fHPGe_Logic;



};

#endif