#include <stdio.h>
#include <string.h>

float leValor(float *ValorLido);
float inicializaPrograma(float *ValorLido);

int main(void) {

  char unidades[9][10] = {"Um ", "Dois ", "Tres ", "Quatro ", "Cinco ", "Seis ", "Sete ", "Oito ", "Nove "};
  char dez[9][15] = {"Onze ", "Doze ", "Treze ", "Quatorze ", "Quinze ", "Desesseis ", "Desessete ", "Dezoito ", "Dezenove "};
  char dezenas[9][15] = {"Dez ", "Vinte ", "Trinta ", "Quarenta ", "Cinquenta ", "Sessenta ", "Setenta ", "Oitenta ", "Noventa "};
  char centenas[9][15] = {"Cem ", "Duzentos ", "Trezentos ", "Quatrocentos ", "Quinhentos ", "Seiscentos ", "Setecentos ", "Oitocentos ", "Novecentos "};

  char extenso[100] = "";
  float valorLido, *pValorLido, parteDecimal; 
  int multiplo, restante;
  
  pValorLido = &valorLido;
  inicializaPrograma(pValorLido);

  while(valorLido != 0){
    strcpy(extenso, "");
    
    restante = valorLido;
    parteDecimal = valorLido - restante;
    
    multiplo = valorLido / 1000;
    restante -= (multiplo * 1000);

    //milhar
    if(multiplo >= 1){
      strcat(extenso, unidades[multiplo - 1]);
      strcat(extenso, "Mil");
      //verificar se precisa de virgula ou 'e'
      int tempDezenas = restante - (restante / 100) * 100;
      if(((restante / 100) >= 1) && (tempDezenas > 0)){ 
        strcat(extenso, ", ");
      }else if(restante > 0){
        strcat(extenso, " e ");
      }else{
        strcat(extenso, " ");
      }
    }

    multiplo = restante / 100;
    restante -= (multiplo * 100);

    //centenas
    if(multiplo == 1){ 
      if(restante == 0){
        strcat(extenso, centenas[0]);
      }else{
        strcat(extenso, "Cento e ");
      }
    }else if(multiplo > 1){ 
      strcat(extenso, centenas[multiplo - 1]);
      if(restante > 0){
         strcat(extenso, "e ");
      }
    }

    multiplo = restante / 10;
    restante -= (multiplo * 10);
    
    //dezenas
    if(multiplo == 1){ 
      if(restante == 0){
        strcat(extenso, dezenas[0]);
      }else{
        strcat(extenso, dez[restante - 1]);
        restante = 0;
      }
    }else if(multiplo > 1){ 
      strcat(extenso, dezenas[multiplo - 1]);
      if(restante > 0){
         strcat(extenso, "e ");
      }
    }
  
    //unidades
    if(restante >= 1){
      strcat(extenso, unidades[restante - 1]);
    }

    restante = valorLido;

    if(restante == 1){
      strcat(extenso, "Real ");
    }else if(restante > 1){
      strcat(extenso, "Reais ");
    }

    parteDecimal += 1e-3; //acrescenta o valor perdido na conversão
    restante = parteDecimal * 100; 

    //analisa se precisa de "e"
    if(strlen(extenso) > 0 && restante > 0){
      strcat(extenso, "e ");
    }

    //dezenas - centavos
    multiplo = restante / 10;
    restante -= (multiplo * 10);
    
    if(multiplo == 1){ 
      if(restante == 0){
        strcat(extenso, dezenas[0]);
      }else{
        strcat(extenso, dez[restante - 1]);
        restante = 0;
      }
    }else if(multiplo > 1){ 
      strcat(extenso, dezenas[multiplo - 1]);
      if(restante > 0){
         strcat(extenso, "e ");
      }
    }

    //unidades - centavos
    if(restante >= 1){
      strcat(extenso, unidades[restante - 1]);
    }
    
    restante = parteDecimal * 100;

    if(restante == 1){
      strcat(extenso, "Centavo ");
    }else if(restante > 1){
      strcat(extenso, "Centavos ");
    }
    
    printf("=> %s\n", extenso);
    
    leValor(pValorLido);
  }
  
  printf("\nPrograma finalizado.\n");
  
  return 0;
}

float inicializaPrograma(float *ValorLido){
  printf("\n*************************************");
  printf("\n*****    Escreve por Extenso    *****");
  printf("\n*************************************");

  printf("\nDigite um valor (ex: 9999.99):");
  printf("\nR$");
  scanf("%f", ValorLido);

  return 0;
}

float leValor(float *ValorLido){
  printf("\n*************************************");
  printf("\nDigite um valor ou 0 para finalizar:");
  printf("\nR$");
  scanf("%f",ValorLido);
  
  return 0;
}