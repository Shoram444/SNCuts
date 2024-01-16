#include "Filters.hh"


ClassImp(Filters);


Filters::Filters(std::vector<std::string>& _filtersToBeUsed) 
{
    for( auto& filter : _filtersToBeUsed)
    {
        if (filter == "useEventHasTwoNegativeParticles")
        {
            useEventHasTwoNegativeParticles = true;
        }

        if (filter == "useEventHasTwoParticles")
        {
            useEventHasTwoParticles = true;
        }
        if (filter == "useEventHasParticles")
        {
            useEventHasParticles = true;
        }
        if (filter == "useEventHasTwoTracks")
        {
            useEventHasTwoTracks = true;
        }
        if (filter == "useEventHasTwoFoilVertices")
        {
            useEventHasTwoFoilVertices = true;
        }
        if (filter == "useEventHasTwoCaloHits")
        {
            useEventHasTwoCaloHits = true;
        }
        if (filter == "useEventHasOneCaloHit")
        {
            useEventHasOneCaloHit = true;
        }
        if (filter == "useEventHasTwoAssociatedCaloHits")
        {
            useEventHasTwoAssociatedCaloHits = true;
        }
        if (filter == "useSDBDRC")
        {
            useEventHasTwoNegativeParticles = true;
            useEventHasTwoTracks            = true;
            useEventHasTwoFoilVertices      = true;
            useEventHasTwoCaloHits          = true;
            useEventHasTwoAssociatedCaloHits= true;
            useEventHasSumEnergyAbove       = true;
            useEventHasSumEnergyBelow       = true;
        }
        if (filter == "useEventHasSumEnergyAbove")
        {
            useEventHasSumEnergyAbove = true;
        }
        if (filter == "useEventHasSumEnergyBelow")
        {
            useEventHasSumEnergyBelow = true;
        }
        if (filter == "useEventHasFoilVertexDistanceBelow")
        {
            useEventHasFoilVertexDistanceBelow = true;
        }
    }
}

Filters::~Filters()
{
        useEventHasTwoNegativeParticles    = false; 
        useEventHasTwoParticles            = false; 
        useEventHasParticles               = false; 
        useEventHasTwoTracks               = false; 
        useEventHasTwoFoilVertices         = false; 
        useEventHasTwoCaloHits             = false; 
        useEventHasOneCaloHit              = false; 
        useEventHasTwoAssociatedCaloHits   = false; 

        useEventHasSumEnergyAbove          = false; 
        minSumEnergy                       = -10000.0;

        useEventHasSumEnergyBelow          = false; 
        maxSumEnergy                       = 100000.0;

        useEventHasFoilVertexDistanceBelow = false; 
        maxFoilVertexDistance              = 100000.0;
}


bool Filters::event_has_two_negative_particles(Event& _event)
{
    if (_event.get_particles().size() != 2)
    {
        return false;
    }

    for (auto& particle : _event.get_particles())
    {
        if( particle.get_charge() != -1)
        {
            return false;
        }
    }
    return true;
}

bool Filters::event_has_particles(Event& _event)
{
    if ( _event.get_particles().size() > 0 )
    {
        return true;
    }
    return false;
}

bool Filters::event_has_two_particles(Event& _event)
{
    if (_event.get_particles().size() == 2)
    {
        return true;
    }

    return false;
}

