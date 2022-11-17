#include <stdio.h>
#include <stdlib.h>
/*
Öğrenci bilgilerini işlemek için çift bağlantılı (doubly linked) bir liste yapısı oluşturun. Öğrenci numarası anahtar bilgi olmalıdır.
Aşağıdaki gibi bir menü kontrolü altında çalışacak şekilde C kodunuzu oluşturun:
– Create link list
– Destroy linked list
– Add node
– Delete node
– Search node
– Display list (traverse list)

Öğrenci No Ad
Soyad Bölüm Sınıf
...

*/

typedef struct n
{

    struct n *next;
    struct n *prev;
    char *isim;
    char *soyisim;
    unsigned int ogrenciNumarasi;
    char *bolum;
    unsigned int sinif;

} OGRENCİ;

typedef struct list
{
    OGRENCİ *posion;
    OGRENCİ *root;
    OGRENCİ *rear;

    int count;

} LIST;



LIST *CreateList()
{
    LIST *liste = (LIST *)malloc(sizeof(LIST));
    liste->root = NULL;
    liste->rear = NULL;
    liste->posion = NULL;
    liste->count = 0;
    return liste;
}

void AddToEndOfList(LIST *liste, OGRENCİ *ogrenci)
{
    OGRENCİ *head = liste->root;

    if (head == NULL)
    {
        printf("dugum \n");

        head = (OGRENCİ *)malloc(sizeof(OGRENCİ));
        head->isim = ogrenci->isim;
        head->soyisim = ogrenci->soyisim;
        head->ogrenciNumarasi = ogrenci->ogrenciNumarasi;
        head->bolum = ogrenci->bolum;
        head->sinif = ogrenci->sinif;
        head->next = NULL;
        head->prev = NULL;
        printf("dugum olusturuldu \n");
        liste->root = head;
        liste->rear = head;
        liste->count++;
    }
    else
    {
        OGRENCİ *temp = (OGRENCİ *)malloc(sizeof(OGRENCİ));

        temp->next = NULL;
        temp->prev = liste->rear;
        temp->isim = ogrenci->isim;
        temp->soyisim = ogrenci->soyisim;
        temp->ogrenciNumarasi = ogrenci->ogrenciNumarasi;
        temp->bolum = ogrenci->bolum;
        temp->sinif = ogrenci->sinif;
        liste->rear->next = temp;

        liste->rear = temp;

        liste->count++;
    }
}
void AddToEndOfList2(LIST *liste, char *isim, char *soyisim, unsigned int ogrenciNumarasi, char *bolum, unsigned int sinif)
{
    OGRENCİ *head = liste->root;

    if (head == NULL)
    {
        printf("dugum \n");

        head = (OGRENCİ *)malloc(sizeof(OGRENCİ));
        head->isim = isim;
        head->soyisim = soyisim;
        head->ogrenciNumarasi = ogrenciNumarasi;
        head->bolum = bolum;
        head->sinif = sinif;
        head->next = NULL;
        head->prev = NULL;
        printf("dugum olusturuldu \n");
        liste->root = head;
        liste->rear = head;
        liste->count++;
    }
    else
    {

        OGRENCİ *temp = (OGRENCİ *)malloc(sizeof(OGRENCİ));

        temp->next = NULL;
        temp->prev = liste->rear;
        temp->isim = isim;
        temp->soyisim = soyisim;
        temp->ogrenciNumarasi = ogrenciNumarasi;
        temp->bolum = bolum;
        temp->sinif = sinif;
        liste->rear->next = temp;

        liste->rear = temp;

        liste->count++;
    }
}

