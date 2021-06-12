// generate a changing phase value and sine of that phase

function genSine(numPts) {
    for(var ndx=0;ndx<numPts;ndx++){
        document.write("<tr><td>" + ndx + "</td><td>" + (ndx * Math.PI * 2 / numPts) + "</td><td>" + (Math.sin(ndx * 2 * Math.PI / numPts)) + "</td></tr>");
    }
}