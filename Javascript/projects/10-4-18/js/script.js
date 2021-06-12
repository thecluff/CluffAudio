// Basic WebAudio playback code 
// This script creates an audio context which is just an event space for generating, connecting and playing
// audio streams.

// This will also open an audio file, import its audio samples, and route them to a playback buffer which connects
// to the audio out of the system

var audioCtx = new (window.AudioContext || window.webkitAudioContext ) ();
// The webAudio API contains a number of nodes, that implement audio functionality, such as gain
var gainNode = audioCtx.createGain();
// The source is where the audio buffer that contains the signal samples is stored
var source;
// We will use isPlaying as a boolean value so that we can toggle the sound on and off
var isPlaying = false;


function getSignal(fn) {
    // An audio context is an object that contains audio related functions and data types
    source = audioCtx.createBufferSource();
    // 'request' has to do with opening and extracting the audio samples from an audio file
    var request = new XMLHttpRequest();
        // Post a request to open a file, designated by 'fn'
    request.open('GET', fn, true); 
    // Fulfill the request by filling an array buffer with samples
    request.responseType = 'arraybuffer';
    // The next step employs an anonymous function (sometimes called a "lamda")
    request.onload = function() {
        audioCtx.decodeAudioData(request.response, function(buffer) {
            source.buffer = buffer;
            source.connect(gainNode);
            gainNode.connect(audioCtx.destination);
        },
        function(e) {"Error with decoding audio data" + e.err});
        
        gainNode.gain.value = 1.0;
    }
    request.send();
}



// This function responds to button clicks and will take an audio filename along with the HTML ID for the button, and
// either start or stop the audio depending on the state of 'isPlaying'
function startAudio(fn,id) {
    if(!isPlaying) {
        document.getElementById(id).innerHTML = "Stop!";
        getSignal(fn); 
        source.start(0)
    }else{
        document.getElementById(id).innerHTML = "Listen!";
        source.stop(0);
    }
    isPlaying = !isPlaying;
    
}











