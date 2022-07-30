min: termo1 + hidro1 + termo2 + hidro2 + termo3 + hidro3;

hidro1 = 0.005000var1;
hidro2 = 0.005000var2;
hidro3 = 0.005000var3;

Vini = 500;

Y1 = 500;
Y2 = 800;
Y3 = 200;

V1 = Vini + Y1 - v_agua_turbinada1;
V2 = V1 + Y2- v_agua_turbinada2;
V3 = V2 + Y3- v_agua_turbinada3;

mvar1 + dif1 = Vini - V1;
mvar1 - dif1 = V1 - Vini;
mvar2 + dif2 = V1 - V2;
mvar2 - dif2 = V2 - V1;
mvar3 + dif3 = V2 - V3;
mvar3 - dif3 = V3 - V2;

mvar1 >= 0;
mvar2 >= 0;
mvar3 >= 0;

dif1 >= 0;
dif2 >= 0;
dif3 >= 0;

var1 = mvar1 + dif1;
var2 = mvar2 + dif2;
var3 = mvar3 + dif3;

termo1 = 0.200000v_termo1;
termo2 = 0.200000v_termo2;
termo3 = 0.200000v_termo3;


1.100000v_agua_turbinada1 + v_termo1 >= 900;
1.100000v_agua_turbinada2 + v_termo2 >= 1000;
1.100000v_agua_turbinada3 + v_termo3 >= 950;
V1 >= 200.000000;
V2 >= 200.000000;
V3 >= 200.000000;
V1 <= 1000.000000;
V2 <= 1000.000000;
V3 <= 1000.000000;
v_termo1 <= 1000.000000;
v_termo2 <= 1000.000000;
v_termo3 <= 1000.000000;
v_termo1 >= 0;
v_termo2 >= 0;
v_termo3 >= 0;
v_agua_turbinada1 >= 0;
v_agua_turbinada2 >= 0;
v_agua_turbinada3 >= 0;
