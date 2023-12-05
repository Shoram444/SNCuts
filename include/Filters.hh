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
        using FilterFunction        = std::function<bool(Event&)>;    // create a holder for filter functions

        //! constructor
		Filters();  

		//! desctructor
		~Filters();

        void add_filters(const std::vector<FilterFunction>& _filters);
        
        static bool event_has_two_negative_particles        (Event& _event);
        static bool event_has_two_particles                 (Event& _event);
        static bool event_has_particles                     (Event& _event);
        static bool event_has_sum_energy_above              (Event& _event, double _minEnergy);
        static bool event_has_sum_energy_below              (Event& _event, double _maxEnergy);
        static bool event_has_two_tracks                    (Event& _event);       //this is equivalend to event_has_two_particles
        static bool event_has_two_foil_vertices             (Event& _event);
        static bool event_has_two_calo_hits                 (Event& _event);
        static bool event_has_two_associated_calo_hits      (Event& _event);

        void set_min_energy_filter(double _minEnergy);
        void set_max_energy_filter(double _maxEnergy);

        double get_min_energy_filter();
        double get_max_energy_filter();

        bool event_passed_filters(Event& _event);

    private:
        std::vector<FilterFunction> filters;

        double minEnergy;
        double maxEnergy;
    
	ClassDef(Filters,1);
};

#endif // FILTERS_HH