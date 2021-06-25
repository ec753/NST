This directory contains files used to translate the raw swc file from the
L-NEURON database to a NEURON session file.

1) the c91662.txtd.swc file was downloaded from L-NEURON
2) a c.dat file was constructed from (1) by removing the comments and
empty lines at the end.
3) c.dat was edited to have the type 10 traces removed with the
program remove10s.m (octave or matlab) which needs delrow.m
4) see also comments in the cell.swc file which explains how was read into
NEURON.
