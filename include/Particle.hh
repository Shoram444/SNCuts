#ifndef PARTICLE_HH
#define PARTICLE_HH

// ROOT headers
#include "TObject.h"

// Standard headers
#include "iostream"

using namespace std;

struct VertexPosition
{
    double x;
    double y;
    double z;
};

class Particle: public TObject
{
    public: 
        //! constructor
		Particle();

		//! desctructor
		~Particle();

		void    set_charge(int charge);
		void    set_energy(double energy);

        int     get_charge();
        double  get_energy();

	private:
		int     charge;
		double  energy;
    
    
	ClassDef(Particle,1);
};

#endif // PARTICLE_HH