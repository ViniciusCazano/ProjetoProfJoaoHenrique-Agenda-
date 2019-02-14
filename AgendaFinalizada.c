#include <stdio.h>
#include <stdlib.h>
struct agenda{
	char nome[40];
	char email[50];
	char fone[20];
};

int tam=100;
int cabecalho(void);//faz a parte escrita inicial do programa
int opcoes(void);//mostra todas as op�oes que o usuario possui
void alteraDado(struct agenda *contatos, int qntdContatos);//ficou depois do main


int cabecalho(void){ //faz a parte escrita inicial do programa
	int a;
	for(a=0;a<14;a++)printf("#");
	printf("\n### AGENDA ###\n");
	for(a=0;a<14;a++)printf("#");
	printf("\n");
	//chama a parte escrita das instru�oes
	opcoes();
	return(0);
}//FIM DA FUN�AO
int opcoes(void){//mostra todas as op�oes que o usuario possui
	printf("Selecione a operacao: \n");
	printf("(S) Salvar contato\n");
	printf("(A) Alterar contato\n");
	printf("(P) Pesquisar contato:\n");
	printf("(E) Estatistica da agenda\n");
	printf("(R) Sair");
	return(0);
}//FIM DA FUN�AO
				/**
				*********PARTE DE SALVAR CONTATO(FUN�AO)
				**/
void adcionaContato(struct agenda *contatos, int qntdContatos){
	system("cls");
	int a;
	for(a=0;a<22;a++)printf("#");
	printf("\n### SALVAR CONTATO ###\n");
	for(a=0;a<22;a++)printf("#");
	printf("\n");
	
	printf("Digite o nome: ");
	scanf("%s%*c",contatos[qntdContatos].nome);
	printf("Digite o email: ");
	scanf("%s%*c",contatos[qntdContatos].email);
	printf("Digite o telefone: ");
	scanf("%s%*c",contatos[qntdContatos].fone);
	system("cls");
}//FIM DA FUN�AO

				/**
				*********PARTE DE PESQUISA DE CONTATOS(FUN�AO)
				**/
void cabecalhoPesquisa(){
	int a;
	for(a=0;a<18;a++)printf("#");
	printf("\n### PESQUISAR ###\n");
	for(a=0;a<18;a++)printf("#");
	printf("\n");
	
	printf("(D) Detalhada\n");
	printf("(G) Geral");
}//FIM DA FUN�AO
void pesquisaContato(struct agenda *contatos, int qntdContatos){
	system("cls");
	cabecalhoPesquisa();
	char deci;
	scanf(" %c", &deci);
	
	if(deci=='d'||deci=='D'){
		char pesquisa[30];
		printf("Digite o nome: ");
		scanf("%s%*c", &pesquisa);
		/**
		*parte de pesquisa
		**/
		//variaveis dos for de controle
		int cont_contato, //controle do for para contatos 
		cont_posiLetra; //controle do for para a posi�ao do vetor de caracter
		/**
		*variaveis para controle de pesquisa
		**/
		int vet_salvaContato[tam], //salva as posi�oes que a pesquisa apontou
		contadorVet=0; //aponta em que posi�ao do vetor parou
		
		for(cont_contato=0; cont_contato<qntdContatos; cont_contato++){ //percorre os contatos
			for(cont_posiLetra=0; cont_posiLetra<40; cont_posiLetra++){ //percorre o array das letras
			
				if(pesquisa[cont_posiLetra] == contatos[cont_contato].nome[cont_posiLetra]){// testa para que todas as letras sejam iguais e em sequencia
					if(pesquisa[cont_posiLetra+1]=='\0'){//testa se � a ultima letra da pesquisa
						cont_posiLetra=40;//para de percorrer o array de letras
						vet_salvaContato[contadorVet]=cont_contato; // salva a posi�ao que os contatos estao salvos na agenda
						contadorVet++;//acrescenta posi�ao no vetor para proxima busca
					}
				}
				
				else{//se nao for ele sai e ja pesquisa outro contato
					cont_posiLetra=40;
				}
			}//fim do for cont_posiLetra
		}//fim do for cont_contato
		
		/**
		*Parte de mostar a pesquisa
		**/
		if(contadorVet>0){//se o contador for maior que 0 � poque ele encontrou um ou mais contatos quebatem com a pesquisa
			int x;
			for(x=0;x<contadorVet;x++){
				printf("Nome: %s\n", contatos[vet_salvaContato[x]].nome);
				printf("Email: %s\n", contatos[vet_salvaContato[x]].email);
				printf("Telefone: %s\n", contatos[vet_salvaContato[x]].fone);
			}
		}
		else{
			printf("Contato nao encontrado!!!\n");
		}
	}// fim do if de pesquisa detalhada
	
	else if (deci=='G'|| deci=='g'){
		int x;
		if(qntdContatos>0){
			for(x=0; x<qntdContatos; x++){
				printf("Nome: %s\n", contatos[x].nome);
				printf("Email: %s\n", contatos[x].email);
				printf("Telefone: %s\n", contatos[x].fone);
			}	
		}
		else printf("Nenhum contato salvo");
		
	}
	else printf("Opcao invalida!!");
	system("pause");
	system("cls");
}//FIM DA FUN�AO

	
	
