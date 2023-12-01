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
    eventNumber = -10000;
    particles.clear();
}

void Event::set_event_number(int eventNumber)
{
    eventNumber = eventNumber;
}

void Event::add_particle(const Particle &newParticle)
{
    particles.push_back(newParticle);
}

void Event::print()
{
    cout << "Event Number: " << eventNumber << endl;

    for (int i = 0; i < particles.size(); i++)
    {
        cout << "Particle Charge: " << particles.at(i).get_charge() << endl;
        cout << "Particle Energy: " << particles.at(i).get_energy() << endl;

        // cout << "Foil Vertex Position: (" << particle.foilVertexPosition.x
        //           << ", " << particle.foilVertexPosition.y
        //           << ", " << particle.foilVertexPosition.z << ")" << endl;

        // cout << "Calo Vertex Position: (" << particle.caloVertexPosition.x
        //           << ", " << particle.caloVertexPosition.y
        //           << ", " << particle.caloVertexPosition.z << ")" << endl;

        cout << "-----------------" << endl;
    }
}