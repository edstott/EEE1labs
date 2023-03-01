# Analysis and Design of Circuits Lab
# Part 4: Spring Term weeks 7--10

## The complete opamp
    
The circuit for the complete opamp is below.
Notice how the bias current for the power amplifier is shared with the common emitter amplifier.
This means the input node for the power amplifier has moved to the base/collector of $T_4$, but that is not a problem since it's only 0.7V difference to the output — equivalent to less than 1mV of input voltage. 
        
Enter the circuit in LTspice, copy-pasting your earlier schematics were appropriate.
Label the input, output and power supply nodes.
Note that $V_{\text{IN}+}$ and $V_{\text{IN}-}$ have swapped to account for the phase inversion introduced by the CE stage.
Omit the capacitor for now.
    
![Transistor diagram of the opamp](graphics/opampComplete2.png)
    
### Initial test at unity gain

Begin testing the opamp by configuring it as a unity-gain voltage follower:

![Opamp configured as a unity-gain voltage follower](graphics/voltageFollower.png)
            
Initially, the opamp will be susceptible to oscillation.
Test this by applying a $\pm1\text{V}$, 100KHz square wave input, which contains the high frequencies that will stimulate oscillation.
In a physical circuit, noise would trigger the oscillation.
            
![Voltage source setup for 100KHz square wave](graphics/opampOsc.png)
                
Run a transient simulation for 50μs.
The simulation runs slowly when there is a high frequency oscillation so the simulation length is kept short.
You will see that a high-frequency oscillation overlays or dominates the square wave.
            
-[ ] Simulate the complete opamp as a voltage follower
            
### Frequency compensation

The oscillation is caused by the delay of the opamp between input and output.
The lag means there is a phase-shift between input and output, and for high frequencies the phase shift is enough to make the inverting input act as a non-inverting input, which causes positive feedback and oscillation.
You can see this effect by performing an open-loop, AC analysis of your opamp.
Configure it as shown below:
            
![Opamp configured for open-loop analysis](graphics/openLoop.png)
            
The feedback path provides unity gain at very low frequencies.
Without this, the input offset voltage error of the opamp, which is less than 1mV, would be greatly amplified and the output would be saturated.
The circuit isn't practical, but it ensures the biasing is correct for the AC analysis.
            
Run the AC analysis with a maximum frequency of 100MHz and plot the magnitude and phase of the output.
You will see the gain at low frequencies is extremely high: over 100dB.
That is what we intended and it means we can assume infinite gain for the purpose of analysing circuits with negative feedback. As frequency increases, the gain drops off due to capacitance in the transistors.
            
The phase plot shows why the voltage follower circuit is unstable: the phase lag increases with frequency and the gain is still greater than 0dB at the point where phase lag reaches 180° and negative feedback becomes positive feedback.
            
- [ ] Obtain the open loop transfer function of the opamp.
            
The capacitor in the opamp is a compensation capacitor for stabilisation.
It acts to bypass the common emitter stage and further reduce the gain at high frequencies.
Switch back to transient analysis and increase the value of the capacitor to make the oscillation disappear.
Start with a value of 1nF.
The frequency of the oscillation will change so vary the duration of the simulation and the period of the square wave to ensure that it has disappeared.
            
Once you have removed the oscillation, check the open loop transfer function again.
You will see that gain is now less than 0dB where phase reaches 180°.
            
- [ ] Use the compensation capacitor to stabalise the opamp
            
### Inverting amplifier
        
Configure your opamp as an inverting amplifier:
        
![Opamp configured as an inverting Amplifier](graphics/invertingAmp.png)
            
Set $R_\text{F}$ as 10kΩ and $V_\text{IN}$ as a sine wave with 1kHz frequency and 10mV amplitude.
Run a transient simulation to confirm that you get the expected amplification.
            
Simulation allows us to do a parametric sweep, which explores the effect of varying a parameter such as gain.
Change the value of $R_\text{F}$ to `{rfb}` and use the Edit menu to add a SPICE directive to the schematic.
Set the directive to `.step param rfb list 1k 10k 100k 1Meg`
        
![Setting up a resistor for parametric sweep](graphics/spiceStep.png)
    
Now run the AC analysis and you will see the overlaid transfer functions for each resistor value.
Notice how they converge at high frequencies. What is the gain-bandwidth product for your opamp?
            
- [ ] Find the transfer functions for inverting amplifiers with different gains. Determine the gain-bandwidth product.
