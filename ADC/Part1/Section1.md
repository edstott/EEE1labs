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

The same current flows through both components. If the instantaneous voltage across the known resistor is $v_R$, then:

$$
i=\frac{v_R}{R}.
$$

In the initial experiment, both components are resistors, so their voltages and current are in phase. The unknown resistance can therefore be calculated from the ratio of their voltage amplitudes.

For capacitors and inductors, voltage and current may have different phases. We describe these sinusoidal quantities using complex voltages and currents, or **phasors**. Uppercase $V$ and $I$ denote phasors; lowercase $v$ and $i$ denote instantaneous signals.

Using phasors:

$$
I=\frac{V_R}{R},
\qquad
Z=\frac{V_Z}{I}=R\frac{V_Z}{V_R}.
$$

If we measure only the amplitudes of the two voltages, we obtain the **magnitude of the impedance**:

$$
|Z|=R\frac{|V_Z|}{|V_R|}.
$$

The phase difference between these voltages provides the phase of the impedance:

$$
\arg(Z)=\arg(V_Z)-\arg(V_R).
$$

This works because the voltage across a resistor is in phase with the current through it. We will return to reactive components in Section 2.

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
- Use **DC coupling** so that the channels measure the complete signals without introducing additional low-frequency attenuation and phase shifts.
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

You can use peak, peak-to-peak or RMS values in this ratio, provided you use the **same measurement convention for both sinusoidal signals**.

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

### Recognising unreliable measurements and choosing R

The impedance magnitude is calculated from:

$$
|Z|=R\frac{|V_Z|}{|V_R|}.
$$

The accuracy of this result depends on the accuracy of the known resistance and both voltage measurements. Component tolerances, electrical noise, oscilloscope resolution and probe loading can all introduce errors.

The choice of test resistor $R$ is particularly important. Aim to make $R$ similar in magnitude to the unknown impedance $|Z|$, so that both voltage signals can be measured clearly. They do not need to be exactly equal, but a very large difference makes one of the measurements difficult.

For a capacitor or inductor, $|Z|$ changes with frequency. A test resistor that works well at one frequency may therefore be unsuitable at another.

#### When R is too large

If $R$ is much larger than $|Z|$, most of the input voltage appears across $R$, leaving only a small voltage across $Z$.

The CH2 signal may then become comparable with electrical noise or the smallest voltage changes the oscilloscope can resolve. Even a small absolute error becomes a large percentage error in this small voltage.

**Decrease R** to increase the proportion of the input voltage appearing across $Z$ and make it easier to measure.

*The voltage across Z is small and noisy, even at a sensitive vertical-scale setting. Decreasing R can improve this measurement.*

![Small and noisy voltage signal across the unknown impedance](graphics/PN-noisy.png)

#### When R is too small

If $R$ is much smaller than $|Z|$, most of the input voltage appears across $Z$. CH1 and CH2 then display nearly identical waveforms.

The math channel calculates:

$$
v_R=v_\mathrm{in}-v_Z.
$$

In this case, it is subtracting two relatively large, nearly equal signals to obtain a small difference. Noise, limited resolution and small differences between the channel or probe responses can become significant compared with that difference.

The resulting math trace may look noisy or blocky, and its amplitude may be unreliable. Enlarging the math trace on the display does not recover detail that was missing from the original channel measurements.

**Increase R** to increase the voltage across it and produce a better-resolved math-channel signal.

*The math-channel waveform is blocky because the small difference between the two measured signals is poorly resolved. Increasing R makes this difference larger.*

![Poorly resolved and quantised math-channel waveform](graphics/PN-mathnoise.png)

#### Choosing a practical resistance

Start with $R=1\,\mathrm{k}\Omega$ and examine both CH2 and the math trace.

- If the voltage across $Z$ is too small or noisy, **decrease R**.
- If the math-channel voltage across $R$ is too small or poorly resolved, **increase R**.
- Adjust the vertical scales of both input channels so that the waveforms occupy a useful portion of the display without clipping.
- If you have an approximate theoretical value of $|Z|$, choose an available resistor of a similar magnitude.
- Whenever you change $R$, record its new value and use it in the impedance calculation.

As practical starting points, if the voltage across $Z$ is below about **5 mV RMS** and cannot be resolved clearly, try a smaller resistor. If the math-channel waveform is less than about **one vertical division peak-to-peak**, check the input-channel scaling and try a larger resistor.

These are guides rather than guarantees of accuracy. Always inspect the waveforms. Change the resistance in sensible steps; a factor of ten is often useful. For this experiment, do not reduce the test resistance below **10 Ω**.

