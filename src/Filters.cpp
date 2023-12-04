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
    if ( _event.get_particles().size() != 0 )
    {
        return true;
    }
    return false;
}

bool Filters::event_has_two_particles(Event& _event)
{
    if (_event.get_particles().size() != 2)
    {
        return false;
    }

    return true;
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