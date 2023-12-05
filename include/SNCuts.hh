#ifndef SNCUTS_H
#define SNCUTS_H

// Interface from Falaise
#include "bayeux/dpp/base_module.h"
#include "bayeux/mctools/simulated_data.h"

#include "falaise/snemo/processing/module.h"
#include "falaise/snemo/datamodels/particle_track_data.h"
#include "falaise/snemo/datamodels/tracker_clustering_solution.h"


#include "Event.hh"
#include "Particle.hh"
#include "Filters.hh"



class SNCuts : public dpp::base_module
{
public:
    ////////////////////////////////////////////////
    // The following PUBLIC methods MUST be defined!
    // Default constructor
    SNCuts();

    // Default destructor
    virtual ~SNCuts();

    //! Configure the module
    virtual void initialize(
        const datatools::properties &myConfig,
        datatools::service_manager &flServices,
        dpp::module_handle_dict_type &what);

    //! Reset the module
    virtual void reset();

    // Process event
    virtual dpp::base_module::process_status process(datatools::things &workItem);
    ////////////////////////////////////////////////
    // Everything else is optional for your usecase
    Event get_event_data(datatools::things &workItem);

private:
    int eventNo;
    Event event;

    std::vector<Filters::FilterFunction>        filtersList;            // container of filter functions to be applied to the event
    Filters eventFilter;                                                // construct Filters instance which holds the filters

    DPP_MODULE_REGISTRATION_INTERFACE(SNCuts);
};

#endif // SNCUTS_H