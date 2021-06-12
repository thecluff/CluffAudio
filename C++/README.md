<br />
<p align="center">
    <img src="https://puredata.info/logo.jpg" alt="Logo" width="80" height="50" width="80">

  <h3 align="center">PureData Synthesis Patches</h3>

  <p align="center">
    Created by Charlie Cluff
  </p>
</p>

## Sound Synthesis Intro (Written Fall 2014)

Sound synthesis, especially in electronic music, has fascinated me since a very young age. From listening to the Moog synthesizer in The Beatles' music as a kid, to the intensely modulated sounds of Dubstep from the 2010's, I was always blown away by the vast possibilities one could create with a synthesizer. Sound Synthesis, which is the generation and modulation of waveforms. Accounting for amplitude, frequency, and phase, sound synthesis involves a high number of different factors that can drastically change the resulting sound.

There are many different types of synthesis, including Additive, Subtractive, Wavetable, Frequency Modulation, and Amplitude Modulation. By using these techniques, we are able to generate an infinitely large range of different sounds. Each technique results in a different timbre, giving musicians techniques for achieving very specific sounds. 

Prior to building virtual instruments, the only programming experience I had was very minimal and text based. After using Pure Data, I became a lot more confident in my programing abilities, and also my ability to interpret sounds in music. I had always assumed that synthesizing sounds from scratch would entail copious amounts of line by line programming. Pure Data showed me that this was not the case. Just like every other programming language, the number of different possibilities are endless. Each week of learning Pure Data opened new worlds of creativity for me.

With many stressful object-oriented programming memories behind me, I was skeptical of how easily I would learn Pure Data. In the past, learning programming languages proved to be extremely difficult for me. This wasn't the case with Pure Data. Due to Pure Data's visual approach, I quickly learned the basics of creating patches in the UI, and was making sounds not long after.

When dealing with Subtractive synthesis, the process is comparable to carving a statue. You start with a block of material, and carve away at it, leaving a pleasant statue to look at.  In this case, the material we're using is harmonic rich noise. By removing certain partials in the waveform, we're able to "carve away" unwanted frequencies, leaving a pleasing sound. The trouble I found with this technique is that it can take some time to attain decent sounding parameters. Since Subtractive Synthesis begins with noise, it can make the synthesis process a little tedious.

Additive Synthesis, however, is a different story. Right off the bat, an additive patch generally sounds pleasing to the ear. Since Additive Synthesis is based purely on Sine waves due to the Fourier principle, the resulting sounds created rarely sound jarring, which can happen easily with Subtractive Synthesis.

Out of all the various methods of synthesis, Wavetable Synthesis is probably the most precise technique. In Wavetable synthesis, the waveform partials are stored in a table, which can be mathematically calculated to produce a desired timbre. One downfall to this method is that once your values are saved into a table, it's hard to fluidly change the values of the partials during performances.
