// generate a changing phase value and sine of that phase

// xVal holds index values
// yVal holds sine values
var xVal = [];
var yVal = [];
var freq = [1,2,3,4,5];
var amp = [1.0,0.5,0.33,0.25,0.2]; // these are the amplitudes of the harmonics
var phase = [0.0,0.0,0.0,0.0,0.0];
var length = 128;
var numHarms = 5;
var showPhase = [];

// A complex waveform requires two loops, an inner loop and an outer loop
// The outer loop will move through the sample sequence
// The inner loop will calculate harmonics 

// The addition of harmonics will require the yVal to be on both sides of the '='
// In other words. yVal[ndx] is assigned yVal[ndx] + ...



function genCmplx() {
    var omega = Math.PI * 2 / length;
    for(var ndx=0;ndx<length;ndx++){
        xVal[ndx] = ndx;
        yVal[ndx] = 0.0;
        showPhase[ndx] = omega * ndx;
        for(var harm=0;harm<numHarms;harm++) {
        
        yVal[ndx] = yVal[ndx] + (amp[harm] * Math.sin(freq[harm]*omega*ndx + phase[harm])); 
        
            
        }
        
        
    }
}

function displayTable() {
    
    for(var ndx=0;ndx<length;ndx++) {
        document.write("<tr><td>" + xVal[ndx] + "</td><td>" + showPhase[ndx] + "</td><td>" + yVal[ndx] + "</td></tr>");
    }
    // document.write("<tr><td>" + "</td><td>" + "</td></tr>")
    
}