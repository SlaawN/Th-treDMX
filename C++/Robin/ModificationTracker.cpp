//---------------------------------------------------------------------------

#pragma hdrstop

#include "ModificationTracker.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

ModificationTracker::ModificationTracker(){


}

ModificationTracker::enableTrack(bool track){

   this->track=track;

}

void ModificationTracker::setModified(bool IsModified){

   this->IsModified=IsModified;

}

void ModificationTracker::resetModified(){

   this->IsModified=false;

}

