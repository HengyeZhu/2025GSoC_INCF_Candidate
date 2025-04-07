import pyneuroml.pynml
from pyneuroml.plot.PlotMorphology import plot_2D

nml2_file = "L1_DAC_bNAC219_1_cell.nml"

pyneuroml.pynml.nml2_to_png(nml2_file)

plot_2D(nml2_file)