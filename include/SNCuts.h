#ifndef SNCUTS_H
#define SNCUTS_H

// Interface from Falaise
#include "bayeux/dpp/base_module.h"
#include "bayeux/mctools/simulated_data.h"

#include "falaise/snemo/processing/module.h"
#include "falaise/snemo/datamodels/particle_track_data.h"


struct VertexPosition {
    double x;
    double y;
    double z;
};

struct Particle {
    double charge;
    double energy;
    VertexPosition foilVertexPosition;
    VertexPosition caloVertexPosition;
};

struct Event {
    int eventNumber;
    std::vector<Particle> particles;

    void add_particle(const Particle& newParticle) {
        particles.push_back(newParticle);
    }

    void print() const {
        std::cout << "Event Number: " << eventNumber << std::endl;

        for (const auto& particle : particles) {
            std::cout << "Particle Charge: " << particle.charge << std::endl;
            std::cout << "Particle Energy: " << particle.energy << std::endl;

            std::cout << "Foil Vertex Position: (" << particle.foilVertexPosition.x
                      << ", " << particle.foilVertexPosition.y
                      << ", " << particle.foilVertexPosition.z << ")" << std::endl;

            std::cout << "Calo Vertex Position: (" << particle.caloVertexPosition.x
                      << ", " << particle.caloVertexPosition.y
                      << ", " << particle.caloVertexPosition.z << ")" << std::endl;

            std::cout << "-----------------" << std::endl;
        }
    }
};

class SNCuts : public dpp::base_module {
    public:
        ////////////////////////////////////////////////
        // The following PUBLIC methods MUST be defined!
        // Default constructor
        SNCuts();

        // Default destructor
        virtual ~SNCuts();


        //! Configure the module
        virtual void initialize( 
            const datatools::properties&   myConfig,
            datatools::service_manager&    flServices,
            dpp::module_handle_dict_type&  what
        );

		//! Reset the module
		virtual void reset();

        // Process event
		virtual dpp::base_module::process_status process(datatools::things& workItem);
        ////////////////////////////////////////////////
        // Everything else is optional for your usecase
        void fill_event(datatools::things& workI);

	private:
		int eventNo;

        Event event;
        Particle particle;


    DPP_MODULE_REGISTRATION_INTERFACE(SNCuts);
};

#endif //SNCUTS_H