# Analysis and Design of Circuits Lab
# Part 1: Autumn Term weeks 4–6

## Section 3: Resonance and Second-Order Filters

In Section 2, you investigated individual capacitors and inductors and used them to build first-order filters. You will now connect an inductor and capacitor together and investigate **series and parallel resonance**. You will then design and build a second-order RLC filter using your group's assigned type and corner frequency. The final challenges investigate a two-stage RC low-pass filter for comparison and a Twin-T notch filter.

Complete the resonance measurements and your assigned RLC filter experiment first. The tasks labelled **Challenge** extend the main investigation. Keep your measurements and analysis together: do not repeat a complete sweep simply to produce a second plot.

### Before the lab

1. Revise the capacitor and inductor impedance equations from Section 2.
2. Calculate the ideal resonant frequency for $L=100\,\mathrm{mH}$ and $C=100\,\mathrm{nF}$ using the equation below.
3. Sketch the expected series and parallel impedance trends and identify which should have a minimum and which should have a maximum.
4. Prepare the measurement table below in your spreadsheet.
5. Find your group's assigned RLC filter type and −3 dB corner frequency in the table at the end. Use the design procedure below to select components and predict the response in LTspice once it has been introduced in the problem classes.

### What is resonance?

An ideal inductor has impedance $j\omega L$, while an ideal capacitor has impedance $-j/(\omega C)$. Their reactances have opposite signs. At a particular frequency their magnitudes are equal:

$$
\omega_0L=\frac{1}{\omega_0C}.
$$

Therefore:

$$
\omega_0=\frac{1}{\sqrt{LC}},
\qquad
f_0=\frac{1}{2\pi\sqrt{LC}}.
$$

Remember that $\omega_0$ is in radians per second and $f_0$ is in hertz. For 100 mH and 100 nF, the ideal prediction is approximately **1.59 kHz**.

In an ideal series connection the impedances cancel, giving zero impedance at resonance. In an ideal parallel connection the branch admittances cancel, giving an unbounded impedance magnitude. Real components have losses, so the measured minimum is not zero and the maximum is not infinite. **Both the series and parallel networks therefore depart from their ideal responses.** The inductor has winding resistance and inter-winding capacitance, while the capacitor has equivalent series resistance (ESR) and parasitic inductance. These properties can change the height and shape of the resonance feature and shift its frequency. Component tolerances also mean that the actual $L$ and $C$ may differ from their nominal values.

Use the ideal curves as a starting prediction, then explain the measured differences using the real component models from Section 2. Do not assume that every discrepancy is an oscilloscope error; equally, check measurement quality before attributing a discrepancy to a parasitic effect.

This resonance comes from connecting the separate capacitor and inductor together. It is different from an individual inductor's **self-resonance**, which involves its unwanted inter-winding capacitance.

<p align="center">
  <img src="graphics/resonance_trends.png" alt="resonance trends" width="700">
</p>

### Series LC network

Connect a **100 nF capacitor and 100 mH inductor in series**. Together, they replace $Z$ in the impedance-measurement divider from Sections 1 and 2. The external test resistor $R$ remains in series with this network.

<p align="center">
  <img src="graphics/LCdiv.png" alt="Measuring the impedance of a series LC network" width="700">
</p>

For ideal components:

$$
Z_\mathrm{series}=j\omega L+\frac{1}{j\omega C}=j\left(\omega L-\frac{1}{\omega C}\right).
$$

Below resonance, the capacitive reactance is larger in magnitude, so the network behaves predominantly capacitively. Above resonance, inductive reactance dominates. At resonance the imaginary terms cancel.

If the total component series resistance is $R_s$, a more realistic model is:

$$
Z_\mathrm{series}=R_s+j\left(\omega L-\frac{1}{\omega C}\right).
$$

The impedance magnitude reaches a minimum close to $R_s$. This gives a physical explanation for the non-zero minimum: reactance can cancel, but the resistance of the wire and component losses remain. Here, $R_s$ includes both the inductor winding resistance and the capacitor ESR. Other parasitic properties can further alter the curve, so this simple series-resistance model may not explain the entire measured frequency range.

#### Measuring the series network

