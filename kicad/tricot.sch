EESchema Schematic File Version 2  date 26/07/2013 00:38:44
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:pgt_components
LIBS:tricot-cache
EELAYER 25  0
EELAYER END
$Descr A4 11700 8267
encoding utf-8
Sheet 1 1
Title "Tricot"
Date "25 jul 2013"
Rev "1"
Comp "Pierre Gradot"
Comment1 "Routage du compte-tours pour tricot"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 3200 6900 0    60   ~ 0
IMPORTANT : Kicad only seems to have CA (Common Anode) 7 segments.\nNevertheless, schematics clearly shows a Common Cathode (CC) mode  !
$Comp
L 7SEGMENTS AFF1
U 1 1 5054D1AC
P 3750 5750
F 0 "AFF1" H 3750 6300 60  0000 C CNN
F 1 "7SEGMENTS" H 3750 5300 60  0000 C CNN
	1    3750 5750
	1    0    0    -1  
$EndComp
NoConn ~ 4350 5300
NoConn ~ 6700 5250
NoConn ~ 8950 5250
Wire Wire Line
	6050 3400 6000 3400
Wire Wire Line
	6000 3400 6000 3100
Wire Wire Line
	6000 3100 4700 3100
Wire Wire Line
	5400 3300 5400 2300
Wire Wire Line
	5400 3300 4700 3300
Wire Wire Line
	5950 2750 5950 2900
Wire Wire Line
	4700 3000 6050 3000
Connection ~ 5000 3600
Wire Wire Line
	4700 3600 5000 3600
Connection ~ 1200 6500
Wire Wire Line
	1200 6650 1200 6500
Wire Wire Line
	1750 6500 1150 6500
Wire Wire Line
	1950 6900 1950 6750
Wire Wire Line
	5950 2750 6550 2750
Wire Wire Line
	7100 3250 7100 3400
Wire Wire Line
	6700 3050 6850 3050
Wire Wire Line
	6950 2750 7100 2750
Wire Wire Line
	6600 3900 6600 4050
Wire Wire Line
	8700 2400 8700 2300
Wire Wire Line
	8700 2300 5400 2300
Wire Wire Line
	7550 2400 5500 2400
Wire Wire Line
	4700 2700 4700 2450
Wire Wire Line
	4700 2450 3800 2450
Wire Wire Line
	3800 2450 3800 2000
Wire Wire Line
	3500 2000 3500 2250
Connection ~ 1750 6250
Wire Wire Line
	1750 6200 1750 6600
Wire Wire Line
	9150 5550 9150 4850
Wire Wire Line
	9150 4850 1050 4850
Wire Wire Line
	1050 4850 1050 3000
Wire Wire Line
	1050 3000 2600 3000
Wire Wire Line
	7750 5900 7500 5900
Wire Wire Line
	7750 5700 7500 5700
Wire Wire Line
	7750 5500 7500 5500
Wire Wire Line
	7750 5300 7500 5300
Wire Wire Line
	8950 5950 8950 6350
Wire Wire Line
	9500 5350 8950 5350
Wire Wire Line
	9500 5850 9500 5950
Wire Wire Line
	9150 6050 9150 6150
Wire Wire Line
	9150 6150 9250 6150
Wire Wire Line
	9500 6350 9500 6600
Wire Wire Line
	7750 5400 7500 5400
Wire Wire Line
	7750 5600 7500 5600
Wire Wire Line
	7750 5800 7500 5800
Wire Wire Line
	5500 5800 5250 5800
Wire Wire Line
	5500 5600 5250 5600
Wire Wire Line
	5500 5400 5250 5400
Wire Wire Line
	7250 6350 7250 6600
Wire Wire Line
	7000 6150 6900 6150
Wire Wire Line
	6900 6150 6900 6050
Wire Wire Line
	7250 5850 7250 5950
Wire Wire Line
	6700 5350 7250 5350
