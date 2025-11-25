/*
============================================================
  Fichero: prueba.c
  Creado: 23-11-2025
  Ultima Modificacion: dimarts, 25 de novembre de 2025, 20:28:12
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "advmake.h"

#define COCINA 1
#define COMEDOR 2

PRE(cocina)
	PRTS("Estas en la cocina del castillo.");
	NLN;
	PRTS("Al norte esta el comedor.");
	NLN;
END

POS(cocina)
	IF(WRS) 
		IF(EQU(WR(0),"ir"))
			IF(WRS>1)
				IF(EQU(WR(1),"norte"))
					NXT(COMEDOR);
					PRTS("Voy...");
				ELSE
					PRTS("No puedo ir hacia ahi...");
				END
			ELSE
				PRTS("Hacia adonde?");
			END
		ELSE
			PRTS("No te entiendo...");
		END
	END
	NLN;
END

PRE(comedor)
	PRTS("Estas en el comedor.");
	NLN;
END

POS(comedor)
	PRTS("Me quedo aqui admirando los cuadros");
	NLN;
END

BEG
	OBJ(COCINA,cocina);
	OBJ(COMEDOR,comedor);
	INI(COCINA);
	PRM("Que quieres hacer ahora?");
	TIT("Prueba");
	AUT("OJP 2025");
END
