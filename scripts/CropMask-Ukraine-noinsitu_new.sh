#!/bin/bash

./CropMask.py -refr /mnt/data/reference/Reference_Ukraine.tif -ratio 0.75 -input \
/mnt/Imagery_S2A/L2A/Spot4-T5/Ukraine/SPOT4_HRVIR1_XS_20130206_N2A_EUkraineD0000B0000/SPOT4_HRVIR1_XS_20130206_N2A_EUkraineD0000B0000.xml \
/mnt/Imagery_S2A/L2A/Spot4-T5/Ukraine/SPOT4_HRVIR1_XS_20130226_N2A_EUkraineD0000B0000/SPOT4_HRVIR1_XS_20130226_N2A_EUkraineD0000B0000.xml \
/mnt/Imagery_S2A/L2A/Spot4-T5/Ukraine/SPOT4_HRVIR1_XS_20130318_N2A_EUkraineD0000B0000/SPOT4_HRVIR1_XS_20130318_N2A_EUkraineD0000B0000.xml \
/mnt/Imagery_S2A/L2A/Spot4-T5/Ukraine/SPOT4_HRVIR1_XS_20130402_N2A_EUkraineD0000B0000/SPOT4_HRVIR1_XS_20130402_N2A_EUkraineD0000B0000.xml \
/mnt/Imagery_S2A/L2A/Spot4-T5/Ukraine/SPOT4_HRVIR1_XS_20130412_N2A_EUkraineD0000B0000/SPOT4_HRVIR1_XS_20130412_N2A_EUkraineD0000B0000.xml \
/mnt/Imagery_S2A/L2A/Spot4-T5/Ukraine/SPOT4_HRVIR1_XS_20130417_N2A_EUkraineD0000B0000/SPOT4_HRVIR1_XS_20130417_N2A_EUkraineD0000B0000.xml \
/mnt/Imagery_S2A/L2A/Spot4-T5/Ukraine/SPOT4_HRVIR1_XS_20130422_N2A_EUkraineD0000B0000/SPOT4_HRVIR1_XS_20130422_N2A_EUkraineD0000B0000.xml \
/mnt/Imagery_S2A/L2A/Spot4-T5/Ukraine/SPOT4_HRVIR1_XS_20130427_N2A_EUkraineD0000B0000/SPOT4_HRVIR1_XS_20130427_N2A_EUkraineD0000B0000.xml \
/mnt/Imagery_S2A/L2A/Spot4-T5/Ukraine/SPOT4_HRVIR1_XS_20130502_N2A_EUkraineD0000B0000/SPOT4_HRVIR1_XS_20130502_N2A_EUkraineD0000B0000.xml \
/mnt/Imagery_S2A/L2A/Spot4-T5/Ukraine/SPOT4_HRVIR1_XS_20130507_N2A_EUkraineD0000B0000/SPOT4_HRVIR1_XS_20130507_N2A_EUkraineD0000B0000.xml \
/mnt/Imagery_S2A/L2A/Spot4-T5/Ukraine/SPOT4_HRVIR1_XS_20130512_N2A_EUkraineD0000B0000/SPOT4_HRVIR1_XS_20130512_N2A_EUkraineD0000B0000.xml \
/mnt/Imagery_S2A/L2A/Spot4-T5/Ukraine/SPOT4_HRVIR1_XS_20130517_N2A_EUkraineD0000B0000/SPOT4_HRVIR1_XS_20130517_N2A_EUkraineD0000B0000.xml \
/mnt/Imagery_S2A/L2A/Spot4-T5/Ukraine/SPOT4_HRVIR1_XS_20130527_N2A_EUkraineD0000B0000/SPOT4_HRVIR1_XS_20130527_N2A_EUkraineD0000B0000.xml \
/mnt/Imagery_S2A/L2A/Spot4-T5/Ukraine/SPOT4_HRVIR1_XS_20130601_N2A_EUkraineD0000B0000/SPOT4_HRVIR1_XS_20130601_N2A_EUkraineD0000B0000.xml \
/mnt/Imagery_S2A/L2A/Spot4-T5/Ukraine/SPOT4_HRVIR1_XS_20130606_N2A_EUkraineD0000B0000/SPOT4_HRVIR1_XS_20130606_N2A_EUkraineD0000B0000.xml \
/mnt/Imagery_S2A/L2A/Spot4-T5/Ukraine/SPOT4_HRVIR1_XS_20130611_N2A_EUkraineD0000B0000/SPOT4_HRVIR1_XS_20130611_N2A_EUkraineD0000B0000.xml \
/mnt/Imagery_S2A/L2A/Spot4-T5/Ukraine/SPOT4_HRVIR1_XS_20130616_N2A_EUkraineD0000B0000/SPOT4_HRVIR1_XS_20130616_N2A_EUkraineD0000B0000.xml \
-t0 20130206 -tend 20130616 -rate 5 -radius 100 -window 6 -nbtrsample 4000 -rseed 0 -lmbd 2 -weight 1 -nbcomp 6 -spatialr 10 -ranger 0.65 -minsize 10 -rfnbtrees 100 -rfmax 25 -rfmin 25 -eroderad 5 -alpha 0.01 -minarea 100 -pixsize 20 -keepfiles -fromstep 5 \
-outdir /mnt/data/ukraine/Ukraine-mask-noinsitu/