Wire Wire Line
	6700 5950 6700 6350
Wire Wire Line
	5500 5300 5250 5300
Wire Wire Line
	5500 5500 5250 5500
Wire Wire Line
	5500 5700 5250 5700
Wire Wire Line
	5500 5900 5250 5900
Wire Wire Line
	2600 3400 2400 3400
Wire Wire Line
	2400 3400 2400 3500
Wire Wire Line
	4900 3650 4900 3600
Wire Wire Line
	2600 2800 850  2800
Wire Wire Line
	850  2800 850  5050
Wire Wire Line
	850  5050 4550 5050
Wire Wire Line
	4550 5050 4550 5600
Wire Wire Line
	3150 5950 2900 5950
Wire Wire Line
	3150 5750 2900 5750
Wire Wire Line
	3150 5550 2900 5550
Wire Wire Line
	3150 5350 2900 5350
Wire Wire Line
	4350 6000 4350 6400
Wire Wire Line
	5350 3800 6150 3800
Wire Wire Line
	5850 3900 6150 3900
Wire Wire Line
	1950 3700 1100 3700
Wire Wire Line
	1450 4000 1100 4000
Wire Wire Line
	10450 3100 10650 3100
Wire Wire Line
	8350 3100 8150 3100
Wire Wire Line
	4900 5400 4350 5400
Wire Wire Line
	4900 5900 4900 6000
Connection ~ 9850 3100
Wire Wire Line
	9850 3250 9850 2900
Connection ~ 7550 3100
Wire Wire Line
	7550 3250 7550 2900
Wire Wire Line
	9850 3750 9850 3850
Wire Wire Line
	7550 3750 7550 3850
Wire Wire Line
	4700 3900 5350 3900
Wire Wire Line
	4700 3800 4850 3800
Wire Wire Line
	2450 3900 2600 3900
Wire Wire Line
	1950 3800 2600 3800
Wire Wire Line
	1950 7500 1950 7400
Wire Wire Line
	2450 3700 2600 3700
Wire Wire Line
	1950 4000 2600 4000
Wire Wire Line
	2400 2700 2600 2700
Wire Wire Line
	4700 3700 5350 3700
Wire Wire Line
	4700 4000 4850 4000
Wire Wire Line
	8700 3750 8700 3850
Wire Wire Line
	8700 3250 8700 2900
Connection ~ 8700 3100
Wire Wire Line
	4550 6100 4550 6200
Wire Wire Line
	4550 6200 4650 6200
Wire Wire Line
	9300 3100 9500 3100
Wire Wire Line
	1900 2700 1700 2700
Wire Wire Line
	1450 3800 1100 3800
Wire Wire Line
	1950 3900 1100 3900
Wire Wire Line
	5850 3700 6150 3700
Wire Wire Line
	5350 4000 6150 4000
Wire Wire Line
	4900 6400 4900 6650
Wire Wire Line
	3150 5450 2900 5450
Wire Wire Line
	3150 5650 2900 5650
Wire Wire Line
	3150 5850 2900 5850
Wire Wire Line
	1950 6200 1950 6350
Wire Wire Line
	2600 2900 950  2900
Wire Wire Line
	950  2900 950  4950
Wire Wire Line
	950  4950 6900 4950
Wire Wire Line
	6900 4950 6900 5550
Wire Wire Line
	6450 3400 6600 3400
Wire Wire Line
	1550 6200 1550 6550
Connection ~ 1550 6300
Wire Wire Line
	3350 2000 3350 2250
Wire Wire Line
	3350 2250 2600 2250
Wire Wire Line
	2600 2250 2600 2700
Wire Wire Line
	3650 2000 3650 2150
Wire Wire Line
	3650 2150 5000 2150
Wire Wire Line
	5000 2150 5000 3600
Connection ~ 4900 3600
Wire Wire Line
	4700 3500 4900 3500
Wire Wire Line
	4900 3500 4900 2250
