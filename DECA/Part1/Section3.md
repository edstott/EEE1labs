# Digital Electronics and Computer Architecture Lab
# Part 1: Autumn Term weeks 4--6
## Section 3: Sequential Circuits

Sections 1 and 2 of this experiment involved combinational logic circuits: circuits that convert inputs to outputs but do not store information.
Digital circuits which store information are called *sequential* and they contain *registers* and a *clock*.
		
This section uses a register to store the value of a bus.
The output of the register is fed back to the input via an adder, which creates a counter.
			
## Before the lab

The basic unit of information storage within digital circuits is the *D-type flip flop* (DFF).
It stores the state of input `D` at the moment when the clock input changes from low to high.
The output `Q` is equal to the stored value and it cannot change until the next rising edge of the clock.
				
|[Symbol of a D-type flip flop](graphics/dff.png)

| D  | Clock | Q  |
| -- | --- | -- |
| X  | 0   | NC |
| X  | 1   | NC |
| 1  | ↑   | 1  |
| 0  | ↑   | 0  |			

*X: Don't care, NC: No Change, ↑: Rising Edge*
					
Often, the state of a bus will be stored so a multi-bit DFF is needed, known as a *register*.
The bits of the register share the same clock input.
				
				\noindent\input{graphics/DECA-reg4}

Make a new project in Issie, and inside make a new sheet with a design for a 4-bit register called `DFF4`, with a bus input `D(3:0)` and a bus output `Q(3:0)`.
Place four of the the Issie component 'D-flip-flop', which is in the 'Flip flops and registers' category of the catalogue.
				
In Issie, all components with a clock input are connected to a global clock line automatically.
The clock ports are marked with a > symbol.
Therefore, you do not have to wire the clock inputs up yourself.
				
## Simulating a sequential circuit
		
First we will simulate your register block.
There are two ways to do this in Issie: using the Simulation tab, and using the Waveform editor.
We will cover both during this lab, but for now we will use the Simulation tab, as you did in the previous experiment.
This is only practical for simple clocked logic; as your designs become more complex we will begin using the waveform editor.
		
A sequential circuit requires a clock, a regular stream of rising edges that will trigger the DFFs to update their outputs.
In Issie, all clock inputs are automatically connected to a single, global clock signal.
You do not need to connect the clock ports yourself here, but remember that sequential circuits cannot function without a clock pulse being sent to each component's clock input.
			
			Click on the `Simulation' tab, and start the simulation. Since we are using clocked logic on this sheet, a new button will have appeared labeled `Clock Tick 0'. When you click this button, the first clock pulse will be sent to all \texttt{clk} inputs in your design. To test the functionality of your \texttt{DFF4}, change the input \texttt{D} and confirm that the output updates when you send a clock pulse.
			
			\noindent\includegraphics[width=0.2\textwidth]{graphics/DECA-iDFF4Sim.png}

            The simulation tab also shows you the outputs from each of the `Stateful components', which in this case are your 4 flip-flops. This may be useful if you need to debug your design because you can check the value of internal signals. Be aware that the output may not display any leading zeros, e.g. it will show \texttt{0x101} instead of \texttt{0x0101}.
			
			\begin{task}
				Simulate the 4-bit register.
			\end{task}
			
		\subsection{Counter}
		
			Registers allow the use of feedback loops in digital designs, where the output depends on the previous state of the system as well as the inputs. A simple example is a counter, where a register is used with an adder to generate a binary number that increments by one every clock cycle.
		
			\input{graphics/DECA-ctr}
			
			Create the counter using the \texttt{DFF4} component and the 4-bit full adder from the previous part of the experiment. To import the 4-bit full adder, copy the \texttt{.dgm} file for the adder, plus the \texttt{.dgm} files for all the user components that are instanced in the adder, into the folder for your new project. Close and re-open the project in Issie. The 4-bit full adder and its dependencies, \texttt{halfadd} and \texttt{fulladd}, should now appear in the catalogue of your current project.
			
			One input to the full adder comes from the output of the DFF4, while the other is set to zero. The increment function is achieved by setting the carry-in high.
			%% To be used if the constants don't work
			%To set the fixed input of 0 and 1 for the full-adder's \texttt{B} and \texttt{Cin} inputs respectively, use normal input ports, and set their values in the Simulation tab when you come to test your circuit.% (note that this approach will not work when we begin to use the waveform simulation window later on).
			%% And if they do
			The `constant' component in Issie, under `Input/Output' in the catalogue, is used to send a constant input to something. Use a constant to set input \texttt{B} of your adder to 0, and input \texttt{Cin} to 1. Set the bit-widths of each constant to match the terminal that they are connected to.
			%Since one of the adder inputs is permanently set at zero, you may wonder if a half-adder could perform the same function with fewer logic gates. But there is no need to create a 4-bit half-adder block -- the compiler will automatically simplify the logic whenever there is an advantage to doing so.
