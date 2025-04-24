# Author: Dane Nicol, 130822325
# Date: Feb 23, 2025
# Description: COMPE 271 MIPS Project

# References/Citations
# Ken Arnold provided examples and taught the COMPE 271
# ChatGPT by OpenAI provided examples and recommendations
# Zybooks gave examples and the fundamentals of C to MIPS

.data

radiationGrid:
.word 11, 24, 15
.word 17, 21, 13
.word 19, 20, 19
.word 12, 28, 10

warning: .asciiz "Radiation Warning!"
hullSector: .asciiz "<-- Hull Sector"
cryo: .asciiz "Entering cryogenic sleep... all ship operations suspended indefinitely... \n neurological activity shutdwon in 3, 2, 1...\n"
nonvalid: .asciiz "Please enter a valid option!\n"
newline: .asciiz        "\n"
test: .asciiz "This message is for testing!"
proceed: .asciiz "Press any key to proceed"

# fuel_Check_Land
msg1: .asciiz "Checking fuel for landing/liftoff...\n"
msg2: .asciiz "Not enough fuel to make a landing and liftoff... mine asteroids!\n"
msg3: .asciiz "You have enough fuel, proceed with cation!\n"


# fuel_Check_Orbit
msg4: .asciiz "Checking fuel for orbit change...\n"
msg5: .asciiz "Not enough fuel to make a orbital change... mine asteroids!\n"
msg6: .asciiz "You have enough fuel, proceed with cation!\n"
msg7: .asciiz "Checking fuel for landing/liftoff...\n"

# display_Inner_System
msg8: .asciiz "Which orbit shall the ship relocate to?\n"
msg9: .asciiz "1: YopYop\n"
cancel: .asciiz "2: Cancel\n"

# display_Outer_System
msg10: .asciiz "Which orbit shall the ship relocate to?\n"
msg11: .asciiz "1: Xin\n"


# display_Orbit_Change
msg13: .asciiz "Which orbit shall the ship relocate to?\n"
msg14: .asciiz "1: Inner System\n"
msg15: .asciiz "2: Outer System\n"
cancel_2: .asciiz "3: Cancel\n"

# orbit_Change_PLANET
msg16: .asciiz "Your orbit has has been changed to YopYop!\n"
msg17: .asciiz "Your orbit has been changed to Xin!\n"
msg18: .asciiz "Your ship fuel has decreased by 500\n"
msg19: .asciiz "Current fuel: "
msg20: .asciiz "Your plant and mealworm health has gone down by 3 points!\n"
msg21: .asciiz "Current health stats!\n"
msg22: .asciiz "Plant Farm: "
msg23: .asciiz "Mealworm Farm: "




# random_Farm_Event (Not implemented in this program)
msg24: .asciiz "Calibration Error! Bio farm malfunction! Suspected viral or bacterial infection. Automatic reset running...\n"
msg25: .asciiz "Bacterial or viral outbreak! Risk Level for mealworm farm: Extreme! Risk Level for plant farm: Extreme!\n"
msg26: .asciiz "The outbreak hurts your plants and mealworms!\n"
msg27: .asciiz "Mealworm and Plant Farm Health -3\n"
msg28: .asciiz "Please proceed with maintenance\n"




#maintain_Farm
msg31: .asciiz "Farm health improved!\n"
msg32: .asciiz "Plant farm health:\n"
msg33: .asciiz "Mealworm farm health:\n"
msg34: .asciiz "Water supply has gone down by 100!\n"
msg35: .asciiz "Current water:\n"

# mine_Asteroid
msg36: .asciiz "Mining asteroids in orbit...\n"
msg43: .asciiz "Your ship resources now have increased by 100!\n"
msg44: .asciiz "Water: "
msg46: .asciiz "Fuel: "
msg41: .asciiz "Asteroids have been mined!\n"

# surface_YopYop
msg47: .asciiz "You have landed on YopYop!\n"
msg48: .asciiz "You observe your surroundings...\n"
msg49: .asciiz "YopYop appears to a mountainous planet due to the frequent geological activity!\n"
msg50: .asciiz "You do surface explorations, analyze surface samples with spectrometer instruments, and record other data! Gained 2 research points!\n"
msg51: .asciiz "Total Research: "

