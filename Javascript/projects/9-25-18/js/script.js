// generate a changing phase value and sine of that phase

// xVal holds index values
// yVal holds sine values
var xVal = [];
var yVal = [];
var Phase = [];
var np;

function genSine(numPts) {
    var PI2OverNumPts = Math.PI * 2 / numPts;
    np = numPts;
    for(var ndx=0;ndx<numPts;ndx++){
        xVal[ndx] = ndx;
        yVal[ndx] = Math.sin(xVal[ndx] * PI2OverNumPts);
        Phase[ndx] = xVal[ndx] * PI2OverNumPts;
        
    }
}

function displayTable() {
    
    for(var ndx=0;ndx<np;ndx++) {
        document.write("<tr><td>" + xVal[ndx] + "</td><td>" + Phase[ndx] + "</td><td>" + yVal[ndx] + "</td></tr>");
    }
    // document.write("<tr><td>" + "</td><td>" + "</td></tr>")
    
}