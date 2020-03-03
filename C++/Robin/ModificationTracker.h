//---------------------------------------------------------------------------

#ifndef ModificationTrackerH
#define ModificationTrackerH
//---------------------------------------------------------------------------

class ModificationTracker{

	private :

		bool IsModified,track;

	public :

	   ModificationTracker();
	   void enableTrack(bool track);

	protected :

		void setModified();
		void resetModified();

};

#endif
