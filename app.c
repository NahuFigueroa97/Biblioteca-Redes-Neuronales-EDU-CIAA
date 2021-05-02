/*============================================================================
 * Autor: Nahuel Figueroa
 * Licencia:
 * Fecha: 24/01/2021
 *===========================================================================*/

// Inlcusiones
#include "app.h"         // <= Su propia cabecera
#include "sapi.h"        // <= Biblioteca sAPI
#include "red_neuronal.h"

float entrada[4][2] = { { 0, 0 }, { 0, 1 }, { 1, 0 }, { 1, 1 }, };

float error_calcule[4][1] = { { 0 }, { 0 }, { 0 }, { 0 }, };

float salida[4][1] = { { 0 }, { 1 }, { 1 }, { 0 }, };

float y[4][1] = { { 0 }, { 0 }, { 0 }, { 0 }, };

float w1[2][3] = { { 0.8, 0.16, 0.5 }, { 0.2, 0.4, 0.7 }, };

float w2[3][3] = { { 0.8, 0.16, 0.5 }, { 0.2, 0.4, 0.7 }, { 0.1, 0.4, 0.25 }, };

float w3[3][1] = { { 0.8 }, { 0.2 }, { 0.1 }, };

float u2[3] = { 0.16, 0.23, 0.40 };
float u3[3] = { 0.16, 0.23, 0.40 };
float u4[1] = { 0.16 };
float output[4] = { 0 }, a = 0.5;
int in, c;
int main(void) {

	boardConfig();
	uartInit(UART_USB, 9600);

	while ( TRUE) {

		// tarda 1.20 min en entrenarse 1000 veces :D // creo que se puede disminuir el tiempo optimizando el codigo :/
		while (c < 1000) {
			backpropagation(2, 0.2, 4, 2, 3, 3, 1, entrada, w1, w2, w3, u2, u3,
					u4, salida, y, error_calcule);
			gpioWrite(LED1, OFF);
			c++;
		}
		for (in = 0; in < 4; in++) {
			output[in] = red_neuronal(4, 2, 3, 3, 1, entrada, w1, w2, w3, u2,
					u3, u4, 0, in);
			printf("%f\n\r", output[in]);
			gpioWrite(LED1, ON);
		}
	}
	return 0;
}