int main(void) {
	struct agenda contatos[tam];
	int repet=0;
	char escolha;// variavel que guarda a op�ao selecionada
	
	do{	
		cabecalho();
		scanf(" %c", &escolha);
		
		if(escolha=='S'||escolha=='s' && repet<tam) {
			adcionaContato(contatos, repet);
			repet++;
		}
		else if (escolha=='P'||escolha=='p'){
			pesquisaContato(contatos, repet);		
		}
		else if(escolha=='A' || escolha=='a' ){
			alteraDado(contatos, repet);
		}
		else if (escolha=='R'||escolha=='r') break;
		else printf("Escolha Invalida!!!\n");

		if(repet==tam){
			repet++;
			printf("\tMemoria cheia!!!!");
		}
	}while(repet!=tam);
	
	return 0;
}//FIM DO MAIN

					/**
					******ALTERAR DADOS (FUN�OES)
					**/
int cabecalhoAlteraDados(void){ //faz a parte escrita inicial do programa
	int a;
	for(a=0;a<23;a++)printf("#");
	printf("\n### ALTERAR DADOS ###\n");
	for(a=0;a<23;a++)printf("#");
	printf("\n");
	//chama a parte escrita das instru�oes
	return(0);
}//FIM DA FUN�AO
int opcoesAltera(void){//mostra todas as op�oes que o usuario possui
	printf("Selecione o que deseja alterar: \n");
	printf("(N) Nome\n");
	printf("(E) Email\n");
	printf("(T) Telefone\n");
	printf("(C) Cancelar\n");
	printf("(S) Salvar");
	return(0);
}//FIM DA FUN�AO
					/**
					******ALTERAR DADOS PRINCIPAL(FUN�OE)
					**/
