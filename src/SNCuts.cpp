// Interface from Falaise
#include "SNCuts.hh"
#include "Event.hh"
#include "PTDParticle.hh"
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
    std::cout << " -----------------------------" << std::endl;
    std::cout << " Using the following filters: " << std::endl;
    try                                                             // myConfig.fetch(configKeyword, classVariable) looks for the config keyword 
    {                                                               // in the pipeline.conf file and sets the corresponding value of the classVariable
        myConfig.fetch("useEventHasTwoNegativeParticles", this->_useEventHasTwoNegativeParticles_);
        if(_useEventHasTwoNegativeParticles_)                       // if in the config file, the useCut is flagged true,
        {                                                           // it will be added to the list of all filters to be used
            std::cout << "EventHasTwoNegativeParticles" << std::endl;
            _filtersToBeUsed.push_back("useEventHasTwoNegativeParticles");  
        }
    } 
    catch (std::logic_error& e) 
    {
    }

    try 
    {
        myConfig.fetch("useEventHasTwoParticles", this->_useEventHasTwoParticles_);
        if(_useEventHasTwoParticles_)
        {
            std::cout << "EventHasTwoParticles" << std::endl;
            _filtersToBeUsed.push_back("useEventHasTwoParticles");
        }
    } 
    catch (std::logic_error& e) 
    {
    }

    try 
    {
        myConfig.fetch("useEventHasParticles", this->_useEventHasParticles_);
        if(_useEventHasParticles_)
        {
            std::cout << "EventHasParticles" << std::endl;
            _filtersToBeUsed.push_back("useEventHasParticles");
        }
    } 
    catch (std::logic_error& e) 
    {
    }

    try 
    {
        myConfig.fetch("useEventHasTwoTracks", this->_useEventHasTwoTracks_);
        if(_useEventHasTwoTracks_)
        {
            std::cout << "EventHasTwoTracks" << std::endl;
            _filtersToBeUsed.push_back("useEventHasTwoTracks");
        }
    } 
    catch (std::logic_error& e) 
    {
    }

    try 
    {
        myConfig.fetch("useEventHasTwoFoilVertices", this->_useEventHasTwoFoilVertices_);
        if(_useEventHasTwoFoilVertices_)
        {
            std::cout << "EventHasTwoFoilVertices" << std::endl;
            _filtersToBeUsed.push_back("useEventHasTwoFoilVertices");
        }
    } 
    catch (std::logic_error& e) 
    {
    }

    try 
    {
        myConfig.fetch("useEventHasTwoCaloHits", this->_useEventHasTwoCaloHits_);
        if(_useEventHasTwoCaloHits_)
        {
            std::cout << "EventHasTwoCaloHits" << std::endl;
            _filtersToBeUsed.push_back("useEventHasTwoCaloHits");
        }
    } 
    catch (std::logic_error& e) 
    {
    }

    try 
    {
        myConfig.fetch("useEventHasOneCaloHit", this->_useEventHasOneCaloHit_);
        if(_useEventHasOneCaloHit_)
        {
            std::cout << "EventHasOneCaloHit" << std::endl;
            _filtersToBeUsed.push_back("useEventHasOneCaloHit");
        }
    } 
    catch (std::logic_error& e) 
    {
    }

    try 
    {
        myConfig.fetch("useEventHasTwoAssociatedCaloHits", this->_useEventHasTwoAssociatedCaloHits_);
        if(_useEventHasTwoAssociatedCaloHits_)
        {
            std::cout << "EventHasTwoAssociatedCaloHits" << std::endl;
            _filtersToBeUsed.push_back("useEventHasTwoAssociatedCaloHits");
        }
    } 
    catch (std::logic_error& e) 
    {
    }

    try 
    {
        myConfig.fetch("useSDBDRC", this->_useSDBDRC_);
        if(_useSDBDRC_)
        {
            std::cout << "SDBDRC" << std::endl;
            _filtersToBeUsed.push_back("useSDBDRC");
        }
    } 
    catch (std::logic_error& e) 
    {
    }

    try 
    {
        myConfig.fetch("useEventHasSumEnergyAbove", this->_useEventHasSumEnergyAbove_);
        if(_useEventHasSumEnergyAbove_)
        {
            _filtersToBeUsed.push_back("useEventHasSumEnergyAbove");
        }
        myConfig.fetch("minSumEnergy", this->_minSumEnergy_);
        std::cout << "EventHasSumEnergyAbove " << _minSumEnergy_ << " keV" << std::endl;
    } 
    catch (std::logic_error& e) 
    {
    }
    
    try 
    {
        myConfig.fetch("useEventHasSumEnergyBelow", this->_useEventHasSumEnergyBelow_);
        if(_useEventHasSumEnergyBelow_)
        {
            _filtersToBeUsed.push_back("useEventHasSumEnergyBelow");
        }
        myConfig.fetch("maxSumEnergy", this->_maxSumEnergy_);
        std::cout << "EventHasSumEnergyBelow " << _maxSumEnergy_ << " keV" << std::endl;
    } 
    catch (std::logic_error& e) 
    {
    }

    try 
    {
        myConfig.fetch("useEventHasFoilVertexDistanceBelow", this->_useEventHasFoilVertexDistanceBelow_);
        if(_useEventHasFoilVertexDistanceBelow_)
        {
            _filtersToBeUsed.push_back("useEventHasFoilVertexDistanceBelow");
        }
        myConfig.fetch("maxFoilVertexDistance", this->_maxFoilVertexDistance_);
        std::cout << "EventHasFoilVertexDistanceBelow " << _maxFoilVertexDistance_ << " mm" << std::endl;
    } 
    catch (std::logic_error& e) 
    {
    }

    try 
    {
        myConfig.fetch("useEventHasPintAbove", this->_useEventHasPintAbove_);
        if(_useEventHasPintAbove_)
        {
            _filtersToBeUsed.push_back("useEventHasPintAbove");
        }
        myConfig.fetch("minPint", this->_minPint_);
        std::cout << "EventHasPintAbove " << _minPint_ << std::endl;
    } 
    catch (std::logic_error& e) 
    {
    }

    try 
    {
        myConfig.fetch("useEventHasPextBelow", this->_useEventHasPextBelow_);
        if(_useEventHasPextBelow_)
        {
            _filtersToBeUsed.push_back("useEventHasPextBelow");
        }
        myConfig.fetch("maxPext", this->_maxPext_);
        std::cout << "EventHasPextBelow " << _maxPext_ << std::endl;
    } 
    catch (std::logic_error& e) 
    {
    }

    std::cout << " -----------------------------" << std::endl;

}

