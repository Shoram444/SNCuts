#include "Particle.hh"

ClassImp(Particle);


Particle::Particle()
{
}

Particle::~Particle()
{
}

void        Particle::set_charge(int _charge)
{
    charge = _charge;
}
void        Particle::set_energy(double _energy)
{
    energy = _energy;
}

int         Particle::get_charge()
{
    return charge;
}
double      Particle::get_energy()
{
    return energy;
}

double 		Particle::get_energy_MeV()
{
    return energy / 1000; // originally energy is stored in keV in ::Particle
}

double 		Particle::get_track_length()
{
    return trackLength;
}


void    Particle::set_track_length(double _trackLength)
{
    trackLength = _trackLength;
}



void        Particle::set_foil_vertex_position(double _X, double _Y, double _Z)
{
    hasFoilVertex = true;
    foilVertexPosition.SetXYZ(_X, _Y, _Z);
}

void        Particle::set_calo_vertex_position(double _X, double _Y, double _Z)
{
    hasCaloVertex = true;
    caloVertexPosition.SetXYZ(_X, _Y, _Z);
}

bool 	    Particle::has_foil_vertex()
{
    return hasFoilVertex;
}
bool 	Particle::has_calo_vertex()
{
    return hasCaloVertex;
}

void        Particle::set_associated_calo_hits_number(int _associatedCaloHitsNo)
{
    associatedCaloHitsNo = _associatedCaloHitsNo;
}

int 		Particle::get_associated_calo_hits_number()
{
    return associatedCaloHitsNo;
}

TVector3    Particle::get_foil_vertex_position()
{
    return foilVertexPosition;
}

TVector3    Particle::get_calo_vertex_position()
{
    return caloVertexPosition;
}
