#include "Event.hh"


ClassImp(Event);


Event::Event()
{
}

Event::~Event()
{
    reset();
}

void Event::reset()
{
    eventTotalEnergy = -1.0; 
    particles.clear();
}

void Event::set_event_number(int _eventNumber)
{
    eventNumber = _eventNumber;
}

void Event::add_particle(Particle &_newParticle)
{
    particles.push_back(_newParticle);
}

std::vector<Particle> Event::get_particles()
{
    return particles;
}

void Event::set_event_total_energy(double _eventTotalEnergy)
{
    eventTotalEnergy = _eventTotalEnergy;
}
double Event::get_event_total_energy()
{
    return eventTotalEnergy;
}

void Event::print()
{
    cout << "Event Number: "        << eventNumber         << endl;
    cout << "Event Total Energy: "  << eventTotalEnergy    << endl;

    for (int i = 0; i < particles.size(); i++)
    {
        cout << "-------------------------------------------------------------------------------------------------" << endl;
        cout << "Particle: "                                << i+1<< "/"<<  particles.size()                        << endl;
        cout << "Particle number of associated caloHits: "  << particles.at(i).get_associated_calo_hits_number()    << endl;
        
        cout << "Particle Charge: "                         << particles.at(i).get_charge()                         << endl;
        cout << "Particle Energy: "                         << particles.at(i).get_energy()                         << endl;
        cout << "Particle has foil vertex: "                << particles.at(i).has_foil_vertex()                    << endl;
        cout << "Foil Vertex Position: (" 
                <<          particles.at(i).get_foil_vertex_position().X()
                << ", " <<  particles.at(i).get_foil_vertex_position().Y()
                << ", " <<  particles.at(i).get_foil_vertex_position().Z() 
            << ")" << endl;

        cout << "Particle has calo vertex: "                << particles.at(i).has_foil_vertex()                    << endl;
        cout << "Calo Vertex Position: (" 
                <<          particles.at(i).get_calo_vertex_position().X()
                << ", " <<  particles.at(i).get_calo_vertex_position().Y()
                << ", " <<  particles.at(i).get_calo_vertex_position().Z() 
            << ")" << endl;
        cout << "-------------------------------------------------------------------------------------------------" << endl;
    }
}