function conv(xn,yn) {
    var zn = [];
    for(var n=0;n<xn.length+yn.length-1;n++) {
        zn[n] = 0.0;
    }
    for(var n1=0;n1<xn.length;n1++) {
        for(var n2=0;n2<yn.length;n2++) {
            zn[n2+n1] = zn[n2+n1] + xn[n1] * yn[n2];
        }
    }
    return zn;
}

function fillTable(xn) {
    document.write("<table>");
    for(var n=0;n<xn.length;n++) {
        document.write("<tr><td>" + xn[n] + "</td></tr>");
    }
    document.write("</table>");
}