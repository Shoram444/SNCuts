#ifndef EVENT_HH
#define EVENT_HH

// ROOT headers
#include "TObject.h"

#include "Particle.hh"

// Standard headers
#include "iostream"

using namespace std;

class Event: public TObject
{
    public: 
        //! constructor
		Event();

		//! desctructor
		~Event();

		void set_event_number(int eventNumber);
		void add_particle(const Particle &newParticle); // add a particle into the event
		void reset(); 									// resets the values of the Event
		void print();	


		int get_event_number(); 

	private:
		int eventNumber;
		std::vector<Particle> particles;
    
    
	ClassDef(Event,1);
};

#endif // EVENT_HH