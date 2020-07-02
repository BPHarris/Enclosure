#!/usr/bin/env python3
from os import system as call
from platform import system

supported_systems = ['Linux']

if system() not in supported_systems:
    print(f'{system()} is not currently supported by this build script.')
    print(f'This script currently supports {supported_systems}.')
    print('Try building a different way, such as with Visual Studio.')
    exit()

if system() == 'Linux':
    # Clean and make, the make will fail at the linker so clear
    call('make clean')
    call('make && clear')

    # Resolve linker issue (output binary in wrong location)
    # HACK: Linux gmake2 creates executable in bin/.../ not bin/.../Enclosure/
    # TODO: Get proper _outdir for build mode/system/arch
    _outdir = 'bin/Debug-linux-x86_64'
    call(f'mv {_outdir}/Enclosure {_outdir}/.tmp')
    call(f'mkdir {_outdir}/Enclosure')
    call(f'mv {_outdir}/.tmp {_outdir}/Enclosure/Enclosure')
    call('clear')

    # Now make properly    
    call('make')

print('Done.')
