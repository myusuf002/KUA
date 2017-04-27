#include "kua.h"

address alokasi(infotype x){
/**  IS : terdefinisi infotype x sebagai info
 *   FS : mengembalikan address elemen list baru
 *        dengan info = x, next = NULL dan Prev = NULL
**/
    address P;
    P = new elmlist;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

address_r alokasi_r(address x, address y){
/**  IS : terdefinisi address x dan address y
 *   FS : mengembalikan address_r elemen relasi baru
 *        dengan next = NULL, Prev = NULL, up = x dan down = y
**/
    address_r P;
    P = new elmlist_r;
    next(P) = NULL;
    prev(P) = NULL;
    up(P) = x;
    down(P) = y;
    return P;
}

void dealokasi(address P){
/**  IS : terdefinisi address P
 *   FS : menghapus elemen list yang ditunjuk oleh P
**/
    delete P;
}

void dealokasi_r(address_r P){
/**  IS : terdefinisi address_r P
 *   FS : menghapus elemen relasi yang ditunjuk oleh P
**/
    delete P;
}

address findElm(List L, infotype x){
/**  IS : terdefinisi infotype x sebagai info yang dicari
          List L mungkin kosong
 *   FS : mengembalikan address elemen list yang memiliki info = x
 *        mengembalikan NULL jika info = x tidak ditemukan
**/
    address p;
    bool cek;
    cek = false;
    if (first(L) != NULL){
        p = first(L);
        while ((cek==false) && (p != NULL)){
            if (info(p).nik == x.nik){
                cek = true;
            }
            else {
                p = next(p);
            }
        }
    }
    if (cek==true) {
        return p;
    }
    else{
        return NULL;
    }
}

address_r findElm_rt(List_r L, address X){
/**  IS : terdefinisi address X sebagai up yang dicari
          Relasi L mungkin kosong
 *   FS : mengembalikan address elemen relasi yang memiliki up = X
 *        mengembalikan NULL jika up = X tidak ditemukan
**/
    address_r p;
    bool cek;
    cek = false;
    if (first(L) != NULL){
        p = first(L);
        while ((cek==false) && (p != NULL)){
            if (up(p) == X){
                cek = true;
            }
            else {
                p = next(p);
            }
        }
    }
    if (cek==true) {
        return p;
    }
    else{
        return NULL;
    }
}

address_r findElm_rs(List_r L, address X){
/**  IS : terdefinisi address X sebagai up yang dicari
          Relasi L mungkin kosong
 *   FS : mengembalikan address elemen relasi yang memiliki up = X
 *        mengembalikan NULL jika up = X tidak ditemukan
**/
    address_r p;
    bool cek;
    cek = false;
    if (first(L) != NULL){
        p = first(L);
        while ((cek==false) && (p != NULL)){
            if (down(p) == X){
                cek = true;
            }
            else {
                p = next(p);
            }
        }
    }
    if (cek==true) {
        return p;
    }
    else{
        return NULL;
    }
}

address findElm_ri(List_r L, address Y){
/**  IS : terdefinisi address Y sebagai up yang dicari
          Relasi L mungkin kosong
 *   FS : mengembalikan address elemen list yang berelasi dengan address = Y
 *        mengembalikan NULL jika address = Y tidak ditemukan
**/
    address_r p;
    bool cek;
    cek = false;
    if (first(L) != NULL){
        p = first(L);
        while ((cek==false) && (p != NULL)){
            if (up(p) == Y){
                cek = true;
            }
            else {
                p = next(p);
            }
        }
    }
    if (cek==true) {
        return down(p);
    }
    else{
        return NULL;
    }
}

void printInfo(List L, address P){
/**  IS : terdefinisi address P
          List L tidak kosong
 *   FS : menampilkan info yang ditunjuk oleh address P
**/
    cout <<"\nNIK                : " <<info(P).nik <<endl;
    cout <<"Nama               : " <<info(P).nama <<endl;
    cout <<"Pekerjaan          : " <<info(P).pekerjaan <<endl;
    cout <<"Alamat             : " <<info(P).alamat <<endl;
    cout <<"Tempat Lahir       : " <<info(P).lahir.tempat <<endl;
    cout <<"Tanggal Lahir      : " <<info(P).lahir.tgl <<" - " <<info(P).lahir.bln <<" - " <<info(P).lahir.thn <<endl;
    cout <<"Status Perkawinan  : ";
    if (info(P).status == 1){
        cout <<"Lajang" <<endl;
    }
    else if (info(P).status == 2){
        cout <<"Kawin" <<endl;
    }
    else if (info(P).status == 3){
        cout <<"Cerai" <<endl;
    }
    cout <<endl;
}

infotype insertInfo(){
/**  IS : -
 *   FS : mengembalikan info yang telah terisi
**/
    infotype x;
    cout <<"\nMasukkan NIK           : ";
    cin >>x.nik;fflush(stdin);
    cout <<"Masukkan Nama          : ";
    getline(cin, x.nama);fflush(stdin);
    cout <<"Masukkan Pekerjaan     : ";
    getline(cin, x.pekerjaan);fflush(stdin);
    cout <<"Masukkan Alamat        : ";
    getline(cin, x.alamat);fflush(stdin);
    cout <<"Masukkan Tempat Lahir  : ";
    getline(cin, x.lahir.tempat);fflush(stdin);
    cout <<"Masukkan Tanggal Lahir : ";
    cin >>x.lahir.tgl;fflush(stdin);
    cout <<"Masukkan Bulan Lahir   : ";
    cin >>x.lahir.bln;fflush(stdin);
    cout <<"Masukkan Tahun Lahir   : ";
    cin >>x.lahir.thn;fflush(stdin);
    x.status = 1;
    return x;
};

void createList(List &L){
/**  IS : List L mungkin tidak kosong
 *   FS : first L diset NULL dan last L diset NULL
**/
    if (first(L) != NULL){
        first(L) = NULL;
        last(L)= NULL;
    }
}

void createList_r(List_r &L){
/**  IS : List L mungkin tidak kosong
 *   FS : terbentuk list Relasi,first L diset NULL dan last L diset NULL
**/
    if (first(L) != NULL){
        first(L) = NULL;
        last(L)= NULL;
    }
}

void delData(List &L, address &P){
/**  IS : List L mungkin kosong
 *   FS : elemen yang ditunjuk oleh P dihapus
**/
     if(first(L)!=NULL){
        if (first(L)==last(L)){
            P = first(L);
            first(L) = NULL;
            last(L) = NULL;
        }
        else if (last(L)==P){
            P = last(L);
            last(L) = prev(last(L));
            next(last(L)) = NULL;
            prev(P) = NULL;
        }
        else if (first(L)==P){
            P = first(L);
            first(L) = next(P);
            prev(first(L)) = NULL;
            next(P) = NULL;
        }
        else{
            next(prev(P)) = next(P);
            prev(next(P)) = prev(P);
            next(P) = NULL;
            prev(P) = NULL;
        }
        dealokasi(P);
    }
}

void delData_r(List_r &L, address_r &P){
/**  IS : Relasi L mungkin kosong
 *   FS : elemen yang ditunjuk oleh P dihapus
**/
     if(first(L)!=NULL){
        if (first(L)==last(L)){
            P = first(L);
            first(L) = NULL;
            last(L) = NULL;
        }
        else if (last(L)==P){
            P = last(L);
            last(L) = prev(last(L));
            next(last(L)) = NULL;
            prev(P) = NULL;
        }
        else if (first(L)==P){
            P = first(L);
            first(L) = next(P);
            prev(first(L)) = NULL;
            next(P) = NULL;
        }
        else{
            next(prev(P)) = next(P);
            prev(next(P)) = prev(P);
            next(P) = NULL;
            prev(P) = NULL;
        }
        up(P) = NULL;
        down(P) = NULL;
        dealokasi_r(P);
    }
}

void insertLast(List &L, address P){
/**  IS : List L mungkin kosong
 *   FS : elemen yang ditunjuk oleh P menjadi elemen terakhir pada List L
**/
    if (first(L)==NULL){
        first(L)=P;
        last(L)=P;
    }
    else {
        next(last(L))=P;
        prev(P)=last(L);
        last(L)=P;
    }
}

void insertFirst_r(List_r &L, address_r P){
/**  IS : Relasi L mungkin kosong
 *   FS : elemen yang ditunjuk oleh P menjadi elemen pertama pada relasi L
**/
    if (first(L)==NULL){
        first(L)=P;
        last(L)=P;
        prev(P)=NULL;
    }
    else {
        next(P)=first(L);
        prev(first(L))=P;
        first(L)=P;
    }
}

void editList(List &L, address P){
/**  IS : List L tidak kosong
 *   FS : elemen yang ditunjuk oleh P terubah sesuai dengan keinginan user
**/
    infotype x;
    char pil;

    cout <<"\nData yang ingin diubah : "<<endl;
    cout <<"(1). NIK            " <<endl;
    cout <<"(2). Nama           " <<endl;
    cout <<"(3). Pekerjaan      " <<endl;
    cout <<"(4). Alamat         " <<endl;
    cout <<"(5). Tempat Lahir   " <<endl;
    cout <<"(6). Tanggal Lahir  " <<endl;
    cin>>pil;
    switch (pil) {
    case '1' :
            cout <<"Masukkan NIK baru : ";
            cin >>info(P).nik;

        break;
    case '2' :
            cout <<"Masukkan Nama baru : ";
            cin >>info(P).nama;

        break;
    case '3' :
        cout <<"Masukkan Pekerjaan baru : ";
            cin >>info(P).pekerjaan;

        break;
    case '4' :
        cout <<"Masukkan Alamat baru : ";
            cin >>info(P).alamat;

        break;
    case '5' :
        cout <<"Masukkan Tempat Lahir baru : ";
            cin >>info(P).lahir.tempat;

        break;
    case '6' :
        cout <<"Masukkan Tanggal Lahir baru : ";
            cout <<"Masukkan Tanggal Lahir : ";
            cin >>x.lahir.tgl;
            cout <<"Masukkan Bulan Lahir   : ";
            cin >>x.lahir.bln;
            cout <<"Masukkan Tahun Lahir   : ";
            cin >>x.lahir.thn;

        break;
        };

}

void sortAs_nik(List &L){
/**  IS : List L tidak kosong
 *   FS : Elemen list L terurut secara ascending menurut nik
**/
    if ((first(L) != NULL)&&(first(L)!=last(L))){
        address P,Q,Min,X,Y;
        P = first(L);
        while (P!=last(L)){
            Min = P;
            Q = next(P);
            while (Q!=NULL){
                if (info(Min).nik > info(Q).nik){
                    Min = Q;
                }
                Q = next(Q);
            }

            if (P!=Min){
                if (next(first(L))==last(L)){
                    next(Min) = P;
                    prev(P) = Min;
                    next(P) = NULL;
                    prev(Min) = NULL;
                    first(L) = Min;
                    last(L) = P;
                }
                else if ((first(L)==P)&&(last(L)==Min)){
                    X = next(P);
                    next(prev(Min)) = P;
                    prev(P) = prev(Min);
                    next(P) = NULL;
                    next(Min) = X;
                    prev(X) = Min;
                    prev(Min) = NULL;
                    first(L) = Min;
                    last(L) = P;
                    P = X;
                }
                else if ((P==first(L))&&(next(P)==Min)){
                    next(P) = next(Min);
                    prev(next(Min)) = P;
                    next(Min) = P;
                    prev(P) = Min;
                    prev(Min) = NULL;
                    first(L) = Min;
                }
                else if ((next(P)==Min)&&(Min==last(L))){
                    next(prev(P)) = Min;
                    prev(Min) = prev(P);
                    next(Min) = P;
                    prev(P) = Min;
                    next(P) = NULL;
                    last(L) = P;
                }
                else if ((P==first(L))&&(next(P)!=Min)){
                    X = next(P);
                    next(prev(Min)) = P;
                    prev(P) = prev(Min);
                    prev(next(Min)) = P;
                    next(P) = next(Min);
                    next(Min) = X;
                    prev(X) = P;
                    prev(Min) = NULL;
                    first(L) = Min;
                    P = X;
                }
                else if ((next(P)!=Min)&&(last(L)==Min)){
                    X = next(P);
                    Y = prev(P);
                    next(prev(Min)) = P;
                    prev(P) = prev(Min);
                    next(P) = NULL;
                    last(L) = P;
                    next(Y) = Min;
                    prev(Min) = Y;
                    prev(X) = Min;
                    next(Min) = X;
                    P = X;
                }
                else if (next(P)==Min){
                    next(prev(P)) = Min;
                    prev(Min) = prev(P);
                    next(P) = next(Min);
                    prev(next(Min)) = P;
                    next(Min) = P;
                    prev(P) = Min;
                }
                else {
                    X = next(P);
                    Y = prev(P);
                    next(prev(Min)) = P;
                    prev(P) = prev(Min);
                    prev(next(Min)) = P;
                    next(P) = next(Min);
                    prev(X) = Min;
                    next(Min) = X;
                    next(Y) = Min;
                    prev(Min) = Y;
                    P = X;
                }
            }
            else{
                P = next(P);
            }
        }
    }
}

void sortDes_nik(List &L){
/**  IS : List L tidak kosong
 *   FS : Elemen list L terurut secara descending menurut nik
**/
    if ((first(L) != NULL)&&(first(L)!=last(L))){
        address P,Q,Max,X,Y;
        P = first(L);
        while (P!=last(L)){
            Max = P;
            Q = next(P);
            while (Q!=NULL){
                if (info(Max).nik < info(Q).nik){
                    Max = Q;
                }
                Q = next(Q);
            }

            if (P!=Max){
                if (next(first(L))==last(L)){
                    next(Max) = P;
                    prev(P) = Max;
                    next(P) = NULL;
                    prev(Max) = NULL;
                    first(L) = Max;
                    last(L) = P;
                }
                else if ((first(L)==P)&&(last(L)==Max)){
                    X = next(P);
                    next(prev(Max)) = P;
                    prev(P) = prev(Max);
                    next(P) = NULL;
                    next(Max) = X;
                    prev(X) = Max;
                    prev(Max) = NULL;
                    first(L) = Max;
                    last(L) = P;
                    P = X;
                }
                else if ((P==first(L))&&(next(P)==Max)){
                    next(P) = next(Max);
                    prev(next(Max)) = P;
                    next(Max) = P;
                    prev(P) = Max;
                    prev(Max) = NULL;
                    first(L) = Max;
                }
                else if ((next(P)==Max)&&(Max==last(L))){
                    next(prev(P)) = Max;
                    prev(Max) = prev(P);
                    next(Max) = P;
                    prev(P) = Max;
                    next(P) = NULL;
                    last(L) = P;
                }
                else if ((P==first(L))&&(next(P)!=Max)){
                    X = next(P);
                    next(prev(Max)) = P;
                    prev(P) = prev(Max);
                    prev(next(Max)) = P;
                    next(P) = next(Max);
                    next(Max) = X;
                    prev(X) = P;
                    prev(Max) = NULL;
                    first(L) = Max;
                    P = X;
                }
                else if ((next(P)!=Max)&&(last(L)==Max)){
                    X = next(P);
                    Y = prev(P);
                    next(prev(Max)) = P;
                    prev(P) = prev(Max);
                    next(P) = NULL;
                    last(L) = P;
                    next(Y) = Max;
                    prev(Max) = Y;
                    prev(X) = Max;
                    next(Max) = X;
                    P = X;
                }
                else if (next(P)==Max){
                    next(prev(P)) = Max;
                    prev(Max) = prev(P);
                    next(P) = next(Max);
                    prev(next(Max)) = P;
                    next(Max) = P;
                    prev(P) = Max;
                }
                else {
                    X = next(P);
                    Y = prev(P);
                    next(prev(Max)) = P;
                    prev(P) = prev(Max);
                    prev(next(Max)) = P;
                    next(P) = next(Max);
                    prev(X) = Max;
                    next(Max) = X;
                    next(Y) = Max;
                    prev(Max) = Y;
                    P = X;
                }
            }
            else{
                P = next(P);
            }
        }
    }
}

void sortAs_usia(List &L){
/**  IS : List L tidak kosong
 *   FS : Elemen list L terurut secara ascending menurut usia
**/
    if ((first(L) != NULL)&&(first(L)!=last(L))){
        address P,Q,Min,X,Y;
        P = first(L);
        while (P!=last(L)){
            Min = P;
            Q = next(P);
            while (Q!=NULL){
                if ( (info(Min).lahir.tgl + info(Min).lahir.tgl*100 + info(Min).lahir.tgl*1000) > (info(Q).lahir.tgl + info(Q).lahir.tgl*100 + info(Q).lahir.tgl*1000) ){
                    Min = Q;
                }
                Q = next(Q);
            }

            if (P!=Min){
                if (next(first(L))==last(L)){
                    next(Min) = P;
                    prev(P) = Min;
                    next(P) = NULL;
                    prev(Min) = NULL;
                    first(L) = Min;
                    last(L) = P;
                }
                else if ((first(L)==P)&&(last(L)==Min)){
                    X = next(P);
                    next(prev(Min)) = P;
                    prev(P) = prev(Min);
                    next(P) = NULL;
                    next(Min) = X;
                    prev(X) = Min;
                    prev(Min) = NULL;
                    first(L) = Min;
                    last(L) = P;
                    P = X;
                }
                else if ((P==first(L))&&(next(P)==Min)){
                    next(P) = next(Min);
                    prev(next(Min)) = P;
                    next(Min) = P;
                    prev(P) = Min;
                    prev(Min) = NULL;
                    first(L) = Min;
                }
                else if ((next(P)==Min)&&(Min==last(L))){
                    next(prev(P)) = Min;
                    prev(Min) = prev(P);
                    next(Min) = P;
                    prev(P) = Min;
                    next(P) = NULL;
                    last(L) = P;
                }
                else if ((P==first(L))&&(next(P)!=Min)){
                    X = next(P);
                    next(prev(Min)) = P;
                    prev(P) = prev(Min);
                    prev(next(Min)) = P;
                    next(P) = next(Min);
                    next(Min) = X;
                    prev(X) = P;
                    prev(Min) = NULL;
                    first(L) = Min;
                    P = X;
                }
                else if ((next(P)!=Min)&&(last(L)==Min)){
                    X = next(P);
                    Y = prev(P);
                    next(prev(Min)) = P;
                    prev(P) = prev(Min);
                    next(P) = NULL;
                    last(L) = P;
                    next(Y) = Min;
                    prev(Min) = Y;
                    prev(X) = Min;
                    next(Min) = X;
                    P = X;
                }
                else if (next(P)==Min){
                    next(prev(P)) = Min;
                    prev(Min) = prev(P);
                    next(P) = next(Min);
                    prev(next(Min)) = P;
                    next(Min) = P;
                    prev(P) = Min;
                }
                else {
                    X = next(P);
                    Y = prev(P);
                    next(prev(Min)) = P;
                    prev(P) = prev(Min);
                    prev(next(Min)) = P;
                    next(P) = next(Min);
                    prev(X) = Min;
                    next(Min) = X;
                    next(Y) = Min;
                    prev(Min) = Y;
                    P = X;
                }
            }
            else{
                P = next(P);
            }
        }
    }
}

void sortDes_usia(List &L){
/**  IS : List L tidak kosong
 *   FS : Elemen list L terurut secara descending menurut usia
**/
    if ((first(L) != NULL)&&(first(L)!=last(L))){
        address P,Q,Max,X,Y;
        P = first(L);
        while (P!=last(L)){
            Max = P;
            Q = next(P);
            while (Q!=NULL){
                if ( (info(Max).lahir.tgl + info(Max).lahir.tgl*100 + info(Max).lahir.tgl*1000) < (info(Q).lahir.tgl + info(Q).lahir.tgl*100 + info(Q).lahir.tgl*1000) ){
                    Max = Q;
                }
                Q = next(Q);
            }

            if (P!=Max){
                if (next(first(L))==last(L)){
                    next(Max) = P;
                    prev(P) = Max;
                    next(P) = NULL;
                    prev(Max) = NULL;
                    first(L) = Max;
                    last(L) = P;
                }
                else if ((first(L)==P)&&(last(L)==Max)){
                    X = next(P);
                    next(prev(Max)) = P;
                    prev(P) = prev(Max);
                    next(P) = NULL;
                    next(Max) = X;
                    prev(X) = Max;
                    prev(Max) = NULL;
                    first(L) = Max;
                    last(L) = P;
                    P = X;
                }
                else if ((P==first(L))&&(next(P)==Max)){
                    next(P) = next(Max);
                    prev(next(Max)) = P;
                    next(Max) = P;
                    prev(P) = Max;
                    prev(Max) = NULL;
                    first(L) = Max;
                }
                else if ((next(P)==Max)&&(Max==last(L))){
                    next(prev(P)) = Max;
                    prev(Max) = prev(P);
                    next(Max) = P;
                    prev(P) = Max;
                    next(P) = NULL;
                    last(L) = P;
                }
                else if ((P==first(L))&&(next(P)!=Max)){
                    X = next(P);
                    next(prev(Max)) = P;
                    prev(P) = prev(Max);
                    prev(next(Max)) = P;
                    next(P) = next(Max);
                    next(Max) = X;
                    prev(X) = P;
                    prev(Max) = NULL;
                    first(L) = Max;
                    P = X;
                }
                else if ((next(P)!=Max)&&(last(L)==Max)){
                    X = next(P);
                    Y = prev(P);
                    next(prev(Max)) = P;
                    prev(P) = prev(Max);
                    next(P) = NULL;
                    last(L) = P;
                    next(Y) = Max;
                    prev(Max) = Y;
                    prev(X) = Max;
                    next(Max) = X;
                    P = X;
                }
                else if (next(P)==Max){
                    next(prev(P)) = Max;
                    prev(Max) = prev(P);
                    next(P) = next(Max);
                    prev(next(Max)) = P;
                    next(Max) = P;
                    prev(P) = Max;
                }
                else {
                    X = next(P);
                    Y = prev(P);
                    next(prev(Max)) = P;
                    prev(P) = prev(Max);
                    prev(next(Max)) = P;
                    next(P) = next(Max);
                    prev(X) = Max;
                    next(Max) = X;
                    next(Y) = Max;
                    prev(Max) = Y;
                    P = X;
                }
            }
            else{
                P = next(P);
            }
        }
    }
}

