min: 0.2 Vterm1 + 0.005 VRH1 + 0.2 Vterm2 + 0.005 VRH2 + 0.2 Vterm3 + 0.005 VRH3;
Vini = 500;

Y1 = 500;
Y2 = 800;
Y3 = 200;

VRH1 = Y1 + Vat1;
VRH2 = Y2 + Vat2;
VRH3 = Y3 + Vat3;

V1 = Vini + Y1 - Vat1;
V2 = V1 + Y2 - Vat2;
V3 = V2 + Y3 - Vat3;

1.1 Vat1 + Vterm1 >= 900;
1.1 Vat2 + Vterm2 >= 1000;
1.1 Vat3 + Vterm3 >= 950;

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






