import cuenta

class Banco:
    def __init__(self):
        self.clientes = []

    def agregar_cliente(self, cliente):
        self.clientes.append(cliente)

    def listar_clientes(self):
        for cliente in self.clientes:
            print(cliente)