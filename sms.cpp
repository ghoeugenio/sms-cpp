#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef struct{
	string mensagem;
}Mensagem;

typedef struct{
	string ddi;
	string ddd;
	string celular;
	string usuario;
	string senha;
	int nmsg = 0, novamensagem = 0;
	Mensagem mensagem[500];
	int lida[500];//1 nao lida - 0 lida
	int vet[500];//0 recebida - 1 enviada
	string rel[500];
	int horario[3][500];	//0 hora - 1 minuto - 2 segundo
}Terminal;

void fflush_stdin() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

int main (){
	
	int x = 0, y = 0, ncel = 0, z = 1, i, v = 0, p = 0, u = 0, a = 0, k, j, c = 1, f = 0, l, d = 1, vef, xkp, sel, b;
	string senha, padrao, aux, auxusuario, auxsenha, ndestino, ddaux, diaux;
	Terminal celulares[50];
	struct tm *local;
	time_t t;
	char auxmensagem[1000];
	
	padrao = "123456";//senha padrao
	
	while(1){
		xkp = 1;
		system("cls");
		cout << "1)Admistracao de base:\n";
		cout << "2)Transmissao de mensagens\n";
		cout << "3)Fechar o programa\n";
		cout << "Escolha a opcao: ";//menu
		
		cin >> x;
		if (x == 1){
			y = 0;
			system("cls");
			cout << "Informe a senha de Administrador: ";//verificacao de senha
			cin >> senha;
			system("cls");
			if (senha != padrao){
				cout << "\nSenha incorreta!\n\n";
				fflush_stdin();
				xkp = 0;
			}
			else{
				while(y != 3){
					fflush_stdin();
					cout << "1)Cadastrar novo terminal\n";
					cout << "2)Lista de cadastros\n";
					cout << "3)Voltar\n";
					cout << "Escolha a opcao: ";
					
					cin >> y;
					system("cls");
					if (y == 1){
						while(z != 0){
							cout << "Insira o DDI(2 digitos): ";
							cin >> diaux;
							system("cls");
							if (diaux.size() != 2){
								system("cls");
								cout << "DDI tem 2 digitos!\n";
								break;
							}
							cout << "Insira o DDD(2 digitos): ";
							cin >> ddaux;
							system("cls");
							if (ddaux.size() != 2){
								system("cls");
								cout << "DDD tem 2 digitos!\n";
								break;
							}
							else{
								cout << "Insira o numero(9 digitos): ";
								cin >> aux;
								fflush_stdin();
								system("cls");
								if (aux.size() != 9){
									system("cls");
									cout << "Numero tem 9 digito!(aperte enter)\n";
									break;
								}
								for(l = 0; l < ncel; l++){
									if((diaux + ddaux + aux) ==  (celulares[l].ddi + celulares[l].ddd + celulares[l].celular)){
										system("cls");
										cout << "Numero ja cadastrado!\n";
										f = 1;
										break;
									}
								}
								if ((f == 0) && (aux.size() == 9)){
									celulares[ncel].ddi = diaux;
									celulares[ncel].ddd = ddaux;
									celulares[ncel].celular = aux;
									system("cls");
									cout << "Insira o usuario: ";
									cin >> celulares[ncel].usuario;
									cout << "insira a senha de acesso: ";
									cin >> celulares[ncel].senha;
									z = 1;
									for(b = 0; b < 500; b++){
										celulares[ncel].lida[b] = 0;
									}
									ncel++;
									system("cls");
									break;
								} 
							}
							break;
						}
					}
					if(y == 2){
						for(i = 0; i < ncel; i++){
							cout << "Terminal " << (i + 1);
							cout << "\nUsuario: " << celulares[i].usuario << "\n"; 
							cout << "DDI + DDD + numero: +" << celulares[i].ddi << " " << celulares[i].ddd << " " << celulares[i].celular << "\n\n";
						}
						if(ncel == 0){
							cout << "\n\nVAZIO\n\n";
						}
					}
					if (y == 3){
						xkp = 0;
						break;
					}
				}
			}	
		}
		if (x == 2){
			v = 0;
			while(v == 0){
				p = 0;
				u = 0;
				a = 0;
				system("cls");
				cout << "Informe o numero do terminal(DDI + DDD + numero): ";
				cin >> auxusuario;
				cout << "Informe a senha: ";
				cin >> auxsenha;
				system("cls");
				i = 0;
				for(i = 0; i < ncel; i++){
					if((celulares[i].ddi + celulares[i].ddd + celulares[i].celular) == auxusuario){
						if(celulares[i].senha == auxsenha){//acesso autorizado
							p = 1;
							while(a != 4){
								k = 0;
								for(b = 0; b < celulares[i].nmsg; b++){
									if(celulares[i].vet[b] == 0){
										k++;
									}
								}
								cout << k << " mensagens recebidas\n";
								k = 0;
								for(b = 0; b < 500; b++){
									if(celulares[i].lida[b] == 1){
										k++;
									}
								}
								cout << k << " mensagens novas\n\n";
								
								cout << "1)Mensagens recebidas\n";
								cout << "2)Escrever mensagem\n";
								cout << "3)Mensagens enviadas\n";
								cout << "4)Voltar\n";
								cout << "Escolha a opcao: ";
							
								cin >> a;
								system("cls");
								
								if (a == 1){
									celulares[i].novamensagem = 0;
									c = 1;
									cout << "Selecione a mensagem: \n";
									for(k = 0; k < celulares[i].nmsg; k++){
										if(celulares[i].vet[k] == 0){
											cout << "Mensagem " << c << "\n"; //" recebida as (" << celulares[i].horario[0][k] << ":" << celulares[i].horario[1][k] << ":" << celulares[i].horario[2][k] << ")\n";
											//cout << "Remetente(DDI + DDD + numero): " << celulares[i].rel[k] << "\n\n";
											//cout << celulares[i].mensagem[k].mensagem << "\n\n";
											c++;
										}
									}
									c = 1;
									cin >> sel;
									system("cls");
									for(k = 0; k < celulares[i].nmsg; k++){
										if(celulares[i].vet[k] == 0){
											if(sel == c){
												cout << "Mensagem " << c << " recebida as (" << celulares[i].horario[0][k] << ":" << celulares[i].horario[1][k] << ":" << celulares[i].horario[2][k] << ")\n";
												cout << "Remetente(DDI + DDD + numero): " << celulares[i].rel[k] << "\n\n";
												cout << celulares[i].mensagem[k].mensagem << "\n\n";
												celulares[i].lida[k] = 0;
											}
											c++;
										}
									}
								}
								
								if (a == 2){
									//system("cls");
									cout << "Insira o destino(DDI + DDD + numero): ";
									cin >> ndestino;
									system("cls");
									vef = 0;
									for(j = 0; j < ncel; j++){
										vef++;
										if((celulares[i].ddi + celulares[i].ddd + celulares[i].celular)  == ndestino){
											cout << "Impossivel enviar mensagem para o prorio numero!\n";
											break;
										}
										else if(ndestino == (celulares[j].ddi + celulares[j].ddd + celulares[j].celular)){
											fflush_stdin();
											cout << "Escreva a mensagem (ate 160 caracteres):";
											cin.getline(auxmensagem, 1000);
											system("cls");
											if (strlen(auxmensagem) > 160){
												cout << "Mensagem muito grande!\n";
												break;
											}
											else{
												t = time(NULL);
												local = localtime(&t);
												celulares[i].mensagem[celulares[i].nmsg].mensagem = auxmensagem;
												celulares[i].vet[celulares[i].nmsg] = 1;
												celulares[i].horario[0][celulares[i].nmsg] = local->tm_hour;
												celulares[i].horario[1][celulares[i].nmsg] = local->tm_min;
												celulares[i].horario[2][celulares[i].nmsg] = local->tm_sec;
												celulares[i].rel[celulares[i].nmsg] = ndestino;
												celulares[i].nmsg++;
												celulares[j].mensagem[celulares[j].nmsg].mensagem = auxmensagem;
												celulares[j].vet[celulares[j].nmsg] = 0;
												celulares[j].horario[0][celulares[j].nmsg] = local->tm_hour;
												celulares[j].horario[1][celulares[j].nmsg] = local->tm_min;
												celulares[j].horario[2][celulares[j].nmsg] = local->tm_sec;
												celulares[j].rel[celulares[j].nmsg] = celulares[i].ddi + celulares[i].ddd + celulares[i].celular;
												celulares[j].lida[celulares[j].nmsg] = 1;
												celulares[j].nmsg++;												
												break;
											}
										}
										
										if(vef == ncel){
											cout << "O numero inserido nao existe\n";
											break;
										}
									}
									
								}
								if(a == 3){
									d = 1;
									for(k = 0; k < celulares[i].nmsg; k++){
										if(celulares[i].vet[k] == 1){
											cout << "Mensagem " << d << " enviada as (" << celulares[i].horario[0][k] << ":" << celulares[i].horario[1][k] << ":" << celulares[i].horario[2][k] << ")\n";
											cout << "Remetente(DDI + DDD + numero): " << celulares[i].rel[k] << "\n\n";
											cout << celulares[i].mensagem[k].mensagem << "\n\n";
											d++;
										}
									}
								}
								
								if(a == 4){
									v = 1;
								}
							}
						}
						else{
							cout << "Senha incorreta. Digite 's' para inserir novamente: ";
							u = 1;
							cin >> aux;
							system("cls");
							if (aux == "s"){
								break;
							}
							else {
								v = 1;
								break;
							}
						}
					}
				}
				if ((p != 1 ) && (u != 1)){
					cout << "Usuario nao encontrado. Digite 's' para inserir novamente: ";
					cin >> aux;
					system("cls");
					if(aux != "s"){
						break;
					}
				}
			}			
		}
		else if(xkp){
			cout << "FIM DO PROGRAMA\n";
			break;
		}		
	}
	
	
	return 0;
}