# surface_Xin
msg52: .asciiz "You have landed on Xin!\n"
msg53: .asciiz "You observe your surroundings...\n"
msg54: .asciiz "Xin appears to be dormant and flat, with lots of crators due to its lack of atmosphere!\n"
msg55: .asciiz "You do surface explorations, analyze surface samples with spectrometer instruments, and record other data! Gained 4 research points!\n"
msg56: .asciiz "Total Research: "

# land_On_Body
msg57: .asciiz "Landing on YopYop...\n"
msg58: .asciiz "Landing on Xin...\n"
msg59: .asciiz "Your ship fuel has decreased by 100!\n"
msg60: .asciiz "Your ship fuel has decreased by 200!\n"
msg61: .asciiz "Current fuel: "

# check_Diagnostics
msg62: .asciiz "Water Supplies at: "
msg63: .asciiz "Oxygen Supply at: "
msg64: .asciiz "Fuel reserves at: "
msg65: .asciiz "Plant Farm Health at: "
msg66: .asciiz "Mealworm Farm Health at: "
msgPoints: .asciiz "Total Research Points at: "

# radiation_Data
msg67: .asciiz "Last radiation data log made... 999 days ago\n"
msg68: .asciiz "<-- HULL SECTOR\n"
msg69: .asciiz "Warning! Cosmic radiation hazard! Proceed to radiation shelter!\n"
msg70: .asciiz "Warning! Solar flare activity detected! Proceed to radiation shelter!\n"
msg71: .asciiz "Warning! Reactor shielding malfuntion! Proceed to radiation shelter!\n"
msg72: .asciiz "Warning! Radiation Dose Rate Exceeds Maxmimum Threshold! Attempting systems reset...\n"
msg73: .asciiz "System access denied, current user does not have authority!\n"

# display_Hub
welcome: .asciiz "Welcome to your control hub, operator\n"
main1: .asciiz "1: Change orbital trajectory\n"
main2: .asciiz "2: Land on current orbiting celetial body\n"
main3: .asciiz "3: Maintain bio farm\n"
main4: .asciiz "4: Mine local asteroids\n"
main5: .asciiz "5: Check ship diagnostics\n"
main6: .asciiz "6: Observe Radiation Data\n"
main7: .asciiz "7: Cryogeneic Sleep\n"
invalid: .asciiz "Please enter a valid option\n"




.text
.globl main

# Note for stack:
# If function contains jal instruction or $s register modification, decrement stack (make room) by 4 (4 bytes per register)
# Then sw (store word) the $ra or $s register to $sp (save to stack)
#
# Proceed with these instructions INSIDE the same



# Then within the jal function: run the instrcution jr $ra to return to where the instruction was called





start:

	# Declaring global integers for ship resources
	li $s0, 10 # Mealworm Farm Health
	li $s1, 10 # Plant Farm Health
	li $s2, 500 # Water
	li $s3, 500 # Oxygen
	li $s4, 1000 # Fuel
	li $s5, 0 # GlobalOrbitNumber
	li $s7, 0 # ResearchPoints

	j main # jump to main, this function is just to initialize my global variables in $s registers


main:

	li $v0, 4
	la $a0, welcome # Displays welcome message
	syscall

	li $v0, 4
	la $a0, main1 # Change orbit message
	syscall

	li $v0, 4
	la $a0, main2 # Land message
	syscall

	li $v0, 4
	la $a0, main3 # Maintain bio farm message
	syscall

	li $v0, 4
	la $a0, main4 # Mine message
	syscall

	li $v0, 4
	la $a0, main5 # Check ship message
	syscall

	li $v0, 4
	la $a0, main6 # Observe Radiation message
	syscall

	li $v0, 4
	la $a0, main7 # Cryogeneic message
	syscall

	li $v0, 5 # Get interger from user input
	syscall
	move $t0, $v0

	# If conditions:
	li $t1, 1
	beq $t0, $t1, main_c1 # changeOrbit

	li $t1, 2
	beq $t0, $t1, main_c2 # landOnBody

	li $t1, 3
	beq $t0, $t1, main_c3 # maintainBioFarm

	li $t1, 4
	beq $t0, $t1, main_c4 # mineAsteroids

	li $t1, 5
	beq $t0, $t1, main_c5 # shipDiagnostics

	li $t1, 6
	beq $t0, $t1, main_c6 # radiationCheck

	li $t1, 7
	beq $t0, $t1, main_c7 # cryogenicSleep

	j skip # else

main_c1:
	jal changeOrbit
	j main

main_c2:
	jal landOnBody
	j main

