
# echo "                                          "
# echo "Please enter the full path to *FALAISE* include files:"
# read FAL_INC
# echo "                                          "


rm -rf build lib ./src/dicts/ CDFiltered.brio 
mkdir  build lib

echo "#############################################"
echo "#         GENERATE ROOT DICTIONARIES        #"
echo "#############################################"
echo " "

cd include
echo "rootcint: ./include/Event.hh         -> ./lib/Eventdict_rdict.pcm         + ./src/dicts/Eventdict.cpp"
      	      rootcint -f ../lib/Eventdict.cpp          Event.hh+
echo "rootcint: ./include/Particle.hh         -> ./lib/Particledict_rdict.pcm         + ./src/dicts/Particledict.cpp"
      	      rootcint -f ../lib/Particledict.cpp          Particle.hh+
echo "rootcint: ./include/Filters.hh         -> ./lib/Filtersdict_rdict.pcm         + ./src/dicts/Filtersdict.cpp"
      	      rootcint -f ../lib/Filtersdict.cpp          Filters.hh+
echo "rootcint: ./include/CDBank.hh         -> ./lib/CDBankdict_rdict.pcm         + ./src/dicts/CDBankdict.cpp"
      	      rootcint -f ../lib/CDBankdict.cpp          CDBank.hh+
echo "rootcint: ./include/CDHit.hh         -> ./lib/CDHitdict_rdict.pcm         + ./src/dicts/CDHitdict.cpp"
      	      rootcint -f ../lib/CDHitdict.cpp          CDHit.hh+
echo "rootcint: ./include/Constants.hh         -> ./lib/Constantsdict_rdict.pcm"
			  rootcint -f ../lib/Constantsdict.cpp          Constants.hh+

echo " "
echo "Dictionaries generated!"
echo " "
	cd ..

	cp -R ./lib/ ./src/dicts/
	rm -rf ./lib/*.cpp
	rm -rf ./src/dicts/*.pcm

echo "#############################################"
echo "#         STARTING CMAKE                    #"
echo "#############################################"
echo " "

cd build

	# cmake -DCMAKE_PREFIX_PATH=$FAL_INC ..
	cmake -DCMAKE_PREFIX_PATH=/sps/nemo/sw/snsw/2023/opt/falaise-5.1.0/include/ ..
	# cmake -DCMAKE_PREFIX_PATH=/sps/nemo/sw/Falaise/tests/install_244/include/ ..
	make

cd ../
	
	flreconstruct -i ../CDFal5.brio -p build/SNCutsPipeline.conf -o CDFiltered.brio

