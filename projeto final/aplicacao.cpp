#include "funcoes.cpp"

int main () {
	char opcao = ' ';
	do {
	   opcao = menu();	
	   switch (opcao) {
	   		case 'NA':
				functionNA();
			break;
			case 'MTA':
				functionMTA();
				break;
			case 'NP':
				functionNP();
				break;
			case 'NAEP':
				functionNAEP();
				break;
			case 'MDA':
				functionMDA();
				break;
			case 'MDR':
				functionMDR();
				break;
			case 'MB':
				functionMB();
				break;
			case 'LD':
				functionLD();
				break;
	   		case 'EO':
	   			funcstionEO();
	   			break;
	   			
	   			std::cout << "Finalizando aplicacao...\n";
	   		break;
	   		// demais funcoes deverão ser chamadas aqui
	   		default:
	   			std::cout << "Opcao invalida\n Tente Novamente!\n";
	   }
	} while(opcao != 'F');	
}