1. Build the circuit with the generator output off. Begin with a 1 kΩ test resistor.
2. Connect CH1 to the input, CH2 across the complete LC network, and both ground clips to the common ground. Set MATH to CH1 − CH2.
3. Use ×10 probes, DC coupling and a sine wave with 0 V offset. Initially use the 1 V peak generator setting from Section 1 and check the actual input waveform.
4. Take readings at the frequencies in the table below. Measure both voltages peak-to-peak and calculate $|Z|=R V_{Z,\mathrm{pp}}/V_{R,\mathrm{pp}}$.
5. Plot each point immediately. Near resonance, the LC voltage may become small; adapt $R$ using the guidance in Section 1. Check for heavy loading or distortion before reducing it further.
6. Add closely spaced frequencies around the minimum until its position and shape are clear. Do not assume that the nominal 1.59 kHz prediction is the exact measured resonant frequency.

### Recording the resonance measurements

Make one copy of this table for the series network and one for the parallel network. Use the **same inductor and capacitor** for both.

| Frequency (Hz) | Test resistance $R$ (Ω) | Network voltage $V_{Z,\mathrm{pp}}$ (V) | Resistor voltage $V_{R,\mathrm{pp}}$ (V) | Impedance magnitude (Ω) |
| --- | --- | --- | --- | --- |
| 100 | | | | |
| 300 | | | | |
| 600 | | | | |
| 1000 | | | | |
| 1300 | | | | |
| 1500 | | | | |
| 1600 | | | | |
| 1700 | | | | |
| 2000 | | | | |
| 3000 | | | | |
| 6000 | | | | |
| 10000 | | | | |
| 40000 | | | | |

Add rows for the extra frequencies chosen around the minimum or maximum. Record any change in test resistance and do not use readings that are dominated by noise.

- [ ] Plot the series-network impedance magnitude against frequency on logarithmic axes and compare it with theory.
- [ ] Identify the minimum, estimate its frequency and explain why its impedance is not zero.
- [ ] Explain the predominantly capacitive and inductive regions on either side.

### Parallel LC network

Reconnect the **same 100 nF capacitor and 100 mH inductor in parallel**, so that the complete parallel combination now forms $Z$ in the measurement circuit.

<p align="center">
  <img src="graphics/LCdivpar.png" alt="Measuring the impedance of a parallel LC network" width="700">
</p>

Using the equation for impedances in parallel:

$$
Z_\mathrm{parallel}=\frac{Z_LZ_C}{Z_L+Z_C}.
$$

For ideal components this becomes:

$$
Z_\mathrm{parallel}=\frac{j\omega L}{1-\omega^2LC}.
$$

As frequency approaches the ideal resonant frequency, the denominator approaches zero and the **impedance magnitude** grows without bound. The complex impedance itself does not tend to a positive real infinity; its reactive sign changes across resonance.

Another way to understand this is to add the branch admittances. At resonance the ideal capacitive and inductive branch currents are equal and opposite, so their sum at the input is zero, even though current can circulate between the two branches.

In the parallel network, the inductor winding resistance and capacitor ESR likewise prevent the ideal response: they introduce loss, prevent complete cancellation of the input current and limit the impedance peak. Their effect is not identical to simply adding a resistance to the ideal parallel impedance; include the losses within their respective component branches when modelling the circuit. Probe loading can also lower the measured peak. The frequency of the real peak may differ slightly from the ideal prediction and from the series-network minimum.

Below resonance, the ideal parallel network is predominantly inductive. Above resonance, it is predominantly capacitive—the opposite ordering to the series network.

#### Measuring the parallel network

1. Turn the generator output off and rewire the components in parallel.
2. Retain the input, network-voltage and math-channel measurements used above, with both probe grounds at common ground.
3. Use the same starting frequencies and a fresh copy of the recording table.
4. Near the impedance peak, the voltage across the test resistor may become small. Increase $R$ if necessary to obtain a reliable math-channel signal.
5. Add readings around the maximum to locate it and resolve its shape.
6. Overlay the parallel-network measurements on the series-network plot and compare both with the ideal predictions.

- [ ] Identify the maximum impedance magnitude and explain why it is finite.
- [ ] Compare the measured resonant frequencies with each other and the ideal prediction.
- [ ] Explain why one connection gives an impedance minimum while the other gives a maximum.
- [ ] Explain how parasitic properties in both the inductor and capacitor cause the measured series and parallel responses to depart from the ideal predictions.

