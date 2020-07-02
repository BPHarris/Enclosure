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
    call('make clean')
    call('make && clear')

    # HACK: Linux gmake2 creates executable in bin/.../ not bin/.../Enclosure/
    # TODO: Get proper _outdir
    _outdir = 'bin/Debug-linux-x86_64'
    call(f'mv {_outdir}/Enclosure {_outdir}/.tmp')
    call(f'mkdir {_outdir}/Enclosure')
    call(f'mv {_outdir}/.tmp {_outdir}/Enclosure/Enclosure')

    call('clear && make')

print('Done.')