dpp::base_module::process_status SNCuts::process(datatools::things& workItem) 
{
    Filters*  eventFilter = new Filters(_filtersToBeUsed);              // construct Filters instance which holds the filters
    eventFilter->set_min_sum_energy(_minSumEnergy_);                    // if not set in config file, value of -10000 is used. 
    eventFilter->set_max_sum_energy(_maxSumEnergy_);                    // if not set in config file, value of 1000000 is used. 
    eventFilter->set_max_foil_vertex_distance(_maxFoilVertexDistance_); // if not set in config file, value of 1000000 is used. 
    eventFilter->set_min_Pint(_minPint_);                               // if not set in config file, value of 0 is used. 
    eventFilter->set_max_Pext(_maxPext_);                               // if not set in config file, value of 0 is used. 

    //// Main method that fills event data from CD, PTD, etc. 
    event = get_event_data(workItem);

    //// If event passes all configured filters it is kept in the brio file, it is removed otherwise
    if( eventFilter->event_passed_filters(event) )
    {
        std::cout << "Event: " << eventNo << " ++PASSED++! "  <<std::endl;
        
        eventNo++;
        return falaise::processing::status::PROCESS_SUCCESS;

    }
    else if (!eventFilter->event_passed_filters(event))
    {
        // std::cout << "Event: " << eventNo << " Failed! "  <<std::endl;

        eventNo++;
        return dpp::base_module::PROCESS_STOP;
    }
    else
    {
        std:cout << "Event: " << eventNo << " Neither passed nor failed, wtf?! "  <<std::endl;
        eventNo++;
        return dpp::base_module::PROCESS_STOP;

    }

}

void SNCuts::reset() 
{   
    this->_set_initialized(false);
}


