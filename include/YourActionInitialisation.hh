#ifndef YOURACTIONINITIALISATION_HH
#define YOURACTIONINITIALISATION_HH

#include <G4VUserActionInitialization.hh>

#include "YourPrimaryGenerator.hh"
#include "YourRunAction.hh"


class YourActionInitialisation : public G4VUserActionInitialization{

    public:
        YourActionInitialisation();
        ~YourActionInitialisation();

        virtual void Build() const;
        virtual void BuildForMaster() const;


};


#endif
