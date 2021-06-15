function dft(x) {
    var N = x.length;
    var X = new Array(x.length*2);
    var pi2overN = 8.0*Math.atan(1.0)/N;
    document.write("Begin DFT calculations" + "<br>");

    for(var k=0;k<N;k++) {
        X[k*2] = X[k*2+1] = 0.0;
        for(var n=0;n<N;n++) {
            X[k*2]+=x[n]*Math.cos(pi2overN*k*n);
            X[k*2+1]-=x[n]*Math.sin(pi2overN*k*n);
        }
        X[k*2]/=N;
        X[k*2+1]/=N;
    }
    return X;
}

function idft(X) {
    var N = X.length/2;
    var x = new Array(N);
    var pi2overN = 8.0*Math.atan(1.0)/N;
    var imag;

    for(var n=0;n<N;n++) {
        imag=x[n]=0.0;

        for(var k=0;k<N;k++) {
            x[n]+=X[k*2]*Math.cos(pi2overN*k*n) -
            X[k*2+1]*Math.sin(pi2overN*k*n);
            imag+=X[k*2]*Math.sin(pi2overN*k*n) +
            X[k*2+1]*Math.cos(pi2overN*k*n);
        }
        if (Math.abs(imag)>1.e-5) {
            document.write("warning: nonzero imaginary value in waveform" + " " + imag + "<br>")
        }
    }
    return x;
}