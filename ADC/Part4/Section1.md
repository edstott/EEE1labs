# Analysis and Design of Circuits Lab
# Part 4: Spring Term weeks 7--10

## Introduction
	
    	An operational amplifier has several ideal parameters, including:
    	\begin{itemize}[noitemsep]
    	    \item Very high differential gain
    	    \item Very low common-mode gain
    	    \item Very high input impedance
    	    \item Very low output impedance
    	\end{itemize}
    	
    	The aim of this experiment is to explore how BJT building blocks can achieve these properties and be combined to make a working opamp. The experiment is conducted in simulation using LTspice, which will be quicker and less susceptible to errors than building circuits on a breadboard.

    \section*{Background}
        Opamps are widely used in analogue systems. They are \emph{integrated circuits}, meaning that they consist of many transistors on a single silicon chip. Opamps are often further integrated as blocks in more complex ICs. The gain and transfer function of an opamp amplifier can be carefully controlled using external components in closed loop configurations. A typical opamp architecture generally has three amplifier stages. 
    
        \begin{center}
            \input{graphics/opampBlock}
            
            \emph{Block diagram of an opamp}
        \end{center}
        
        The differential stage acts to amplify the difference between the two input signals, while ignoring any \emph{common mode} input, i.e~the mean voltage of the two inputs. The high gain stage applies a large amount of voltage gain, such that the opamp can be treated as having infinite gain for the purposes of analysing the behaviour of a closed loop application circuit. The final stage increases the output current so that the opamp has a low output impedance for driving other circuits. At the transistor level, these blocks look like the diagram below. It looks complex but by the end of the experiment you will be familiar with all the blocks that make it up.
    
        \begin{center}
        \input{graphics/opampComplete1}
        
        \emph{Transistor diagram of the opamp}
        \end{center}
        
        The behaviour of the BJTs is defined by the usual expressions:
        
        \begin{equation}
        	I_\mathrm{C} = I_\mathrm{S} \mathrm{e}^\frac{V_\mathrm{BE}}{V_\mathrm{T}} \left(1+\frac{V_\mathrm{CE}}{V_\mathrm{A}}\right)
        	\label{e:IClong}
        \end{equation}
        
        For $V_\mathrm{A}\gg V_\mathrm{CE}$, equation~\ref{e:IClong} is approximated as:
                
        \begin{equation}
        		I_\mathrm{C} = I_\mathrm{S} \mathrm{e}^\frac{V_\mathrm{BE}}{V_\mathrm{T}}
        \end{equation}
        
        We will also use the small signal output impedance:
        
        \begin{equation}
        		r_\mathrm{0} = \frac{V_\mathrm{A}}{I_\mathrm{C}}
        \end{equation}

## Current Mirror and Current Source
    
        The current mirror is a widely used building block that acts as a current buffer. The current flowing in the input branch of the circuit is mirrored so that the same current also flows in the output branch. An ideal current mirror has an infinite output impedance since it acts like a current source. It can be built with PNP transistors to make a source of positive current, and NPN transistors to make a current sink. 
    
        \subsection{Simple current mirror} 
            \label{s:simplemirror}
            A simple PNP current mirror looks like this:
        
            \begin{center}
                \input{graphics/simpleMirror}
                
                \emph{Simple current mirror}
            \end{center}
        
            The circuit consists of two similar transistors with their bases and emitters connected. Since the base-emitter voltages of the two transistors are equal then their collector currents should also be equal. The input transistor \EEsym{T}{1} has its collector connected to its base, so it acts like a diode and provides a sink for the base currents of the transistors. Simulate the current mirror using this circuit:

            \begin{center}
                \input{graphics/simpleMirrorTest}
                
                \emph{Test circuit for current mirror}
            \end{center}
            
            Make sure to select a specific transistor model after you have placed them on your schematic. Use 2N2907 for PNP transistors. The diode-connected transistor \EEsym{T}{1} has a fixed collector voltage, allowing the input current to be set with \EEsym{R}{1}. \Vcc and \EEsym{V}{C} should be set up with voltage sources, with $V_\text{C}=-10$V at first. Choose a value of \EEsym{R}{1} so that $I_\text{IN}=1$mA.
            
            \begin{center}
                \includegraphics[width=8cm]{graphics/cMirror.png}
                
                \emph{Simulation schematic for the current mirror}
            \end{center}
            
            We are interested in the DC (bias or quiescent) performance of the current mirror. So run a DC operating point simulation --- `DC op pnt' in the simulation setup window in LTspice. When you run the simulation this returns a table listing all the DC voltages and currents in the circuit. Note how the use of node names in the circuit makes it easier to read the simulation results.
            
            \begin{center}
                \includegraphics[width=6cm]{graphics/DCop.png}
                
                \emph{Simulation results for the current mirror}
            \end{center}
            
            \begin{task}
                Run a DC analysis to find \EEsym{I}{IN} and \EEsym{I}{OUT}. What is the \emph{current transfer ratio} between input and output?
            \end{task}
            
            The current mirror can be compared to an ideal current source by finding its output resistance \EEsym{R}{OUT}. Find this by varying \EEsym{V}{C} between $-15$V and $-5$V. You can use the `DC Sweep' simulation mode, which allows you to step the value of \EEsym{V}{C} and record the output current for each step.
            
            \begin{equation}
                R_\text{OUT}=\frac{\Delta V_\text{C}}{\Delta I_\text{OUT}}
            \end{equation}
            
            \begin{task}
                Find the output resistance of the current mirror. Does it match the predicted output resistance $r_\text{0}=V_\mathrm{A}/I_\mathrm{C}$?
            \end{task}


        \subsection{Wilson Current Mirror}
            
            The simple current mirror has a few sources of inaccuracy:
            \begin{itemize}[noitemsep]
                \item \Ic for the two transistors is only equal if the transistors are identical. In simulation this is true, but in practice transistors will have slightly different \Ic for the same \Vbe
                \item \EEsym{I}{IN} includes the \Ib of \EEsym{T}{2} and, since $\beta$ is finite, this causes a difference between the currents
                \item BJTs have a finite output resistance and \EEsym{I}{OUT} will depend on \Vce of \EEsym{T}{2}
            \end{itemize}
            
            A much higher quality current-mirror can be obtained by the addition of just a single transistor, connected between the input and the output of the simple current-mirror. The modified circuit is shown below --- it is known as the Wilson current-mirror after its inventor. 

            \begin{center}
                \input{graphics/wilsonMirror}
                
                \emph{Wilson current mirror}
            \end{center}
            
            The extra transistor, \EEsym{T}{3}, now accounts for most of the voltage drop between \Vcc and the output. That means \EEsym{T}{1} and \EEsym{T}{2} have a similar \Vce and therefore \Ic of the two transistors is closer. \EEsym{T}{3} also cancels out the effect of the base current in the output and reduces the error due to finite β.
            
            Choose the value of \EEsym{R}{1} so that $I_\text{IN}=1$mA again. Note that the voltage of the input node is now $V_\text{CC}-2V_\text{BE}$
            
            \begin{task}
                Repeat the characterisation of the current mirror and look for an improvement in the current transfer ratio and output impedance.
            \end{task}