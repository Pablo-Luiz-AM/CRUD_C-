#include <iostream>
#include <cstring>

const int MAX_ITENS = 100;

struct Item {
    int id;
    char nome[50];
};

Item database[MAX_ITENS];
int itemCount = 0;

void criarItem() {
    if (itemCount < MAX_ITENS) {
        Item newItem;
        newItem.id = itemCount + 1;

        std::cout << "Digite o nome do item: ";
        std::cin.ignore();  // Limpa o buffer do teclado
        std::cin.getline(newItem.nome, sizeof(newItem.nome));

        database[itemCount++] = newItem;
        std::cout << "Item criado: ID=" << newItem.id << ", Nome=" << newItem.nome << std::endl;
    } else {
        std::cout << "Limite de itens atingido. Não é possível adicionar mais itens." << std::endl;
    }
}

void lerTodosOsItens() {
    if (itemCount == 0) {
        std::cout << "Nenhum item encontrado." << std::endl;
    } else {
        std::cout << "Itens no banco de dados:" << std::endl;
        for (int i = 0; i < itemCount; ++i) {
            std::cout << "ID=" << database[i].id << ", Nome=" << database[i].nome << std::endl;
        }
    }
}

void atualizarItem() {
    int id;
    std::cout << "Digite o ID do item a ser atualizado: ";
    std::cin >> id;

    for (int i = 0; i < itemCount; ++i) {
        if (database[i].id == id) {
            std::cout << "Digite o novo nome: ";
            std::cin.ignore();
            std::cin.getline(database[i].nome, sizeof(database[i].nome));

            std::cout << "Item atualizado: ID=" << database[i].id << ", Nome=" << database[i].nome << std::endl;
            return;
        }
    }

    std::cout << "Item com ID " << id << " não encontrado" << std::endl;
}

void excluirItem() {
    int id;
    std::cout << "Digite o ID do item a ser excluído: ";
    std::cin >> id;

    for (int i = 0; i < itemCount; ++i) {
        if (database[i].id == id) {
            for (int j = i; j < itemCount - 1; ++j) {
                database[j] = database[j + 1];
            }
            --itemCount;
            std::cout << "Item com ID " << id << " excluído" << std::endl;
            return;
        }
    }

    std::cout << "Item com ID " << id << " não encontrado" << std::endl;
}

int main() {
    char escolha;

    do {
        std::cout << "\nEscolha uma opção:\n";
        std::cout << "1. Criar item\n";
        std::cout << "2. Ler todos os itens\n";
        std::cout << "3. Atualizar item por ID\n";
        std::cout << "4. Excluir item por ID\n";
        std::cout << "0. Sair\n";
        std::cout << "Opção: ";
        std::cin >> escolha;

        switch (escolha) {
            case '1':
                criarItem();
                break;
            case '2':
                lerTodosOsItens();
                break;
            case '3':
                atualizarItem();
                break;
            case '4':
                excluirItem();
                break;
            case '0':
                std::cout << "Saindo..." << std::endl;
                break;
            default:
                std::cout << "Opção inválida. Tente novamente." << std::endl;
        }
    } while (escolha != '0');

    return 0;
}