main_c3:
	jal maintainBioFarm
	j main

main_c4:
	jal mineAsteroids
	j main

main_c5:
	jal shipDiagnostics
	j main

main_c6:
	jal radiationCheck
	j main

main_c7:
	jal cryogenicSleep
	j main

skip:
	li $v0, 4
	la $a0, nonvalid # Message shows nonvalid selection
	syscall
	j main # Jumps back to main if nonvalid selection

changeOrbit:
	addi $sp, $sp, -4 # Make room for $ra
	sw $ra, 0($sp) # Store return address

	jal fuelCheckOrbit # Jump && link to fuelCheckOrbit
	jal displayOrbitChange # Jump && link to displayOrbitChange

	li $v0, 5 # Get interger from user input
	syscall
	move $t0, $v0

	# if functions
	li $t1, 1
	beq $t0, $t1, orbit_c1 # orbitChangeInnerSystem

	li $t1, 2
	beq $t0, $t1, orbit_c2 # orbitChangeOuterSystem

	li $v0, 4
	la $a0, nonvalid # Message shows nonvalid selection
	syscall

	lw $ra, 0($sp) # Load back return address
	addi $sp, $sp, 4 # Clean up stack

	jr $ra

orbit_c1:
	jal orbitChangeInnerSystem

	lw $ra, 0($sp) # Load back return address
	addi $sp, $sp, 4 # Clean up stack

	jr $ra # return back to caller

orbit_c2:
	jal orbitChangeOuterSystem

	lw $ra, 0($sp) # Load back return address
	addi $sp, $sp, 4 # Clean up stack

	jr $ra # return back to caller


fuelCheckOrbit:

	addi $sp, $sp, -4 # Make room for $ra
	sw $ra, 0($sp) # Store return address

	li $v0, 4
	la $a0, msg4 # Checking fuel orbit message
	syscall

	li $v0, 12 # Wait for any keypress
	syscall

	move $t0, $s4 # Assign fuel value to temp register 0

	bge $t0, 500, fuelCheckOrbit_Cont # Enough fuel


	li $v0, 4
	la $a0, msg5 # Not enough fuel message
	syscall
	
	li $v0, 12 # Wait for any keypress
	syscall

	lw $ra, 0($sp) # Load back return address
	addi $sp, $sp, 4 # Clean up stack
	
	#Note: we are not returning to return address, only cleaning up stack since we need to go back to main
	
	j main

fuelCheckOrbit_Cont:
	li $v0, 4
	la $a0, msg6 # Enough fuel message
	syscall

	lw $ra, 0($sp) # Load back return address
	addi $sp, $sp, 4 # Clean up stack

	jr $ra # return back to caller



displayOrbitChange:

	addi $sp, $sp, -4 # Make room for $ra
	sw $ra, 0($sp) # Store return address

	li $v0, 4
	la $a0, msg13 # Ship relocate message
	syscall

	li $v0, 4
	la $a0, msg14 # Inner system message
	syscall

	li $v0, 4
	la $a0, msg15 # Outer system message
	syscall

	lw $ra, 0($sp) # Load back return address
	addi $sp, $sp, 4 # Clean up stack

	jr $ra # return back to caller (changeOrbit)

orbitChangeInnerSystem:

	addi $sp, $sp, -4 # Make room for $ra
	sw $ra, 0($sp) # Store return address

	jal displayInnerSystem

	li $v0, 5 # Get interger from user input
	syscall
	move $t0, $v0

	li $t1, 1
	bne $t0, $t1, skipClean
	jal orbitChangeInnerSystem1
	
	lw $ra, 0($sp) # Load back return address
	addi $sp, $sp, 4 # Clean up stack

	jr $ra # return back to caller


orbitChangeInnerSystem1:
	addi $sp, $sp, -4 
	sw $ra, 0($sp)


	li $v0, 4
	la $a0, msg16 # Orbit change YopYop message
	syscall

# load necessary global variables into function
	move $t0, $s4 # load fuel into temp 0
	move $t1, $s1 # load plant into temp 1
	move $t2, $s0 # load mealworm into temp 2
	move $t3, $s5 # load globalOrbitNumber into temp 3

	li $t4, 500 # load integer 500 into temp 4 for fuel subtraction
	li $t5, 3 # load integer 3 into temp 5 for plant health subtraction
	li $t6, 1 # load integer 1 into temp 6 for mealworm health subtraction

