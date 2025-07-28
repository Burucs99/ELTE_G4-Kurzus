#ifndef YOURRUNACTION_HH
#define YOURRUNACTION_HH

#include <G4RunManager.hh>
#include <G4UserRunAction.hh>
#include <G4AnalysisManager.hh>
#include "G4Timer.hh"


class YourRunAction : public G4UserRunAction{

    public:

        YourRunAction();
        ~YourRunAction();

        virtual void BeginOfRunAction(const G4Run* theRun);
        virtual void EndOfRunAction(const G4Run* theRun);

    private:

        G4Timer* timer;

};


#endif