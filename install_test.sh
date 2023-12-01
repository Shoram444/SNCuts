rm -rf build lib ./src/dicts/
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

	cmake -DCMAKE_PREFIX_PATH=/sps/nemo/sw/Falaise/tests/install_244/include/ ..
	make

cd ../
	
	flreconstruct -i CD.brio -p SNCutsPipeline.conf -o CD.brio

