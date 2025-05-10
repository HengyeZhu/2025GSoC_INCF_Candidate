import json

with open('L1_DAC_cNAC187_1_cellParams.json', 'r') as file:
    data = json.load(file)

default_parameters = {}

for sec_name, sec_data in data['secs'].items():
    ions = sec_data.get('ions', {})
    mechs = sec_data.get('mechs', {})

    for mech_name, mech_params in mechs.items():
        ion = None
        erev = None

        if mech_name == 'pas':
            ion = 'non_specific'
            erev = f"{mech_params.get('e', -60.0)} mV"
        else:
            for ion_name, ion_data in ions.items():
                if mech_name.lower().startswith(ion_name.lower()):
                    ion = ion_name
                    erev = f"{ion_data.get('e', 0.0)} mV"
                    break

        if ion and erev:
            default_parameters[mech_name] = {'ion': ion, 'erev': erev}

with open('default_parameters.txt', 'w') as file:
    file.write("default_parameters = {\n")
    for key, value in default_parameters.items():
        file.write(f"    '{key}': {{'ion': '{value['ion']}', 'erev': '{value['erev']}'}},\n")
    file.write("}\n")




