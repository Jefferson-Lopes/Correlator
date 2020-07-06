# Correlation
In general, correlation describes the mutual relationship which exists between two or more things. The same definition holds good even in the case of signals. That is, correlation between signals indicates the measure up to which the given signal resembles another signal. 

Depending on whether the signals considered for correlation are same or different, we have two kinds of correlation: autocorrelation and cross-correlation.

## Autocorrelation
This is a type of correlation in which the given signal is correlated with itself, usually the time-shifted version of itself. Mathematical expression for the autocorrelation of continuous time signal x (t) is given by

![](https://latex.codecogs.com/gif.latex?Rxx%28%5Ctau%20%29%20%3D%20%5Cint_%7B-%5Cinfty%20%7D%5E%7B%5Cinfty%20%7D%20x%28t%29x%5E*%28t%20-%20%5Ctau%20%29dt)

where * denotes the complex conjugate.

Similarly the autocorrelation of the discrete time signal x[n] is expressed as

![](https://latex.codecogs.com/gif.latex?Rxx%5Bm%5D%20%3D%20%5Csum_%7Bn%3D-%5Cinfty%7D%5E%7B%5Cinfty%7Dx%5Bn%5Dx%5E*%5Bn-m%5D)

Learn more about this project, [click here](https://github.com/Jefferson-Lopes/FPGA/tree/master/Correlation/Autocorrelation)

## Cross-Correlation
This is a kind of correlation, in which the signal in-hand is correlated with another signal so as to know how much resemblance exists between them. Mathematical expression for the cross-correlation of continuous time signals x (t) and y (t) is given by

![](https://latex.codecogs.com/gif.latex?Rxy%28%5Ctau%29%3D%5Cint_%7B-%5Cinfty%7D%5E%7B%5Cinfty%7Dx%28t%29y%5E*%28t-%5Ctau%29dt)

Similarly, the cross-correlation of the discrete time signals x [n] and y [n] is expressed as

![](https://latex.codecogs.com/gif.latex?Rxy%5Bm%5D%20%3D%20%5Csum_%7Bn%3D-%5Cinfty%7D%5E%7B%5Cinfty%7Dx%5Bn%5Dy%5E*%5Bn-m%5D)

Learn more about this project, [click here](https://github.com/Jefferson-Lopes/FPGA/tree/master/Correlation/Cross_correlation)

## Contact me
[![](Output_files/gmail.png)](mailto:jefferson.lopes@ee.ufcg.edu.br?subject=[GitHub]%20FPGA%20-%20correlation) ![](Output_files/separador.png) [![](Output_files/insta.png)](https://instagram.com/jeff.777.lopes?igshid=1i5gr7ch0bvkd)
