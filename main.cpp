#include "kua.h"
int main()
{
    int  j;
    char menu, pil, pol, pel;
    List pria, wanita;
    infotype x, s, i;
    address P, X, Y;
    createList(pria);
    createList(wanita);

    List_r kawin;
    createList_r(kawin);
    address_r Q, R;

    do {
        system("cls");
        cout <<"\t\t\t\tAPLIKASI ADMINISTRASI \n\t\t\t\t KANTOR URUSAN AGAMA" <<endl <<endl;
        cout <<"\t(1). Data Calon Pengantin \n";
        cout <<"\t(2). Data Pernikahan \n";
        cout <<"\t(0). Exit\n" ;
        cout <<"\nPilihan : ";
        cin >>menu;
//# Calon Pengantin #################################################################################################################
        if (menu == '1'){
            do{
                system("cls");
                cout <<"\t\t\t\tAPLIKASI ADMINISTRASI \n\t\t\t\t KANTOR URUSAN AGAMA" <<endl <<endl;
                cout <<"Data Calon Pengantin\n";
                cout <<"\t(1). Input Data \t\t (2). Delete Data \n" ;
                cout <<"\t(3). Edit Data  \t\t (4). Search Data \n" ;
                cout <<"\t(5). Show Data  \t\t (6). Sort Data  \n" ;
                cout <<" \t\t\t\t\t (0). Back\n";
                cout <<"\nPilihan : ";
                cin >>pil;

                switch (pil){
                case '1' :
// INPUT ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    do{
                        system("cls");
                        cout <<"\t\t\t\t    INPUT DATA" <<endl <<endl;
                        cout <<"(1). Input Data Pria  " <<endl;
                        cout <<"(2). Input Data Wanita  " <<endl;
                        cout <<"(0). Back" <<endl;
                        cout <<"\nPilihan : ";
                        cin >>pol;
                        switch (pol){
                            case '1' :
                                cout <<"(1). Input Data Pria  " <<endl;
                                x = insertInfo();
                                P = alokasi(x);
                                insertLast(pria, P);
                                getch();
                                break;
                            case '2' :
                                cout <<"(2). Input Data Wanita  " <<endl;
                                x = insertInfo();
                                P = alokasi(x);
                                insertLast(wanita, P);
                                getch();
                                break;
                            case '0'  : break;
                            default : break;
                        }
                    }while (pol != '0');
                    break;
// INPUT ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                case '2' :
// DELETE ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    do{
                        system("cls");
                        cout <<"\t\t\t\t    DELETE DATA" <<endl <<endl;
                        cout <<"(1). Delete Data Pria  " <<endl;
                        cout <<"(2). Delete Data Wanita  " <<endl;
                        cout <<"(0). Back" <<endl;
                        cout <<"\nPilihan : ";
                        cin >>pol;
                        switch (pol){
                            case '1' :
                                cout <<"(1). Delete Data Pria  " <<endl;
                                cout <<"Masukkan NIK : ";
                                cin >>x.nik;
                                P = findElm(pria, x);
                                if (P == NULL){
                                    cout <<"Data tidak ditemukan" <<endl;
                                }
                                else{
                                    Q = findElm_rt(kawin, P);
                                    while (Q != NULL){
                                        info(down(Q)).status = 3;
                                        delData_r(kawin, Q);
                                        Q = findElm_rt(kawin, P);
                                    }
                                    delData(pria, P);
                                    cout <<"Data berhasil dihapus" <<endl;
                                }
                                getch();
                                break;
                            case '2' :
                                cout <<"(2). Delete Data Wanita  " <<endl;
                                cout <<"Masukkan NIK : ";
                                cin >>x.nik;
                                P = findElm(wanita, x);
                                if (P == NULL){
                                    cout <<"Data tidak ditemukan" <<endl;
                                }
                                else{
                                    Q = findElm_rs(kawin, P);
                                    while (Q != NULL){
                                        info(up(Q)).status = 3;
                                        delData_r(kawin, Q);
                                        Q = findElm_rs(kawin, P);
                                    }
                                    delData(wanita, P);
                                    cout <<"Data berhasil dihapus" <<endl;
                                }
                                getch();
                                break;
                            case '0'  : break;
                            default : break;
                        }
                    }while (pol != '0');
                    break;
// DELETE ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                case '3' :
// EDIT ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    do{
                        system("cls");
                        cout <<"\t\t\t\t    EDIT DATA" <<endl <<endl;
                        cout <<"(1). Edit Data Pria  " <<endl;
                        cout <<"(2). Edit Data Wanita  " <<endl;
                        cout <<"(0). Back" <<endl;
                        cout <<"\nPilihan : ";
                        cin >>pol;
                        switch (pol){
                            case '1' :
                                cout <<"(1). Edit Data Pria  " <<endl;
                                cout <<"Masukkan NIK : ";
                                cin >>x.nik;
                                P = findElm(pria, x);
                                if (P == NULL){
                                    cout <<"Data tidak ditemukan" <<endl;
                                }
                                else{
                                    editList(pria, P);
                                    cout <<"Data yang telah diubah : " <<endl;
                                    printInfo(pria, P);
                                }
                                getch();
                                break;
                            case '2' :
                                cout <<"(2). Edit Data Wanita  " <<endl;
                                cout <<"Masukkan NIK : ";
                                cin >>x.nik;
                                P = findElm(wanita, x);
                                if (P == NULL){
                                    cout <<"Data tidak ditemukan" <<endl;
                                }
                                else{
                                    editList(wanita, P);
                                    cout <<"Data yang telah diubah : " <<endl;
                                    printInfo(wanita, P);
                                }
                                getch();
                                break;
                            case '0'  : break;
                            default : break;
                        }
                    }while (pol != '0');
                    break;
// EDIT ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                case '4' :
// SEARCH ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    do{
                        system("cls");
                        cout <<"\t\t\t\t    SEARCH DATA" <<endl <<endl;
                        cout <<"(1). Search Data Pria  " <<endl;
                        cout <<"(2). Search Data Wanita  " <<endl;
                        cout <<"(3). Search Data Pasangan  " <<endl;
                        cout <<"(0). Back" <<endl;
                        cout <<"\nPilihan : ";
                        cin >>pol;
                        switch (pol){
                            case '1' :
                                cout <<"(1). Search Data Pria  " <<endl;
                                cout <<"Masukkan NIK : ";
                                cin >>x.nik;
                                P = findElm(pria, x);
                                if (P == NULL){
                                    cout <<"Data tidak ditemukan" <<endl;
                                }
                                else{
                                    printInfo(pria, P);
                                }
                                getch();
                                break;
                            case '2' :
                                cout <<"(2). Search Data Wanita  " <<endl;
                                cout <<"Masukkan NIK : ";
                                cin >>x.nik;
                                P = findElm(wanita, x);
                                if (P == NULL){
                                    cout <<"Data tidak ditemukan" <<endl;
                                }
                                else{
                                    printInfo(wanita, P);
                                }
                                getch();
                                break;
                            case '3' :
                                cout <<"(3). Search Data Pasangan  " <<endl;
                                cout <<"\t (1). Search Data Suami " <<endl;
                                cout <<"\t (2). Search Data Wanita  " <<endl;
                                cout <<"\t (0). Back" <<endl;
                                cout <<"\nPilihan : ";
                                cin >>pel;
                                switch (pel){
                                    case '1' :
                                        cout <<"(1). Search Data Suami  " <<endl;
                                        cout <<"Masukkan NIK Wanita : ";
                                        cin >>x.nik;
                                        Y = findElm(wanita, x);
                                        if (Y == NULL){
                                            cout <<"Data tidak ditemukan" <<endl;
                                        }
                                        else{
                                            if (info(Y).status == 2 ) {
                                                Q = findElm_rs(kawin, Y);
                                                printInfo(pria, up(Q));
                                            }
                                            else{
                                                cout <<"\n  Data yang dimasukkan tidak memiliki pasangan" <<endl;
                                            }
                                        }
                                        getch();
                                        break;
                                    case '2' :
                                        cout <<"(2). Search Data Istri  " <<endl;
                                        cout <<"Masukkan NIK Pria : ";
                                        cin >>x.nik;
                                        X = findElm(pria, x);
                                        if (X == NULL){
                                            cout <<"Data tidak ditemukan" <<endl;
                                        }
                                        else{
                                            if (info(X).status == 2 ) {
                                                Q = first(kawin);
                                                while (Q != NULL) {
                                                    if ( up(Q) == X){
                                                        printInfo(wanita, down(Q));
                                                    }
                                                }
                                            }
                                            else{
                                                cout <<"\n  Data yang dimasukkan tidak memiliki pasangan" <<endl;
                                            }
                                        }
                                        getch();
                                        break;
                                        case '0'  : break;
                                        default : break;
                                        }

                                break;
                            case '0'  : break;
                            default : break;
                        }
                    }while (pol != '0');
                    break;
// SEARCH ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                case '5' :
// SHOW ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    do{
                        system("cls");
                        cout <<"\t\t\t\t    SHOW DATA" <<endl <<endl;
                        cout <<"(1). Show Data Pria  " <<endl;
                        cout <<"(2). Show Data Wanita  " <<endl;
                        cout <<"(0). Back" <<endl;
                        cout <<"\nPilihan : ";
                        cin >>pol;
                        switch (pol){
                            case '1' :
                                cout <<"(1). Show Data Pria  " <<endl;
                                if(first(pria) == NULL){
                                    cout <<"Data Kosong" <<endl;
                                    getch();
                                }
                                else{
                                    P = first(pria);
                                    j = 1;
                                    while(P != NULL){
                                        cout <<"(" <<j <<").___________________________________________________________" <<endl;
                                        printInfo(pria, P);
                                        P = next(P);
                                        j++;
                                        getch();
                                    }
                                }

                                break;
                            case '2' :
                                cout <<"(2). Show Data Wanita  " <<endl;
                                if(first(wanita) == NULL){
                                    cout <<"Data Kosong" <<endl;
                                    getch();
                                }
                                else{
                                    P = first(wanita);
                                    j = 1;
                                    while(P != NULL){
                                        cout <<"(" <<j <<").___________________________________________________________" <<endl;
                                        printInfo(wanita, P);
                                        P = next(P);
                                        j++;
                                        getch();
                                    }
                                }

                                break;
                            case '0'  : break;
                            default : break;
                        }
                    }while (pol != '0');
                    break;
