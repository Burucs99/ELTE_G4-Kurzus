#include "YourDetectorConstruction.hh"
#include <G4EventManager.hh>
#include <G4Material.hh>
#include <G4NistManager.hh>
#include <G4Tubs.hh>
#include <G4VPhysicalVolume.hh>
#include <G4VisAttributes.hh>
#include "G4SystemOfUnits.hh"
#include "G4Box.hh"
#include "G4Types.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4VPhysicalVolume.hh"
#include "G4VUserDetectorConstruction.hh"
#include "YourSensitiveDetector.hh"
#include "G4SDManager.hh"
YourDetectorConstruction::YourDetectorConstruction()
:   G4VUserDetectorConstruction(),fHPGe_Logic(nullptr)    
{
    G4cout<<"Building YourDetectorConstruction"<<G4endl;

}

YourDetectorConstruction::~YourDetectorConstruction() {}


G4VPhysicalVolume* YourDetectorConstruction::Construct() {
    G4cout<<"Benne vagyunk a YourDetectorConstruction::Construct() függvényben"<<G4endl;


    // Formánk : Hogy néz ki a geometria például kocka vagy karika vagy háromszög .... SHAPE


    // Formát LOGIKAILAG Elhelyezzük : Hol és miből van a forma LOGICAL Volume

    // Fizikai Volume : 

    G4NistManager* nistMGR = G4NistManager::Instance();
    G4Material* vilag_anyag = nistMGR->FindOrBuildMaterial("G4_Galactic");


    G4double vilag_meret = 1*m;

    G4Box* vilagForma = new G4Box("forma-Vilag",vilag_meret/2,vilag_meret/2,vilag_meret/2);
    G4LogicalVolume* vilagLogikai = new G4LogicalVolume(vilagForma,vilag_anyag,"logikai-Vilag")  ;
    G4VPhysicalVolume* vilagFizikai = new G4PVPlacement(nullptr,G4ThreeVector(0,0,0),vilagLogikai,"Vilag",nullptr,false,0);

    vilagLogikai->SetVisAttributes(new G4VisAttributes(G4Color(0,0,0.1,0.1)));
    //Germánium HPGe kreálás 
    /* 
    1.) Forma = Tubus vagy henger
    2.) Logikai Volumenje
    3.) Fizikai Volumenje amit hozzá adunk a világhoz


    4.) Logikai volumenjéhez hozzá rendeleünk egy Sensitive Detectort.
    
    */
    // 1.) Forma = Tubus vagy henger
    G4double Sugár_Max = 2.4*cm;
    G4double Tubus_Magasság = 5.4*cm;
    G4Material* Germánium = nistMGR->FindOrBuildMaterial("G4_Ge");

    G4Tubs* HPGe_Forma = new G4Tubs("HPGe_Forma",
                                    0,
                                    Sugár_Max,
                                    Tubus_Magasság,
                                    0,
                                    360*deg);
    G4LogicalVolume* HPGe_Logikai = new G4LogicalVolume(HPGe_Forma,Germánium,"logikai-HPGe")  ;
    G4VPhysicalVolume* HPGE_Fizikai = new G4PVPlacement(nullptr,
                                                        G4ThreeVector(0,0,0),
                                                        HPGe_Logikai,
                                                        "HPGe",
                                                        vilagLogikai,
                                                        false,0) ; 
    
    fHPGe_Logic = HPGe_Logikai;
    return vilagFizikai; 

}

void YourDetectorConstruction::ConstructSDandField(){
    // LÉtrehozzuk a sensdetet
    YourSensitiveDetector* sensDet = new YourSensitiveDetector("Sensitive_HPGe");
    //Hozzáadjuk a sensdet-"bankhoz"
    G4SDManager::GetSDMpointer()->AddNewDetector(sensDet);
    // Mi hpge logikai volumenünket sensitivvé tesszük
    fHPGe_Logic->SetSensitiveDetector(sensDet);

}