# Note the orbital environment of Xin is harsher for mealworms
# Note the orbital envionment of YopYop is harsher for plants



	li $t3, 0 # set global orbit number to 0 (YopYop)
	move $s5, $t3 # store the updated global variable


	# Subtract fuel by 500
	sub $t0, $t0, $t4

	move $s4, $t0 # load back temp into saved for fuel

	li $v0, 4
	la $a0, msg18 # Ship decrease fuel message
	syscall

	li $v0, 4
	la $a0, msg19 # Current fuel message
	syscall

	# printf a space!
	li $v0, 11 # set syscall for printf
	li $a0, 32 # load ascii value of space
	syscall

	li $v0, 1
	move $a0, $t0 # display current fuel integer
	syscall

	li $v0, 4
	la $a0, newline # display newline
	syscall

	li $v0, 12 # Wait for any keypress
	syscall

	li $v0, 4
	la $a0, msg20 # Plant && mealworm farm went down message
	syscall

	li $v0, 4
	la $a0, msg21 # Current health stats message
	syscall


	# Subtract plant health by 3
	sub $t1, $t1, $t5
	# Subtract mealworm health by 1
	sub $t2, $t2, $t6

	move $s0, $t1 # load back temps into saved for plant and meamworm
	move $s1, $t2

	li $v0, 4
	la $a0, msg22 # Current plant health message
	syscall

	# printf a space!
	li $v0, 11 # set syscall for printf
	li $a0, 32 # load ascii value of space
	syscall

	li $v0, 1
	move $a0, $t1 # display current plant health integer
	syscall

	li $v0, 4
	la $a0, newline # display newline
	syscall

	li $v0, 4
	la $a0, msg23 # Current mealworm health message
	syscall

	# printf a space!
	li $v0, 11 # set syscall for printf
	li $a0, 32 # load ascii value of space
	syscall

	li $v0, 1
	move $a0, $t2 # display current plant health integer
	syscall

	li $v0, 12 # Wait for any keypress
	syscall


	lw $ra, 0($sp)

	addi $sp, $sp, 4 # clean up the stack and return it to inital state

	jr $ra


orbitChangeOuterSystem:

	addi $sp, $sp, -4 # Make room for $ra
	sw $ra, 0($sp) # Store return address

	jal displayOuterSystem

	li $v0, 5 # Get interger from user input
	syscall
	move $t0, $v0

	li $t1, 1
	bne $t0, $t1, skipClean
	jal orbitChangeOuterSystem1
	
	lw $ra, 0($sp) # Load back return address
	addi $sp, $sp, 4 # Clean up stack

	jr $ra # return back to caller

skipClean:
	lw $ra, 0($sp) # Load back return address
	addi $sp, $sp, 4 # Clean up stack

	jr $ra

orbitChangeOuterSystem1:
	addi $sp, $sp, -4 # Decrement the stack 16 bytes to make room for $ra register
	sw $ra, 0($sp)


	li $v0, 4
	la $a0, msg17 # Orbit change Xin message
	syscall

	# load necessary global variables into function
	move $t0, $s4 # load fuel into temp 0
	move $t1, $s1 # load plant into temp 1
	move $t2, $s0 # load mealworm into temp 2
	move $t3, $s5 # load globalOrbitNumber into temp 3

	li $t4, 500 # load integer 500 into temp 4 for fuel subtraction
	li $t5, 1 # load integer 1 into temp 5 for mealworm health subtraction
	li $t6, 3 # load integer 3 into temp 6 for plant health subtraction