void AddToBeginningOfList(LIST *liste, OGRENCİ *ogrenci)
{
    OGRENCİ *head = liste->root;

    if (head == NULL)
    {
        printf("dugum \n");

        head = (OGRENCİ *)malloc(sizeof(OGRENCİ));
        head->isim = ogrenci->isim;
        head->soyisim = ogrenci->soyisim;
        head->ogrenciNumarasi = ogrenci->ogrenciNumarasi;
        head->bolum = ogrenci->bolum;
        head->sinif = ogrenci->sinif;
        head->next = NULL;
        head->prev = NULL;
        printf("dugum olusturuldu \n");
        liste->root = head;
        liste->rear = head;
        liste->count++;
    }
    else
    {
        OGRENCİ *temp = (OGRENCİ *)malloc(sizeof(OGRENCİ));

        temp->next = liste->root;
        temp->prev = NULL;
        temp->isim = ogrenci->isim;
        temp->soyisim = ogrenci->soyisim;
        temp->ogrenciNumarasi = ogrenci->ogrenciNumarasi;
        temp->bolum = ogrenci->bolum;
        temp->sinif = ogrenci->sinif;
        liste->root->prev = temp;
        liste->root = temp;
        liste->count++;
    }
}
void AddToBeginningOfList2(LIST *liste, char *isim, char *soyisim, unsigned int ogrenciNumarasi, char *bolum, unsigned int sinif)
{
    OGRENCİ *head = liste->root;

    if (head == NULL)
    {
        printf("dugum \n");

        head = (OGRENCİ *)malloc(sizeof(OGRENCİ));
        head->isim = isim;
        head->soyisim = soyisim;
        head->ogrenciNumarasi = ogrenciNumarasi;
        head->bolum = bolum;
        head->sinif = sinif;
        head->next = NULL;
        head->prev = NULL;
        printf("dugum olusturuldu \n");
        liste->root = head;
        liste->rear = head;
        liste->count++;
    }
    else
    {
        OGRENCİ *temp = (OGRENCİ *)malloc(sizeof(OGRENCİ));

        temp->next = liste->root;
        temp->prev = NULL;
        temp->isim = isim;
        temp->soyisim = soyisim;
        temp->ogrenciNumarasi = ogrenciNumarasi;
        temp->bolum = bolum;
        temp->sinif = sinif;
        liste->root->prev = temp;
        liste->root = temp;
        liste->count++;
    }
}

void AddAtYourChoosingPosionOfList(LIST *liste, unsigned int secim, OGRENCİ *student)
{
    if (secim == 1)
    {
        AddToBeginningOfList(liste, student);
    }
    else if (secim == 2)
    {
        OGRENCİ *iter = liste->root;
        OGRENCİ *temp = (OGRENCİ *)malloc(sizeof(OGRENCİ));
        temp->isim = student->isim;
        temp->soyisim = student->soyisim;
        temp->ogrenciNumarasi = student->ogrenciNumarasi;
        temp->bolum = student->bolum;
        temp->sinif = student->sinif;
        temp->next = iter->next;
        temp->prev = iter;
        iter->next->prev = temp;
        iter->next = temp;
        liste->count++;
    }
    else if (secim > liste->count)
    {
        AddToEndOfList(liste, student);
    }
    else if (secim <= 0)
    {
        printf("yanlis secim yaptiniz \n");
    }
    else
    {
        OGRENCİ *iter = liste->root;

        for (size_t i = 0; i < secim - 2; i++)
        {
            iter = iter->next;
        }
        OGRENCİ *temp = (OGRENCİ *)malloc(sizeof(OGRENCİ));
        temp->isim = student->isim;
        temp->soyisim = student->soyisim;
        temp->ogrenciNumarasi = student->ogrenciNumarasi;
        temp->bolum = student->bolum;
        temp->sinif = student->sinif;
        temp->next = iter->next;
        temp->prev = iter;
        iter->next->prev = temp;
        iter->next = temp;
        liste->count++;
    }
}
void AddAtYourChoosingPosionOfList2(LIST *liste, unsigned int secim, char *isim, char *soyisim, unsigned int ogrenciNumarasi, char *bolum, unsigned int sinif)
{

    if (secim == 1)
    {
        AddToBeginningOfList2(liste, isim, soyisim, ogrenciNumarasi, bolum, sinif);
    }
    else if (secim == 2)
    {
        OGRENCİ *iter = liste->root;
        OGRENCİ *temp = (OGRENCİ *)malloc(sizeof(OGRENCİ));
        temp->isim = isim;
        temp->soyisim = soyisim;
        temp->ogrenciNumarasi = ogrenciNumarasi;
        temp->bolum = bolum;
        temp->sinif = sinif;
        temp->next = iter->next;
        temp->prev = iter;
        iter->next->prev = temp;
        iter->next = temp;
        liste->count++;
    }
    else if (secim > liste->count)
    {
        AddToEndOfList2(liste, isim, soyisim, ogrenciNumarasi, bolum, sinif);
    }
    else if (secim <= 0)
    {
        printf("yanlis secim yaptiniz \n");
    }
    else
    {
        OGRENCİ *iter = liste->root;

        for (size_t i = 0; i < secim - 2; i++)
        {
            iter = iter->next;
        }
        OGRENCİ *temp = (OGRENCİ *)malloc(sizeof(OGRENCİ));
        temp->isim = isim;
        temp->soyisim = soyisim;
        temp->ogrenciNumarasi = ogrenciNumarasi;
        temp->bolum = bolum;
        temp->sinif = sinif;
        temp->next = iter->next;
        temp->prev = iter;
        iter->next->prev = temp;
        iter->next = temp;
        liste->count++;
    }
}