### From resonance to second-order filters

A transfer function relates output voltage to input voltage:

$$
T(j\omega)=\frac{V_\mathrm{out}}{V_\mathrm{in}}.
$$

Its magnitude is the voltage-amplitude ratio and its phase is the output phase relative to the input. Measure CH1 at the input and CH2 at the output, both relative to common ground. For these filter measurements, the math-channel impedance calculation is no longer needed.

The first-order filter explanations and experiments are in Section 2. The following experiments extend those ideas. A second-order low-pass or high-pass response can have a stopband slope of 40 dB per decade, compared with 20 dB per decade for a first-order response. A second-order low-pass phase can approach −180°.

A circuit containing two reactive components does not automatically have the same response as every other second-order circuit. Their connection and damping determine the shape.

### Main experiment: design and build your assigned RLC filter

Use the **numerical part of your group identifier**, following the same allocation as Section 2:

| Group number | Assigned RLC response |
| --- | --- |
| Odd, for example A01 or B03 | Low-pass |
| Even, for example A02 or B04 | High-pass |

**Retain your group's individual corner frequency from the allocation table at the end of this section.** The group numbers determine the filter type; the frequency is separately specified for each group. Each group builds one RLC configuration, not both.

The table specifies the **−3 dB corner frequency**, not the natural frequency. Choose $L$, $C$ and $R$ to achieve that corner within **10%** of the target, with approximately critical damping.

#### Low-pass circuit: odd-numbered groups

Connect $R$ and $L$ in series from the input to the output, and connect $C$ from the output to ground. Measure the output across the capacitor.

<p align="center">
  <img src="graphics/RLClow.png" alt="RLC low-pass topology; any component values shown are a worked example" width="650">
</p>

**Any component values shown in this diagram are a worked example. Choose your own values for your assigned corner frequency.**

At low frequency, the capacitor has a large impedance and the output approaches the input. At high frequency, the inductor impedes current and the capacitor shunts the output towards ground. The ideal transfer function is:

$$
T_\mathrm{LP}(s)=\frac{1}{LCs^2+RCs+1},
\qquad s=j\omega.
$$

#### High-pass circuit: even-numbered groups

Connect $R$ and $C$ in series from the input to the output, and connect $L$ from the output to ground. Measure the output across the inductor.

<p align="center">
  <img src="graphics/RLChigh.png" alt="RLC high-pass topology for even-numbered groups" width="650">
</p>

At low frequency, the series capacitor has a large impedance and the inductor has a small impedance, so the output is small. At high frequency, the capacitor's impedance decreases and the inductor's increases, so the output approaches the input. The ideal transfer function is:

$$
T_\mathrm{HP}(s)=\frac{LCs^2}{LCs^2+RCs+1}.
$$

These expressions assume ideal reactive components. Include winding resistance in the inductor branch when simulating the real circuit; it can affect the numerator as well as the damping of the high-pass circuit.

#### Selecting component values

Both ideal circuits have natural frequency and damping ratio:

$$
\omega_n=\frac{1}{\sqrt{LC}},
\qquad
\zeta=\frac{R}{2}\sqrt{\frac{C}{L}}.
$$

For critical damping, $\zeta=1$:

$$
R_\mathrm{total}=2\sqrt{\frac{L}{C}}.
$$

Critical damping gives a monotonic ideal response without a resonant gain peak. **The natural frequency is different from the −3 dB corner.** For critical damping:

$$
f_{c,\mathrm{LP}}\approx0.644f_n,
\qquad
f_{c,\mathrm{HP}}\approx1.554f_n.
$$

1. Read your assigned −3 dB corner $f_c$ from the table.
2. Calculate the required natural frequency: $f_n=f_c/0.644$ for low-pass, or $f_n=f_c/1.554$ for high-pass.
3. Calculate the required product $LC=1/(2\pi f_n)^2$.
4. Select available $L$ and $C$ values, using sensible series or parallel combinations where needed. Recalculate the predicted corner from your actual choices.
5. Calculate the critical-damping total resistance. Use the inductor winding resistance estimated in Section 2 to choose an external resistor approximately equal to the required total minus that winding resistance. If this would require a negative resistance, choose a different combination of $L$ and $C$.
6. Simulate the complete circuit with your chosen values, including winding resistance, and check the predicted corner and response shape.

