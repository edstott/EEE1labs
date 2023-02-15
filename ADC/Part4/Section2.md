# Analysis and Design of Circuits Lab
# Part 4: Spring Term weeks 7--10

## Amplifier Stages

        An opamp should have a very high voltage gain, which we can achieve with a common emitter amplifier.
        
            \begin{center}
            \input{graphics/CEamp}
            
            \emph{Common Emitter Amplifier}
            \end{center}
            
        The base of the transistor is biased from \Vcc via \EEsym{R}{B} --- select a value that will result in a collector current of 1mA. The capacitor blocks any bias current from the input. \EEsym{R}{C} should be selected to set \Vout at 0V under quiescent conditions.
    
        \begin{task}
            Choose bias resistors for the common emitter amplifier and confirm with a DC operating point simulation
        \end{task}
    
        \subsection{Gain}
            The gain of the amplifier can be analysed using the small signal equivalent circuit:
        
            \begin{center}
            \input{graphics/CEequiv}
            
            \emph{Small signal equivalent of CE amplifier}
            \end{center}
            
            \EEsym{r}{be} is the input resistance of the transistor:
            \begin{equation}
                r_\text{be}=\frac{\beta}{g_\text{m}}
            \end{equation}
            
            \EEsym{r}{o} is the small signal output impedance:
            \begin{equation}
            		r_\mathrm{0} \approx \frac{V_\mathrm{A}}{I_\mathrm{C}}
            \end{equation}
            
            \EEsym{g}{m} is the small signal transconductance of the transistor which relates the change in collector output current to the change in base-emitter input voltage:
            
            \begin{equation}
                g_\text{m}=\frac{\mathrm{d}I_\text{C}}{\mathrm{d}V_\text{BE}}=\frac{I_\text{C}}{V_\text{T}}
            \end{equation}
            
            The gain can be derived from the equivalent circuit:
            
            \begin{equation}
                \label{eq:cegain}
                A_\text{V}=\frac{v_\text{o}}{v_\text{in}}=-g_\text{m}\left(\frac{R_\text{C}r_\text{o}}{R_\text{C}+r_\text{o}}\right)
            \end{equation}
    
            \begin{task}
                Calculate the theoretical gain of the amplifier
            \end{task}
            
            The gain of a circuit is usually simulated with an AC analysis, which uses a small signal model of the circuit derived from an initial computation of the DC operating point. the output is a plot of the circuit's transfer function. Run an AC analysis by:
            
            \begin{enumerate}[noitemsep]
                \item Add net labels to the input and output nodes
                \item Set the amplitude of the input source to 1 by opening the source properties and entering `1' in the box `AC amplitude'
                \item Edit the simulation command and choose the `AC analysis' tab
                \item Choose a decade sweep with 100 points per decade. Set the start frequency to `10' (10Hz) and the stop frequency to `100meg' (100MHz)
                \item Run the simulation
                \item Select the output node. This will add lines showing the transfer function of the circuit as a gain (in dB) and phase
            \end{enumerate}
            
            This circuit should give an output of around 45dB in the passband. Since the input amplitude was 1 (0dB), that makes the gain 45dB, which is around $A_\text{V}=180$. In a real circuit, an input amplitude of 1V would cause the output to clip, but for an AC analysis this doesn't matter because the small signal model is a \emph{linearised} representation of the circuit around the DC bias point. The gain would be the same whatever input amplitude is specified. You will also see that the gain rolls off at low and high frequency. The low frequency rolloff is caused by the input coupling capacitor and the high frequency rolloff is caused by the internal parasitic capacitance of the transistor.
            
            \begin{task}
                Perform an AC analysis to find the gain of the circuit.
            \end{task}
    
        \subsection{Input resistance}
            \label{s:CEinputR}
            Ideally, voltage amplifiers would have infinite input resistance, to ensure that all of the signal voltage from the source is transferred to the input of the amplifier. The input resistance given by the small signal model for our amplifier is:
            
            \begin{equation}
                r_\text{IN} = \frac{R_\text{B}r_\text{be}}{R_\text{B}+r_\text{be}}
            \end{equation}
            
            We can find $R_\text{IN}$ in simulation by finding the effect of adding a series resistor to the input. If the amplifier did have infinite input resistance then this resistor would have no effect because there would be no current flowing through it. Add a 10kΩ resistor in series with the capacitor and run the simulation again. You will find the gain has reduced --- call the new gain $A'_\text{V}$ (in $V/V$, not dB). You can now calculate the input resistance of the amplifier as:
            
            \begin{equation}
                A'_\text{V} = A_\text{V} \frac{R_\mathrm{IN}}{R_\mathrm{IN}+10\mathrm{k}}
            \end{equation}
            \begin{equation}
                R_\mathrm{IN} = 10\mathrm{k} \frac{A'_\text{V}}{A_\text{V} - A'_\text{V}}
            \end{equation}
            
            \begin{task}
                Find the input resistance according to the small signal model and verify it with a simulation
            \end{task}
    
        \subsection{Using an active load}
            According to equation \ref{eq:cegain}, we can increase the gain of the amplifier by increasing \EEsym{R}{C}. However, we don't want to reduce \Ic because that would reduce \EEsym{g}{m} and increase \EEsym{r}{o}. We can't greatly increase \Vcc to maintain \Ic for practical reasons, such as power dissipation. Furthermore, an opamp is an integrated circuit and large resistors on an IC consume a very large amount of silicon area compared to transistors. Instead, we can replace \EEsym{R}{C} with a current mirror, which in this application acts as an \emph{active load}. The current mirror has a high output resistance and the output current can be set independently of the output voltage by choosing the input current.
            
            Replace \EEsym{R}{C} with a current mirror in your amplifier schematic:
    
            \begin{center}
            \input{graphics/CEactiveLoad}
            
            \emph{CE amplifier with active load}
            \end{center}
            
            The base current for \EEsym{T}{1} is now biased by resistors \EEsym{R}{1} and \EEsym{R}{2}. A bypass capacitor to ground prevents the bias resistors from reducing the AC gain through negative feedback. \Ic will be set at 1mA by \EEsym{R}{B} via the current mirror, as in Section~\ref{s:simplemirror}. Choose \EEsym{R}{1} so that the current in \EEsym{R}{1} is around $2I_\text{B}$. Then choose \EEsym{R}{2} to set \Vout at 0V, observing that $V_\text{CB}=2R_2\times 3I_\text{B}$. Confirm the biasing with an operating point simulation and adjust the resistor values if necessary.
            
            Now that \EEsym{R}{C} is the output resistance of \EEsym{T}{4}, the gain of our amplifier becomes:
            
            \begin{equation}
                A_\text{V} = \frac{v_\text{o}}{v_\text{in}} = -g_\text{m} \left( \frac{1}{r_\text{o,T1}} + \frac{1}{r_\text{o,T4}} + \frac{1}{R_2} \right)^{-1}
            \end{equation}
            
             \begin{task}
                Add the current mirror to your CE amplifier, set up the biasing and measure the gain with an AC analysis
            \end{task}
    
        \subsection{Darlington Pair}
            In Section~\ref{s:CEinputR} we found the input resistance of the common emitter amplifier, which wasn't very high. We can improve it using a Darlington pair configuration:
        
            \begin{center}
                \input{graphics/darlActiveLoad}
                
                \emph{CE amplifier with Darlington pair and active load}
            \end{center}
            
            Since \Ib for \EEsym{T}{1} comes from the emitter of \EEsym{T}{2}, the input current for the amplifier is decreased by a factor of approximately β. The resistor \EEsym{R}{E} is used to make sure that the collector bias current is split equally between \EEsym{T}{1} and \EEsym{T}{2}. This ensures that both transistors have similar high frequency behaviour, which is dependent on \Ic.
            
            Including the effect of \EEsym{R}{E}, the input resistance is now:
            
            \begin{equation}
                r_\text{in} = \beta \left( \frac{1}{R_\text{E}} + \frac{g_\text{m}}{\beta}\right)^{-1}
            \end{equation}
            
            It is easier to bias this amplifier when it is integrated with the other amplifier blocks, so you don't need to simulate it on its own.