# Note the orbital environment of Xin is harsher for mealworms
# Note the orbital envionment of YopYop is harsher for plants



	li $t3, 1 # set global orbit number to 1 (Xin)
	move $s5, $t3 # store the updated global variable


	# Subtract fuel by 500
	sub $t0, $t0, $t4

	move $s4, $t0 # load back temp into saved for fuel

	li $v0, 4
	la $a0, msg18 # Ship decrease fuel message
	syscall

	li $v0, 4
	la $a0, msg19 # Current fuel message
	syscall

	li $v0, 1
	move $a0, $t0 # display current fuel integer
	syscall

	li $v0, 4
	la $a0, newline # display newline
	syscall

	li $v0, 12 # Wait for any keypress
	syscall

	li $v0, 4
	la $a0, msg20 # Plant && mealworm farm went down message
	syscall

	li $v0, 4
	la $a0, msg21 # Current health stats message
	syscall


	# Subtract plant health by 1
	sub $t1, $t1, $t5
	# Subtract mealworm health by 3
	sub $t2, $t2, $t6
	

	move $s0, $t1 # load back temps into saved for plant and meamworm
	move $s1, $t2

	li $v0, 4
	la $a0, msg22 # Current plant health message
	syscall

	# printf a space!
	li $v0, 11 # set syscall for printf
	li $a0, 32 # load ascii value of space
	syscall

	li $v0, 1
	move $a0, $t1 # display current plant health integer
	syscall

	li $v0, 4
	la $a0, newline # display newline
	syscall

	li $v0, 4
	la $a0, msg23 # Current mealworm health message
	syscall

	# printf a space!
	li $v0, 11 # set syscall for printf
	li $a0, 32 # load ascii value of space
	syscall

	li $v0, 1
	move $a0, $t2 # display current plant health integer
	syscall

	li $v0, 12 # Wait for any keypress
	syscall


	lw $ra, 0($sp)

	addi $sp, $sp, 4 # clean up the stack and return it to inital state

	jr $ra

displayInnerSystem:

	addi $sp, $sp, -4 # Make room for $ra
	sw $ra, 0($sp) # Store return address

	li $v0, 4
	la $a0, msg8 # Ship relocate message
	syscall

	li $v0, 4
	la $a0, msg9 # YopYop message
	syscall

	lw $ra, 0($sp) # Load back return address
	addi $sp, $sp, 4 # Clean up stack

	jr $ra # return back to caller


displayOuterSystem:

	addi $sp, $sp, -4 # Make room for $ra
	sw $ra, 0($sp) # Store return address

	li $v0, 4
	la $a0, msg8 # Ship relocate message
	syscall

	li $v0, 4
	la $a0, msg11 # Xin message
	syscall

	lw $ra, 0($sp) # Load back return address
	addi $sp, $sp, 4 # Clean up stack

	jr $ra # return back to caller





landOnBody:

	addi $sp, $sp, -4 # Make room for $ra
	sw $ra, 0($sp) # Store return address

	jal fuelCheckLand
	
	# If conditions:
	li $t0, 0 
	beq $t0, $s5, yopyop # If orbit number = 0, land yopyop

	li $t0, 1
	beq $t0, $s5, xin # If orbit number = 1, land xin

	j skipClean
	
yopyop:
	li $v0, 4
	la $a0, msg57 # You are landing yopyop message
	syscall
	
	move $t1, $s4 # move fuel to $t4
	
	addi $t1, $t1, -100 # Subtract fuel by 100
	
	move $s4, $t1 # modify fuel value after subtraction
	
	li $v0, 4
	la $a0, msg59 # Fuel -100 message
	syscall
	
	li $v0, 4
	la $a0, msg61 # Current Fuel
	syscall
	
	li $v0, 1
	move $a0, $t1 # display current fuel
	syscall
	
	li $v0, 4
	la $a0, newline # display newline
	syscall
	
	li $v0, 12 # Wait for any keypress
	syscall
	
	
	# -------- 
	
	
	li $v0, 4
	la $a0, msg47 # landed on yopyop message
	syscall
	
	li $v0, 12 # Wait for any keypress
	syscall
	
	li $v0, 4
	la $a0, msg48 # observe surroundings message
	syscall

	li $v0, 12 # Wait for any keypress
	syscall
	
	li $v0, 4
	la $a0, msg49 # yopyop description message
	syscall
	
	li $v0, 12 # Wait for any keypress
	syscall
	
	li $v0, 4
	la $a0, msg50 # surface exploration message
	syscall
	
	li $v0, 4
	la $a0, msg51 # total research
	syscall

	move $t0, $s7 # move points to $t0
	addi $t0, $t0, 2 # Gain 2 research points
	move $s7, $t0 # save research points back
	
	li $v0, 1
	move $a0, $t0 # Display total research
	syscall
	
	li $v0, 12 # Wait for any keypress
	syscall
	
	lw $ra, 0($sp) # Load back return address
	addi $sp, $sp, 4 # Clean up stack

	jr $ra # return back to caller
	
