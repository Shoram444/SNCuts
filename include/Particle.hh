#ifndef PARTICLE_HH
#define PARTICLE_HH

// ROOT headers
#include "TObject.h"
#include "TVector3.h"

// Standard headers
#include "iostream"

using namespace std;


class Particle: public TObject
{
    public: 
        //! constructor
		Particle();

		//! desctructor
		~Particle();

		void    set_charge(int _charge);
		void    set_energy(double _energy);
		void    set_foil_vertex_position(double _X, double _Y, double _Z);
		void    set_calo_vertex_position(double _X, double _Y, double _Z);


        int     	get_charge();
        double 		get_energy();
		TVector3    get_foil_vertex_position();
		TVector3    get_calo_vertex_position();

	private:
		int     charge;
		double  energy;

		TVector3 foilVertexPosition;
		TVector3 caloVertexPosition;
    
    
	ClassDef(Particle,1);
};

#endif // PARTICLE_HH