Event SNCuts::get_event_data(datatools::things& workItem)
{
    event.reset();
    event.set_event_number(eventNo);
    
    double totEne = 0.0;

    if(workItem.has("PTD"))
    {
        using namespace snemo::datamodel;

        snemo::datamodel::particle_track_data        PTDbank = workItem.get<particle_track_data>("PTD");
        snemo::datamodel::ParticleHdlCollection PTDparticles = PTDbank.particles();

        for (auto& iParticle : PTDparticles)
        {
            PTDParticle* ptdparticle = new PTDParticle(); //explicitly creates instance of Particle class from this Cuts module, as there is a name clash with Bayeux

            const snemo::datamodel::particle_track& track = iParticle.get();
            if      (particle_has_negative_charge (track)) 
            {               
                ptdparticle->set_charge(-1);
            }           
            else if (particle_has_neutral_charge  (track)) 
            {           
                ptdparticle->set_charge(0);
            }                   
            else if (particle_has_positive_charge (track)) 
            {       
                ptdparticle->set_charge(1);
            }               
            else if (particle_has_undefined_charge(track)) 
            {       
                ptdparticle->set_charge(1000);
            }           
            else 
            {
                ptdparticle->set_charge(1001); //something fishy
            }

            if (track.has_vertices()) // check vertices
            {
                const std::vector<datatools::handle<snemo::datamodel::vertex>> & particle_vertices = track.get_vertices();

                for (
                    datatools::handle<vertex> iVertex : particle_vertices
                )
                {
                    snemo::datamodel::vertex vtx = iVertex.get(); // get the vertex

                    if (vtx.is_on_source_foil())
                    {
                        ptdparticle->set_foil_vertex_position(
                                vtx.get_spot().get_position().x(),
                                vtx.get_spot().get_position().y(),
                                vtx.get_spot().get_position().z()
                            );
                    }
                    
                    else if (
                        vtx.is_on_main_calorimeter() || 
                        vtx.is_on_x_calorimeter   () ||
                        vtx.is_on_gamma_veto      () 
                    )
                    {
                        ptdparticle->set_calo_vertex_position(
                                vtx.get_spot().get_position().x(),
                                vtx.get_spot().get_position().y(),
                                vtx.get_spot().get_position().z()
                            );
                    }
                }
            }
                

            if (track.has_associated_calorimeter_hits()) 
            {

                int assCaloHitNo = 0;

                const std::vector<datatools::handle<snemo::datamodel::calibrated_calorimeter_hit>> & assCaloHits = track.get_associated_calorimeter_hits(); 
                for (
                    datatools::handle<snemo::datamodel::calibrated_calorimeter_hit> iCaloHit : track.get_associated_calorimeter_hits()
                    )
                {
                    snemo::datamodel::calibrated_calorimeter_hit cch = iCaloHit.get();

                    ptdparticle->set_energy            (cch.get_energy()        / CLHEP::keV);  //energy in keV
                    ptdparticle->set_energy_sigma_MeV  (cch.get_sigma_energy()  / CLHEP::MeV);  //energy sigma in MeV
                    ptdparticle->set_time              (cch.get_time()          / CLHEP::ns);   //calohit time in ns
                    ptdparticle->set_time_sigma        (cch.get_sigma_time()    / CLHEP::ns);   //calohit time sigma in ns

                    totEne += cch.get_energy() / CLHEP::keV;
                    assCaloHitNo++;
                }

                ptdparticle->set_associated_calo_hits_number(assCaloHitNo);
            }

            if( track.has_trajectory())
            {
                const snemo::datamodel::tracker_trajectory & trajectory = track.get_trajectory();

                ptdparticle->set_track_length(trajectory.get_pattern().get_shape().get_length());

                if( TMath::Abs(trajectory.get_pattern().get_first().x()) <= trajectory.get_pattern().get_last().x() )
                {
                    double mul = ( trajectory.get_pattern().get_first_direction().x() * trajectory.get_pattern().get_first().x() > 0 ) ? 1.0 : -1.0;
                    geomtools::vector_3d direction = trajectory.get_pattern().get_first_direction() * mul; 
                }
                else
                {
                    double mul = ( trajectory.get_pattern().get_last_direction().x() * trajectory.get_pattern().get_last().x() > 0 ) ? 1.0 : -1.0;
                    geomtools::vector_3d direction = trajectory.get_pattern().get_last_direction() * mul; 
                }

            }

            event.add_particle(*ptdparticle);
            delete ptdparticle;
        }
    }
    else 
    {
        std::cout << "No PTD Bank!!!\n";
    }

    event.set_event_total_energy(totEne);

    if(workItem.has("CD"))
    {
        using namespace snemo::datamodel;

        snemo::datamodel::calibrated_data falaiseCDbank = workItem.get<calibrated_data>("CD");

        CDBank* SNCCDBank = new CDBank();                                                       //SNCuts CD bank

        const std::vector<datatools::handle<snemo::datamodel::calibrated_calorimeter_hit>> & caloHits = falaiseCDbank.calorimeter_hits();

        for (
            const datatools::handle<snemo::datamodel::calibrated_calorimeter_hit> & calohit : caloHits 
            )
        {
            CDHit* cdhit = new CDHit();

            cdhit->set_energy( calohit.get().get_energy() / CLHEP::keV );
            SNCCDBank->add_calohit(*cdhit);

            delete cdhit;
        }

        event.add_cd_bank(*SNCCDBank);

        delete SNCCDBank;
    }

    return event;
}