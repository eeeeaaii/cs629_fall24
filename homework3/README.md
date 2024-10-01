# Homework 3: Line Drawing Exercise

You will write code that draws lines and curves using the algorithms discussed in class. I will give you a host program that takes command line arguments that specify which lines or curves to draw, and you will implement the functions that actually do the drawing.

The program should support as many as possible of the following line and curve types. The more types you support, the more credit/points you will get on this assigment.

1. straight lines drawn using the midpoint algorithm
1. anti-aliased straight lines (using the box filter algorithm)
1. anti-aliased straight lines (using weighted area sampling, i.e. the cone filter - see lecture notes)
1. Bézier curves drawn using midpoint algorithm (remember, to draw a curve you draw a lot of short lines)
1. anti-aliased Bézier curves drawn using the box filter algorithm
1. a "faded" Bézier curve where each segment starts off with full intensity at the start of the curve and gradually fades to black by the end of the curve.

If your program doesn't support one of the line types, it should just ignore the input (not crash and not draw anything).

## Invoking the program

The program accepts any number of "opcodes" on the command line and will draw one line per opcode (see examples below). Each opcode requires some numeric data to be passed in so it knows where to draw the line. You don't have to write the command line parsing code. There are six opcodes, one for each line type:

```
1. line
2. aaline
3. aalinewas
4. bezier
5. aabezier
6. faded
```

Line start and endpoints are specified like this:
```
sx,sy;ex,ey
```

Bezier curve control points are specified like this:
```
p0x,p0y;p1x,p1y;p2x,p2y;p3x,p3y
```

Examples:

To draw a straight line using the midpoint algorithm from (10, 11) to (100, 110):

```homework3_exe.exe --line "10,11;100,110"```

To draw a straight line using box filter anti aliasing from (10, 11) to (100, 110):

```homework3_exe.exe --aaline "10,11;100,110"```

To draw a straight line using weighted area sampling anti aliasing from (10, 11) to (100, 110):

```homework3_exe.exe --aalinewas "10,11;100,110"```

To draw a bezier curve using the midpoint algorithm using the four control points (10, 11), (50, 11), (10, 50), (100, 110)

```homework3_exe.exe --bezier "10,11;50,11;10,50;100,110"```

To draw a bezier curve using weighted area sampling using the four control points (10, 11), (50, 11), (10, 50), (100, 110)

```homework3_exe.exe --aabezier "10,11;50,11;10,50;100,110"```

To draw a faded bezier curve using the four control points (10, 11), (50, 11), (10, 50), (100, 110)

```homework3_exe.exe --faded "10,11;50,11;10,50;100,110"```

To draw three different lines using midpoint:

```homework3_exe.exe --line "0,0;30,30" --line "10,10;35,35" --line "30,30;130,130"```


## Drawing API

I've provided a miniature drawing API for you to use so you can focus on the algorithm part of this assignment. The drawing API allows you to draw one pixel at a time. You can make the pixel any color. There are two C++ classes you will use to do your drawing. The `Frame` object is the canvas or surface you will draw into, and a `Color` object represents a color to draw with. 
Frame has three operations:

```
frame.getColor(i, j); // returns a Color object
frame.setColor(i, j, c); // assuming c is a color object, sets the color at i, j to that color
frame.addColor(i, j, c); // like setColor, but if the pixel is already non-black, this adds to the color already there.
```

To create a color, use an initializer. You can also multiply colors by a number to scale the color vector by that amount.

```
Color c1 = { 1.0, 1.0, 1.0 }; // pure white
Color c2 = { 0.0, 0.0, 0.0 }; // black
Color c3 = { 0.5, 0.5, 0.5 }; // 50% gray

Color c4 = c1 * 0.5; // also 50% gray
```

Note that for this assignment, all the lines should be white (0xFFFFFF, or ```{1.0, 1.0, 1.0}```) except the "faded" line, which should fade from white to black (0xFFFFFF to 0x000000). Also note that if you should always consider the possibility that you might be drawing overtop of another color, so you should probably use addColor and not setColor (your line might overlap with a previously drawn line)


This example draws a small red square.

```
Frame frame;

Color c = { 1.0, 0.0, 0.0 };

for (int i = 100; i < 110; i++) {
    for (int j = 100; j < 110; j++) {
        frame.setColor(i, j, c);
    }
}
```

I have also provided a 2d vector class called Vect. This has overloaded operators that allow you to perform vector addition, scaling, etc.

```
Vect v1 = { 1.0, 0.0 }; // Create a vector
Vect v2 = { 0.0, 1.0 };
bool isItTheSame = (v1 == v2); // Compare vectors
Vect sum = v1 + v2; // Vector addition
Vect diff = v1 - v2; // Vector subtraction
Vect neg = -v1; // Flip vector
Vect scaled = 2.0 * v1; // Scale vector
float dotp = v1 * v2; // Dot product
float mag = sum.mag(); // magnitude (length)
float slp = sum.slope(); // slope of vector
Vect norm = sum.normalize();
    // normalize vector to length 1
float proj = v1.projectOnto(sum);
    // use dot product to project one vector onto another
std::cout << v1 << std::endl;
    // stream operator defined for debugging
```

<br>
<br>

