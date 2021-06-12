#!/bin/bash

# ./ProjectBase infilename outfilename channels algorithm value 1 value 2
# ./MixProject infilename1 infilename2 outflename offset gain

# Reduce the gain for salt-n-peppa_bigshot_ex.wav to 35%
./ProjectBase2 salt_n_pepa_bigshot_ex.wav bigshot0_25gain.wav 2 1 0.35

# Add a fadein for bigshot0_25gain,wav of 10 secs
./ProjectBase2/ bigshot0_25gain.wav bigshot-gainfade.wav 2 4 10

# Add a fadeout for bigshot0_25gain.wav of 8 secs
./ProjectBase2 bigshot_gainfade.wav bigshot_gainfade2.wav 2 5 8

# Add a fadeout to riverdance_ex.wav of 4 secs
./ProjectBase2 riverdance_ex.wav riverdancefadeOut.wav 2 5 4

# Mix riverdancefadeOut.wav and bigshot_gainfade.wav to yield strange_mix.wav 8 1.0
./MixProject riverdancefadeOut.wav bigshot gainfade2.wav strangemix.wav 8 1.0