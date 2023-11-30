cd build
	rm -r *
	cmake -DCMAKE_PREFIX_PATH=/sps/nemo/sw/Falaise/tests/install_244/include/ ..
	make

cd ../
	
	flreconstruct -i CD.brio -p SNCutsPipeline.conf -o CD.brio