Wire Wire Line
	4900 2250 3500 2250
Wire Wire Line
	3950 2000 3950 2350
Wire Wire Line
	3950 2350 4800 2350
Wire Wire Line
	4800 2350 4800 2800
Wire Wire Line
	4800 2800 4700 2800
Wire Wire Line
	9850 2200 5300 2200
Wire Wire Line
	9850 2200 9850 2400
Wire Wire Line
	6850 3550 6850 3700
Wire Wire Line
	6300 3050 6050 3050
Connection ~ 1750 6500
Wire Wire Line
	1550 6300 1150 6300
Wire Wire Line
	1200 6150 1200 6300
Connection ~ 1200 6300
Wire Wire Line
	4800 3500 4800 4450
Wire Wire Line
	4800 4450 4900 4450
Connection ~ 4800 3500
Wire Wire Line
	5400 4550 5400 4450
Wire Wire Line
	5400 4450 5300 4450
Wire Wire Line
	5950 2900 4700 2900
Wire Wire Line
	6050 3050 6050 3000
Wire Wire Line
	4700 3400 5500 3400
Wire Wire Line
	5500 3400 5500 2400
Wire Wire Line
	4700 3200 5300 3200
Wire Wire Line
	5300 3200 5300 2200
Text Notes 5150 4350 0    60   ~ 0
Condensateur\nde découplage
$Comp
L GND #PWR01
U 1 1 506D41B7
P 5400 4550
F 0 "#PWR01" H 5400 4550 30  0001 C CNN
F 1 "GND" H 5400 4480 30  0001 C CNN
	1    5400 4550
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 506D412D
P 5100 4450
F 0 "C1" V 5150 4550 50  0000 L CNN
F 1 "100n" V 5150 4350 50  0000 L CNN
	1    5100 4450
	0    1    1    0   
$EndComp
$Comp
L LM7805C LM7805C1
U 1 1 50353453
P 1750 4950
F 0 "LM7805C1" H 1750 4600 60  0000 C CNN
F 1 "LM7805C" H 1750 4950 60  0001 C CNN
	1    1750 4950
	1    0    0    -1  
$EndComp
$Comp
L CONN_2 P1
U 1 1 506ADC76
P 800 6400
F 0 "P1" V 750 6400 40  0000 C CNN
F 1 "CONN_2" V 850 6400 40  0000 C CNN
	1    800  6400
	-1   0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 5059CBB3
P 6850 3700
F 0 "#PWR02" H 6850 3700 30  0001 C CNN
F 1 "GND" H 6850 3630 30  0001 C CNN
	1    6850 3700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 5059CBAE
P 7100 3400
F 0 "#PWR03" H 7100 3400 30  0001 C CNN
F 1 "GND" H 7100 3330 30  0001 C CNN
	1    7100 3400
	1    0    0    -1  
$EndComp
$Comp
L LED D3
U 1 1 5059CBA9
P 6500 3050
F 0 "D3" H 6500 3150 50  0000 C CNN
F 1 "LED" H 6500 2950 50  0000 C CNN
	1    6500 3050
	1    0    0    -1  
$EndComp
$Comp
L R R24
U 1 1 5059CBA8
P 6850 3300
F 0 "R24" V 6930 3300 50  0000 C CNN
F 1 "1k" V 6850 3300 50  0000 C CNN
	1    6850 3300
	1    0    0    -1  
$EndComp
$Comp
L R R25
U 1 1 5059CB93
P 7100 3000
F 0 "R25" V 7180 3000 50  0000 C CNN
F 1 "1k" V 7100 3000 50  0000 C CNN
	1    7100 3000
	1    0    0    -1  
$EndComp
$Comp
L LED D4
U 1 1 5059CB92
P 6750 2750
F 0 "D4" H 6750 2850 50  0000 C CNN
F 1 "LED" H 6750 2650 50  0000 C CNN
	1    6750 2750
	1    0    0    -1  
