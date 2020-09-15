# GreenHouse Simulator Scripting Support #

The GreenHouse Simulator provides the means to implement and execute prototype backend interface methods written using JavaScript.
This document describes the scripting functionality provided by the GreenHouse Simulator application.
It is intended as an API reference for individuals looking to implement a simulated backend interface functionality for rapid prototyping.

## Disclaimers ##

- This document is not intended as an introduction to JavaScript.
- The simulator application's scripting functionality was not intended as a means of providing a real backend implementation we still strongly suggest you implement your backend in C/C++ using the GreenHouse plugin infrastructure.

## Table of contents ##

- [Execution context](#execution-context)
    - [Method scripts](#method-scripts)
    - [Property value changed scripts](#property-value-changed-scripts)
    - [Object initialization scripts](#object-initialization-scripts)
    - [Action scripts](#action-scripts)
- [API reference](#api-reference)
    - [Simulator](#simulator)
        - [Simulator.object](#simulator.object)
        - [Simulator.script](#simulator.script)
        - [Simulator.trigger](#simulator.script)
        - [Simulator.replay](#simulator.replay)
        - [Simulator.activateTheme](#simulator.activateTheme)
        - [Simulator.objects](#simulator.objects)
        - [Simulator.availableThemes](#simulator.availablethemes)
        - [Simulator.startProcess](#simulator.startprocess)
        - [Simulator.stopProcess](#simulator.stopprocess)
        - [Simulator.simulateClickEvent](#simulator.simulateclickevent)
        - [Simulator.captureScreen](#simulator.capturescreen)
    - [Interface object](#interface-object)
        - [object.method](#object.method)
        - [object.event](#object.event)
        - [object.property](#object.property)
        - [object.name](#object.name)
        - [object.objectMethods](#object.objectmethods)
        - [object.objectEvents](#object.objectevents)
        - [object.objectProperties](#object.objectproperties)
    - [Interface property](#interface-property)
        - [property.value](#property.value)
        - [property.name](#property.name)
        - [property.type](#property.type)
    - [Interface event](#interface-event)
        - [event.call](#event.call)
        - [event.name](#event.name)
        - [event.eventArguments](#event.eventArguments)
    - [Argument](#argument)
        - [argument.value](#argument.value)
        - [argument.name](#argument.name)
        - [argument.type](#argument.type)
    - [Interface method](#interface-method)
        - [method.call](#method.call)
        - [method.callOverRPC](#method.callOverRPC)
        - [method.name](#method.name)
        - [method.methodArguments](#method.methodArguments)
    - [Model](#model)
        - [removeRow](#removerow)
        - [prependRow](#prependrow)
        - [appendRow](#appendrow)
        - [setRowData](#setrowdata)
        - [setModelJsonData](#setmodeljsondata)
        - [roles](#roles)
        - [length](#length)
    - [Action script](#action-script)
        - [script.trigger](#script.trigger)
- [Samples](#samples)
    - [Incrementing a property](#incrementing-a-property)
    - [Decrementing a property](#decrementing-a-property)
- [Script deployment](#script-deployment)

## Execution context ##

### Method scripts ###
Method scripts get executed inside a context containing the following symbols:
- Simulator - the main simulator object
- self - the method's interface object
- method - the currently executed method's object
- args - an object containing the executed method's argument value map

### Property value changed scripts ###
Method scripts get executed inside a context containing the following symbols:
- Simulator - the main simulator object
- self - the property's interface object
- property - the changed property's object
- value - a var containing the new property value

### Object initialization scripts ###
Object initialization scripts get executed inside a context containing the following symbols:
- Simulator - the main simulator object
- self - the initialized object
- function startTimerLoop(interval, action) - a function used to start a timer loop, returns object used to identify the started timer loop
- function stopTimerLoop(loopObject) - a function used to stop a timer loop

### Action scripts ###
Action scripts get executed inside a context containing the following symbols:
- Simulator - the main simulator object

## API reference ##

### Simulator ###

#### Simulator.object ####
```
function object(<string> objectName) -> returns a backend interface object

example usage:
let obj = Simulator.object("MyInterface");
```

#### Simulator.script ####
```
function script(<string> scriptName) -> returns an action script object

example usage:
let action = Simulator.script("myAction");
action.trigger();
```

#### Simulator.trigger ####
```
function trigger(<string> scriptName, int afterMsecs) -> executes an action script object
after a certain period of time

This is a shortcut for Simulator.script("myAction").trigger();
example usage:
Simulator.trigger("myAction",2000);
Execute the script "MyAction" after waiting for 2 seconds.
```

#### Simulator.replay ####
```
function replay(<string> oifSessionName, int afterMsecs) -> executes the oif session script
after a certain period of time

This will execute the steps recorded in a previous session and stored in
an "oif" script. The script is searched for in simScripts/actions.

example usage:
Simulator.replay("myRecordedSession.oif",2000);
```

#### Simulator.activateTheme ####
```
function activateTheme(<string> themeName)

example usage:
Simulator.activateTheme("MyTheme");
```

#### Simulator.objects ####
```
array objects -> an array containing all of the available backend interface objects

example usage:
Simulator.objects.forEach(function(obj) {
    console.log("Backend Interface: " + obj.name);
});
```

#### Simulator.availableThemes ####
```
array availableThemes -> an array containing the names of available themes

example usage:
Simulator.objects.forEach(function(themeName) {
    console.log("Theme: " + themeName);
});
```

#### Simulator.startProcess ####
```
command -> a string containing the name of the command that's to be executed
argList -> a list of arguments that are to be passed to the executed command

example usage:
var procId = Simulator.startProcess("executable", ["arg1", "arg2"]);

```

#### Simulator.stopProcess ####
```
procId -> a process id returned by a call to startProcess

example usage:
Simulator.stopProcess(procId);
```

#### Simulator.simulateClickEvent ####
```
mouseX -> the simulated click event's x coordinate
mouseY -> the simulated click event's y coordinate
rightClick -> true if the simulated event is supposed to be a right click [false by default]

example usage:
Simulator.simulateClickEvent(256, 128);
```

#### Simulator.captureScreen ####
```
saveLocation -> a string containing the path for the resulting screen shot

example usage:
Simulator.captureScreen("screenShot.png");
```

### Interface object ###

#### object.method ####
```
function method(<string> methodName) -> returns a backend interface method object

example usage:
let method = self.method("foo");
```

#### object.event ####
```
function event(<string> eventName) -> returns a backend interface event object

example usage:
let event = self.event("foo");
```

#### object.property ####
```
function property(<string> propertyName) -> returns a backend interface property object

example usage:
let property = self.property("foo");
```

#### object.name ####
```
string name -> the objects name

example usage:
console.log("Object: " + self.name)
```

#### object.objectMethods ####
```
array objectMethods -> an array containing all of the object methods

example usage:
self.objectMethods.forEach(function (method) {
    console.log("Backend Interface Method: " + method.name);
})
```

#### object.objectEvents ####
```
array objectEvents -> an array containing all of the object events

example usage:
self.objectEvents.forEach(function (event) {
    console.log("Backend Interface Event: " + event.name);
})
```

#### object.objectProperties ####
```
array objectProperties -> an array containing the object properties

example usage:
self.objectProperties.forEach(function (property) {
    console.log("Backend Interface Property: " + property.name);
})
```

### Interface property ###

#### property.value ####
```
var value -> the property's value

example usage:
let prop = self.property("foo");
if (prop.value < 100)
    prop.value += 1
```

#### property.name ####
```
string name -> the property's name

example usage:
let prop = self.property("foo");
console.log("Property: " + prop.name)
```

### property.type ####
```
int property.type -> the property's type identifier

example usage:
let prop = self.property("foo");
if (prop.type === SimulatorObject.Int)
    console.log("Property type: int");
```

### Interface event ###

#### event.call ####
```
function call(<object> arguments) -> used to invoke the event
NOTE: the arguments parameter is optional and any arguments not included there will use their default value

example usage:
let event = self.event("foo")
event.call({ "bar": 1, "buzz": 2 })
```

#### event.name ####
```
string name -> the event's name

example usage:
let event = self.event("foo")
console.log("Event: " + event.name)
```

#### event.eventArguments ####
```
array eventArguments -> an array containing the events arguments

example usage:
let event = self.event("foo")
event.eventArguments.forEach(function (arg) {
    console.log("argument: " + arg.name);
})
```

### Argument ###

#### argument.value ####
```
var value -> the arguments current default value

example:
arg.value = 0;
```

#### argument.name ####
```
string name -> the argument's name

example usage:
console.log("Argument: " + arg.name)
```

#### argument.type ####
```
int type -> the argument's type identifier

example usage:
if (arg.type === SimulatorObject.Int)
    console.log("Argument type: int");
```

### Interface method ###

#### method.call ####
```
function call(<object> arguments) -> used to invoke the method

example usage:
let method = self.method("foo")
method.call({ "bar": 1, "buzz": 2 })
```

#### method.callOverRPC ####
```
function call(<object> arguments) -> used to invoke the method over rpc

example usage:
let method = self.method("foo")
method.callOverRPC({ "bar": 1, "buzz": 2 })
```


#### method.name ####
```
string name -> the method's name

example usage:
let method = self.method("foo")
console.log("Method: " + method.name)
```

#### method.methodArguments ####
```
string methodArguments -> a string containing the method's argument signature

example usage:
let method = self.method("foo")
console.log("Method: " + method.name " (" + method.methodArguments + ")")
```

### Model ### 

#### removeRow ####
```
function removeRow(<int> index) -> used to remove a model row

example usage:
let model = self.property("modelProperty").value;
model.removeRow(model.length - 1)
```

#### prependRow ####
```
function prependRow(<object> rowData) -> used to prepend a new row

example usage:
let model = self.property("modelProperty").value;
model.prependRow({ "foo": 1, "bar": 2 })
```

#### appendRow ####
```
function appendRow(<object> rowData) -> used to append a new row

example usage:
let model = self.property("modelProperty").value;
model.appendRow({ "foo": 1, "bar": 2 })
```

#### setRowData ####
```
function setRowData(<int> index, <object> rowData) -> used to set an existing row's data

example usage:
let model = self.property("modelProperty").value;
model.setRowData(0, { "foo": 1, "bar": 2 })
```

#### setModelJsonData ####
```
function setModelJsonData(<string> model) -> used to populate the model with new data

example usage:
let model = self.property("modelProperty").value;
model.setModelJsonData("[{ \"foo\": 1, \"bar\": 2 }, { \"foo\": 3, \"bar\": 4 }]")
```

#### roles ####
```
array roles -> an array containing the model's role names

example usage:
let model = self.property("modelProperty").value;
model.roles.forEach(function (role) {
    console.log("Role: " + role);
})
```

#### length ####
```
int length -> the number of model rows

example usage:
let model = self.property("modelProperty").value;
console.log("Row count: " + model.length)
```

### Action script ###

#### script.trigger ####
```
function trigger() -> used to trigger the script action

example usage:
let action = Simulator.script("myAction");
action.trigger();
```

## Samples ##

### Incrementing a property ###
```
let prop = self.property("foo")
if (prop)
    prop.value = Math.min(100, prop.value + 1)
```

### Decrementing a property ###
```
let prop = self.property("foo");
if (prop)
    prop.value = Math.max(0, prop.value - 1);
```

## Script deployment ##

The simulator process automatically stores user provided method scripts inside a "simScripts" folder found in in its working directory.
The same folder is later used to load known scripts when the simulator application is started.

The "simScripts" folder uses the following structure:
```
simScripts
├── <InterfaceFoo>
│   ├── <methodA>.js
│   └── <methodB>.js
└── <InterfaceBar>
    ├── <methodA>.js
    └── <methodB>.js
```

Given the above installing externally developed scripts is a simple case of copying them into the "simScripts" directory.
You will also find that the auto generated Simulator.pro and CMakeLists.txt files are setup to automatically copy the contents of a "simScritps"
folder residing in the source directory.