As a **worked example only**, 100 mH and 100 nF give $f_n\approx1.59\,\mathrm{kHz}$ and an ideal critical-damping total resistance of 2 kΩ. The corresponding low-pass corner is approximately **1.02 kHz**, while the high-pass corner is approximately **2.47 kHz**. This illustrates why the same component values do not give the same −3 dB corner for the two critically damped configurations.

The resistance adjustment is a starting approximation. In a real high-pass circuit, winding resistance changes the low-frequency response as well as the damping. Use the simulated and measured response to assess the result.

#### Building and measuring your assigned filter

1. Record your assigned type and target frequency, chosen component values and predicted corner in your lab book.
2. With the generator output off, build the appropriate circuit. Connect CH1 to the input and CH2 to the output; both probe ground clips go to common ground.
3. Apply a sine wave with 0 V offset and initially 1 V peak amplitude. Check that the actual input remains sinusoidal.
4. Use a copy of the measurement table below. Add readings at approximately **0.5, 0.8, 1.0, 1.2 and 2 times your assigned corner**, keeping the overall sweep within 10 Hz–40 kHz. Merge duplicate or very close frequencies rather than repeating them.
5. Find the measured passband gain: low-frequency gain for low-pass, or high-frequency gain for high-pass. Locate the frequency where the magnitude is **0.707 times that gain**, or 3 dB below its level. Add intermediate readings if necessary.
6. Plot magnitude in dB and phase against logarithmic frequency. Compare the corner, roll-off and phase with the simulation, and explain discrepancies using tolerances, winding resistance and measurement limits.

At high frequency, an RLC high-pass filter approaches unity gain, but its ideal phase approaches **0°**, not +180°. At low frequency its ideal phase approaches +180°. For the low-pass circuit, phase moves from approximately 0° towards −180°. When readings wrap between +180° and −180°, describe the same continuous phase trend consistently.

- [ ] Build and characterise your assigned RLC filter.
- [ ] Compare the measured −3 dB corner with your assigned target and explain why it differs from the natural frequency.
- [ ] Compare the second-order roll-off with the first-order response from Section 2.

### Filter measurement table

Use one copy for the main RLC experiment and another for the RC comparison challenge. Add frequencies around your assigned RLC corner as instructed above. For the notch challenge, use its separately specified frequencies with these same columns. Record phase directly; a separate delay column is not required.

| Frequency (Hz) | Input peak-to-peak voltage (V) | Output peak-to-peak voltage (V) | Magnitude ratio | Gain (dB) | Phase (°) |
| --- | --- | --- | --- | --- | --- |
| 10 | | | | | |
| 100 | | | | | |
| 300 | | | | | |
| 600 | | | | | |
| 1000 | | | | | |
| 1600 | | | | | |
| 3000 | | | | | |
| 6000 | | | | | |
| 10000 | | | | | |
| 20000 | | | | | |
| 40000 | | | | | |

### Challenge: compare the RLC filter with a cascaded RC filter

All groups attempting this challenge build the **RC low-pass ladder** below.

- **Odd-numbered groups:** compare it with your own RLC low-pass measurements.
- **Even-numbered groups:** compare it with the RLC low-pass measurements of an odd-numbered group. Identify the group supplying the comparison data and keep your own RC readings clearly labelled.

The RLC groups have different assigned corners, so compare both the actual frequency plots and the response shapes relative to each circuit's own −3 dB corner. Identical corners are not expected.

Use:

$$
R_1=R_2=1\,\mathrm{k}\Omega,
\qquad
C_1=C_2=100\,\mathrm{nF}.
$$

Use these component values for the experiment; they give the intended frequency range for the comparison.

Connect $R_1$ from the input to the first node and $C_1$ from that node to ground. Connect $R_2$ from the first node to the output, and $C_2$ from the output to ground.

<p align="center">
  <img src="graphics/second_order_rc_lowpass.png" alt="second order rc lowpass" width="700">
</p>

At low frequency, both capacitors have large impedances, little current flows through the resistors, and the output approaches the input. At high frequency, the capacitors increasingly shunt the signal to ground and the output falls.

