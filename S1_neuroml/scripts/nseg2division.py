import xml.etree.ElementTree as ET

NAMESPACE = "http://www.neuroml.org/schema/neuroml2"

nseg_mapping = {}
with open("section_nseg_mapping.txt", "r") as file:
    for line in file:
        section, nseg = line.strip().split(": ")
        nseg_mapping[section] = nseg

nml_file = "L1_DAC_bNAC219_1_cell.nml" 
tree = ET.parse(nml_file)
root = tree.getroot()

for segment_group in root.findall(".//{{{}}}segmentGroup".format(NAMESPACE)):
    group_id = segment_group.get("id")
    if group_id in nseg_mapping:
        prop = ET.Element("{{{}}}property".format(NAMESPACE), tag="numberInternalDivisions", value=nseg_mapping[group_id])
        segment_group.insert(0, prop)  

ET.register_namespace("", NAMESPACE)
tree.write("L1_DAC_bNAC219_1_cell_try.nml", encoding="UTF-8", xml_declaration=True)