#### When both R and Z are small

Choosing $R$ similar to $|Z|$ helps balance the two voltage measurements, but it does not solve every measurement problem.

If both are small, the circuit presents a low impedance to the signal generator. Maintaining the same input voltage would require a larger current:

$$
I=\frac{V_\mathrm{in}}{R+Z},
$$

where the quantities in this expression are phasors.

A real signal generator has an internal source resistance and a limited output-current capability. Under heavy loading, its terminal voltage can fall. If its output stage approaches its current limit, the waveform may also become distorted. Small measured voltages can additionally make noise more prominent.

Consequently, reducing $R$ may increase the proportion of voltage across $Z$ while also increasing the load on the generator.

Check the actual input waveform on CH1 whenever you use small impedances:

- Confirm that it remains a clean sine wave.
- Measure the actual input rather than assuming it equals the generator’s displayed setting.
- If the waveform becomes distorted, reduce the generator amplitude or increase $R$, then check that both measured voltages are still large enough to resolve.
- If you cannot obtain clean, measurable signals, ask a demonstrator for help.

A reduction in input amplitude alone does not invalidate the voltage-ratio method, provided both voltages are measured accurately and the circuit remains linear. Distortion is more problematic: a distorted waveform contains several frequencies, so its amplitude ratio cannot generally be interpreted as the impedance magnitude at one frequency.

#### Other sources of error

**Resistor tolerance:** the actual test resistance may differ from its labelled value. Measure it with a multimeter while the circuit is unpowered and the resistor is isolated from other current paths. Use the measured value in your calculation.

**Probe and channel mismatch:** both probes must have the same attenuation setting, with matching settings on the oscilloscope. Check probe compensation. Differences in gain or phase between the channels can introduce errors when their signals are subtracted.

**Probe loading:** a probe has a finite input resistance and capacitance, so connecting it changes the circuit slightly. This becomes more important when measuring large impedances or working at higher frequencies. The ×10 setting reduces this loading compared with ×1 operation.

**Noise and connections:** loose contacts, long leads and poor grounding can produce unstable or noisy readings. Keep connections short and secure, and connect both probe ground clips to the circuit’s common ground.

**Measurement consistency:** use the same amplitude convention for both voltages. Check automatic measurements against the displayed waveforms, especially when a signal is small or noisy.

- [ ] Check that both the voltage across Z and the math-channel voltage across R are clearly resolved.
- [ ] Explain whether R should be increased or decreased if either measurement becomes unreliable.
- [ ] Record any changes to R and any limitations affecting your measurements.

## Challenge: source impedance of the signal generator

A real signal generator does not behave as an ideal voltage source. Its output can be represented by a **Thévenin equivalent circuit**: an ideal voltage source in series with a source resistance $R_\mathrm{source}$.

![Equivalent circuit of a signal generator](graphics/sigeneq.png)

When a load resistance is connected, current flows through both the source resistance and the load. Some of the source voltage is dropped across $R_\mathrm{source}$, so the voltage at the output terminals decreases.

This is the loading effect discussed above. In this challenge, we model the source impedance as a resistance at the chosen test frequency.

![Equivalent circuit of a signal generator connected to a load](graphics/sigenloadeq.png)

The two resistances form a potential divider:

$$
V_\mathrm{out}
=
V_\mathrm{source}
\frac{R_\mathrm{load}}
{R_\mathrm{load}+R_\mathrm{source}}.
$$

Because this model contains only resistances, the same divider relationship applies to the voltage amplitudes.

You will determine $R_\mathrm{source}$ from two output-voltage measurements.

1. Keep the signal generator’s frequency, amplitude, DC offset and load-display setting unchanged throughout the experiment.
2. Connect a $10\,\mathrm{k}\Omega$ load across the output and measure the output-voltage amplitude.
3. Replace it with a $200\,\Omega$ load and measure the output-voltage amplitude again.
4. Use the same amplitude measurement convention for both readings and check that the output remains sinusoidal.
5. Write the potential-divider equation for each load and solve the two simultaneous equations for the source-voltage amplitude and $R_\mathrm{source}$.

The internal source voltage is the same in both equations because the generator settings remain unchanged and the generator is operating within its linear range. The measured output voltage changes because the load changes.

- [ ] Determine the source resistance of the signal generator using the two loads.
- [ ] Explain which load gives the lower output voltage and why.
- [ ] Explain what happens to the output voltage when the load resistance is much larger than the source resistance.
