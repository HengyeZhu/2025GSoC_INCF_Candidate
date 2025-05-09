import json

file_name = 'L1_DAC_bNAC219_1_cellParams.json'
with open(file_name, 'r') as file:
    data = json.load(file)

section_nseg_mapping = []

if 'secs' in data:
    for section, properties in data['secs'].items():
        nseg = properties['geom']['nseg']
        section_nseg_mapping.append((section, nseg))

output_file_name = 'section_nseg_mapping.txt'
with open(output_file_name, 'w') as output_file:
    for section, nseg in section_nseg_mapping:
        output_file.write(f"{section}: {nseg}\n")

print("Section and nseg mapping:")
for section, nseg in section_nseg_mapping:
    print(f"{section}: {nseg}")

print(f"\nResults have been saved to {output_file_name}")