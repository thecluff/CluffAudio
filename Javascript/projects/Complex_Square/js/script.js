// generate a changing phase value and sine of that phase

// xVal holds index values
// yVal holds sine values
var xVal = [];
var yVal = [];
var freq = [];
var amp = []; // these are the amplitudes of the harmonics
var phase = [];
var length = 128;
var numHarms = 9;
var showPhase = [];


// Let JS do the work of calculating the harmonic amplitudes

// function calcSine(nh) {
//     for(var n=0;n<nh;n++){
//         freq[n] = n+1;
//         amp[n] = 1/freq[n];
//         phase[n] = 0.0;
//     }
// }

// function calcSaw(nh) {
//     for(var n=0;n<nh;n++){
//         freq[n] = n+1;
//         amp[n] = 1/freq[n];
//         phase[n] = 0.0;
//     }
// }


// function calcTri(nh) {
//     for(var n=0;n<nh;n++){
//         freq[n] = n+1;
//         amp[n] = 1/freq[n];
//         phase[n] = 0.0;
//     }
// }

function calcSquare(nh) {
    for(var n=0;n<nh;n+=2){
        freq[n] = n+1;
        amp[n] = 1/freq[n];
        phase[n] = 0.0;
    }
}

// A complex waveform requires two loops, an inner loop and an outer loop
// The outer loop will move through the sample sequence
// The inner loop will calculate harmonics 

// The addition of harmonics will require the yVal to be on both sides of the '='
// In other words. yVal[ndx] is assigned yVal[ndx] + ...

function genCmplx() {
    var omega = Math.PI * 2 / length;
    calcSquare(numHarms);
    for(var ndx=0;ndx<length;ndx++){
        xVal[ndx] = ndx;
        yVal[ndx] = 0.0;
        showPhase[ndx] = omega * ndx;
        for(var harm=0;harm<numHarms;harm+=2) {
        
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