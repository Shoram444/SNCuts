This is a repository which implements a simple data-cuts Falaise module for the SUperNEMO experiment.

The module's main goal is to input a `.brio` file and *cut* data through a series of filters (for now I'm only implementing simple double beta decay topology filters, this may change in the future depending on collaboration's needs). The goal is to provide a *pure* `.brio` file with **only** the desired events inside!

The caveat is that the module must be placed in the pipeline **after** reconstruction is finished, since it pulls data from the `CDbank` and the `PTDbank`. (If these two are not provided in the `.brio` file, the module will do nothin.) 

To install the module, simple download this repository, edit the `-DCMAKE_PREFIX_PATH=PATH/TO/FALAISE/INCLUDE/` line and run `./install_test.sh` command. This will run the cmake and make commands and run a short test on a provided `CD.brio` file. 