// SHOW ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                case '6' :
// SORT ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    do{
                        system("cls");
                        cout <<"\t\t\t\t    SORT DATA" <<endl <<endl;
                        cout <<"(1). Sort Data Pria  " <<endl;
                        cout <<"(2). Sort Data Wanita  " <<endl;
                        cout <<"(0). Back" <<endl;
                        cout <<"\nPilihan : ";
                        cin >>pol;
                        switch (pol){
                            case '1' :
                                cout <<"(1). Sort Data Pria  " <<endl;
                                    cout <<"\t (1). Sort Ascending NIK Data Pria  " <<endl;
                                    cout <<"\t (2). Sort Descending NIK Data Pria  " <<endl;
                                    cout <<"\t (3). Sort Ascending Usia Data Pria  " <<endl;
                                    cout <<"\t (4). Sort Descending Usia Data Pria  " <<endl;
                                    cout <<"\t (0). Back" <<endl;
                                    cout <<"\nPilihan : ";
                                    cin >>pel;
                                    switch (pel){
                                        case '1' :
                                            cout <<"(1). Sort Ascending NIK Data Pria  " <<endl;
                                            sortAs_nik(pria);

                                            break;
                                        case '2' :
                                            cout <<"(2). Sort Descending NIK Data Pria  " <<endl;
                                            sortDes_nik(pria);

                                            break;
                                        case '3' :
                                            cout <<"(3). Sort Ascending Usia Data Pria  " <<endl;
                                            sortAs_usia(pria);

                                            break;
                                        case '4' :
                                            cout <<"(4). Sort Descending Usia Data Pria  " <<endl;
                                            sortDes_usia(pria);

                                            break;
                                        case '0'  : break;
                                        default : break;
                                        }

                                getch();
                                break;
                            case '2' :
                                cout <<"(2). Sort Data Wanita  " <<endl;
                                    cout <<"\t (1). Sort Ascending NIK Data Wanita  " <<endl;
                                    cout <<"\t (2). Sort Descending NIK Data Wanita  " <<endl;
                                    cout <<"\t (3). Sort Ascending Usia Data Wanita  " <<endl;
                                    cout <<"\t (4). Sort Descending Usia Data Wanita  " <<endl;
                                    cout <<"\t (0). Back" <<endl;
                                    cout <<"\nPilihan : ";
                                    cin >>pel;
                                    switch (pel){
                                        case '1' :
                                            cout <<"(1). Sort Ascending NIK Data Wanita  " <<endl;
                                            sortAs_nik(wanita);

                                            break;
                                        case '2' :
                                            cout <<"(2). Sort Descending NIK Data Wanita  " <<endl;
                                            sortDes_nik(wanita);

                                            break;
                                        case '3' :
                                            cout <<"(3). Sort Ascending Usia Data Wanita  " <<endl;
                                            sortAs_usia(wanita);

                                            break;
                                        case '4' :
                                            cout <<"(4). Sort Descending Usia Data Wanita  " <<endl;
                                            sortDes_usia(wanita);

                                            break;
                                        case '0'  : break;
                                        default : break;
                                        }

                                getch();
                                break;
                            case '0'  : break;
                            default : break;
                        }
                    }while (pol != '0');
                    break;