bool Filters::event_has_sum_energy_above(Event& _event, double _minSumEnergy)
{
    if( _event.get_event_total_energy() >  _minSumEnergy)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Filters::event_has_sum_energy_below(Event& _event, double _maxSumEnergy)
{
    if( _event.get_event_total_energy() <  _maxSumEnergy)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Filters::event_has_two_tracks(Event& _event)
{
    return event_has_two_particles(_event);
}

bool Filters::event_has_two_foil_vertices(Event& _event)
{
    int numberFoilVertices = 0;
    for (auto& particle : _event.get_particles())
    {
        if( particle.has_foil_vertex() )
        {
            numberFoilVertices++;
        }
    }
    if ( numberFoilVertices == 2 )
    {
        return true;
    }
    return false;
}

bool Filters::event_has_two_calo_hits(Event& _event)
{
    if( _event.get_cd_bank().get_number_of_calo_hits() == 2 )
    {
        return true;
    }
    return false; 
}

bool Filters::event_has_one_calo_hit(Event& _event)
{
    if( _event.get_cd_bank().get_number_of_calo_hits() == 1 )
    {
        return true;
    }
    return false;
}

bool Filters::event_has_two_associated_calo_hits(Event& _event)
{
    if ( event_has_two_particles(_event) )
    {
        for (auto& particle : _event.get_particles())
        {
            if ( particle.get_associated_calo_hits_number() != 1 )  // if there are multiple calohits associated with single PTD entry: fail
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

void Filters::set_min_sum_energy(double _minSumEnergy)
{
    minSumEnergy = _minSumEnergy;
}

void Filters::set_max_sum_energy(double _maxSumEnergy)
{
    maxSumEnergy = _maxSumEnergy;
}

double Filters::get_min_sum_energy()
{
    return minSumEnergy;
}
double Filters::get_max_sum_energy()
{
    return maxSumEnergy;
}

void Filters::set_max_foil_vertex_distance(double _maxFoilVertexDistance)
{
    maxFoilVertexDistance = _maxFoilVertexDistance;
}

bool Filters::event_has_foil_vertex_distance_below(Event& _event, double _maxFoilVertexDistance) // is it better if vertex distance is calculated here, or is part of Event?
{
    double foilVertexDistance = 1000000.0;
    if( event_has_two_foil_vertices(_event) && event_has_two_tracks(_event))  // Calculate foil vertex distance only if there are 2 foil vertices!
    {
        double dy = _event.get_particles().at(0).get_foil_vertex_position().Y() - _event.get_particles().at(1).get_foil_vertex_position().Y(); 
        double dz = _event.get_particles().at(0).get_foil_vertex_position().Z() - _event.get_particles().at(1).get_foil_vertex_position().Z();

        foilVertexDistance =  sqrt(  // I'm omitting X-component since this doesn't really make sense to use
                pow( dy , 2) + 
                pow( dz , 2) 
            );
    }

    if( foilVertexDistance < _maxFoilVertexDistance )
    {
        return true;
    }

    return false;
}


bool Filters::event_passed_filters(Event& _event) {
    if ( useEventHasTwoNegativeParticles && !event_has_two_negative_particles(_event) )         // event doesn't pass filter if filter should be used AND is not fulilled!
    {
        return false;
    }
    if ( useEventHasTwoParticles && !event_has_two_particles(_event) )
    {
        return false;
    }
    if ( useEventHasParticles && !event_has_particles(_event) ) 
    {
        return false;
    }
    if ( useEventHasTwoTracks && !event_has_two_tracks(_event) ) 
    {
        return false;
    }
    if ( useEventHasTwoFoilVertices && !event_has_two_foil_vertices(_event) ) 
    {
        return false;
    }
    if ( useEventHasTwoCaloHits && !event_has_two_calo_hits(_event) ) 
    {
        return false;
    }
    if ( useEventHasOneCaloHit && !event_has_one_calo_hit(_event) ) 
    {
        return false;
    }
    if ( useEventHasTwoAssociatedCaloHits && !event_has_two_associated_calo_hits(_event) ) 
    {
        return false;
    }
    if ( useEventHasSumEnergyAbove && !event_has_sum_energy_above(_event, minSumEnergy) )       
    {
        return false;
    }
    if ( useEventHasSumEnergyBelow && !event_has_sum_energy_below(_event, maxSumEnergy) )       
    {
        return false;
    }
    if ( useEventHasFoilVertexDistanceBelow && !event_has_foil_vertex_distance_below(_event, maxFoilVertexDistance) )       
    {
        return false;
    }
    return true;
}

