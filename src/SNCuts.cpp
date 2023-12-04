// Interface from Falaise
#include "SNCuts.hh"
#include "Event.hh"
#include "Particle.hh"
#include "Filters.hh"



DPP_MODULE_REGISTRATION_IMPLEMENT(SNCuts, "SNCuts")

SNCuts::SNCuts() : dpp::base_module() 
{
    eventNo = 0;
    std::cout << "constructed!" << std::endl;
}

SNCuts::~SNCuts()
{ 
    if (this->is_initialized())
    {
        this->reset();
    }
}

void SNCuts::initialize( 
            const datatools::properties&   myConfig,
            datatools::service_manager&    flServices,
            dpp::module_handle_dict_type&  /*moduleDict*/
        ) 
{
    this->_set_initialized(true);
}

dpp::base_module::process_status SNCuts::process(datatools::things& workItem) 
{
    // event.reset();
    event = get_event_data(workItem);

    filtersList.push_back(&Filters::event_has_two_particles);
    filtersList.push_back(&Filters::event_has_two_negative_particles);
    filtersList.push_back(&Filters::event_has_particles);

    eventFilter.add_filters(filtersList);                                   // construct Filters instance which holds the filters


    if( eventFilter.event_passed_filters(event) )
    {
        std::cout << "Event: " << eventNo << " Passed! "  <<std::endl;

        eventNo++;
        return falaise::processing::status::PROCESS_OK;

    }
    else if (!eventFilter.event_passed_filters(event))
    {
        std::cout << "Event: " << eventNo << " Failed! "  <<std::endl;

        eventNo++;
        return dpp::base_module::PROCESS_STOP;
    }
    else
    {
        std:cout << "Event: " << eventNo << " Neither passed nor failed, wtf?! "  <<std::endl;
        eventNo++;
    }

    return falaise::processing::status::PROCESS_OK;
}

void SNCuts::reset() 
{   
    this->_set_initialized(false);
}


Event SNCuts::get_event_data(datatools::things& workItem)
{
    event.reset();
    event.set_event_number(eventNo);

    if(workItem.has("PTD"))
    {
        using namespace snemo::datamodel;

        snemo::datamodel::particle_track_data    PTDbank = workItem.get<particle_track_data>("PTD");
        const snemo::datamodel::ParticleHdlCollection& PTDparticles = PTDbank.particles();

        for (auto& iParticle : PTDparticles)
        {
            ::Particle* particle = new ::Particle(); //explicitly creates instance of Particle class from this Cuts module, as there is a name clash with Bayeux

            const snemo::datamodel::particle_track& track = iParticle.get();
            if      (particle_has_negative_charge (track)) 
            {               
                particle->set_charge(-1);
            }           
            else if (particle_has_neutral_charge  (track)) 
            {           
                particle->set_charge(0);
            }                   
            else if (particle_has_positive_charge (track)) 
            {       
                particle->set_charge(1);
            }               
            else if (particle_has_undefined_charge(track)) 
            {       
                particle->set_charge(1000);
            }           
            else 
            {
                particle->set_charge(1001); //something fishy
            }

            if (track.has_vertices()) // There isn't any time ordering to the vertices so check them all
            {
                for (const auto& iVertex : track.get_vertices())
                {
                    if (particle_track::vertex_is_on_source_foil(iVertex.get()))
                    {
                        particle->set_foil_vertex_position(
                            iVertex.get().get_position().x(),
                            iVertex.get().get_position().y(),
                            iVertex.get().get_position().z()
                            );
                    }
                    
                    else if (
                        particle_track::vertex_is_on_main_calorimeter(iVertex.get()) || 
                        particle_track::vertex_is_on_x_calorimeter   (iVertex.get()) ||
                        particle_track::vertex_is_on_gamma_veto      (iVertex.get()) 
                    )
                    {
                        particle->set_calo_vertex_position(
                            iVertex.get().get_position().x(),
                            iVertex.get().get_position().y(),
                            iVertex.get().get_position().z()
                            );
                    }
                }
            }

            if (track.has_associated_calorimeter_hits()) // There isn't any time ordering to the vertices so check them all
            {
                for (const auto& iCaloHit : track.get_associated_calorimeter_hits())
                {
                    particle->set_energy(iCaloHit.get().get_energy() / CLHEP::keV);  //energy in kev
                }
            }
            
            event.add_particle(*particle);
            delete particle;
        }

    }
    else std::cout << "No PTD Bank!!!\n";
    event.print();
    return event;
}