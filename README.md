# BitManipulation_Brain
Distinguish between the different hex number and sending to appropriate functions after checking
dispatches messages based upon their type. There are two message types "display" and "motor". These two message types are mixed into the same packet format and the function that needs to be written needs to distinguish between these two messages and call the appropriate function. Display messages must be passed to the function called display_message() and motor messages must be passed to a function called update_motor().
