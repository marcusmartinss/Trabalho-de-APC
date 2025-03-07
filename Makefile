# Nome do executável final do projeto
TARGET = trabalho_apc.bin

# Diretórios do projeto
SRC_DIR = src
LIBS_DIR = libs
BUILD_DIR = build

# Definição do compilador (GCC) e flags de compilação
CC = gcc
CFLAGS = -Wall -Wextra -std=c99   # Mantem warnings rigorosos e define o padrão C99

# Localiza os arquivos-fonte dentro dos diretórios definidos
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
LIBS_FILES = $(wildcard $(LIBS_DIR)/*.c)

# Criação da lista de arquivos objeto (.o) a partir dos arquivos fonte encontrados
# - Extrai os nomes dos arquivos fonte (.c) sem o caminho completo
# - Substitui a extensão .c por .o e os armazena no diretório de build
OBJ_FILES = $(patsubst %.c, $(BUILD_DIR)/%.o, $(notdir $(SRC_FILES) $(LIBS_FILES)))

# Regra principal: compila e gera o executável
all: $(TARGET)

# Criação do diretório build caso ainda não exista
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compilação dos códigos-fonte de src/ para objetos .o no diretório build/
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compilação dos códigos-fonte de libs/ para objetos .o no diretório build/
$(BUILD_DIR)/%.o: $(LIBS_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Linkagem: Gera o executável final a partir dos arquivos objeto compilados
$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(TARGET)

# Regra de execução do programa
run: $(TARGET)
	@./$(TARGET)

# Regra de limpeza: remove arquivos compilados intermediários (.o) e diretório build/
clean:
	rm -rf $(BUILD_DIR)

# Regra de limpeza completa: remove também o binário final gerado
clean-all: clean
	rm -f $(TARGET)
