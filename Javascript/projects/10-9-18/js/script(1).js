// Generate Tone and play with WebAudio
// Basic WebAudio playback code 
// This script creates an audio context which is just an event space for generating, connecting and playing
// audio streams.

// This will also open an audio file, import its audio samples, and route them to a playback buffer which connects
// to the audio out of the system

// We need to set up our tone generator

var audioCtx = new (window.AudioContext || window.webkitAudioContext) ();

var freqs = [];
var amps = [];
var phs = [];
var numHarms = 15;
// The audio context is initiated with a default sample rate of 44.1
var omega = 2 * Math.PI / audioCtx.sampleRate;
// These are all new considerations
var fundFreq = 432;
var gainLevel = 1.0;
var numChans = 2;
var dur = 2.0;

xVal = [];
yVal = [];


// We must create an audio buffer (ie an array) that has sufficient length for a two channel audio signal of some duration(specified by the variable 'dur') and having a sample rate.

var numSamps = dur * audioCtx.sampleRate * 2;

// A single channel buffer will have one half of the length of a two channel buffer
var singChanSamps = Math.floor(numSamps / 2);



// The webAudio API contains a number of nodes, that implement audio functionality, such as gain
var gainNode = audioCtx.createGain();
// The source is where the audio buffer that contains the signal samples is stored
var source;
var myArrayBuffer = audioCtx.createBuffer(numChans, numSamps, audioCtx.sampleRate);

// We will use isPlaying as a boolean value so that we can toggle the sound on and off
var isPlaying = false;


// ***************************************** Functions ***

function calcSaw(nh) {
  for(var n=0;n<nh;n++){
    freqs[n] = n+1;
    amps[n] = 1/freqs[n];
    phs[n] = 0.0;
  }
}

function genCmplx() {
  calcSaw(numHarms);
  for(var ndx=0;ndx<singChanSamps;ndx++){
    xVal[ndx] = ndx;
    yVal[ndx] = 0.0;
    // showPhase[ndx] = omega * ndx;
    for(var harm=0;harm<numHarms;harm++) {
      yVal[ndx] = yVal[ndx] + (amps[harm] * Math.sin(fundFreq*omega*freqs[harm]*ndx + phs[harm])); 

    }
  }
}

function monoToStereo() {
  for (var channel = 0; channel < numChans; channel++) {
    var nowBuffering = myArrayBuffer.getChannelData(channel);
    for (var i = 0; i < singChanSamps; i++) {
      nowBuffering[i] = yVal[i];
    }
  }
}

function getSignal(fn) {
  source = audioCtx.createBufferSource();
  source.buffer = myArrayBuffer;
  source.connect(gainNode);
  gainNode.connect(audioCtx.destination);

}

// This function responds to button clicks and will take an audio filename along with the HTML ID for the button, and
// either start or stop the audio depending on the state of 'isPlaying'
function startAudio(fn,id) {
  if(!isPlaying) {
    document.getElementById(id).innerHTML = "Stop!";
    calcSaw(50);
    genCmplx();
    monoToStereo();
    getSignal(fn); 
    source.start(0);
  }else{
    document.getElementById(id).innerHTML = "Listen!";
    source.stop(0);
  }
  isPlaying = !isPlaying;

}

function displayTable() {
    
    for(var ndx=0;ndx<length;ndx++) {
        document.write("<tr><td>" + xVal[ndx] + "</td><td>" + phs[ndx] + "</td><td>" + yVal[ndx] + "</td></tr>");
    }
    // document.write("<tr><td>" + "</td><td>" + "</td></tr>")
    
}