The second stage loads the first. Therefore the complete transfer function is **not** simply the product of two isolated identical RC responses. For equal resistors and capacitors, with a negligible additional output load:

$$
T(s)=\frac{1}{1+3sRC+s^2R^2C^2},
\qquad s=j\omega.
$$

The component time constant gives $1/(2\pi RC)\approx1.59\,\mathrm{kHz}$, but this is **not the −3 dB frequency of the loaded ladder**. Its −3 dB point is approximately 0.374 times this value, about 596 Hz.

<p align="center">
  <img src="graphics/second_order_filter_trends.png" alt="second order filter trends" width="700">
</p>

1. Predict the response in LTspice using the complete connected circuit.
2. Build the ladder and connect CH1 to its input and CH2 to its output.
3. Measure at the frequencies in a fresh copy of the filter table above, adding points around the measured transition if needed.
4. Plot magnitude in dB and phase against logarithmic frequency, following Section 2's measurement method.
5. Overlay its magnitude and phase measurements with the selected RLC low-pass results. Both should approach a second-order roll-off, but their corners and transition shapes need not match. The RC ladder has a predicted −3 dB corner near 596 Hz; the RLC target is group-specific. For a shape comparison, you may additionally plot against normalised frequency $f/f_c$, using each circuit's own measured corner.
6. Compare with the simulation and explain the loading effect. At high frequency, mark readings that approach the noise floor rather than assuming their phase is reliable.

- [ ] Compare the RLC and RC filters: low-frequency gain, −3 dB corner, stopband slope and phase. Explain which features are shared and which differ.
- [ ] Explain why cascading unbuffered stages changes the response compared with two isolated stages.

### Challenge: build a Twin-T notch filter

A notch, or band-stop, filter rejects a band around a particular frequency while passing lower and higher frequencies. It is useful for suppressing an unwanted tone. This differs from a band-pass filter, which passes frequencies around its centre and attenuates those away from it.

Use the **Twin-T topology shown below**: two T networks connected in parallel between input and output. One T has two series resistors and a midpoint capacitor to ground; the other has two series capacitors and a midpoint resistor to ground.

<p align="center">
  <img src="graphics/twin_t_notch.png" alt="twin t notch" width="700">
</p>

For the balanced ideal circuit:

$$
R_1=R_2=R,\quad R_3=R/2,\qquad C_1=C_2=C,\quad C_3=2C,
$$

and:

$$
f_0=\frac{1}{2\pi RC}.
$$

Design for a notch frequency of approximately **1.6 kHz**, choosing components from the available-parts list. The two paths cancel at the ideal notch frequency. Component mismatch, source and load effects, and measurement noise limit the depth of a real notch.

<p align="center">
  <img src="graphics/notch_filter_trends.png" alt="notch filter trends" width="700">
</p>

1. Choose $R$ and $C$ and obtain the balancing values $R/2$ and $2C$. Use series or parallel combinations where they improve the match.
2. Calculate the predicted notch frequency and simulate the circuit.
3. Build it and connect CH1 to the input and CH2 to the output, with both grounds at common ground.
4. Begin at **100, 300, 600, 1000, 1200, 1400, 1600, 1800, 2000, 2400, 3000, 6000, 10000 and 40000 Hz**. Use the filter table columns above.
5. Add finer frequency steps near the minimum to find its location and depth. A very small output makes the phase unreliable; at an ideal zero-output notch, output phase is undefined.
6. Compare the measured response with the simulation and explain any difference in notch frequency or depth.

- [ ] Show your selected component values and the measured notch response.
- [ ] Explain how cancellation produces the notch and why the measured output does not reach exactly zero.

### Available components

**Resistors ( $\times10^0\Omega$ to $\times10^6\Omega$ )**

| | | | | | | | |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 1.0 | 1.1 | 1.2 | 1.3 | 1.5 | 1.6 | 1.8 | 2.0 |
| 2.2 | 2.4 | 2.7 | 3.0 | 3.3 | 3.6 | 3.9 | 4.3 |
| 4.7 | 5.1 | 5.6 | 6.2 | 6.8 | 7.5 | 8.2 | 9.1 |

**Capacitors (multilayer ceramic)**

| | | | | | |
| --- | --- | --- | --- | --- | --- |
| 1 nF | 2.2 nF | 4.7 nF | 10 nF | 22 nF | 33 nF |
| 47 nF | 68 nF | 100 nF | 220 nF | 470 nF | 1 µF |