$EndComp
NoConn ~ 4100 2000
$Comp
L PICKIT3_ICSP ICSP1
U 1 1 5059CA14
P 3700 1600
F 0 "ICSP1" H 3700 2200 60  0000 C CNN
F 1 "PICKIT3_ICSP" V 3150 1700 60  0000 C CNN
	1    3700 1600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 5055C0BE
P 6600 4050
F 0 "#PWR04" H 6600 4050 30  0001 C CNN
F 1 "GND" H 6600 3980 30  0001 C CNN
	1    6600 4050
	1    0    0    -1  
$EndComp
$Comp
L LED D2
U 1 1 5055C0B2
P 6250 3400
F 0 "D2" H 6250 3500 50  0000 C CNN
F 1 "LED" H 6250 3300 50  0000 C CNN
	1    6250 3400
	1    0    0    -1  
$EndComp
$Comp
L R R23
U 1 1 5055C08C
P 6600 3650
F 0 "R23" V 6680 3650 50  0000 C CNN
F 1 "1k" V 6600 3650 50  0000 C CNN
	1    6600 3650
	1    0    0    -1  
$EndComp
Text Label 7550 5900 0    60   ~ 0
SG
Text Label 7550 5800 0    60   ~ 0
SF
Text Label 7550 5700 0    60   ~ 0
SE
Text Label 7550 5600 0    60   ~ 0
SD
Text Label 7550 5500 0    60   ~ 0
SC
Text Label 7550 5400 0    60   ~ 0
SB
Text Label 7550 5300 0    60   ~ 0
SA
Text Label 8950 6300 0    60   ~ 0
SDP
$Comp
L GND #PWR05
U 1 1 50550A8E
P 9500 6600
F 0 "#PWR05" H 9500 6600 30  0001 C CNN
F 1 "GND" H 9500 6530 30  0001 C CNN
	1    9500 6600
	1    0    0    -1  
$EndComp
$Comp
L R R22
U 1 1 50550A8D
P 9500 5600
F 0 "R22" V 9580 5600 50  0000 C CNN
F 1 "180" V 9500 5600 50  0000 C CNN
	1    9500 5600
	-1   0    0    1   
$EndComp
$Comp
L R R21
U 1 1 50550A8C
P 9150 5800
F 0 "R21" V 9230 5800 50  0000 C CNN
F 1 "4,7k" V 9150 5800 50  0000 C CNN
	1    9150 5800
	-1   0    0    1   
$EndComp
$Comp
L BC547 Q3
U 1 1 50550A8B
P 9400 6150
F 0 "Q3" H 9550 6225 40  0000 C CNN
F 1 "BC547" H 9525 6150 40  0000 L CNN
	1    9400 6150
	1    0    0    -1  
$EndComp
$Comp
L 7SEGMENTS AFF3
U 1 1 50550A8A
P 8350 5700
F 0 "AFF3" H 8350 6250 60  0000 C CNN
F 1 "7SEGMENTS" H 8350 5250 60  0000 C CNN
	1    8350 5700
	1    0    0    -1  
$EndComp
$Comp
L 7SEGMENTS AFF2
U 1 1 50550A79
P 6100 5700
F 0 "AFF2" H 6100 6250 60  0000 C CNN
F 1 "7SEGMENTS" H 6100 5250 60  0000 C CNN
	1    6100 5700
	1    0    0    -1  
$EndComp
$Comp
L BC547 Q2
U 1 1 50550A78
P 7150 6150
F 0 "Q2" H 7300 6225 40  0000 C CNN
F 1 "BC547" H 7275 6150 40  0000 L CNN
	1    7150 6150
	1    0    0    -1  
$EndComp
$Comp
L R R15
U 1 1 50550A77
P 6900 5800
F 0 "R15" V 6980 5800 50  0000 C CNN
F 1 "4,7k" V 6900 5800 50  0000 C CNN
	1    6900 5800
	-1   0    0    1   
