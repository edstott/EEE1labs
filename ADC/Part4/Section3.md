# Analysis and Design of Circuits Lab
# Part 4: Spring Term weeks 7--10

## Differential Amplifier

        An opamp amplifies a differential signal: the difference between the inverting and non-inverting inputs. It should not amplify a \emph{common mode} signal that is applied equally to both inputs. A circuit with high differential mode gain but low common mode gain is the long tailed pair (LTP):

        \begin{center}
        \input{graphics/ltp}
        
        \emph{Long tailed pair}
        \end{center}
        
        With $V_{\text{IN}+} = V_{\text{IN}-}$, \Ic through \EEsym{T}{1} and \EEsym{T}{2}. However, a slight difference between the inputs causes a large imbalance in \Ic between the transistors, which results in a change to \EEsym{V}{OUT}. A common mode input also causes a change in \EEsym{V}{OUT}, but the gain is smaller due to the emitter degeneration from \EEsym{R}{E}.

        \subsection{Gain and Input Resistance}
            The theoretical gain of the LTP from the small signal model is:
            
            \begin{equation}
                A_\text{d} = \frac{v_\text{o}}{v_\text{d}} = \frac{g_\text{m,T2}}{2} \left( \frac{1}{r_\text{o,T2}} + \frac{1}{R_\text{C}}  \right)^{-1}
            \end{equation}
            
            \EEsym{v}{d} is the differential input voltage, $v_\text{d}=v_\text{+}-v_\text{-}$. In quiescent conditions with $V_{\text{IN}+} = V_{\text{IN}-}=0$, the circuit is biased with a combined collector current $I_\text{o}=1mA$. The DC output voltage is therefore around -4V, which is about the level we need to directly couple it to the input of the Darlington pair.
            
            \begin{task}          
                Enter the LTP ciruit in LTspice and perform an AC analysis to find the differential gain. Compare to the theoretical gain.
            \end{task}
            
            The differential input resistance of the circuit from the small signal model is:
            \begin{equation}
                r_\text{ind} = 2 r_\text{be} = \frac{2\beta}{g_\text{m}}
            \end{equation}
            
            \begin{task}          
                Add a 10kΩ resistor in series with the base of \EEsym{T}{1} (you also change the source resistance of \Vin) and use the change in differential gain to find the differential input resistance.
            \end{task}
            
        \subsection{Common mode Voltage Gain and Common Mode Rejection Ratio}
            The input stage should have a small common mode voltage gain. The small signal model gives:
            \begin{equation}
                A_\text{c} = \frac{v_\text{o}}{v_\text{c}} = -\frac{R_\text{C}}{2R_\text{E}}
            \end{equation}
            
            Find the common mode gain in simulation by connecting \EEsym{V}{IN-} to \EEsym{V}{IN+} instead of ground and performing an AC analysis
            
            \begin{task}          
                Find the common mode gain
            \end{task}
            
            A more useful figure is the ratio of differential gain to common mode gain, the \emph{common mode rejection ratio} (CMRR). The small signal model for this circuit gives:
            
            \begin{equation}
                \text{CMRR} = \frac{A_\text{d}}{A_\text{c}} = g_\text{m}R_\text{E} = \frac{R_\text{E}I\text{o}}{2V_\text{T}}
            \end{equation}
            
            It is normally quoted in dB in opamp datasheets.
            
            \begin{task}          
                What is the CMRR of your circuit?
            \end{task}
            
   
        \subsection{Increasing CMRR and gain with active load}         
            
            The small signal model shows that CMRR can be increased by increasing \EEsym{I}{o} or \EEsym{R}{E}. Using a larger resistor or greater \Vcc has the same drawbacks as it did for the common emitter stage so, once again, a better solution is to replace the resistor with an active load. A Wilson current mirror gives a very high output resistance:

            \begin{center}
                \input{graphics/ltpActiveLoad}
                
                \emph{Long tailed pair with active load}
            \end{center}
            
            Choose \EEsym{R}{1} to give $I_\text{o} = 1$mA.
            
            \begin{task}          
                What is the CMRR of the LTP with active load?
            \end{task}
            
            The overall gain of the LTP, both common mode and differential, increases with \EEsym{R}{C}. A current mirror can also be used here to increase the gain. However, instead of setting it up as a constant current source, we can use the mirror to reflect the current from the unused leg of the LTP back into the output:

            \begin{center}
                \input{graphics/ltpFull}
                
                \emph{Complete differential input stage}
            \end{center}
            
            The second current mirror acts to resist the imbalance in current between the two legs. Hence, a small differential input voltage results in a large change in \Vout as the LTP fights the current mirror. The circuit also has the advantage of using the unused signal current in the left hand leg of the LTP to boost the output. A biasing resistor and blocking capacitor are added to each base to add DC stability for testing purposes.
            
            Small signal analysis now gives the differential gain as:
            
            \begin{equation}
                A_\text{d} = g_\text{m,T2}\left( \frac{1}{r_\text{o,T2}} + \frac{1}{r_\text{o,T7}} + \frac{1}{R_\text{B}}  \right)^{-1}
            \end{equation}
            
            \begin{task}          
                Measure the differential gain with the addition of the second current mirror
            \end{task}
