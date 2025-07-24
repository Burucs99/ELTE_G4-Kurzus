#ifndef YOURPRIMARYGENERATOR_HH
#define YOURPRIMARYGENERATOR_HH


#include "G4VUserPrimaryGeneratorAction.hh"
class G4ParticleGun;

class YourPrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction {
public:

/* 
Geant4 futás felépülése :


RUN : RunManager felügyeli 

Event : Egy eventen belül lehetnek események , például egy radioaktív bomlás

Primary Vertexek : * cézium itt áll és a vertex az hogy oda raktam 

"Step"-ek --- >   *   ---> Barium o ->>> 
step1:              step2:
e- (x,y,z,p,E) ->>> e- (x+deltax,y+deltay,...)

*/
    YourPrimaryGeneratorAction();
    virtual ~YourPrimaryGeneratorAction();

    virtual void GeneratePrimaries(G4Event* anEvent);

private:
    G4ParticleGun* fPGun;

};


#endif