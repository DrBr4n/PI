
float multInt1 (int n, float m){

  float r = 0;



  while(n>0){

    r+=m;

    n--;

  }

  //for(i=0; i<n; i++, r+=m);

     

  return r;

}



float multInt2 (int n, float m){

  float r = 0;



  while(n>0){

    if(n%2!=0) r+=m;

    m*=2;

    n/=2;

  }

   

  return r;

}



float multInt3 (int n, float m, int *count){

  float r = 0;

  *count = 0;

   

  while(n>0){

    if(n%2!=0) r+=m;

    m*=2;

    n/=2;

    (*count)++;

  }

  return r;

}

int mdc1 (int a, int b){

  // 1- Encontrar o menor entre a e b

  // 2 - Percorrer os valores entre [menor..1] e ver qual deles divide a e também divide b

  // 3 - se encontrar algum sair do ciclo

   

  int menor, r = 1;

  if(a>b) menor = b;

  else menor = a;

   

  while(menor>0 && r==1){

    if(a%menor==0 && b%menor==0){

      r = menor;

    }

    menor--;

  }

  return r;

}

int mdc3 (int a, int b, int *count){

  *count = 0;

   

  while(a>0 && b>0) {

    if (a > b)

      a-=b;

    else

      b-=a;

    (*count)++;

  }

  return (a+b);

}

int mdc4 (int a, int b, int *count){

  *count = 0;

   

  while(a>0 && b>0) {

    if (a > b)

      a%=b;

    else

      b%=a;

    (*count)++;

  }

  return (a+b);

}


int main() {

 int a=45,b=126,c;

 int r = mdc3(a,b,&c);

 printf("O mdc de %d e %d é %d.\n O número de iterações é: %d", a, b, r, c);

 return 0;

}