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

By default the rom will compile a gcc build, this can be changed in Makefile in `COMPILER ?= gcc`

It can be changed to `ido` but remember to do `make clean` if you do so.

The final version of 1.3 will use GCC. Tested on PJ64 1.6, PJ64 2.3, Mupen64

It also works on console thanks to beta testers with Everdrive.

## Misc

My Discord: https://discord.gg/KHU9YHw