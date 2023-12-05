#include "Filters.hh"


ClassImp(Filters);


Filters::Filters() 
{
}

Filters::~Filters()
{
}

void Filters::add_filters(const std::vector<FilterFunction>& _filters)
{
    for (const auto& filter : _filters)
    {
        filters.push_back(filter);
    }
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

bool Filters::event_has_sum_energy_above(Event& _event)
{
    if( minEnergy == 0 &&  maxEnergy == 0 )
    {
        std::cout << "ENERGY FILTER WAS NOT INITIALZED! PLEASE INITIALIZE EMIN AND EMAX!" << std:endl;
        return true;
    }

    if( _event.get_event_total_energy() >  minEnergy)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Filters::event_has_sum_energy_below(Event& _event)
{
    if( minEnergy == 0 &&  maxEnergy == 0 )
    {
        std::cout << "ENERGY FILTER WAS NOT INITIALZED! PLEASE INITIALIZE EMIN AND EMAX!" << std:endl;
        return true;
    }

    if( _event.get_event_total_energy() <  maxEnergy)
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
    return true; // FIX THIS! 
}

bool Filters::event_has_two_associated_calo_hits(Event& _event)
{
    if ( event_has_two_particles(_event) )
    {
        for (auto& particle : _event.get_particles())
        {
            if ( particle.get_associated_calo_hits_number() > 1 )  // if there are multiple calohits associated with single PTD entry: fail
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

void Filters::set_min_energy_filter(double _minEnergy)
{
    minEnergy = _minEnergy;
}

void Filters::set_max_energy_filter(double _maxEnergy)
{
    maxEnergy = _maxEnergy;
}

bool Filters::event_passed_filters(Event& _event) {
    for (auto& filter_passed : filters) 
    {
        if (!filter_passed(_event)) 
        {
            return false;
        }
    }
    return true;
}

