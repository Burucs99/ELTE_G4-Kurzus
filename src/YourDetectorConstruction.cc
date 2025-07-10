#include "YourDetectorConstruction.hh"
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


YourDetectorConstruction::YourDetectorConstruction()
:   G4VUserDetectorConstruction(){
    G4cout<<"Building YourDetectorConstruction"<<G4endl;

}

YourDetectorConstruction::~YourDetectorConstruction() {}


G4VPhysicalVolume* YourDetectorConstruction::Construct() {
    G4cout<<"Benne vagyunk a YourDetectorConstruction::Construct() függvényben"<<G4endl;


    // Formánk : Hogy néz ki a geometria például kocka vagy karika vagy háromszög .... SHAPE


    // Formát LOGIKAILAG Elhelyezzük : Hol és miből van a forma LOGICAL Volume

    // Fizikai Volume : 

    G4NistManager* nistMGR = G4NistManager::Instance();
    G4Material* vilag_anyag = nistMGR->FindOrBuildMaterial("G4_AIR");


    G4double vilag_meret = 1*m;

    G4Box* vilagForma = new G4Box("forma-Vilag",vilag_meret/2,vilag_meret/2,vilag_meret/2);
    G4LogicalVolume* vilagLogikai = new G4LogicalVolume(vilagForma,vilag_anyag,"logikai-Vilag")  ;
    G4VPhysicalVolume* vilagFizikai = new G4PVPlacement(nullptr,G4ThreeVector(0,0,0),vilagLogikai,"Vilag",nullptr,false,0);

    return vilagFizikai; 
}