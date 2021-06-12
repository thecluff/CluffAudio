#!/bin/bash                                                             

echo "                                                 "
echo "   ,___     ,___ _                               "
echo "  /   /    /   ///     /) /)                     "
echo " /        /    // , , // //                      "
echo "(___/o   (___/(/_(_/_//_//_                      "
echo "                    /) /)                        "
echo "                   (/ (/                         "
echo " ______              _   _ __                    "
echo "(  /  o             //  ( /  )        o       _/_"
echo " -/--,  _ _   __,  //    /--'_   __  ,  _  _, /  "
echo "_/   (_/ / /_(_/(_(/_   /   / (_(_)_/|_(/_(__(__ "
echo "                                    /)           "
echo "                                   (/            "
echo "                                                 "
echo "          Charlie Cluff - Final Project          "
echo "      DAT150CA - Beginning Audio Programming     "
echo "                                                 "


#   Create directories                               

mkdir ./audio/
mkdir ./audio/chords2/
mkdir ./audio/chords2/chord1/
mkdir ./audio/chords2/chord2/
mkdir ./audio/chords2/chord3/
mkdir ./audio/chords2/chord4/
mkdir ./audio/chords2/chord5/
mkdir ./audio/chords2/chords2final/
mkdir ./audio/chords2/mix_chords/


#   Mix all pureData-generated tones together into chords                               

#   Chord 1
./MixProject ./raw/pd/chord1Tone01.wav ./raw/pd/chord1Tone02.wav ./audio/chords2/chord1/chord1_3.wav 0 1.0
./MixProject ./raw/pd/chord1Tone03.wav ./raw/pd/chord1Tone04.wav ./audio/chords2/chord1/chord2_3a.wav 0 1.0
./MixProject ./raw/pd/chord1Tone05.wav ./raw/pd/chord1Tone06.wav ./audio/chords2/chord1/chord2_3b.wav 0 1.0

./MixProject ./audio/chords2/chord1/chord1_3.wav ./audio/chords2/chord1/chord2_3a.wav ./audio/chords2/chord1/chord3_3a.wav 0 1.0
./MixProject ./audio/chords2/chord1/chord2_3b.wav ./audio/chords2/chord1/chord3_3a.wav ./audio/chords2/chord1/chord1_prefade.wav 0 1.0

#   Add a fade in to the chord for 1 sec
./FinalProject2 ./audio/chords2/chord1/chord1_prefade.wav ./audio/chords2/chord1/chord1_fadein.wav 1 4 1.0

#   Add a fadeout for 1 sec
./FinalProject2 ./audio/chords2/chord1/chord1_fadein.wav ./audio/chords2/chords2final/chord1_final.wav 1 5 1.0

echo "Chord 1 created."

#   Chord 2
./MixProject ./raw/pd/chord2Tone01.wav ./raw/pd/chord2Tone02.wav ./audio/chords2/chord2/chord1_3.wav 0 1.0
./MixProject ./raw/pd/chord2Tone03.wav ./raw/pd/chord2Tone04.wav ./audio/chords2/chord2/chord2_3a.wav 0 1.0
./MixProject ./raw/pd/chord2Tone05.wav ./raw/pd/chord2Tone06.wav ./audio/chords2/chord2/chord2_3b.wav 0 1.0

./MixProject ./audio/chords2/chord2/chord1_3.wav ./audio/chords2/chord2/chord2_3a.wav ./audio/chords2/chord2/chord3_3a.wav 0 1.0
./MixProject ./audio/chords2/chord2/chord2_3b.wav ./audio/chords2/chord2/chord3_3a.wav ./audio/chords2/chord2/chord2_prefade.wav 0 1.0

#   Add a fade in to the chord for 1 sec
./FinalProject2 ./audio/chords2/chord2/chord2_prefade.wav ./audio/chords2/chord2/chord2_fadein.wav 1 4 1.0

#   Add a fadeout for 1 sec
./FinalProject2 ./audio/chords2/chord2/chord2_fadein.wav ./audio/chords2/chords2final/chord2_final.wav 1 5 1.0

echo "Chord 2 created."

#   Chord 3
./MixProject ./raw/pd/chord3Tone01.wav ./raw/pd/chord3Tone02.wav ./audio/chords2/chord3/chord1_3.wav 0 1.0
./MixProject ./raw/pd/chord3Tone03.wav ./raw/pd/chord3Tone04.wav ./audio/chords2/chord3/chord2_3a.wav 0 1.0

./MixProject ./audio/chords2/chord3/chord1_3.wav ./audio/chords2/chord3/chord2_3a.wav ./audio/chords2/chord3/chord3_3a.wav 0 1.0
./MixProject ./raw/pd/chord3Tone05.wav ./audio/chords2/chord3/chord3_3a.wav ./audio/chords2/chord3/chord3_prefade.wav 0 1.0

#   Add a fade in to the chord for 1 sec
./FinalProject2 ./audio/chords2/chord3/chord3_prefade.wav ./audio/chords2/chord3/chord3_fadein.wav 1 4 1.0

#   Add a fadeout for 1 sec
./FinalProject2 ./audio/chords2/chord3/chord3_fadein.wav ./audio/chords2/chords2final/chord3_final.wav 1 5 1.0

echo "Chord 3 created."

#   Chord 4
./MixProject ./raw/pd/chord4Tone01.wav ./raw/pd/chord4Tone02.wav ./audio/chords2/chord4/chord1_3.wav 0 1.0
./MixProject ./raw/pd/chord4Tone03.wav ./raw/pd/chord4Tone04.wav ./audio/chords2/chord4/chord2_3a.wav 0 1.0

