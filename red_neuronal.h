/*
 * red_neuronal.h
 *
 *  Created on: 17 mar. 2021
 *      Author: nahuu
 */

#ifndef LIBS_SAPI_SAPI_V0_5_2_SOC_PERIPHERALS_INC_RED_NEURONAL_H_
#define LIBS_SAPI_SAPI_V0_5_2_SOC_PERIPHERALS_INC_RED_NEURONAL_H_

float sigmoide(double x);
float red_neuronal(int examples, int capa_1, int capa_2, int capa_3, int capa_4,
		float *entrada, float *w1, float *w2, float *w3, float *u2, float *u3,
		float *u4, int i_capa_4, int i_example);
float a_3(int examples, int capa_1, int capa_2, int capa_3, float *entrada,
		float *w1, float *w2, float *u2, float *u3, int i_capa_3,
		int i_example);
float a_2(int examples, int capa_1, int capa_2, float *entrada, float *w1,
		float *u2, int i_capa_2, int i_example);
float delta_4(int examples, int capa_4, float *Y, float *S, int i_example,
		int i_capa_4);
float delta_3(int examples, int capa_1, int capa_2, int capa_3, int capa_4,
		float *entrada, float *w1, float *w2, float *w3, float *Y, float *S,
		float *u2, float *u3, int i_capa_1, int i_capa_2, int i_capa_3,
		int i_capa_4, int i_example);
float delta_2(int examples, int capa_1, int capa_2, int capa_3, int capa_4,
		float *entrada, float *w1, float *w2, float *w3, float *Y, float *S,
		float *u2, float *u3, int i_capa_1, int i_capa_2, int i_capa_3,
		int i_capa_4, int i_example);
void backpropagation(float margen, float alfa, int examples, int capa_1,
		int capa_2, int capa_3, int capa_4, float *entrada, float *w1,
		float *w2, float *w3, float *u2, float *u3, float *u4, float *S,
		float *Y, float *error_calcule);

#endif /* LIBS_SAPI_SAPI_V0_5_2_SOC_PERIPHERALS_INC_RED_NEURONAL_H_ */
