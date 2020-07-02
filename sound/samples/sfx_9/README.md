# Bank/Channel 09

## Warning

This bank has 7 sounds (6 indexed). It can go higher than that and it will work fine but it will kill sound effects when you start a race with Koopa the Quick and Racing Penguin.
A workaround about that is to stub it's player sequence in `play_race_fanfare`

In Isabelle 64, a hacky workaround was to re-record the race fanfare as sound file (aiff).
There are still some sound replacements in this bank but new sounds will be added in bank `sfx_mario_peach` aka Bank 10 (0x10).

## Sounds Changed

| Sound Number (Hex) | Sound Defined | Original Mario Description |
| ------------- | ------------- | ------------- |
| 0x00 | Unchanged | Electric Piano? |
| 0x01 | Unchanged | "Huh-Hoo!" (Double Jump) |
| 0x02 | Unchanged | Square Wave-Like piano sound (Modified for pause screen and others) |
| 0x03 | Same as in Super Mario Sunshine 64 | Used for the coin sound, health bar, camera swing and other assorted SFX |
| 0x04 | Unchanged | ErEr! (Denied Camera Control) |
| 0x05 | Unchanged | Camera Snapshot sound (Pressing R for camera) |
| 0x06 | Unchanged | Weird-Boing sound (Stretching Mario's face?) |
| 0x07 | ACNH text scrolling | N/A |
| 0x08 | ACNH click hover | N/A|
| 0x09 | ACNH click select | N/A |
| 0x0A | ACNH dialog opened | N/A |
| 0x0B | ACNH dialog closed | N/A |
| 0x0C | ACNH app open (Used for pause) | N/A |
| 0x0D | N64DD startup sound | N/A |
| 0x0E | SM64 Race Fanfare (Used as a workaround) | N/A |