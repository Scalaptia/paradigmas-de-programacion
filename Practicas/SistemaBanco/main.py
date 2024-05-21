import banco
import cuenta
import os
import cuenta_ahorro

banco = banco.Banco()

def MenuAdmin():
    while True:
        os.system('clear')
        print("1.- Agregar cliente")
        print("2.- Agregar cliente de ahorro") 
        print("3.- Listar clientes")
        print("4.- Salir")
        opcion = input("Opcion: ")
        os.system('clear')

        if opcion == "1":
            try:
                nombre = input("Nombre: ")
                saldo = float(input("Saldo: "))
            except ValueError:
                print("Saldo no valido")
                input("Presione Enter para continuar...")
                continue

            cliente = cuenta.Cuenta(nombre, saldo)
            banco.agregar_cliente(cliente)
        elif opcion == "2":
            try:
                nombre = input("Nombre: ")
                saldo = float(input("Saldo: "))
                tasa_interes = float(input("Tasa de interes: "))
            except ValueError:
                print("Saldo o tasa de interes no validos")
                input("Presione Enter para continuar...")
                continue

            cliente = cuenta_ahorro.CuentaAhorro(nombre, saldo, tasa_interes)
            banco.agregar_cliente(cliente)
        elif opcion == "3":
            banco.listar_clientes()
            input("Presione Enter para continuar...")
        elif opcion == "4":
            break
        else:
            print("Opcion no valida")
            input("Presione Enter para continuar...")

def MenuUsuario(usuario):
    while True:
        os.system('clear')
        print(f"Bienvenido {usuario.propietario} - {usuario.numero_cuenta}")
        print("1.- Depositar")
        print("2.- Retirar")
        print("3.- Transferir")
        print("4.- Mostrar saldo")
        if isinstance(usuario, cuenta_ahorro.CuentaAhorro):
            print("5.- Depositar interes")
            print("6.- Salir")
        else:
            print("5.- Salir")

        opcion = input("Opcion: ")
        os.system('clear')

        if opcion == "1":
            try:
                cantidad = float(input("Cantidad: "))
            except ValueError:
                print("Cantidad no valida")
                input("Presione Enter para continuar...")
                continue

            usuario.depositar(cantidad)
            print("Deposito realizado")
            input("Presione Enter para continuar...")
        elif opcion == "2":
            try:
                cantidad = float(input("Cantidad: "))
            except ValueError:
                print("Cantidad no valida")
                input("Presione Enter para continuar...")
                continue

            usuario.retirar(cantidad)
            print("Retiro realizado")
            input("Presione Enter para continuar...")
        elif opcion == "3":
            try:
                cuenta_destino = int(input("Cuenta destino: "))
                cantidad = float(input("Cantidad: "))
            except ValueError:
                print("Cantidad o cuenta destino no validos")
                input("Presione Enter para continuar...")
                continue

            for cliente in banco.clientes:
                if cliente.numero_cuenta == cuenta_destino:
                    usuario.transferir(cantidad, cliente)
                    input("Presione Enter para continuar...")
                    break
            else:
                print("Cuenta destino no encontrada")
                input("Presione Enter para continuar...")
        elif opcion == "4":
            print(f"Saldo: {usuario.mostrar_saldo()}")
            input("Presione Enter para continuar...")
        elif opcion == "5" and not isinstance(usuario, cuenta_ahorro.CuentaAhorro):
            break
        elif opcion == "5" and isinstance(usuario, cuenta_ahorro.CuentaAhorro):
            usuario.depositar_interes()
            print("Interes depositado")
            input("Presione Enter para continuar...")
        elif opcion == "6" and isinstance(usuario, cuenta_ahorro.CuentaAhorro):
            break
        else:
            print("Opcion no valida")
            input("Presione Enter para continuar...")
        
def RegistrarUsuario():
    try:
        tipo_cuenta = int(input("Tipo de cuenta\n1- Normal\n2- Ahorro\nOpcion: "))
        nombre = input("Nombre: ")
    except ValueError:
        print("Tipo de cuenta no valida")
        input("Presione Enter para continuar...")
        return
    
    if tipo_cuenta == 1:
        cliente = banco.registrar_cliente(nombre)
    elif tipo_cuenta == 2:
        try:
            tasa_interes = float(input("Tasa de interes: "))
        except ValueError:
            print("Tasa de interes no valida")
            input("Presione Enter para continuar...")
            return
        
        cliente = banco.registrar_cliente_ahorro(nombre, tasa_interes)
    else:
        print("Tipo de cuenta no valida")
        input("Presione Enter para continuar...")
        return

    if cliente:
        print(f"Usuario {cliente.propietario} registrado con el numero de cuenta {cliente.numero_cuenta}")
        input("Presione Enter para continuar...")
    else:
        print("Error al registrar usuario")
        input("Presione Enter para continuar...")

def IniciarSesion():
    try:
        num_cuenta = int(input("Numero de cuenta: "))
    except ValueError:
        print("Numero de cuenta no valido")
        input("Presione Enter para continuar...")
        return
    
    usuario = banco.iniciar_sesion(num_cuenta)

    if usuario:
        return usuario
    
    print("Usuario no encontrado")
    input("Presione Enter para continuar...")

def MenuInicio():
    while True:
        os.system('clear')
        print("1.- Ingresar como administrador")
        print("2.- Iniciar sesion")
        print("3.- Registrar usuario")
        print("4.- Salir")
        opcion = input("Opcion: ")
        os.system('clear')

        if opcion == "1":
            MenuAdmin()
        elif opcion == "2":
            usuario = IniciarSesion()
            if usuario:
                MenuUsuario(usuario)
        elif opcion == "3":
            RegistrarUsuario()
        elif opcion == "4":
            break
        else:
            print("Opcion no valida")
            input("Presione Enter para continuar...")

MenuInicio()