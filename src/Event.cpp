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
    // eventNumber = -10000;
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


void Event::print()
{
    cout << "Event Number: " << eventNumber << endl;

    for (int i = 0; i < particles.size(); i++)
    {
        cout << "-----------------" << endl;
        cout << "Particle number: " << i                            << endl;
        cout << "Particle Charge: " << particles.at(i).get_charge() << endl;
        cout << "Particle Energy: " << particles.at(i).get_energy() << endl;

        cout << "Foil Vertex Position: (" 
                <<          particles.at(i).get_foil_vertex_position().X()
                << ", " <<  particles.at(i).get_foil_vertex_position().Y()
                << ", " <<  particles.at(i).get_foil_vertex_position().Z() 
            << ")" << endl;

        cout << "Calo Vertex Position: (" 
                <<          particles.at(i).get_calo_vertex_position().X()
                << ", " <<  particles.at(i).get_calo_vertex_position().Y()
                << ", " <<  particles.at(i).get_calo_vertex_position().Z() 
            << ")" << endl;
        cout << "-----------------" << endl;
    }
}