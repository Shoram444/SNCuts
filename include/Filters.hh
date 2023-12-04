#ifndef FILTERS_HH
#define FILTERS_HH

// ROOT headers
#include "TObject.h"

#include "Particle.hh"
#include "Event.hh"

// Standard headers
#include "iostream"
#include <functional>

using namespace std;

class Filters: public TObject
{
    public: 
        using FilterFunction = std::function<bool(Event&)>;    // create a holder for filter functions

        //! constructor
		Filters();  

		//! desctructor
		~Filters();

        void add_filters(const std::vector<FilterFunction>& _filters);
        
        static bool event_has_two_negative_particles(Event& _event);
        static bool event_has_two_particles(Event& _event);
        static bool event_has_particles(Event& _event);

        bool event_passed_filters(Event& _event);

    private:
        std::vector<FilterFunction> filters;

    
	ClassDef(Filters,1);
};

#endif // FILTERS_HH