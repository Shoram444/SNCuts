#include "Particle.hh"

ClassImp(Particle);


Particle::Particle()
{
}

Particle::~Particle()
{
}

void    Particle::set_charge(int charge)
{
    charge = charge;
}
void    Particle::set_energy(double energy)
{
    energy = energy;
}

int     Particle::get_charge()
{
    return charge;
}
double  Particle::get_energy()
{
    return energy;
}
