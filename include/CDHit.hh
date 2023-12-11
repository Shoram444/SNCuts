#ifndef CDHIT_HH
#define CDHIT_HH

// ROOT headers
#include "TObject.h"

// Standard headers
#include "iostream"


using namespace std;


class CDHit: public TObject
{
    public: 
        //! constructor
		CDHit();

		//! desctructor
		~CDHit();

		void    set_energy(double _energy);

        double 	get_energy();    					

	private:
		double energy = 0.0;

    
	ClassDef(CDHit,1);
};

#endif // CDHIT_HH