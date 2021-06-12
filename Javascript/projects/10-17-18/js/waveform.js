var xVal = [];
var yVal = [];
var freq = [];
var amp = [];
var phase = [];
var length = 128;
var numHarms = 25;
var showPhase = [];


function calcSaw(nh) {
    // numHarms = nh;
    for(var n=0;n<=nh;n++) {
        freq[n] = n+1;
        amp[n] = 1/freq[n];
        phase[n] = 0.0;
    }
}


function genCmplx() {
    var omega = Math.PI * 2 / length;
    calcSaw(numHarms);
    for(var ndx=0;ndx<length;ndx++) {
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
}