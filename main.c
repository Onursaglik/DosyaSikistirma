#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>



struct deflate_compare
{
    char characther;
    int length;
    char *deff;

}*left,*right;

struct ayirma_lz77
{
    int uzaklik;
    char *ilerleme;
    char karakter;
    int uzunluk;

};

/*
struct compare_deflate_lz77
{

};
*/
struct lz77_compare
{
    char *temper;
    int adim;
    char **searcher;
    int bolum;
    int *booleann;

}secim_ayraci(char*ilk_parca,struct lz77_compare,int bolum);



struct lz77_compare secim_ayraci(char *ilk_parca,struct lz77_compare gezici,int bolum)
{

    int j=0,kannter=0,sayici=0,bolunen=0,bolum1=0,i=0;
    int size=strlen(ilk_parca);
    gezici.booleann=(int*)malloc(sizeof(int)*size);

    while(i<size)
    {
        bolunen=strlen(ilk_parca);
        bolum1=7;
        gezici.bolum=bolunen/bolum1;
        gezici.booleann[i]=0;
        i++;
    }
//printf("bolum1 deger : %d",bolum1);

    gezici.searcher=(char**)malloc(sizeof(char*)*gezici.bolum),i=0;
    int kosulsagla=1;
    int memor=bolum1+1;
    int adet=0;

    while(i<gezici.bolum)
    {
        //memory up -70
        gezici.bolum=bolunen/bolum1;
        gezici.searcher[i]=(char*)malloc(sizeof(char)*memor);
        adet++;
        i++;
    }


    while(j!=gezici.bolum)
    {
        gezici.bolum=bolunen/bolum1;
        gezici.searcher[j][kannter]=ilk_parca[sayici];
        /*
        ayirim için 7 şerlik sıra uygun gördüm.
        */
        sayici++;
        kannter++;

        if(kosulsagla==1)
        {
            if(kannter%bolum1==0 && bolum1==7)
            {
                gezici.searcher[j][kannter]='\0';
                j++;
                kannter=0;
            }
        }
    }
    return gezici;
}

/*
void deflate_coder()
{

}
*/

int hesapla_length(int alignment,int dongu,int j,char *metcounter,int i,struct lz77_compare gezici)
{
    int uzunluk=0;
    int boyut=0;

    if(dongu!=0)
    {

        while(888888)
        {
            boyut=strlen(metcounter);

            if(boyut!=0)
            {

                if(metcounter[j]!=gezici.searcher[alignment][i]||j==boyut)
                {
                    break;
                }
            }
            else
            {
                printf("error length is not found || hata uzunluk bulunamadı");
            }

            uzunluk++;
            i++;
            j++;
        }
    }
    return uzunluk;
}