xin:
	
	li $v0, 4
	la $a0, msg58 # You are landing xin message
	syscall
	
	move $t1, $s4 # move fuel to $t4
	
	addi $t1, $t1, -100 # Subtract fuel by 100
	
	move $s4, $t1 # modify fuel value after subtraction
	
	li $v0, 4
	la $a0, msg59 # Fuel -100 message
	syscall
	
	li $v0, 4
	la $a0, msg61 # Current Fuel
	syscall
	
	li $v0, 1
	move $a0, $t1 # display current fuel
	syscall
	
	li $v0, 4
	la $a0, newline # display newline
	syscall
	
	li $v0, 12 # Wait for any keypress
	syscall
	
	# -------- 


	li $v0, 4
	la $a0, msg52 # landed on xin message
	syscall
	
	li $v0, 12 # Wait for any keypress
	syscall
	
	li $v0, 4
	la $a0, msg53 # observe surroundings message
	syscall

	li $v0, 12 # Wait for any keypress
	syscall
	
	li $v0, 4
	la $a0, msg54 # xin description message
	syscall
	
	li $v0, 12 # Wait for any keypress
	syscall
	
	li $v0, 4
	la $a0, msg55 # surface exploration message
	syscall
	
	li $v0, 4
	la $a0, msg56 # total research
	syscall
	
	move $t0, $s7 # move points to $t0
	addi $t0, $t0, 4 # Gain 4 research points
	move $s7, $t0 # save research points back
	
	li $v0, 1
	move $a0, $t0 # Display total research
	syscall
	
	li $v0, 12 # Wait for any keypress
	syscall
	
	lw $ra, 0($sp) # Load back return address
	addi $sp, $sp, 4 # Clean up stack

	jr $ra # return back to caller
	
	
	
fuelCheckLand:

	addi $sp, $sp, -4 # Make room for $ra
	sw $ra, 0($sp) # Store return address

	li $v0, 4
	la $a0, msg1 # Checking fuel orbit message
	syscall

	li $v0, 12 # Wait for any keypress
	syscall

	move $t0, $s4 # Assign fuel value to temp register 0

	bge $t0, 100, fuelCheckLand_Cont # Enough fuel


	li $v0, 4
	la $a0, msg2 # Not enough fuel message
	syscall


	lw $ra, 0($sp) # Load back return address
	addi $sp, $sp, 4 # Clean up stack
	
	#Note: we are not returning to return address, only cleaning up stack since we need to go back to main
	
	j main

fuelCheckLand_Cont:
	li $v0, 4
	la $a0, msg3 # Enough fuel message
	syscall

	lw $ra, 0($sp) # Load back return address
	addi $sp, $sp, 4 # Clean up stack

	jr $ra # return back to caller


# msg 31 - 25
maintainBioFarm:

	addi $sp, $sp, -4 # Make room for $ra
	sw $ra, 0($sp) # Store return address

	li $v0, 4
	la $a0, msg31 # farm health improved message
	syscall
	
	addi $s0, $s0, 2 # increase plant by 2
	addi $s1, $s1, 2 # increase mealworm by 2
	addi $s2, $s2, -100 # subtract 100 from water
	
	
	li $v0, 12 # Wait for any keypress
	syscall
	
	li $v0, 4
	la $a0, msg32 # plant health:
	syscall
	
	li $v0, 1
	la $a0, ($s0) # display plant integer
	syscall

	li $v0, 4
	la $a0, newline # display newline
	syscall
	
	li $v0, 4
	la $a0, msg33 # mealworm health:
	syscall
	
	li $v0, 1
	la $a0, ($s1) # display mealworm integer
	syscall

	li $v0, 4
	la $a0, newline # display newline
	syscall
	
	li $v0, 12 # Wait for any keypress
	syscall
	
	li $v0, 4
	la $a0, msg34 # water supply warning
	syscall
	
	li $v0, 12 # Wait for any keypress
	syscall
	
	li $v0, 4
	la $a0, msg35 # current water:
	syscall
	
	li $v0, 1
	la $a0, ($s2) # water integer
	syscall

	li $v0, 4
	la $a0, newline # display newline
	syscall
	
	li $v0, 12 # Wait for any keypress
	syscall

	lw $ra, 0($sp) # Load back return address
	addi $sp, $sp, 4 # Clean up stack

	jr $ra # return back to caller

