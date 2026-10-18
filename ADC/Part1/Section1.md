# Analysis and Design of Circuits Lab
# Part 1: Autumn Term weeks 4–6

This laboratory explores passive components: resistors, capacitors and inductors, and how they can be combined to make frequency-dependent circuits.

In Section 1, you will learn how to measure impedance using a known resistor and an oscilloscope. [Section 2](Section2.md) explores reactive components and first-order filters. [Section 3](Section3.md) investigates resonance and second-order filters.

## Section 1: Measuring Impedance

### The measurement principle

For a resistor, Ohm’s law relates the voltage across it to the current through it. Impedance extends this idea to components such as capacitors and inductors when we analyse sinusoidal signals.

To determine a component’s impedance, we need to know the voltage across it and the current through it. However, an oscilloscope probe measures voltage rather than current.

We can determine the current indirectly by placing a known resistor $R$ in series with the unknown impedance $Z$:

![Potential divider with unknown impedance](graphics/Zdiv.png)

The same current flows through both components. If the voltage across the known resistor is $v_R$, then:

$$
i=\frac{v_R}{R}.
$$

For the initial experiment, both components are resistors, so their voltages and current are in phase. The unknown resistance can therefore be calculated from:

$$
Z=\frac{v_Z}{i}=R\frac{v_Z}{v_R}.
$$

For capacitors and inductors, the voltage and current may have different phases. The corresponding relationship uses complex voltages, or phasors:

$$
Z=R\frac{V_Z}{V_R}.
$$

If we measure only the amplitudes of the two voltages, we obtain the **magnitude of the impedance**:

$$
|Z|=R\frac{|V_Z|}{|V_R|}.
$$

The phase difference between these voltages provides the phase of the impedance. We will return to reactive components in Section 2.

### Connecting the oscilloscope correctly

The oscilloscope channels measure voltages relative to a common ground. Their probe ground clips are connected together inside the instrument and, in this setup, share the signal generator’s ground.

**Both probe ground clips must connect to the circuit’s common ground.** They cannot be connected to different circuit nodes without joining those nodes together electrically.

Connect the probes as follows:

- Connect the **CH1 probe tip** to the top of the divider to measure $v_A$, which is also $v_\mathrm{in}$.
- Connect the **CH2 probe tip** to the junction between $R$ and $Z$ to measure $v_Z$.
- Connect **both probe ground clips** to the bottom of $Z$, at the circuit’s common ground.

The channels are also referred to as CHA and CHB in the instructions and figures: CHA corresponds to CH1, and CHB to CH2.

![Correct oscilloscope connections for measuring impedance](graphics/Zdivscope.png)

Each channel now measures a voltage relative to the same reference node. From Kirchhoff’s voltage law:

$$
v_A=v_R+v_Z.
$$

Therefore, the voltage across the known resistor is:

$$
v_R=v_A-v_Z.
$$

The oscilloscope’s **math channel** performs this subtraction, sample by sample, when set to **CH1 − CH2**.

Subtract the waveforms using the math channel before measuring the amplitude of $v_R$. For reactive components, subtracting the two amplitude readings alone generally gives the wrong answer because the waveforms may have different phases.

### Why a probe must not be connected directly across R

It may seem natural to measure $v_R$ by connecting a probe tip to the top of $R$ and its ground clip to the junction between $R$ and $Z$.

However, the ground clip is already connected internally to the signal generator’s ground. Connecting it to the junction creates a conducting path from the junction to the bottom of $Z$. This **short-circuits $Z$** and changes the circuit being measured.

<!-- Add the redrawn incorrect-connection diagram here. Show the probe ground clip connected to the R–Z junction and highlight the resulting short-circuit path across Z. -->

The probe ground clip cannot be treated as an independent negative measurement terminal. Keep both ground clips at the common ground and use the math channel to calculate the voltage across $R$.

### Before taking measurements

For each measurement:

- Check that the circuit and both probe ground clips share the same common ground.
- Set both probe switches to **×10** and configure both oscilloscope channels for **×10 probes**.
- Use **DC coupling** initially so that the displayed waveforms include any DC offset.
- Adjust the vertical scales so that both measured waveforms occupy a useful portion of the display without clipping.

Matching the physical probe settings to the oscilloscope settings is essential for correct voltage readings.

### Checking the method with two resistors

Begin with two equal resistors so that you can check the measurement method before using a capacitor or inductor.

1. Build the potential-divider circuit with $R=1\,\mathrm{k}\Omega$ and a second $1\,\mathrm{k}\Omega$ resistor in the position labelled $Z$.
2. Connect CH1 to measure $v_A=v_\mathrm{in}$ and CH2 to measure $v_Z$, following the grounding instructions above.
3. Set the signal generator to a **100 Hz sine wave**, with **1 V peak amplitude** (2 V peak-to-peak) and **0 V DC offset**. Check the actual input voltage on CH1; the generator’s displayed amplitude may depend on its load setting.
4. Set the oscilloscope timebase to **5 ms/div**.
5. Select **CH1 as the trigger source**, use **Auto trigger mode**, and place the trigger level near the centre of the CH1 waveform.

We use a sine wave because sinusoidal measurements will also allow us to characterise capacitors and inductors.

![Potential divider built on a breadboard](graphics/PN-breadboard.jpg)

Press `MATH` and select `CH1`, `SUB` and `CH2` to display:

$$
v_R=\mathrm{CH1}-\mathrm{CH2}.
$$

