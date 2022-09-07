# VIRSA Configurations

This directory contains configuration files for VIRSA and any other supporting functionality of VIRSA.

## virsaConfig.json

The `virsaConfig.json` contains information about how VIRSA will operate when executed:

- `role`
    - `Streamer` => The VIRSA instance will capture video/audio data and broadcast it to the specified address and port.

    - `Viewer` => The VIRSA instance will receive video/audio data and display it to the specified output.

- `address` => Destination Address to send/receive network traffic to/from.

- `port` => Destination port to send/receive network traffic to/from.

- `output` => Output form that data received from a `Streamer` will be displayed on.
    - <span style="color:red">NOTE: This is only available when VIRSA's role is a `Viewer`.</span>