$EndComp
$Comp
L R R16
U 1 1 50550A76
P 7250 5600
F 0 "R16" V 7330 5600 50  0000 C CNN
F 1 "180" V 7250 5600 50  0000 C CNN
	1    7250 5600
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR06
U 1 1 50550A75
P 7250 6600
F 0 "#PWR06" H 7250 6600 30  0001 C CNN
F 1 "GND" H 7250 6530 30  0001 C CNN
	1    7250 6600
	1    0    0    -1  
$EndComp
Text Label 6700 6300 0    60   ~ 0
SDP
Text Label 5300 5300 0    60   ~ 0
SA
Text Label 5300 5400 0    60   ~ 0
SB
Text Label 5300 5500 0    60   ~ 0
SC
Text Label 5300 5600 0    60   ~ 0
SD
Text Label 5300 5700 0    60   ~ 0
SE
Text Label 5300 5800 0    60   ~ 0
SF
Text Label 5300 5900 0    60   ~ 0
SG
$Comp
L BC547 Q1
U 1 1 5054D51D
P 4800 6200
F 0 "Q1" H 4950 6275 40  0000 C CNN
F 1 "BC547" H 4925 6200 40  0000 L CNN
	1    4800 6200
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG07
U 1 1 50550828
P 1200 6650
F 0 "#FLG07" H 1200 6920 30  0001 C CNN
F 1 "PWR_FLAG" H 1200 6880 30  0000 C CNN
	1    1200 6650
	-1   0    0    1   
$EndComp
$Comp
L PWR_FLAG #FLG08
U 1 1 50550821
P 1200 6150
F 0 "#FLG08" H 1200 6420 30  0001 C CNN
F 1 "PWR_FLAG" H 1200 6380 30  0000 C CNN
	1    1200 6150
	1    0    0    -1  
$EndComp
Text Label 1950 6300 0    60   ~ 0
VDD
NoConn ~ 2600 3100
NoConn ~ 2600 3200
NoConn ~ 2600 3600
NoConn ~ 2600 3500
NoConn ~ 2600 3300
$Comp
L VCC #PWR09
U 1 1 505501D7
P 1550 6550
F 0 "#PWR09" H 1550 6650 30  0001 C CNN
F 1 "VCC" H 1550 6650 30  0000 C CNN
	1    1550 6550
	-1   0    0    1   
$EndComp
Text Label 2950 5950 0    60   ~ 0
SG
Text Label 2950 5850 0    60   ~ 0
SF
Text Label 2950 5750 0    60   ~ 0
SE
Text Label 2950 5650 0    60   ~ 0
SD
Text Label 2950 5550 0    60   ~ 0
SC
Text Label 2950 5450 0    60   ~ 0
SB
Text Label 2950 5350 0    60   ~ 0
SA
Text Label 4350 6350 0    60   ~ 0
SDP
$Comp
L GND #PWR010
U 1 1 50550164
P 4900 6650
F 0 "#PWR010" H 4900 6650 30  0001 C CNN
F 1 "GND" H 4900 6580 30  0001 C CNN
	1    4900 6650
	1    0    0    -1  
$EndComp
Text Label 6000 3700 0    60   ~ 0
SDP
Text Label 6000 3800 0    60   ~ 0
SC
Text Label 6000 3900 0    60   ~ 0
SD
Text Label 6000 4000 0    60   ~ 0
SE
Text Label 1150 4000 0    60   ~ 0
SG
Text Label 1150 3900 0    60   ~ 0
SF
Text Label 1150 3800 0    60   ~ 0
SA
Text Label 1150 3700 0    60   ~ 0
SB
Text Label 4750 3500 0    60   ~ 0
VDD
Text Label 1750 2700 0    60   ~ 0
VDD
Text Label 10550 3100 0    60   ~ 0
VDD
Text Label 9400 3100 0    60   ~ 0
VDD
Text Label 8250 3100 0    60   ~ 0
VDD
$Comp
L GND #PWR011
U 1 1 5054DDB1
P 4900 3650
F 0 "#PWR011" H 4900 3650 30  0001 C CNN
F 1 "GND" H 4900 3580 30  0001 C CNN
	1    4900 3650
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR012
U 1 1 5054DA0C
P 9850 3850
F 0 "#PWR012" H 9850 3850 30  0001 C CNN
F 1 "GND" H 9850 3780 30  0001 C CNN
	1    9850 3850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR013
