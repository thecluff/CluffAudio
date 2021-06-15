var space = "&nbsp; &nbsp; &nbsp; &nbsp;"

function powersOf2(name) {
    for(var ndx=0;ndx<=32,ndx++) {
        document.write(ndx + spaces + Math.pow(2,ndx) + "<br />");
    }
}