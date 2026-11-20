# Simple LED Resistor Calculator
supply_voltage = float(input("Supply voltage (e.g., 5 for Arduino): "))
led_voltage = float(input("LED forward voltage (e.g., 2.0 for red, 3.2 for blue): "))
desired_current_ma = float(input("Desired current in mA (usually 15 to 20): "))

if led_voltage >= supply_voltage:
    print("Warning: Supply voltage must be higher than the LED forward voltage!")
elif desired_current_ma <= 0:
    print("Warning: Current must be greater than 0 mA.")
else:
    # Ohm's Law: R = V / I
    current_amps = desired_current_ma / 1000
    resistance = (supply_voltage - led_voltage) / current_amps
    print(f"You need at least a {resistance:.1f} Ohm resistor!")