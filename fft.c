#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 256
#define bool _Bool
#define OVS 889516850
#define DOVS 1779033700
#define SHN  31

typedef unsigned char		UWord8;

typedef struct
{	
  int real;
  int imag;
} COMPLEX;


COMPLEX wn[N/2] = 
{
{2147483647, 0},
{2146836865, -52701886},
{2144896908, -105372028},
{2141664947, -157978697},
{2137142926, -210490205},
{2131333570, -262874923},
{2124240379, -315101294},
{2115867624, -367137860},
{2106220350, -418953276},
{2095304368, -470516330},
{2083126253, -521795962},
{2069693340, -572761285},
{2055013722, -623381597},
{2039096240, -673626407},
{2021950482, -723465450},
{2003586778, -772868705},
{1984016187, -821806412},
{1963250500, -870249094},
{1941302224, -918167571},
{1918184579, -965532977},
{1893911493, -1012316783},
{1868497584, -1058490807},
{1841958163, -1104027236},
{1814309215, -1148898639},
{1785567395, -1193077990},
{1755750016, -1236538674},
{1724875039, -1279254514},
{1692961061, -1321199779},
{1660027307, -1362349203},
{1626093615, -1402677998},
{1591180424, -1442161873},
{1555308767, -1480777043},
{1518500249, -1518500249},
{1480777043, -1555308766},
{1442161873, -1591180424},
{1402677998, -1626093615},
{1362349203, -1660027307},
{1321199779, -1692961061},
{1279254514, -1724875038},
{1236538674, -1755750016},
{1193077990, -1785567395},
{1148898639, -1814309215},
{1104027236, -1841958163},
{1058490807, -1868497584},
{1012316783, -1893911493},
{965532977, -1918184579},
{918167571, -1941302224},
{870249094, -1963250500},
{821806413, -1984016187},
{772868705, -2003586778},
{723465451, -2021950482},
{673626407, -2039096240},
{623381597, -2055013722},
{572761285, -2069693340},
{521795962, -2083126253},
{470516330, -2095304368},
{418953276, -2106220350},
{367137860, -2115867624},
{315101294, -2124240379},
{262874923, -2131333570},
{210490206, -2137142926},
{157978697, -2141664947},
{105372028, -2144896908},
{52701887, -2146836865},
{0, -2147483647},
{-52701886, -2146836865},
{-105372028, -2144896908},
{-157978697, -2141664947},
{-210490205, -2137142926},
{-262874923, -2131333570},
{-315101294, -2124240379},
{-367137860, -2115867624},
{-418953276, -2106220350},
{-470516330, -2095304368},
{-521795962, -2083126253},
{-572761285, -2069693340},
{-623381597, -2055013722},
{-673626407, -2039096240},
{-723465450, -2021950482},
{-772868705, -2003586778},
{-821806412, -1984016187},
{-870249094, -1963250500},
{-918167571, -1941302224},
{-965532977, -1918184579},
{-1012316783, -1893911493},
{-1058490807, -1868497584},
{-1104027235, -1841958163},
{-1148898639, -1814309215},
{-1193077990, -1785567395},
{-1236538674, -1755750016},
{-1279254514, -1724875039},
{-1321199779, -1692961061},
{-1362349203, -1660027307},
{-1402677998, -1626093615},
{-1442161873, -1591180425},
{-1480777043, -1555308767},
{-1518500249, -1518500249},
{-1555308766, -1480777043},
{-1591180424, -1442161873},
{-1626093615, -1402677999},
{-1660027307, -1362349203},
{-1692961061, -1321199780},
{-1724875038, -1279254515},
{-1755750016, -1236538675},
{-1785567395, -1193077990},
{-1814309215, -1148898640},
{-1841958163, -1104027236},
{-1868497584, -1058490807},
{-1893911493, -1012316783},
{-1918184579, -965532978},
{-1941302223, -918167571},
{-1963250500, -870249095},
{-1984016187, -821806413},
{-2003586778, -772868705},
{-2021950482, -723465451},
{-2039096240, -673626408},
{-2055013722, -623381597},
{-2069693340, -572761285},
{-2083126253, -521795963},
{-2095304368, -470516330},
{-2106220350, -418953276},
{-2115867624, -367137860},
{-2124240379, -315101294},
{-2131333570, -262874923},
{-2137142926, -210490206},
{-2141664947, -157978697},
{-2144896908, -105372028},
{-2146836865, -52701887}
};

UWord8 FindIndex8bit(UWord8 k){
	UWord8 j;
	k=k&(0xff);
	j=((k&0x001)<<7)+((k&0x002)<<5)+((k&0x004)<<3)+((k&0x008)<<1)+((k&0x010)>>1)+((k&0x020)>>3)+((k&0x040)>>5)+((k&0x080)>>7);
	return j;
}


//ReverseIndex
void ReverseIndex(COMPLEX *x){
int i,j;
COMPLEX tmp;
for (i=0;i<N;i++){
	j=FindIndex8bit(i);
	if (j>i){
		tmp.real=x[i].real;
		tmp.imag=x[i].imag;
		x[i].real =x[j].real;
		x[i].imag =x[j].imag;
		x[j].real=tmp.real;
		x[j].imag=tmp.imag;
		}
	}
}

void fft_c(COMPLEX *x) {
	int i, j, k, u = 0, l = 0, wi = 0;


	int SubBlockNum, SubBlockStep = 1;
	bool ov, ovd;
	COMPLEX XkWn;

	ReverseIndex(x);
	for (k = N; k>1; k = (k >> 1)) {
		ov = 0; ovd = 0;
		for (i = 0; i<N; i++)
			if (x[i].real>DOVS || x[i].imag>DOVS || x[i].real<-DOVS || x[i].imag<-DOVS)
			{
				ovd = 1;
				break;
			}
			else if (x[i].real>OVS || x[i].imag>OVS || x[i].real<-OVS || x[i].imag<-OVS)
			{
				ov = 1;
			}
		if (ovd == 1)
			for (i = 0; i<N; i++)
			{
				x[i].real = x[i].real >> 2;
				x[i].imag = x[i].imag >> 2;
			}
		else if (ov == 1)
			for (i = 0; i<N; i++)
			{
				x[i].real = x[i].real >> 1;
				x[i].imag = x[i].imag >> 1;
			}
		SubBlockNum = k >> 1;
		SubBlockStep = SubBlockStep << 1;
		wi = 0;
		for (j = 0; j<SubBlockStep >> 1; j++) {
			for (u = j; u<N; u += SubBlockStep) {
				l = u + (SubBlockStep >> 1);


				XkWn.real = ((x[l].real*wn[wi].real) >> SHN) - ((x[l].imag*wn[wi].imag) >> SHN);
				XkWn.imag = ((x[l].imag*wn[wi].real) >> SHN) + ((x[l].real*wn[wi].imag) >> SHN);

				x[l].real = x[u].real - XkWn.real;
				x[l].imag = x[u].imag - XkWn.imag;
				x[u].real = x[u].real + XkWn.real;
				x[u].imag = x[u].imag + XkWn.imag;
			}
			wi += SubBlockNum;
		}
	}

}



// int main(){
//    COMPLEX XXX[N];
//    for(int i=0; i<N; i++) 
//    {
// 		XXX[i].real = 1;
// 		XXX[i].imag = 0;
// 		printf("%d   ", XXX[i].real);
// 		printf("%d\n", XXX[i].imag);
//    }

//    fft_c(XXX);

// 	for(int i=0; i<N; i++) 
//    {
// 		printf("%d   ", XXX[i].real);
// 		printf("%d\n", XXX[i].imag);
//    }

// 	return 0;

// }