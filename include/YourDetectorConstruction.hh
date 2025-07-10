#ifndef YOURDETECTORCONSTRUCTION_HH
#define YOURDETECTORCONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"

class YourDetectorConstruction : public G4VUserDetectorConstruction {
public:
    //Konstruktór
    YourDetectorConstruction();
    //Destruktór
    virtual ~YourDetectorConstruction();

    virtual G4VPhysicalVolume* Construct();

private:




};

#endif