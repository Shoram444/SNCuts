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
		void    set_associated_calo_hits_number(int _associatedCaloHitsNo);
		void    set_energy(double _energy);
		void    set_foil_vertex_position(double _X, double _Y, double _Z);
		void    set_calo_vertex_position(double _X, double _Y, double _Z);
		bool 	has_foil_vertex();
		bool 	has_calo_vertex();

        int     	get_charge();
        int 		get_associated_calo_hits_number();    					// get the number of calo hits per PTD entry (this may not be 1)
        double 		get_energy();
		TVector3    get_foil_vertex_position();
		TVector3    get_calo_vertex_position();

	private:
		int     charge;
		int 	associatedCaloHitsNo = 0;
		double  energy = 0;

		bool hasFoilVertex = false;
		bool hasCaloVertex = false;

		TVector3 foilVertexPosition;
		TVector3 caloVertexPosition;
    
    
	ClassDef(Particle,1);
};

#endif // PARTICLE_HH