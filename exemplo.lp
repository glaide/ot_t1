min: t1 + h1 + t2 + h2 + t3 + h3;

h1 = 0.005var1;
h2 = 0.005var2;
h3 = 0.005var3;


Vini = 500;
Y1 = 500;
Y2 = 800;
Y3 = 200;

V1 = Vini + Y1 - Vat1;
V2 = V1 + Y2 - Vat2;
V3 = V2 + Y3 - Vat3;

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

t1 = 0.2Vterm1;
t2 = 0.2Vterm2;
t3 = 0.2Vterm3;

/*------------------------------------acima está certo--------------------*/
1.1Vat1 + Vterm1 >= 900;
1.1Vat2 + Vterm2 >= 1000;
1.1Vat3 + Vterm3 >= 950;

V1 >= 200;
V2 >= 200;
V3 >= 200;

V1 <= 1000;
V2 <= 1000;
V3 <= 1000;


Vterm1 <= 1000;
Vterm2 <= 1000;
Vterm3 <= 1000;


Vterm1 >= 0;
Vterm2 >= 0;
Vterm3 >= 0;

Vat1 >= 0;
Vat2 >= 0;
Vat3 >= 0;