// SORT ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



                case '0'  : break;
                default : break;
                }
            }while (pil != '0');


        }
//# Calon Pengantin #################################################################################################################



//# Pernikahan ######################################################################################################################
        else if (menu == '2'){
            do{
                system("cls");
                cout <<"\t\t\t\tAPLIKASI ADMINISTRASI \n\t\t\t\t KANTOR URUSAN AGAMA" <<endl <<endl;
                cout <<"Data Pernikahan \n";
                cout <<"\t(1). Pendaftaran Nikah \t\t (2). Pendaftaran Cerai \n" ;
                cout <<"\t(3). Daftar Pernikahan  \t (4). Daftar Perceraian \n" ;
                cout <<"\t\t\t\t\t (0). Back        \n" ;
                cout <<"\nPilihan : ";
                cin >>pil;

                switch (pil){
                case '1' :
// PENDAFTARAN NIKAH //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    cout <<"\nMasukkan NIK Pria   : ";
                    cin >> s.nik;
                    X = findElm(pria, s);
                    if (X == NULL){
                        cout <<"\nData tidak ditemukan" <<endl;
                        getch();
                        break;
                    }

                    cout <<"\nMasukkan NIK Wanita : ";
                    cin >> i.nik;
                    Y = findElm(wanita, i);
                    if (Y == NULL){
                        cout <<"\nData tidak ditemukan" <<endl;
                    }
                    if ((Y != NULL) && (X != NULL)){
                        info(X).status = 2;
                        info(Y).status = 2;
                        Q = alokasi_r(X, Y);
                        insertFirst_r(kawin, Q);
                        cout <<"\n  Pernikahan berhasil, Selamat Menempuh Hidup Baru";
                    }
                    getch();
                    break;
// PENDAFTARAN NIKAH //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                case '2' :
// PENDAFTARAN CERAI //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    cout <<"\nMasukkan NIK Wanita : ";
                    cin >> i.nik;
                    Y = findElm(wanita, i);
                    if (Y == NULL){
                        cout <<"\nData tidak ditemukan" <<endl;
                    }
                    else{
                         if (info(Y).status != 2){
                            cout <<"\n  Data yang dimasukkan tidak memiliki pasangan" <<endl;
                         }
                         else{
                            Q = findElm_rs(kawin, Y);
                            info(up(Q)).status = 3;
                            info(down(Q)).status = 3;
                            delData_r(kawin, Q);
                            cout <<"\n  Perceraian berhasil, Selamat Menempuh Hidup Baru" <<endl;
                         }
                    }
                    getch();
                    break;
// PENDAFTARAN CERAI //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                case '3' :
// DAFTAR NIKAH //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    if (first(kawin) == NULL){
                        cout <<"Data Kosong" <<endl;
                        getch();
                    }
                    else {
                        R = first(kawin);
                        j = 1;
                        while(R != NULL){
                            cout <<"(" <<j <<").___________________________________________________________" <<endl;
                            cout <<"\tSuami : " <<info(up(R)).nama <<" (" <<info(up(R)).nik <<") Menikah dengan ";
                            cout <<"\tIstri : " <<info(down(R)).nama <<" (" <<info(down(R)).nik <<") " <<endl;
                            R = next(R);
                            j++;
                            getch();
                        }
                    }
                    break;
// DAFTAR NIKAH //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                case '4' :
// DAFTAR CERAI //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    X = first(pria);
                    Y = first(wanita);
                    j = 0;
                    if( (first(pria) == NULL) && (first(wanita) == NULL) ){
                        cout <<"Data Kosong" <<endl;
                    }
                    else{
                        while(X != NULL){
                            if (info(X).status == 3){
                                j++;
                                cout <<"(" <<j <<").___________________________________________________________" <<endl;
                                cout <<"\tNama : " <<info(X).nama <<endl;
                                cout <<"\tNIK  : " <<info(X).nik <<endl;
                                getch();
                            }
                            X = next(X);
                        }

                        while(Y != NULL){
                            if (info(Y).status == 3){
                                j++;
                                cout <<"(" <<j <<").___________________________________________________________" <<endl;
                                cout <<"\tNama : " <<info(Y).nama <<endl;
                                cout <<"\tNIK  : " <<info(Y).nik <<endl;
                                getch();
                            }
                            Y = next(Y);
                        }
                        if (j == 0){
                            cout <<"Data Kosong" <<endl;
                        }
                    }
                    getch();
                    break;
// DAFTAR CERAI //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                case '0'  : break;
                default : break;
                }
            }while (pil != '0');

        }
//# Pernikahan #####################################################################################################################


    }while( menu != '0');
    //getch();
    return 0;
}
