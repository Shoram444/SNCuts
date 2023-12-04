#include "Particle.hh"

ClassImp(Particle);


Particle::Particle()
{
}

Particle::~Particle()
{
}

void    Particle::set_charge(int _charge)
{
    charge = _charge;
}
void    Particle::set_energy(double _energy)
{
    energy = _energy;
}

int     Particle::get_charge()
{
    return charge;
}
double  Particle::get_energy()
{
    return energy;
}


void        Particle::set_foil_vertex_position(double _X, double _Y, double _Z)
{
    foilVertexPosition.SetXYZ(_X, _Y, _Z);
}

void        Particle::set_calo_vertex_position(double _X, double _Y, double _Z)
{
    caloVertexPosition.SetXYZ(_X, _Y, _Z);
}

TVector3    Particle::get_foil_vertex_position()
{
    return foilVertexPosition;
}

TVector3    Particle::get_calo_vertex_position()
{
    return caloVertexPosition;
}
