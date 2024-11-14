#!/bin/sh

rm -rf maps
mkdir maps

for i in `seq 1 10`;
do
	./perl_map_generator 10 10 3 > maps/map$i;
done
