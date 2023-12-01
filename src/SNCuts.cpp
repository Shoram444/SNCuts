// Interface from Falaise
#include "SNCuts.hh"
#include "Event.hh"
#include "Particle.hh"


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
    std::cout << "Event number = " << eventNo << std::endl;
    fill_event(workItem);

    if(eventNo == 99)
    {
        std::cout << "removed event: " << eventNo << std::endl;
        eventNo++;

        return dpp::base_module::PROCESS_STOP;
    }
    eventNo++;

    return falaise::processing::status::PROCESS_OK;
}

void SNCuts::reset() 
{   
    this->_set_initialized(false);
}


void SNCuts::fill_event(datatools::things& workItem)
{
    Event* event = new Event();

    event->set_event_number(eventNo);

    if(workItem.has("PTD"))
    {
        using namespace snemo::datamodel;

        snemo::datamodel::particle_track_data    PTDbank = workItem.get<particle_track_data>("PTD");
        const snemo::datamodel::ParticleHdlCollection& PTDparticles = PTDbank.particles();

        for (const auto& iParticle : PTDparticles)
        {
            Particle* particle = new Particle();

            const snemo::datamodel::particle_track& track = iParticle.get();
            if      (particle_has_negative_charge (track)) 
            {               
                particle->charge = -1;
            }           
            else if (particle_has_neutral_charge  (track)) 
            {           
                particle->charge = 0;
            }                   
            else if (particle_has_positive_charge (track)) 
            {       
                particle->charge = 1;
            }               
            else if (particle_has_undefined_charge(track)) 
            {       
                particle->charge = 1000;
            }           
            else 
            {
                particle->charge = 1001; //something fishy
            }

            particle->energy = 10.0;
            particle->foilVertexPosition = {7.0, 8.0, 9.0};
            particle->caloVertexPosition = {7.0, 8.0, 9.0};

            event->add_particle(particle);
            delete particle;
        }

    }
    else std::cout << "No PTD Bank!!!\n";
    
    event->print();
    delete event;
}