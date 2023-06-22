#include <iostream>

using namespace std;

void digraph(), undigraph(), wgraph();

bool ketemu, nolsemua;
int i, j, k, matrix[10][10], sumber, tujuan;
int jumlah_vertex, jumlah_edge;
string divider = "---------------------------------------";

int main()
{
    int pilihan;

    while(pilihan != 4) {
        cout << "~~~~~~~~~~~~~~~~ GRAPH ~~~~~~~~~~~~~~~~" << endl << endl;
        cout << "Menu Graph : " << endl;
        cout << "1. Undirected Graph" << endl;
        cout << "2. Directed Graph" << endl;
        cout << "3. Weighted Graph" << endl;
        cout << "4. Selesai" << endl;
        cout << divider << endl;
        cout << "Masukkan pilihan anda : ";
        cin >> pilihan;
        cout << endl;

        if(pilihan == 1) {
            undigraph();
        } else if(pilihan == 2) {
            digraph();
        } else if(pilihan == 3) {
            wgraph();
        } else if(pilihan == 4) {
            break;
        } else {
            cout << "Menu tidak ditemukan." << endl << endl;
        }
    }

}

void undigraph() {
    cout << "=========== Undirected Graph ==========" << endl << endl;
    cout << "Input Jumlah Vertex\t: ";
    cin >> jumlah_vertex;
    cout << "Input Jumlah Edge\t: ";
    cin >> jumlah_edge;
    cout << divider << endl;
    
    string nama_vertex[jumlah_vertex];
    
	for(i = 0; i < jumlah_vertex; i++) {
        cout << "Nama Vertex - [" << i + 1 << "] : "; 
        cin >> nama_vertex[i];
    }

    cout << divider << endl;

	for (i = 1; i <= jumlah_vertex; i++) {
		for (j = 1; j <= jumlah_vertex; j++) {
			matrix[i][j] = 0;
        }
    }

	for(i = 1; i <= jumlah_edge; i++) {
		cout << "Vertex Sumber\t: ";
		cin >> sumber;
		cout << "Vertex Tujuan\t: ";
		cin >> tujuan;
        cout << divider << endl;

		matrix[sumber][tujuan] = 1;
		matrix[tujuan][sumber] = 1;
	}

    cout << endl;

    i = 1;
    nolsemua = false;

    while(i <= jumlah_vertex && !nolsemua) {
        j = 1;
        ketemu = false;
        while(j <= jumlah_vertex && !ketemu) {
            if(matrix[i][j] == 1) {
                ketemu = true;
            } else {
                j++;
            }
        }

        if(!ketemu) {
            nolsemua = true;
        } else {
            i++;
        }
    }

	if(nolsemua) {
		cout << "Grafh tidak terhubung";
    } else {
		cout << "Garis yang dapat dibentuk : ";

        for(i = 1; i <= jumlah_vertex; i++) {

            for(j = 1; j <= jumlah_vertex; j++) {
               if(matrix[i][j] == 1) {
                    cout << nama_vertex[i - 1] << nama_vertex[j -1] << ", ";
                }
            }
        }

        cout << endl << endl;
    }
}

void digraph() {
    cout << "============ Directed Graph ===========" << endl << endl;
    cout << "Input Jumlah Vertex\t: ";
    cin >> jumlah_vertex;
    cout << "Input Jumlah Edge\t: ";
    cin >> jumlah_edge;
    cout << divider << endl;
    
    string nama_vertex[jumlah_vertex];
    
	for(i = 0; i < jumlah_vertex; i++) {
        cout << "Nama Vertex - [" << i + 1 << "] : "; 
        cin >> nama_vertex[i];
    }

    cout << divider << endl;

	for (i = 1; i <= jumlah_vertex; i++) {
		for (j = 1; j <= jumlah_vertex; j++) {
			matrix[i][j] = 0;
        }
    }

	for(i = 1; i <= jumlah_edge; i++) {
		cout << "Vertex Sumber\t: ";
		cin >> sumber;
		cout << "Vertex Tujuan\t: ";
		cin >> tujuan;
        cout << divider << endl;

		matrix[sumber][tujuan] = 1;
	}

    cout << endl;

	if(nolsemua) {
		cout << "Grafh tidak terhubung";
    } else {
		cout << "Garis yang dapat dibentuk : ";

        for(i = 1; i <= jumlah_vertex; i++) {
            for(j = 1; j <= jumlah_vertex; j++) {
               if(matrix[i][j] == 1) {
                    cout << nama_vertex[i - 1] << nama_vertex[j -1] << ", ";
                }
            }
        }

        cout << endl << endl;
    }
}

void wgraph() {
    int total_weight = 0;

    struct Vertex {
        string *nama;
        int *weight;
    };

    cout << "============ Weighted Graph ===========" << endl << endl;
    cout << "Input Jumlah Vertex\t: ";
    cin >> jumlah_vertex;
    cout << "Input Jumlah Edge\t: ";
    cin >> jumlah_edge;
    cout << divider << endl;
    
    Vertex vertex;
    vertex.nama = new string[jumlah_vertex];
    vertex.weight = new int[jumlah_edge];

	for(i = 0; i < jumlah_vertex; i++) {
        cout << "Nama Vertex - [" << i + 1 << "] : "; 
        cin >> vertex.nama[i];
    }

    cout << divider << endl;

	for (i = 1; i <= jumlah_vertex; i++) {
		for (j = 1; j <= jumlah_vertex; j++) {
			matrix[i][j] = 0;
        }
    }

	for(i = 0; i < jumlah_edge; i++) {
		cout << "Vertex Sumber\t: ";
		cin >> sumber;
		cout << "Vertex Tujuan\t: ";
		cin >> tujuan;
        cout << "Weight\t\t: ";
        cin >> vertex.weight[i];
        cout << divider << endl;

		matrix[sumber][tujuan] = 1;
	}

    cout << endl;

	if(nolsemua) {
		cout << "Grafh tidak terhubung";
    } else {
		cout << "Garis yang dapat dibentuk : ";

        for(i = 1; i <= jumlah_vertex; i++) {
            for(j = 1; j <= jumlah_vertex; j++) {
               if(matrix[i][j] == 1) {
                    cout << vertex.nama[i - 1] << vertex.nama[j -1] << ", ";
                }
            }
        }

        cout << endl << divider << endl;

        k = 0;

        for(i = 1; i <= jumlah_vertex; i++) {
            for(j = 1; j <= jumlah_vertex; j++) {
               if(matrix[i][j] == 1) {
                    total_weight += vertex.weight[k];

                    cout << "Simpul " << vertex.nama[i - 1] << " dengan Simpul " << vertex.nama[j -1] << " : " << vertex.weight[k] << endl;

                    k++;
                }
            }
        }
        
        cout << divider << endl;
        cout << "Jarak panjang : " << total_weight << endl << endl;
    }
}