U 1 1 5054DA09
P 8700 3850
F 0 "#PWR013" H 8700 3850 30  0001 C CNN
F 1 "GND" H 8700 3780 30  0001 C CNN
	1    8700 3850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR014
U 1 1 5054DA05
P 7550 3850
F 0 "#PWR014" H 7550 3850 30  0001 C CNN
F 1 "GND" H 7550 3780 30  0001 C CNN
	1    7550 3850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR015
U 1 1 5054D8CD
P 2400 3500
F 0 "#PWR015" H 2400 3500 30  0001 C CNN
F 1 "GND" H 2400 3430 30  0001 C CNN
	1    2400 3500
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 5054D8C7
P 2150 2700
F 0 "R4" V 2230 2700 50  0000 C CNN
F 1 "4,7k" V 2150 2700 50  0000 C CNN
	1    2150 2700
	0    1    1    0   
$EndComp
$Comp
L R R8
U 1 1 5054D86D
P 4900 5650
F 0 "R8" V 4980 5650 50  0000 C CNN
F 1 "180" V 4900 5650 50  0000 C CNN
	1    4900 5650
	-1   0    0    1   
$EndComp
$Comp
L R R11
U 1 1 5054D7FA
P 5600 3700
F 0 "R11" V 5680 3700 50  0000 C CNN
F 1 "390" V 5600 3700 50  0000 C CNN
	1    5600 3700
	0    1    1    0   
$EndComp
$Comp
L R R9
U 1 1 5054D7F9
P 5100 3800
F 0 "R9" V 5180 3800 50  0000 C CNN
F 1 "390" V 5100 3800 50  0000 C CNN
	1    5100 3800
	0    1    1    0   
$EndComp
$Comp
L R R12
U 1 1 5054D7F8
P 5600 3900
F 0 "R12" V 5680 3900 50  0000 C CNN
F 1 "390" V 5600 3900 50  0000 C CNN
	1    5600 3900
	0    1    1    0   
$EndComp
$Comp
L R R10
U 1 1 5054D7F7
P 5100 4000
F 0 "R10" V 5180 4000 50  0000 C CNN
F 1 "390" V 5100 4000 50  0000 C CNN
	1    5100 4000
	0    1    1    0   
$EndComp
$Comp
L R R3
U 1 1 5054D7E9
P 1700 4000
F 0 "R3" V 1780 4000 50  0000 C CNN
F 1 "390" V 1700 4000 50  0000 C CNN
	1    1700 4000
	0    1    1    0   
$EndComp
$Comp
L R R6
U 1 1 5054D7E6
P 2200 3900
F 0 "R6" V 2280 3900 50  0000 C CNN
F 1 "390" V 2200 3900 50  0000 C CNN
	1    2200 3900
	0    1    1    0   
$EndComp
$Comp
L R R2
U 1 1 5054D7E2
P 1700 3800
F 0 "R2" V 1780 3800 50  0000 C CNN
F 1 "390" V 1700 3800 50  0000 C CNN
	1    1700 3800
	0    1    1    0   
$EndComp
$Comp
L R R5
U 1 1 5054D7D7
P 2200 3700
F 0 "R5" V 2280 3700 50  0000 C CNN
F 1 "390" V 2200 3700 50  0000 C CNN
	1    2200 3700
	0    1    1    0   
