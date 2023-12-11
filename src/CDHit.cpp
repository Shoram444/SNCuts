#include "CDHit.hh"


ClassImp(CDHit);


CDHit::CDHit()
{
}

CDHit::~CDHit()
{
}

void    CDHit::set_energy(double _energy)
{
    energy = _energy;
}

double 	CDHit::get_energy()
{
    return energy;
}    