int main()
{
    FILE *dosya=fopen("metin.txt","r");

    int surec=1;
    int bolumm=1;
    char al_karakter;
    int sayac1=0;
    char *ilk_parca=(char*)malloc(sizeof(char)*1);

    if(al_karakter!=EOF)
    {
        while(al_karakter!=EOF)
        {
            al_karakter=fgetc(dosya);
            if(al_karakter==EOF)
            {
                //en son dosyaya yli üslü yazdırıyor bunu yapmazsak
                break;
            }
            sayac1=surec-1;
            ilk_parca[sayac1]=al_karakter;
            surec++;
            bolumm++;
            //Dinamik bellek artirimi.
            if(sayac1==0&&al_karakter==EOF)
            {
                break;
            }
            ilk_parca=realloc(ilk_parca,sizeof(char)*surec);
        }
    }

    fclose(dosya);

    //son bitimi esitliyoruz
    struct lz77_compare gezici;
    struct deflate_compare dumpp;
    ilk_parca[surec-1]='\0';
    int period=7;
    int boyut2=strlen(ilk_parca);
    char girdi='c';

    struct ayirma_lz77 *ayirici=(struct ayirma_lz77*)malloc(sizeof(struct ayirma_lz77)*boyut2);

    if(bolumm!=1)
    {
        //Secim ayracina gonderildi
        gezici=secim_ayraci(ilk_parca,gezici,bolumm);
    }

    int uzunluk=0,uzaklik=0,count=7,alignment,j,i=0,flag,k=1,sayac=0,kanntent=0,bolum2=7,dongu=1,cikarilacak=0;

    if(girdi=='c')
    {
        while(count<boyut2)
        {
            alignment=0;
            kanntent=(count/bolum2);
            while(alignment<kanntent)
            {
                if(surec!=1)
                {
                    j=0;

                    while(j<bolum2)
                    {

                        if(ilk_parca[count]==gezici.searcher[alignment][j])
                        {

                            uzunluk=hesapla_length(alignment,dongu,count,ilk_parca,j,gezici);
                            sayac=1;

                            if(uzunluk>1)
                            {
                                flag=1;
                                i=0;

                                while(i<uzunluk)

                                {
                                    if(gezici.booleann[count+i]==1&&sayac==1)
                                    {
                                        flag=0;
                                        break;
                                    }
                                    i++;
                                }

                                if(sayac==1)

                                {
                                    if(flag==1)
                                    {
                                        cikarilacak=(alignment*bolum2)+j;
                                        uzaklik=count-cikarilacak;
                                        i=0;

                                        while(i<uzunluk)
                                        {
                                            gezici.booleann[count+i]=1;
                                            dongu++;
                                            i++;

                                        }
                                        ayirici[count].karakter=ilk_parca[count];

                                        if(girdi=='c')
                                        {
                                            //girdi=c rememb code
                                            ayirici[count].uzaklik=uzaklik;
                                            dongu=1;
                                            ayirici[count].uzunluk=uzunluk;
                                        }
                                        else
                                        {

                                            dongu=0;
                                        }
                                    }
                                }
                            }

                            if(k==1)
                            {
                                uzunluk=0;
                                uzaklik=0;
                            }

                            else
                            {

                                break;

                            }
                        }
                        j++;
                    }
                }
                alignment++;
            }
            count++;
        }
    }

    if(alignment!=0)
    {
        printf("\nmetin.txt dosyasina lz77 sikistirma algoritmasi uygulandi.\nlz77_compare_encoded.txt dosyasini kontrol edebilirsiniz. ");
    }

    int len=0;
    FILE *deflate_dosya;

    char c;
    deflate_dosya = fopen("metin.txt","r");
    fseek(deflate_dosya,0,SEEK_END);
    int counterr=ftell(deflate_dosya);
    char karakter_dizi[counterr];
    struct deflate_compare *karakterr;
    int x=0;
    printf("\n");

    do
    {
        c = fgetc(dosya);
        printf(" %c ",c);

        if(len%2==0)
        {
            printf("%c",c);
            karakter_dizi[x]=c;
            x++;
        }
        if(len%2==1)

        {
            printf("%c",c);
            karakter_dizi[x]=c;
            x++;
        }

        len++;

        if( feof(dosya) )
        {
            break ;
        }

    }
    while(1);

    printf("\n\n");

/////////////lz77 yazdirma//////////////
    FILE *fp;
    fp=fopen("lz77_compare_encoded.txt","w+");

    i=0;
    //printf("%d",boyut2);
    if(boyut2!=0)
    {
        i=0;

        while(i<boyut2)
        {
            if(gezici.booleann[i]==0 && i<boyut2)
            {
                fprintf(fp,"<0,0,%c>\n",ilk_parca[i]);
            }

            else if(gezici.booleann[i]!=0 && i<boyut2)
            {
                fprintf(fp,"<%d,%d,%c>\n",ayirici[i].uzaklik,ayirici[i].uzunluk,ayirici[i].karakter);
                i=ayirici[i].uzunluk-1+i;
            }
            i++;
        }
    }

    fseek(fp,0,SEEK_END);
//fseek imlecin kaldigi yerden sayim yapiyordu imleci her seferinde 0 ilk karaktere aldik böylece boyutu dogru olarak aldim.

    /*
    //boyutu yanlis aldi

        char karakter;
        int saydim=0;
        char k1[10000];

        while(!feof(fp))
    {
        fscanf(fp,"%s",&k1[i]);
        saydim++;

    }
        printf("lz77 boyutumuz %d ",saydim);
    */

    if(girdi=='c')

    {
        int boyutumuz=ftell(fp);
        printf("\n\nLZ77 uygulamasinin boyutu : %d\t\n",boyutumuz);

    }

    fclose(fp);

    return 0;
}