$EndComp
$Comp
L R R7
U 1 1 5054D781
P 4550 5850
F 0 "R7" V 4630 5850 50  0000 C CNN
F 1 "4,7k" V 4550 5850 50  0000 C CNN
	1    4550 5850
	-1   0    0    1   
$EndComp
$Comp
L R R14
U 1 1 5054D5BB
P 7550 3500
F 0 "R14" V 7630 3500 50  0000 C CNN
F 1 "10k" V 7550 3500 50  0000 C CNN
	1    7550 3500
	1    0    0    -1  
$EndComp
$Comp
L R R18
U 1 1 5054D5B8
P 8700 3500
F 0 "R18" V 8780 3500 50  0000 C CNN
F 1 "10k" V 8700 3500 50  0000 C CNN
	1    8700 3500
	1    0    0    -1  
$EndComp
$Comp
L R R20
U 1 1 5054D5B5
P 9850 3500
F 0 "R20" V 9930 3500 50  0000 C CNN
F 1 "10k" V 9850 3500 50  0000 C CNN
	1    9850 3500
	1    0    0    -1  
$EndComp
$Comp
L R R19
U 1 1 5054D5B3
P 9850 2650
F 0 "R19" V 9930 2650 50  0000 C CNN
F 1 "220" V 9850 2650 50  0000 C CNN
	1    9850 2650
	1    0    0    -1  
$EndComp
$Comp
L R R17
U 1 1 5054D5AD
P 8700 2650
F 0 "R17" V 8780 2650 50  0000 C CNN
F 1 "220" V 8700 2650 50  0000 C CNN
	1    8700 2650
	1    0    0    -1  
$EndComp
$Comp
L R R13
U 1 1 5054D5A4
P 7550 2650
F 0 "R13" V 7630 2650 50  0000 C CNN
F 1 "220" V 7550 2650 50  0000 C CNN
	1    7550 2650
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW3
U 1 1 5054D373
P 10150 3100
F 0 "SW3" H 10300 3210 50  0000 C CNN
F 1 "SW_PUSH" H 10150 3020 50  0000 C CNN
	1    10150 3100
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW2
U 1 1 5054D371
P 9000 3100
F 0 "SW2" H 9150 3210 50  0000 C CNN
F 1 "SW_PUSH" H 9000 3020 50  0000 C CNN
	1    9000 3100
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW1
U 1 1 5054D36E
P 7850 3100
F 0 "SW1" H 8000 3210 50  0000 C CNN
F 1 "SW_PUSH" H 7850 3020 50  0000 C CNN
	1    7850 3100
	1    0    0    -1  
$EndComp
$Comp
L PIC18(L)F2XK22 PIC1
U 1 1 5054D163
P 3650 3350
F 0 "PIC1" H 3650 4300 50  0000 C CNN
F 1 "PIC18(L)F2XK22" H 3650 3450 50  0000 C CNN
	1    3650 3350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR016
U 1 1 50353598
P 1950 7500
F 0 "#PWR016" H 1950 7500 30  0001 C CNN
F 1 "GND" H 1950 7430 30  0001 C CNN
	1    1950 7500
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 5035358D
P 1950 7150
F 0 "R1" V 2030 7150 50  0000 C CNN
F 1 "470" V 1950 7150 50  0000 C CNN
	1    1950 7150
	1    0    0    -1  
$EndComp
$Comp
L LED D1
U 1 1 50353531
P 1950 6550
F 0 "D1" H 1950 6650 50  0000 C CNN
F 1 "LED" H 1950 6450 50  0000 C CNN
	1    1950 6550
	0    1    1    0   
$EndComp
$Comp
L GND #PWR017
U 1 1 503534A7
P 1750 6600
F 0 "#PWR017" H 1750 6600 30  0001 C CNN
F 1 "GND" H 1750 6530 30  0001 C CNN
	1    1750 6600
	1    0    0    -1  
$EndComp
$EndSCHEMATC