OGRENCİ *SearchItem(LIST *liste, OGRENCİ *ogrenci)
{
    OGRENCİ *iter = liste->root;
    while (iter->next != NULL)
    {
        if (iter->ogrenciNumarasi == ogrenci->ogrenciNumarasi)
        {
            return iter;
        }
        iter = iter->next;
    }
    if (iter->ogrenciNumarasi == ogrenci->ogrenciNumarasi)
    {
        return iter;
    }
    return NULL;
}
OGRENCİ *SearchItemWithSchoolNumber(LIST *liste, unsigned int ogrenciNumarasi)
{
    OGRENCİ *iter = liste->root;
    while (iter->next != NULL)
    {
        if (iter->ogrenciNumarasi == ogrenciNumarasi)
        {
            return iter;
        }
        iter = iter->next;
    }
    if (iter->ogrenciNumarasi == ogrenciNumarasi)
    {
        return iter;
    }
    return NULL;
}

void DeleteItem(LIST *liste, OGRENCİ *ogrenci)
{
    OGRENCİ *iter = liste->root;
    if (iter == NULL)
    {
        printf("liste bos \n");
        return;
    }
    else if (iter->ogrenciNumarasi == ogrenci->ogrenciNumarasi)
    {
        if (iter->next == NULL)
        {
            printf("listenin ilk elemanı silindi ve baska eleman yok  \n");
            liste->root = NULL;

            liste->count--;
            free(iter);
            return;
        }
        else
        {
            printf("listenin ilk elemanı silindi \n");
            liste->root = iter->next;
            liste->root->prev = NULL;
            liste->count--;
            free(iter);
            return;
        }
    }
    else
    {
        while (iter->next != NULL)
        {
            if (iter->ogrenciNumarasi == ogrenci->ogrenciNumarasi)
            {
                iter->prev->next = iter->next;
                iter->next->prev = iter->prev;
                liste->count--;
                free(iter);
                return;
            }
            iter = iter->next;
        }

        if (iter->ogrenciNumarasi == ogrenci->ogrenciNumarasi)
        {
            iter->prev->next = NULL;
            liste->count--;
            free(iter);
            return;
        }
    }
}
void DeleteItemWithStudentNumber(LIST *liste, unsigned int ogrenciNumarasi)
{
    OGRENCİ *iter = liste->root;
    if (iter == NULL)
    {
        printf("liste bos \n");
        return;
    }
    else if (iter->ogrenciNumarasi == ogrenciNumarasi)
    {
        if (iter->next == NULL)
        {
            printf("listenin ilk elemanı silindi ve baska eleman yok  \n");
            liste->root = NULL;

            liste->count--;
            free(iter);
            return;
        }
        else
        {
            printf("listenin ilk elemanı silindi \n");
            liste->root = iter->next;
            liste->root->prev = NULL;
            liste->count--;
            free(iter);
            return;
        }
    }
    else
    {
        while (iter->next != NULL)
        {
            if (iter->ogrenciNumarasi == ogrenciNumarasi)
            {
                iter->prev->next = iter->next;
                iter->next->prev = iter->prev;
                liste->count--;
                free(iter);
                return;
            }
            iter = iter->next;
        }

        if (iter->ogrenciNumarasi == ogrenciNumarasi)
        {
            iter->prev->next = NULL;
            liste->count--;
            free(iter);
            return;
        }
    }
}

void DestroyList(LIST *liste)
{

    OGRENCİ *iter = liste->rear;
    while (iter->prev != liste->root)
    {
        OGRENCİ *temp = iter;
        temp->next = NULL;

        iter = iter->prev;
        iter->next = NULL;
        temp->prev = NULL;

        free(temp);

        liste->count--;
    }
    OGRENCİ *temp = iter;
    temp->next = NULL;
    iter = iter->prev;
    iter->next = NULL;
    temp->prev = NULL;

    free(temp);
    liste->count--;
    free(liste->root);
    liste->root = NULL;
    liste->rear = NULL;

    printf("liste silindi \n");
}