**Inductors**

|    |    |    |
| -- | -- | -- |
| 1mH | 2.2mH | 3.3mH |
| 4.7mH | 10mH | 22mH |
| 33mH | 47mH | 100mH |

### Group allocations for the main RLC experiment

The frequency in this table is the target **−3 dB corner**, in hertz. Odd-numbered groups build low-pass (LP); even-numbered groups build high-pass (HP). Use the assigned frequency even if it differs from another group with the same filter type.

| Pair | Type | Frequency (Hz) | Pair | Type | Frequency (Hz) | Pair | Type | Frequency (Hz) |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| A01 | LP | 1900 | A38 | HP | 8700 | B20 | HP | 7400 |
| A02 | HP | 8700 | A39 | LP | 5100 | B21 | LP | 8800 |
| A03 | LP | 7400 | A40 | HP | 4000 | B22 | HP | 5300 |
| A04 | HP | 1800 | A41 | LP | 3400 | B23 | LP | 1100 |
| A05 | LP | 8800 | A42 | HP | 5900 | B24 | HP | 4900 |
| A06 | HP | 1900 | A43 | LP | 4000 | B25 | LP | 7300 |
| A07 | LP | 8800 | A44 | HP | 1900 | B26 | HP | 2800 |
| A08 | HP | 5000 | A45 | LP | 4900 | B27 | LP | 4400 |
| A09 | LP | 2800 | A46 | HP | 5900 | B28 | HP | 2000 |
| A10 | HP | 2700 | A47 | LP | 2800 | B29 | LP | 2300 |
| A11 | LP | 2300 | A48 | HP | 6600 | B30 | HP | 5000 |
| A12 | HP | 1900 | A49 | LP | 2300 | B31 | LP | 1500 |
| A13 | LP | 4900 | A50 | HP | 6100 | B32 | HP | 5100 |
| A14 | HP | 5000 | A51 | LP | 5000 | B33 | LP | 2300 |
| A15 | LP | 5300 | A52 | HP | 5900 | B34 | HP | 2300 |
| A16 | HP | 5900 | A53 | LP | 7300 | B35 | LP | 3400 |
| A17 | LP | 7400 | A54 | HP | 8900 | B36 | HP | 4900 |
| A18 | HP | 7300 | A55 | LP | 2800 | B37 | LP | 3400 |
| A19 | LP | 4100 | B01 | LP | 4500 | B38 | HP | 3300 |
| A20 | HP | 1700 | B02 | HP | 7400 | B39 | LP | 2400 |
| A21 | LP | 7400 | B03 | LP | 3400 | B40 | HP | 3300 |
| A22 | HP | 5900 | B04 | HP | 1400 | B41 | LP | 2300 |
| A23 | LP | 3400 | B05 | LP | 6100 | B42 | HP | 5100 |
| A24 | HP | 1600 | B06 | HP | 1900 | B43 | LP | 2700 |
| A25 | LP | 8700 | B07 | LP | 1600 | B44 | HP | 5000 |
| A26 | HP | 8800 | B08 | HP | 1600 | B45 | LP | 3400 |
| A27 | LP | 3400 | B09 | LP | 4400 | B46 | HP | 4800 |
| A28 | HP | 8800 | B10 | HP | 1700 | B47 | LP | 5900 |
| A29 | LP | 8700 | B11 | LP | 1100 | B48 | HP | 8700 |
| A30 | HP | 970 | B12 | HP | 4900 | B49 | LP | 1100 |
| A31 | LP | 730 | B13 | LP | 5900 | B50 | HP | 7300 |
| A32 | HP | 3400 | B14 | HP | 1900 | B51 | LP | 7300 |
| A33 | LP | 3400 | B15 | LP | 2300 | B52 | HP | 2100 |
| A34 | HP | 5900 | B16 | HP | 2300 | B53 | LP | 8800 |
| A35 | LP | 4000 | B17 | LP | 4400 | B54 | HP | 1400 |
| A36 | HP | 3400 | B18 | HP | 5900 | B55 | LP | 5900 |
| A37 | LP | 1700 | B19 | LP | 8900 |  |  |  |

LP: low-pass; HP: high-pass.