void alteraDado(struct agenda *contatos, int qntdContatos){
	system("cls");
	cabecalhoAlteraDados();
	int conSelecionado, repet=1 ;
	char deciSelec;
				/**
				*Parte para pesquisa qual contato sera alterado
				**/
	char pesquisa[30];
	printf("Digite o nome: ");
	scanf("%s%*c", &pesquisa);
	//parte de pesquisa
	int cont_contato, cont_posiLetra;//variaveis dos for de controle
	int vet_salvaContato[tam], contadorVet=0;
	int contLetrasIgual=0;
	
	for(cont_contato=0; cont_contato<qntdContatos+1; cont_contato++){ //percorre os contatos
		for(cont_posiLetra=0; cont_posiLetra<40; cont_posiLetra++){ //percorre o array das letras
			if(pesquisa[cont_posiLetra]==contatos[cont_contato].nome[cont_posiLetra]){// testa para que todas as letras sejam iguais
				if(pesquisa[cont_posiLetra+1]=='\0'){//testa se � a ultima letra da pesquisa
					cont_posiLetra=40;//para de percorrer o array de letras
					vet_salvaContato[contadorVet]=cont_contato; // salva a posi�ao que o contatos esta salva na agenda
					contadorVet++;//acrescenta posi�ao 
					
				}//fim do if que testa se � a ultima letra da pesquisa
			}// fim do if que testa se as letras sao iguais
			
			else cont_posiLetra=40;//se nao for igual ele sai e ja pesquisa outro contato
			
		}//fim do for cont_posiLetra
	}//fim do for cont_contato
	
	//parte de mostar a pesquisa
	if(contadorVet>0){
		int x;
		for(x=0;x<contadorVet;x++){// mostra todo os resultados encontrados
			printf("ID: %d\n",vet_salvaContato[x]);
			printf("Nome: %s\n",vet_salvaContato[x], contatos[vet_salvaContato[x]].nome);
			printf("Email: %s\n", contatos[vet_salvaContato[x]].email);
			printf("Telefone: %s\n", contatos[vet_salvaContato[x]].fone);			}
		}// fim do for
	else printf("Contato nao encontrado!!\n");
				/**
				*fim da busca de pesquisa
				**/
		
	printf("Selecione o ID do contato:");
	scanf("%d", &conSelecionado);// pede para o usuario passar o id do contato
	system("cls");
	
	do{
		int meNome=0, meEmail=0, meFone=0;
		char nome[40], email[50], fone[20];
		
		cabecalhoAlteraDados();//mostra o cabecalho do altera dados
		
		if(meNome>0) printf("Nome: %s\n", nome);//testa se o usuario ja alterou o nome
		else printf("Nome: %s\n",contatos[conSelecionado].nome);
		
		if(meEmail>0) printf("Email: %s\n", email);//testa se o usuario ja alterou o email
		else printf("Email: %s\n", contatos[conSelecionado].email);
		
		if(meFone>0) printf("Telefone: %s\n", fone);//testa se o usuario ja alterou o telefone
		else printf("Telefone: %s\n", contatos[conSelecionado].fone);
		
		opcoesAltera();//mostra as op�oes que o usuario possui
		scanf(" %c", &deciSelec);//pega a decisao do usuario
		if(deciSelec=='N'||deciSelec=='n'){//testa se o usuario deseja alterar o nome
			printf("Alterar nome para: ");
			scanf(" %s", &nome); //usuario digita novo nome de contato
			meNome++;//variavel para controlar se ouve altera�ao no nome
			system("cls");
		}
		else if(deciSelec=='E'||deciSelec=='e'){ //testa se o usuario deseja alterar o email
			printf("Alterar Email para: ");
			scanf(" %s", &email);//usuario digita novo email de contato
			meEmail++;//variavel para controlar se ouve altera�ao no email
			system("cls");
		}
		else if(deciSelec=='T'||deciSelec=='t'){ //testa se o usuario deseja alterar o telefone
			printf("Alterar telefone para: ");
			scanf(" %s", &fone);//usuario digita novo telefone de contato
			meFone++;//variavel para controlar se ouve altera�ao no telefone
			system("cls");
		}
		else if(deciSelec=='S'||deciSelec=='s'){ //testa se o usuario deseja salvar as altera�oes
			int x;
			if(meNome>0){//testa se o usuario mexeu no nome do contato atraves da variavel de controle de nome
				for(x=0;x<40;x++){
					contatos[conSelecionado].nome[x] = nome[x];//percorre salvando caracter por caracter
				}
			}
			
			if(meEmail>0){//testa se o usuario mexeu no nome do contato atraves da variavel de controle de email
				for(x=0;x<50;x++){
					contatos[conSelecionado].email[x] = email[x]; //percorre salvando caracter por caracter
				}
			}
			
			if(meFone>0){//testa se o usuario mexeu no nome do contato atraves da variavel de controle de telefone
				for(x=0;x<50;x++){
					contatos[conSelecionado].fone[x] =fone[x];//percorre salvando caracter por caracter
				}
			}
			//retorna para o usuario que o contato foi salvo novamente e como ele foi alterado
			printf("Contato salvo com sucesso!!\n");
			printf("%d)Nome: %s\n",conSelecionado, contatos[conSelecionado].nome);
			printf("Email: %s\n", contatos[conSelecionado].email);
			printf("Telefone: %s\n", contatos[conSelecionado].fone);
			repet=0;
		}
		else if(deciSelec=='C'||deciSelec=='c')repet=0;// testa se o usuario deseja cancelar a altera�ao
		
		else printf("Opcao invalida!!");// se o usuario digitar algo invalido
	}while(repet!=0);
	system("pause");
	system("cls");
}//FIM DA FUN�AO





