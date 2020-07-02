# Isabelle 64 - More than just a SM64 character edit

A SM64 Decomp Mod that let's you play as the yellow dog from Animal Crossing, Isabelle.

Source code contains progress of the next release (Isabelle 64 version 1.3)

<img src="https://i.imgur.com/9S7fnCr.png"/></a>

<img src="https://i.imgur.com/PGH0Sq6.png"/></a>

## Info
* Initially made as a tribute for her reveal in Smash Ultimate (September 2018).
* First versions (1.0 and 1.1) were made using binary edits and other tools.
* Version 1.2 was the first version made in Decomp, however 1.3 is not based of it because it uses an old repo.

## Quick Installation

If is the first time doing this you first need to run these commands:

`make -C tools` then `./extract_assets.py us`

Then after you do the step above, build the rom, running `make` and wait until it's done.

It defaults to `VERSION_US` and `F3DZEX` due to changes. No need to change those or things will break.

## Compiler used

GCC is used, can be compiled back to ido in Makefile in `COMPILER ?= ido` but remember to do `make clean` if you do so.

Tested on PJ64 1.6, PJ64 2.3, Mupen64, CEN64

It also works on console thanks to beta testers with Everdrive.

## PC Port

Support for it has been added sometime using widescreen and no draw distance but pc code was private until devs actually decided to release it.

Only tested DX11-DX12 on Windows 10

## Bugs
* For some reason `Makefile` doesn't define `NON_MATCHING`, so it's defined in `macros.h`

## Misc

My Discord: https://discord.gg/KHU9YHw