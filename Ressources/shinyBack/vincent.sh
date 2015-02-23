#!/bin/bash

a=1

while [ $a -lt 722 ]
do

curl -O "http://www.pokemontrash.com/pokedex/images/x-y5g/back/shiny/"$a".png"

a=$(($a + 1))

done