mineAsteroids:

	addi $sp, $sp, -4 # Make room for $ra
	sw $ra, 0($sp) # Store return address
	
	addi $s4, $s4, 100 # increase fuel by 100
	addi $s2, $s2, 100 # increase water by 100
	
	li $v0, 4
	la $a0, msg36 # mining...
	syscall
	
	li $v0, 12 # Wait for any keypress
	syscall
	
	li $v0, 4
	la $a0, msg43 # resource increase!
	syscall
	
	li $v0, 12 # Wait for any keypress
	syscall
	
	li $v0, 4
	la $a0, msg46 # water
	syscall
	
	li $v0, 1
	la $a0, ($s4) # display fuel integer
	syscall
	
	li $v0, 4
	la $a0, newline # display newline
	syscall
	
	li $v0, 4
	la $a0, msg44 # water
	syscall
	
	li $v0, 1
	la $a0, ($s2) # display water integer
	syscall
	
	li $v0, 4
	la $a0, newline # display newline
	syscall
	
	li $v0, 12 # Wait for any keypress
	syscall
	
	li $v0, 4
	la $a0, msg41 # asteroids have been mined
	syscall
	

	lw $ra, 0($sp) # Load back return address
	addi $sp, $sp, 4 # Clean up stack

	jr $ra # return back to caller

# msg: 62 - 66, $s: 2, 3, 4, 1, 0
shipDiagnostics:

	addi $sp, $sp, -4 # Make room for $ra
	sw $ra, 0($sp) # Store return address
	
	li $v0, 4
	la $a0, msg62
	syscall

	li $v0, 1
	la $a0, ($s2)
	syscall


	li $v0, 4
	la $a0, newline # display newline
	syscall

	li $v0, 4
	la $a0, msg63
	syscall

	li $v0, 1
	la $a0, ($s3)
	syscall

	li $v0, 4
	la $a0, newline # display newline
	syscall

	li $v0, 4
	la $a0, msg64
	syscall

	li $v0, 1
	la $a0, ($s4)
	syscall

	li $v0, 4
	la $a0, newline # display newline
	syscall

	li $v0, 4
	la $a0, msg65
	syscall

	li $v0, 1
	la $a0, ($s1)
	syscall

	li $v0, 4
	la $a0, newline # display newline
	syscall

	li $v0, 4
	la $a0, msg66
	syscall

	li $v0, 1
	la $a0, ($s0)
	syscall
	
	li $v0, 4
	la $a0, newline # Print out newline
	syscall
	
	li $v0, 4
	la $a0, msgPoints
	syscall

	li $v0, 1
	la $a0, ($s7)
	syscall

	li $v0, 12 # Wait for any keypress
	syscall

	lw $ra, 0($sp) # Load back return address
	addi $sp, $sp, 4 # Clean up stack

	jr $ra # return back to caller

radiationCheck:
	addi $sp, $sp, -4 # Make room for $ra
	sw $ra, 0($sp) # Store return address
	
	j radiationStart

radiationStart:
	la $t0, radiationGrid # Load base address of the array
	li $t1, 3	# Number of rows
	li $t2, 4	# Number of columns
	li $t3, 0	# i = 0 (row index)
# Note: This is a 3x4 array

row_loop:
	bge $t3, $t1, radiationDone	# if i >= 4, finish 

	li $t4, 0	# j = 0 (col index)

col_loop:
	bge $t4, $t2, next_row	# if j >= 4, proceed to next row

	# Compute address: base + ((i * numCols) + j) * 4
	mul $t5, $t3, $t2	# multiply i and columns
	add $t5, $t5, $t4	# add j
	mul $t5, $t5, 4		# multiply by 4 to compensate for word offset
	add $t6, $t0, $t5	# Memory address 

	lw $a0, 0($t6)	# Load word from memory
	li $v0, 1	# Print integer syscall
	syscall

	li $v0, 11	# set syscall for printf
	li $a0, 32	# load ascii value of space
	syscall

	addi $t4, $t4, 1	# j++
	j col_loop

next_row:

	li $v0, 4
	la $a0, newline # Print out newline
	syscall

	addi $t3, $t3, 1	# i++
	j row_loop

radiationDone:

	li $v0, 4
	la $a0, warning
	syscall
	
	li $v0, 12 # Wait for any keypress
	syscall
	
	lw $ra, 0($sp) # Load back return address
	addi $sp, $sp, 4 # Clean up stack

	jr $ra # return back to caller
	

cryogenicSleep:
	li $v0, 4
	la $a0, cryo # Dislays cryo message
	syscall

	li $v0, 12 # Wait for any keypress
	syscall

	j exit

exit:
	li $v0, 10
	syscall
