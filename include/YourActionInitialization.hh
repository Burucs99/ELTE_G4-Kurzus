#ifndef YOURACTION_HH
#define YOURACTION_HH


#include "G4VUserActionInitialization.hh"

class YourActionInitialization : public G4VUserActionInitialization{
public:
    YourActionInitialization();
    ~YourActionInitialization() override;

    void Build() const override;
    virtual void BuildForMaster() const override;
    



private:



};
#endif