void PrintList(LIST *liste)
{
    OGRENCİ *head = liste->root;
    while (head->next != NULL)
    {
        printf("isim: %s soyisim: %s ogrenci numarasi: %d bolum: %s sinif: %u \n", head->isim, head->soyisim, head->ogrenciNumarasi, head->bolum, head->sinif);

        head = head->next;
    }
    printf("isim: %s soyisim: %s ogrenci numarasi: %d bolum: %s sinif: %u \n", head->isim, head->soyisim, head->ogrenciNumarasi, head->bolum, head->sinif);
    printf("\n");
}

int countOfList(LIST *liste)
{
    return liste->count;
}

OGRENCİ * GetDataFromStudent(){
    char *isim=(char*)malloc(sizeof(char)*100);
    char *soyisim=(char*)malloc(sizeof(char)*100);
    char *bolum=(char*)malloc(sizeof(char)*100);
    unsigned int ogrenciNumarasi;
    unsigned int sinif;

    printf("isim giriniz: ");
    scanf("%s",isim);
    

    printf("soyisim giriniz: ");
    scanf("%s",soyisim);
    

    printf("bolum giriniz: ");
    scanf("%s",bolum);
    

    printf("ogrenci numarasi giriniz: ");
    scanf("%u",&ogrenciNumarasi);
    


    printf("sinif giriniz: ");
    scanf("%u",&sinif);
    printf("\n");

    OGRENCİ *ogrenci=(OGRENCİ*)malloc(sizeof(OGRENCİ));
    ogrenci->isim=isim;
    ogrenci->soyisim=soyisim;
    ogrenci->bolum=bolum;
    ogrenci->ogrenciNumarasi=ogrenciNumarasi;
    ogrenci->sinif=sinif;


    



    


    return ogrenci;
}

int main(){
    LIST *liste =NULL;
    OGRENCİ *temp = NULL;
    int secim;


    do
    {
        printf("1-Liste olustur \n");
        printf("2-Listeye bastan eleman ekle \n");
        printf("3-Listeye sondan eleman ekle \n");
        printf("4-Listeye istedigin yerden eleman ekle \n");
        printf("5-Listeden ogrenci numarasi ile eleman sil \n");
        printf("6-Listeden ogrenci numarasi ile eleman bul \n");
        printf("7-Listeyi yazdir \n");
        printf("8-Listeyi sil \n");
        
        printf("0-Cikis \n");
        printf("\n");


        printf("seciminizi giriniz: ");
        scanf("%d", &secim);
        printf("\n");
        switch (secim)
        {
        
        case 1:
            liste = CreateList();
            printf("Liste eleman sayisi: %d \n", countOfList(liste));
            printf("\n");
            
            break;
        case 2:
            temp=GetDataFromStudent();
            AddToBeginningOfList(liste, temp);
            printf("Liste eleman sayisi: %d \n", countOfList(liste));
            printf("\n");
            break;
        case 3:
            temp=GetDataFromStudent();
            AddToEndOfList(liste, temp);
            printf("Liste eleman sayisi: %d \n", countOfList(liste));
            printf("\n");
            break;
        case 4:
            printf("kacinci siraya ekleyelim ? :");
            unsigned int  sira;
            scanf("%u",&sira);
            temp=GetDataFromStudent();
            AddAtYourChoosingPosionOfList(liste,sira,temp);
            printf("Liste eleman sayisi: %d \n", countOfList(liste));
            printf("\n");
            break;
        case 5:
            printf("silinecek ogrenci numarasini giriniz: ");
            int studentNumber;
            scanf("%d", &studentNumber);
            DeleteItemWithStudentNumber(liste, studentNumber);
            printf("Liste eleman sayisi: %d \n", countOfList(liste));
            printf("\n");
            break;    
        case 6:
            printf("bulunacak ogrenci numarasini giriniz: ");
            
            scanf("%d", &studentNumber);
            OGRENCİ *finded=SearchItemWithSchoolNumber(liste, studentNumber);
            printf("isim: %s soyisim: %s ogrenci numarasi: %d bolum: %s sinif: %u \n", finded->isim, finded->soyisim, finded->ogrenciNumarasi, finded->bolum, finded->sinif);
            printf("Liste eleman sayisi: %d \n", countOfList(liste));
            printf("\n");
            break;
        case 7:
            PrintList(liste);
            printf("Liste eleman sayisi: %d \n", countOfList(liste));
            printf("\n");
            break;
        case 8:
            DestroyList(liste);
            printf("Liste eleman sayisi: %d \n", countOfList(liste));
            printf("\n");
            break;
        

        case -1:
            printf("cikiliyor \n");
            exit(0);

            break;            
       
        }
    } while (secim != 0);
    
    

    
    

    
    
    
    

    return 0;

}
    