% 			Set the counter as the top-level unit, compile and run a simulation. You should see the Q output count up on every clock cycle.
            In Issie, floating ports (inputs/outputs of components that are not connected to anything) are not allowed. To solve this, connect the `Cout' port of your full adder to either an output port, or to the `Wire Label' component from the `Input/Output' section of the catalogue.
            
            %% Version for broken constant port component:
            %Test your counter using the Simulation tab. Ensure that you set your inputs to the \texttt{B} and \texttt{Cin} inputs of your full adder to \texttt{0b0000} and \texttt{0b1} respectively. Each time you click on the `Clock Tick N' button, you should see that the output value increments by one. Confirm that the counter behaves as you expect.
			
			%% Version for working constant port component
			Test your counter using the Simulation tab. Each time you click on the `Clock Tick N' button, you should see that the output value increments by one. Confirm that the counter behaves as you expect.
			
			\begin{task}
				Implement and simulate the 4-bit counter.
			\end{task}
			
		\subsection{Counter with synchronous load}
		
			%The counter so far follows a fixed sequence and the only way to break the sequence is to use the reset input. This isn't ideal because the reset signal will usually be used to reset the entire system. Furthermore, the reset is an \emph{asynchronous} signal, meaning that it works instantly and not just on a clock edge. Asynchronous signals can cause problems if they are triggered in normal use because the system may not have long enough to respond to the input before the next clock edge occurs.
			
			The counter so far follows a fixed sequence. To make the counter more useful, we wish to introduce the ability to set the value of the counter.  We will create a \emph{synchronous load} function with a multiplexer. The multiplexer provides the facility to break the feedback loop and instead feed the register with a specific valuer. You can use the 4-bit, 2-input multiplexer that you created in the previous section by copying the relevant \texttt{.dgm} files.
		
			\input{graphics/DECA-ctrld}
			
			With load signal \texttt{LD} set to 0 the counter will behave the same as before, since the output of the multiplexer is equal to the input \texttt{A}. When \texttt{LD} is 1, the register is loaded with the value of input D. Use the simulation tab to test the load function by setting bus input \texttt{D} to a value of your choice and setting \texttt{LD} to 1 and advancing the clock by one pulse. Set \texttt{LD} back to 0 and the counter will continue to count up from the new value on successive clock pulses.
			
			\begin{task}
				Implement and simulate the synchronous load function.
			\end{task}
		
		\begin{mdframed}[backgroundcolor=blue!20] 
			\subsection{Challenge: Countdown timer with auto-reset}
				Counters are frequently used as timers that count down for a certain number of clock pulses and then reset and repeat. Convert your counter with load to a timer. You'll need to:
				\begin{itemize}
					\item Change the adder to a subtracter so it counts down instead of up
					\item Trigger the load signal automatically when the output is zero
				\end{itemize}
				
			\input{graphics/DECA-tmr}
			
			    When you simulate your design, you should find that the output repeats every $D+1$ clock pulses.
				
				Note the inclusion of a reduction NOR gate to generate the control signal for the multiplexer. Reduction logic operations use a Boolean function to convert a bus to a single bit. For example, reduction NOR produces logic 1 if every bit of the bus is 0, otherwise the output is 0. You can implement a reduction NOR with the Bus Compare component, which outputs 1 if the bus input equals a predefined value.
		\end{mdframed}