./MixProject ./audio/chords2/chord4/chord1_3.wav ./audio/chords2/chord4/chord2_3a.wav ./audio/chords2/chord4/chord3_3a.wav 0 1.0
./MixProject ./raw/pd/chord4Tone05.wav ./audio/chords2/chord4/chord3_3a.wav ./audio/chords2/chord4/chord4_prefade.wav 0 1.0

#   Add a fade in to the chord for 1 sec
./FinalProject2 ./audio/chords2/chord4/chord4_prefade.wav ./audio/chords2/chord4/chord4_fadein.wav 1 4 1.0

#   Add a fadeout for 1 sec
./FinalProject2 ./audio/chords2/chord4/chord4_fadein.wav ./audio/chords2/chords2final/chord4_final.wav 1 5 1.0

echo "Chord 4 created."

#   Chord 5
./MixProject ./raw/pd/chord5Tone01.wav ./raw/pd/chord5Tone02.wav ./audio/chords2/chord5/chord1_3.wav 0 1.0
./MixProject ./raw/pd/chord5Tone03.wav ./raw/pd/chord5Tone04.wav ./audio/chords2/chord5/chord2_3a.wav 0 1.0
./MixProject ./raw/pd/chord5Tone05.wav ./raw/pd/chord5Tone06.wav ./audio/chords2/chord5/chord2_3b.wav 0 1.0

./MixProject ./audio/chords2/chord5/chord1_3.wav ./audio/chords2/chord5/chord2_3a.wav ./audio/chords2/chord5/chord3_3a.wav 0 1.0
./MixProject ./audio/chords2/chord5/chord2_3b.wav ./audio/chords2/chord5/chord3_3a.wav ./audio/chords2/chord5/chord5_prefade.wav 0 1.0

#   Add a fade in to the chord for 1 sec
./FinalProject2 ./audio/chords2/chord5/chord5_prefade.wav ./audio/chords2/chord5/chord5_fadein.wav 1 4 1.0

#   Add a fadeout for 1.5 sec
./FinalProject2 ./audio/chords2/chord5/chord5_fadein.wav ./audio/chords2/chords2final/chord5_final.wav 1 5 1.5

echo "Chord 5 created."


#   Combine all other elements                                 

#   Mix chords together from monophonic audio files
./MixProject ./audio/chords2/chords2final/chord1_final.wav ./audio/chords2/chords2final/chord2_final.wav ./audio/chords2/mix_chords/chordmix1.wav 2.61 1.0
./MixProject ./audio/chords2/chords2final/chord3_final.wav ./audio/chords2/chords2final/chord4_final.wav ./audio/chords2/mix_chords/chordmix2.wav 2.61 1.0
./MixProject ./audio/chords2/chords2final/chord1_final.wav ./audio/chords2/chords2final/chord2_final.wav ./audio/chords2/mix_chords/chordmix3.wav 2.61 1.0
./MixProject ./audio/chords2/chords2final/chord5_final.wav ./audio/chords2/chords2final/chord1_final.wav ./audio/chords2/mix_chords/chordmix4.wav 2.61 1.0

#   Combine each chord consecutively, in two different files
./MixProject ./audio/chords2/mix_chords/chordmix1.wav ./audio/chords2/mix_chords/chordmix2.wav ./audio/chords2/mix_chords/chordmix1a.wav 5.22 1.0
./MixProject ./audio/chords2/mix_chords/chordmix3.wav ./audio/chords2/mix_chords/chordmix4.wav ./audio/chords2/mix_chords/chordmix1b.wav 5.22 1.0

#   Combine the previous two files
./MixProject ./audio/chords2/mix_chords/chordmix1a.wav ./audio/chords2/mix_chords/chordmix1b.wav ./audio/chords2/mix_chords/chordmix1_final.wav 10.43 0.85

#   Rectify chords
./FinalProject2 ./audio/chords2/mix_chords/chordmix1_final.wav ./audio/chords2/mix_chords/chordmix1_final2.wav 1 3

#   Mix chords with percussion
./MixProject ./raw/other/drumsample1.wav ./raw/other/drumsample2.wav ./audio/drum_mix.wav 0 0.9
./MixProject ./audio/chords2/mix_chords/chordmix1_final2.wav ./audio/drum_mix.wav ./audio/mix_complete.wav 0 0.9


#   Step 6 - Finishing touches                                 

#   Double the complete mix
./MixProject ./audio/mix_complete.wav ./audio/mix_complete.wav ./audio/final_mix_double.wav 20.869569 1.0

#   Add rap vocals
./MixProject ./audio/final_mix_double.wav ./raw/other/acapella.wav ./audio/final_mix_vox.wav 20.869569 1.0

#   Final Bounce

#   Process other stems
./FinalProject2 ./raw/other/pads.wav ./audio/pads_2.wav 1 10 1 3
./FinalProject2 ./audio/pads_2.wav ./audio/pads_3.wav 2 1 0.7


./MixProject ./audio/final_mix_vox.wav ./audio/pads_3.wav ./audio/ccluff_final_project_mono.wav 20.869569 1.0

echo "Chords and percussion mixed."

#   Make Stereo
./MonoToStereo ./audio/ccluff_final_project_mono.wav ./ccluff_final_project.wav

echo "Converted to Stereo."


#   Clean up files                                                   

rm -r ./audio/

echo "Song is now complete!"

while true; do
    read -p "Do you want to open the song now? (y or n) " yn
    case $yn in
        [Yy]* ) open ccluff_final_project.wav; break;;
        [Nn]* ) exit;;
        * ) echo "Please answer yes or no.";;
    esac
done