You can hide CH1 by pressing its channel button twice. It will still be used to calculate the math trace and provide the trigger.

Since the two resistors are equal, the input voltage should divide equally between them. The $v_R$ and $v_Z$ waveforms should therefore have approximately equal amplitudes and be in phase.

![Oscilloscope display showing the math-channel measurement](graphics/PN-math.png)

Identify the traces by their channel labels rather than relying only on their colours.

- [ ] Display $v_R$ using the math channel and compare it with $v_Z$.
- [ ] Confirm that $v_R\approx v_Z$ when the two resistors are equal.
- [ ] Use the measured voltage ratio and the known resistance to calculate the resistance of the component in the position labelled $Z$.

Small differences are expected because real resistors have tolerances and voltage measurements have finite accuracy.

### Measuring voltage amplitudes

When the two components are different, measure the amplitudes of both $v_Z$ and $v_R$ and calculate:

$$
|Z|=R\frac{|V_Z|}{|V_R|}.
$$

You can use peak, peak-to-peak or RMS values in this ratio, provided you use the **same measurement convention for both signals**.

For a sine wave with zero DC offset:

$$
V_\mathrm{pp}=2V_\mathrm{peak},
\qquad
V_\mathrm{RMS}=\frac{V_\mathrm{peak}}{\sqrt{2}}.
$$

The conversion factor cancels in the voltage ratio. For example:

$$
|Z|=R\frac{V_{Z,\mathrm{pp}}}{V_{R,\mathrm{pp}}}
   =R\frac{V_{Z,\mathrm{RMS}}}{V_{R,\mathrm{RMS}}}.
$$

Do not divide a peak-to-peak reading for one waveform by an RMS reading for the other.

#### Using cursors

Peak-to-peak measurements are convenient with cursors because the waveform’s maximum and minimum are easier to identify than its exact centre.

Place one voltage cursor at the positive peak and the other at the negative peak. Their difference gives the peak-to-peak voltage.

Measure $v_Z$ on CH2 and $v_R$ on the math channel.

#### Using automatic measurements

Using cursors repeatedly can be laborious, so the oscilloscope also provides automatic measurement functions.

Press `AUTO MEASURE` to enable measurements. You can display up to six measurements and select the source and measurement type for each.

Add the following measurements for both **CH2** ($v_Z$) and **MATH** ($v_R$):

- Amplitude
- Peak-peak
- RMS

Check what each function measures. In oscilloscope menus, **“Amplitude” does not necessarily mean the mathematical peak amplitude**. It commonly measures the difference between estimated upper and lower waveform levels, so it may be close to the peak-to-peak reading.

The peak-to-peak function uses the waveform’s extreme values and can be affected by noise spikes. The amplitude function estimates the waveform levels and may be less sensitive to occasional spikes. Compare the automatic readings with your cursor measurements rather than assuming that every function gives the same quantity.

RMS measurements may include a DC component, depending on the selected function. For the zero-offset sine waves used here, compare the readings with the sine-wave relationship above.

- [ ] Compare the automatic amplitude and peak-to-peak readings with your cursor measurements.
- [ ] Check whether the RMS readings are consistent with those expected for a sine wave.
- [ ] Compare with an AC voltage measurement from the multimeter, ensuring that the signal frequency is within its specified measurement range.

### Recognising unreliable measurements

The math channel calculates the difference between two measured waveforms. If those waveforms are almost identical, their difference may be small compared with the noise or resolution of either measurement.

Similarly, if the voltage across $Z$ is very small, it may be difficult to measure accurately.

Before accepting a result, check that both $v_Z$ and $v_R$ are clearly resolved and that their amplitudes are stable. Section 2 explains how changing the test resistor $R$ can improve the measurement when the unknown impedance varies with frequency.

## Challenge: source impedance of the signal generator

A real signal generator does not behave as an ideal voltage source. Its output can be represented by a **Thévenin equivalent circuit**: an ideal voltage source in series with a source resistance $R_\mathrm{source}$.

![Equivalent circuit of a signal generator](graphics/sigeneq.png)

When a load resistance is connected, current flows through both the source resistance and the load. Some of the source voltage is dropped across $R_\mathrm{source}$, so the voltage at the output terminals decreases.

![Equivalent circuit of a signal generator connected to a load](graphics/sigenloadeq.png)

The two resistances form a potential divider:

$$
v_\mathrm{out}
=
v_\mathrm{source}
\frac{R_\mathrm{load}}
{R_\mathrm{load}+R_\mathrm{source}}.
$$

You will determine $R_\mathrm{source}$ from two output-voltage measurements.

1. Keep the signal generator’s frequency, amplitude, DC offset and load-display setting unchanged throughout the experiment.
2. Connect a $10\,\mathrm{k}\Omega$ load across the output and measure the output-voltage amplitude.
3. Replace it with a $200\,\Omega$ load and measure the output-voltage amplitude again.
4. Use the same amplitude measurement convention for both readings.
5. Write the potential-divider equation for each load and solve the two simultaneous equations for $v_\mathrm{source}$ and $R_\mathrm{source}$.

The internal source voltage $v_\mathrm{source}$ is the same in both equations because the generator settings remain unchanged. The measured output voltage changes because the load changes.

- [ ] Determine the source resistance of the signal generator using the two loads.
- [ ] Explain which load gives the lower output voltage and why.
- [ ] Explain what happens to the output voltage when the load resistance is much larger than the source resistance.
