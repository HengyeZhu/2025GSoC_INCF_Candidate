import json

#default_parameters of L1_DAC_bNAC219_1_cell
default_parameters = {
    'SKv3_1': {'ion': 'k', 'erev': '-85.0 mV'},
    'Nap_Et2': {'ion': 'na', 'erev': '50.0 mV'},
    'NaTs2_t': {'ion': 'na', 'erev': '50.0 mV'},
    'pas': {'ion': 'non_specific', 'erev': '-60.0 mV'},
    'NaTa_t': {'ion': 'na', 'erev': '50.0 mV'},
    'K_Tst': {'ion': 'k', 'erev': '-85.0 mV'},
    'SK_E2': {'ion': 'k', 'erev': '-85.0 mV'},
    'K_Pst': {'ion': 'k', 'erev': '-85.0 mV'},
    'Im': {'ion': 'k', 'erev': '-85.0 mV'},
    'Ca_LVAst': {'ion': 'ca', 'erev': '132.4579341637009 mV'},
    'Ca': {'ion': 'ca', 'erev': '132.4579341637009 mV'}
}

with open('/home/gluciferd/2025GSoC_INCF_Candidate/S1_neuroml/scripts/L1_DAC_cNAC187_1_cellParams.json') as file:
    data = json.load(file)

mechs_ions_data = {}
for sec_name, sec_info in data['secs'].items():
    if 'mechs' in sec_info or 'ions' in sec_info:
        mechs_ions_data[sec_name] = {
            'mechs': sec_info.get('mechs', {}),
            'ions': sec_info.get('ions', {})
        }

channels_info = {}
for sec_name, sec_info in mechs_ions_data.items():
    for mech_name, mech_params in sec_info['mechs'].items():
        if mech_name == 'Ih':
            continue
        for key, value in mech_params.items():
            if key.endswith('bar'):
                channel_key = f"{mech_name} ({key}={value})"
                if channel_key not in channels_info:
                    channels_info[channel_key] = []
                channels_info[channel_key].append(sec_name)

neuroml_output = '<morphology>\n'
for channel_key, segments in channels_info.items():
    channel_name = channel_key.split('(')[0].strip()
    neuroml_output += f'  <segmentGroup id="{channel_name}_group">\n'
    for segment in segments:
        neuroml_output += f'    <include segmentGroup="{segment.strip()}"/>\n'
    neuroml_output += '  </segmentGroup>\n'
neuroml_output += '</morphology>\n'
neuroml_output += '<biophysicalProperties id="biophys">\n'
neuroml_output += '  <membraneProperties>\n'
for channel_key, segments in channels_info.items():
    channel_name = channel_key.split('(')[0].strip()
    if channel_name in default_parameters:
        ion = default_parameters[channel_name]['ion']
        erev = default_parameters[channel_name]['erev']
        neuroml_output += f'    <channelDensity id="{channel_name}_group_{channel_name}" '
        neuroml_output += f'segmentGroup="{channel_name}_group" ion="{ion}" ionChannel="{channel_name}" '
        neuroml_output += f'erev="{erev}" condDensity="{channel_key.split("(")[1].strip()}"/>\n'
neuroml_output += '  </membraneProperties>\n'
neuroml_output += '</biophysicalProperties>\n'

with open('L1_DAC_bNAC219_1_cell.biophys.cell.xml', 'w') as file:
    file.write(neuroml_output)

print("ok")