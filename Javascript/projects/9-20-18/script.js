var spaces = "&nbsp; &nbsp; &nbsp; &nbsp;";

function toDecibels(val) {
    return 20 * Math.log10(val);
}

function pOf2(val) {
    return Math.pow(2,val);
}

function powersOf2() {
    
    for(var ndx=0;ndx<=32;ndx++) {
        document.write(ndx + spaces + Math.pow(2,ndx) + spaces + toDecibels(Math.pow(2,ndx)) + "<br>");
    }
}


function powersOf2T() {
    // Set up table
    document.write("<table>" + "<br>");
    document.write("<tr style='background-color: #cecece'>" + "<td>Index</td>" + "<td>Powers</td>" + "<td>dB</td>" + "</tr>");
    for(var ndx=0;ndx<=32;ndx++) {
        document.write("<tr><td>" + ndx + "<td>" + pOf2(ndx) + "</td>" + "<td>" + toDecibels(pOf2(ndx)) + "</td>" + "</td></tr>");
    }
    document.write("</table>" + "<br>");

    
}