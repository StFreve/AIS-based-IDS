all:
	cd AIS && make
	cd IDS && make
	cd Server && make

clean:
	cd AIS && make clean
	cd IDS && make clean
	cd Server && make clean

test:
	./bin/Server